// Copyright 2016 NAVER Corp. All rights reserved.

#include "CafeSDKPluginPrivatePCH.h"
#include "IOSAppDelegate.h"
#include "IOSView.h"
#include "IOSPlatformString.h"

FIOSCafeSdk* GetSharedCafeSdk()
{
    static FIOSCafeSdk* CafeSdk = nullptr;
    if (CafeSdk == nullptr)
    {
        CafeSdk = new FIOSCafeSdk();
    }
    return CafeSdk;
}

static void ListenNCSDKOpenURL(UIApplication* application, NSURL* url, NSString* sourceApplication, id annotation)
{
    [[NCSDKLoginManager getSharedInstance] finishNaverLoginWithURL:url];
}

FIOSCafeSdk::FIOSCafeSdk()
{
}

void FIOSCafeSdk::Init(FString ClientId, FString ClientSecret, int32 CafeId) const
{
    [[CafeCallbackObject getSharedInstance] setSDKInfoWithClientId:ClientId.GetNSString()
                                                      clientSecret:ClientSecret.GetNSString()
                                                            cafeId:CafeId];
    FIOSCoreDelegates::OnOpenURL.AddStatic(&ListenNCSDKOpenURL);
}

void FIOSCafeSdk::StartHome() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startHome)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

void FIOSCafeSdk::StartNotice() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startNotice)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

void FIOSCafeSdk::StartEvent() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startEvent)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

void FIOSCafeSdk::StartMenu() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startMenu)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

void FIOSCafeSdk::StartMenuById(int32 MenuId) const
{
    dispatch_block_t block = ^{
        [[NCSDKManager getSharedInstance] presentArticleListViewControllerWithMenuId:MenuId];
    };
    [[CafeCallbackObject getSharedInstance] startMainThreadWithBlock:block];
}

void FIOSCafeSdk::StartProfile() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startProfile)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

void FIOSCafeSdk::StartWrite(int32 MenuId, FString Subject, FString Text) const
{
    dispatch_block_t block = ^{
        [[NCSDKManager getSharedInstance] presentArticlePostViewControllerWithMenuId:MenuId
                                                                             subject:[NSString stringWithFString:Subject]
                                                                             content:[NSString stringWithFString:Text]];
    };
    [[CafeCallbackObject getSharedInstance] startMainThreadWithBlock:block];
}

void FIOSCafeSdk::StartImageWrite(int32 MenuId, FString Subject, FString Text, FString ImageUri) const
{
    dispatch_block_t block = ^{
        [[NCSDKManager getSharedInstance] presentArticlePostViewControllerWithType:kGLArticlePostTypeImage
                                                                            menuId:MenuId
                                                                           subject:[NSString stringWithFString:Subject]
                                                                           content:[NSString stringWithFString:Text]
                                                                          filePath:[NSString stringWithFString:ImageUri]];
    };
    [[CafeCallbackObject getSharedInstance] startMainThreadWithBlock:block];
}

void FIOSCafeSdk::StartVideoWrite(int32 MenuId, FString Subject, FString Text, FString VideoUri) const
{
    dispatch_block_t block = ^{
        [[NCSDKManager getSharedInstance] presentArticlePostViewControllerWithType:kGLArticlePostTypeVideo
                                                                            menuId:MenuId
                                                                           subject:[NSString stringWithFString:Subject]
                                                                           content:[NSString stringWithFString:Text]
                                                                          filePath:[NSString stringWithFString:VideoUri]];
    };
    [[CafeCallbackObject getSharedInstance] startMainThreadWithBlock:block];
}

bool FIOSCafeSdk::IsShow() const
{
    return false;
}

void FIOSCafeSdk::SyncGameUserId(FString GameUserId) const
{
    [[NCSDKManager getSharedInstance] syncGameUserId:[NSString stringWithFString:GameUserId]];
}

void FIOSCafeSdk::StartMore() const
{
    [[CafeCallbackObject getSharedInstance] performSelectorOnMainThread:@selector(startMore)
                                                             withObject:nil
                                                          waitUntilDone:NO];
}

bool FIOSCafeSdk::IsSupportedIOSVersion() const
{
    bool isSupported = false;
    static NSString *reqSysVer = @"7.0";
    NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
    if ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending)
    {
        isSupported = true;
    }
    return isSupported;
}


@implementation CafeCallbackObject
#pragma mark - NCSDKDelegate
+ (CafeCallbackObject*)getSharedInstance
{
    static CafeCallbackObject *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance  = [[[self class] alloc] init];
    });
    [sharedInstance setParentViewController];
    return sharedInstance;
}
- (void)setSDKInfoWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret cafeId:(NSInteger)cafeId {
    [[NCSDKManager getSharedInstance] setNaverLoginClientId:clientId
                                     naverLoginClientSecret:clientSecret
                                                     cafeId:cafeId];
    [[NCSDKManager getSharedInstance] setOrientationIsLandscape:YES];
    [[NCWidget getSharedInstance] setNcWidgetDelegate:self];
}

- (void)setParentViewController {
    [[NCSDKManager getSharedInstance] setParentViewController:[IOSAppDelegate GetDelegate].IOSController];
    [[NCSDKManager getSharedInstance] setNcSDKDelegate:self];
}
- (void)startHome {
    [[NCSDKManager getSharedInstance] presentMainViewController];
}
- (void)startNotice {
    [[NCSDKManager getSharedInstance] presentMainViewControllerWithTabIndex:kGLTabTypeNotice];
}
- (void)startEvent {
    [[NCSDKManager getSharedInstance] presentMainViewControllerWithTabIndex:kGLTabTypeEvent];
}
- (void)startMenu {
    [[NCSDKManager getSharedInstance] presentMainViewControllerWithTabIndex:kGLTabTypeMenuList];
}
- (void)startProfile {
    [[NCSDKManager getSharedInstance] presentMainViewControllerWithTabIndex:kGLTabTypeProfile];
}
- (void)startMore {
    [[NCSDKManager getSharedInstance] presentEtc];
}
- (void)startMainThreadWithBlock:(void (^)(void))block {
    if (![[NSThread currentThread] isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), block);
    } else {
        block();
    }
}
#pragma mark NCSDKDelegate
- (void)ncSDKViewDidLoad {
    FCafeSDKPluginModule::OnCafeSdkStarted.Broadcast();
}
- (void)ncSDKViewDidUnLoad {
    [[NCSDKManager getSharedInstance] startWidget];
    FCafeSDKPluginModule::OnCafeSdkStopped.Broadcast();
}
- (void)ncSDKJoinedCafeMember {
    FCafeSDKPluginModule::OnCafeSdkJoined.Broadcast();
}
- (void)ncSDKPostedArticleAtMenu:(NSInteger)menuId {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        FCafeSDKPluginModule::OnCafeSdkPostedArticle.Broadcast(menuId);
    });
}
- (void)ncSDKPostedCommentAtArticle:(NSInteger)articleId {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        FCafeSDKPluginModule::OnCafeSdkPostedComment.Broadcast(articleId);
    });
}
- (void)ncSDKRequestScreenShot {
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}
- (void)ncWidgetPostArticle {
    GetSharedCafeSdk()->StartWrite(0, "", "");
}
- (void)ncWidtetExecuteGLink {
    GetSharedCafeSdk()->StartHome();
}
- (void)ncWidgetPostArticleWithImage {
    FScreenshotRequest::RequestScreenshot("CafeSdkScreenshot.png", false, false);
}
@end
