# PLUG SDK

![http://static.naver.net/m/cafe/glink/promotion/cafe_sdk_open/img_intro1_20151111.png](http://static.naver.net/m/cafe/glink/promotion/cafe_sdk_open/img_intro1_20151111.png)

PLUG SDK는 모바일 게임에서 이탈하지 않고 커뮤니케이션이 가능한 IN-GAME COMMUNITY 라이브러리 입니다. 간단한 조작으로 프로젝트에 PLUG SDK를 추가 할 수 있습니다.

이미 많은 게임에 적용되어 검증되어 있는 PLUG SDK는 손쉽게 커뮤니케이션 기능을 게임 안에 넣을 수 있습니다.

# How To Get Started
- 최신 버전을 [다운로드](https://github.com/naver/cafe-sdk-unreal/archive/master.zip)하면 샘플 프로젝트를 실행할 수 있다.
- 한국 채널인 네이버 카페를 사용하기 위해 [제휴 신청](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D-%EC%84%A0%ED%96%89-%EC%9E%91%EC%97%85)이 필요하다.
- 글로벌 채널을 사용하기 위해 [제휴 신청](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)이 필요하다.
- 프로젝트에 적용하기 위한 [위키 가이드](https://github.com/naver/cafe-sdk-unreal/wiki)가 작성 되어 있다.

# Communication
- [개발 문의 사항](http://cafe.naver.com/ArticleList.nhn?search.clubid=28285034&search.menuid=13&search.boardtype=L)에 있는 질문과 답변이 적용하는데 도움이 될 수 있다.
- 문의 사항이 있는 경우 [카페](http://cafe.naver.com/navercafesdk) 혹은 [e-mail](dl_navercafesdk@navercorp.com)을 사용한다.

# Usages
- [iOS GitHub](https://github.com/naver/cafe-sdk-ios)
- [Android GitHub](https://github.com/naver/cafe-sdk-android)

## 프로젝트 설정
Plugins 폴더에 CafeSDKPlugin을 복사한다.

### Android
Build/Android 폴더에 제공된 Android를 복사한다.
- ManifestApplicationAdditions.txt
- javaLibs (folder)

### iOS
DefaultEngine.ini에 프로젝트 설정을 추가한다.
```
AdditionalLinkerFlags=-ObjC
AdditionalShippingLinkerFlags=-ObjC
AdditionalPlistData=<key>CFBundleURLTypes</key> <array>    <dict>            <key>CFBundleURLSchemes</key>           <array>               <string>gLinkSample</string>        </array>    </dict>   </array><key>NSAppTransportSecurity</key><dict><key>NSAllowsArbitraryLoads</key><true/></dict> <key>LSApplicationQueriesSchemes</key><array><string>navercafe</string><string>naversearchapp</string><string>naversearchthirdlogin</string></array>    <key>CFBundleURLTypes</key><array><dict><key>CFBundleTypeRole</key><string>Editor</string><key>CFBundleURLSchemes</key><array><string>gLinkSample</string></array></dict></array><key>NSPhotoLibraryUsageDescription</key><string>Access your photos to create a post.</string>
```

Build.cs에 Framework를 추가한다.

```
if (Target.Platform == UnrealTargetPlatform.IOS)
{
    // Add framework
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "NaverCafeSDK",
            "../../ThirdPartyFrameworks/iOS/NaverCafeSDK.embeddedframework.zip",
            "Resources/NaverCafeSDK.bundle"
        )
    );
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "NaverLogin",
            "../../ThirdPartyFrameworks/iOS/NaverLogin.embeddedframework.zip",
            "Resources/NaverAuth.bundle"
        )
    );
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "AFNetworking",
            "../../ThirdPartyFrameworks/iOS/AFNetworking.embeddedframework.zip"
        )
    );
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "SDWebImage",
            "../../ThirdPartyFrameworks/iOS/SDWebImage.embeddedframework.zip"
        )
    );
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "FLAnimatedImage",
            "../../ThirdPartyFrameworks/iOS/FLAnimatedImage.embeddedframework.zip"
        )
    );

    PublicFrameworks.AddRange(
        new string[] {
            "UIKit",
            "Foundation",
            "MediaPlayer",
            "SystemConfiguration",
            "Security",
            "MobileCoreServices",
            "GameKit",
            "AssetsLibrary",
        }
    );
    PublicWeakFrameworks.Add("ReplayKit");
}
```

## Initialize
### 한국 채널(네이버 카페)

[네이버 아이디로 로그인](https://developers.naver.com/products/login/api)에 애플리케이션을 등록하고 받은 ClientId, ClientSecret 값을 세팅한다.

[네이버 카페를 개설](http://section.cafe.naver.com/)하고 얻은 카페 ID를 세팅한다.

[네이버 아이디로 로그인](https://developers.naver.com/products/login/api)에 애플리케이션 설정에 등록한 iOS URL Scheme을 세팅한다.

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    UCafeSdkBlueprintLibrary::Init("U5ZHoj_OStOHOJ8mec_s", "piPHPA9i4E", 28334359);
}
```



### 글로벌 채널 
[제휴 신청](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)을 통해 받은 ConsumerKey, communityId 값을 세팅한다.

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    UCafeSdkBlueprintLibrary::InitGlobal("IHCd_HmSiMcXOMC37xZ8", 1013329, NULL);
}
```

## UCafeSdkBlueprintLibrary

### StartHome
PLUG를 실행한다.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void StartHome();

```

### ShowWidgetWhenUnloadSdk

PLUG X버튼을 클릭할 때 위젯이 화면에 노출되는 여부를 설정한다.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void ShowWidgetWhenUnloadSdk(bool bUse);

```

### SetUseVideoRecord

PLUG 위젯에 녹화 버튼 노출 여부를 설정한다. (iOS 9.0 이상)


```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void SetUseVideoRecord(bool bUse);

```

### CallBack Delegate
PLUG에서는 PLUG에서 발생하는 사용자 이벤트를 콜백 함수로 전달해 준다.

PLUG 실행/종료, 글작성(이미지/동영상 첨부 개수), 가입, 댓글 작성, 투표 등이 있다.

```cpp
static FOnCafeSdkStarted OnCafeSdkStarted;
static FOnCafeSdkStopped OnCafeSdkStopped;
static FOnCafeSdkClickAppSchemeBanner OnCafeSdkClickAppSchemeBanner;
static FOnCafeSdkJoined OnCafeSdkJoined;
static FOnCafeSdkPostedArticle OnCafeSdkPostedArticle;
static FOnCafeSdkPostedComment OnCafeSdkPostedComment;
static FOnCafeSdkRecordFinish OnCafeSdkRecordFinish;
static FOnCafeSdkDidVote OnCafeSdkDidVote;
```

## Requirements
Unreal Engine | 설명
--- | ---
4.13 | iOS 동영상 녹화 가능 버전<br>ReplayKit.framework : https://docs.unrealengine.com/latest/INT/Support/Builds/ReleaseNotes/2016/4_13/index.html
4.11 | iOS 최소 버전<br>flag issue : iOS -ObjC setting at Other Linker Flags(https://github.com/EpicGames/UnrealEngine/pull/1775)

폴더 구조
-------------

file      | 설명 		
---			| ---		
guide/			| 가이드 문서 및 CafeSDK 설명
lib/		 	| Android/iOS 용 CafeSDK 라이브러리 파일
sample/		| CafeSDK 샘플 UE4 프로젝트
LICENSE     | 라이선스 파일
README.md   | readme 파일


의존 라이브러리 iOS
-------------

1. [네이버 아이디 로그인-4.0.7](https://nid.naver.com/devcenter/docs.nhn?menu=IOS)
2. [AFNetworking](https://github.com/AFNetworking/AFNetworking)
<br>2.x 모두 사용 가능하며 2.6.3에서 테스트 진행했습니다.
3. [SDWebImage-3.8.2](https://github.com/rs/SDWebImage)
4. [FLAnimatedImage-1.0.12](https://github.com/Flipboard/FLAnimatedImage)


의존 라이브러리 Android
-------------

1. [네이버 아이디 로그인](https://nid.naver.com/devcenter/docs.nhn?menu=Android)
2. android support library v4
3. [naver volleyer](http://mvnrepository.com/artifact/com.navercorp.volleyextensions/volleyer)   (2.0.1 사용 중)
4. [volley](http://mvnrepository.com/artifact/com.mcxiaoke.volley/library/) (1.0.2사용 중)
5. [google gson](http://mvnrepository.com/artifact/com.google.code.gson/gson)  (2.3.1 사용 중)
6. [glide](http://mvnrepository.com/artifact/com.github.bumptech.glide/glide)  (3.6.1 사용 중)
7. [otto](http://mvnrepository.com/artifact/com.squareup/otto)  (1.3.8 사용 중)

라이선스
-------------
NAVER Cafe SDK for Unreal Engine

Copyright 2016 NAVER Corp. All rights reserved.

Unauthorized use, modification and redistribution of this software are strongly prohibited.

