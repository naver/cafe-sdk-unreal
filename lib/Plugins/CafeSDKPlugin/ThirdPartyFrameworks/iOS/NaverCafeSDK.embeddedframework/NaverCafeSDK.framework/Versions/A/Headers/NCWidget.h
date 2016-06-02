//
//  WidgetViewController.h
//  Unity-iPhone
//
//  Created by Naver on 2016. 3. 29..
//
//

#import <UIKit/UIKit.h>

@protocol NCWidgetDelegate;

@interface NCWidget : UIViewController

@property (nonatomic, strong) UIButton *mainButton;
@property (nonatomic, weak) id<NCWidgetDelegate> ncWidgetDelegate;

- (void)setUseVideoRecord:(BOOL)useRecord;
- (void)setRootView:(UIView *)view;

+ (NCWidget *)getSharedInstance;

@end

@protocol NCWidgetDelegate <NSObject>
@optional
- (void)ncWidgetPostArticle;
- (void)ncWidtetExecuteGLink;
- (void)ncWidgetPostArticleWithImage;
@end

