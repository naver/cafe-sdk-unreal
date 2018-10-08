# PLUG SDK

PLUG SDK는 모바일 게임 사용자가 게임 도중 게임을 벗어나지 않고 게임의 커뮤니티와 소통할 수 있도록 제공되는 인앱 커뮤니티 라이브러리입니다. 간단한 조작으로 프로젝트에 PLUG SDK를 추가할 수 있습니다.

이미 많은 게임에 적용돼 검증된 PLUG SDK를 사용하면 손쉽게 커뮤니케이션 기능을 게임 안에 넣을 수 있습니다.
 
![PLUG](http://static.naver.net/m/cafe/glink/promotion/cafe_sdk_open/img_intro1_20151111.png)

## How To Get Started 

### 제휴 신청

PLUG SDK를 앱에 적용하려면 PLUG SDK 제휴를 신청해야 합니다. 제휴 양식을 작성해 PLUG 제휴 담당자에게 메일로 제휴를 신청합니다.

- [제휴 양식 다운로드](https://github.com/naver/cafe-sdk-android/raw/master/guide/alliance/%EB%84%A4%EC%9D%B4%EB%B2%84%EC%B9%B4%ED%8E%98SDK_%EC%A0%9C%ED%9C%B4%EC%96%91%EC%8B%9D_%EA%B2%8C%EC%9E%84%EC%82%AC%EB%AA%85_%EA%B2%8C%EC%9E%84%EB%AA%85_ver.2.0.0.xlsx)
- PLUG 제휴 담당자 메일 주소: <a href="mailto:dl_naverplugpartner@navercorp.com">dl_naverplugpartner@navercorp.com</a>

제휴 신청이 완료되면 PC의 카페 관리 페이지에서 네이버 PLUG SDK 콘텐츠를 관리할 수 있습니다. 

### 적용 가이드

- [PLUG 적용 가이드](https://github.com/naver/cafe-sdk-unreal/wiki)
- [최신 버전 및 샘플 프로젝트 다운로드](https://github.com/naver/cafe-sdk-unreal/archive/master.zip)
  
## Communication 

개발과 관련된 문의 사항은 PLUG 공식 카페를 사용합니다.

- [PLUG 공식 카페](http://cafe.naver.com/navercafesdk)
- [PLUG 공식 카페의 개발 문의 게시판](http://cafe.naver.com/ArticleList.nhn?search.clubid=28285034&search.menuid=13&search.boardtype=L)
  
## Usages 

### 1. 요구 사항 

|Unreal 엔진 버전	|설명|
|---|---|
|4.13	|iOS에서 동영상 녹화가 가능한 버전("[Unreal Engine 4.13 Release Notes](https://docs.unrealengine.com/latest/INT/Support/Builds/ReleaseNotes/2016/4_13/index.html)" 참고)|
|4.11	|iOS용 PLUG SKD를 사용할 수 있는 최소 버전("[flag issue : iOS -ObjC setting at Other Linker Flags](https://github.com/EpicGames/UnrealEngine/pull/1775)" 참고, 접근 권한 필요)|

### 2. 프로젝트 설정 

다운로드한 샘플 프로젝트에 포함된 **Plugins/CafeSDKPlugin** 폴더를 프로젝트에 복사한 다음 운영체제에 따라 다음과 같이 개발 환경을 설정합니다.

> 운영체제별 PLUG SDK에 관한 자세한 내용은 GitHub 저장소를 참고합니다.
> - [Android용 PLUG SDK의 GitHub 저장소](https://github.com/naver/cafe-sdk-android)
> - [iOS용 PLUG SDK의 GitHub 저장소](https://github.com/naver/cafe-sdk-ios)

#### 2.1 Android 설정

다운로드한 샘플 프로젝트에 포함된 **Build/Android** 폴더에서 다음 파일과 폴더를 프로젝트에 복사합니다.

- ManifestApplicationAdditions.txt
- JavaLibs 폴더

#### 2.2 iOS 설정

**DefaultEngine.ini** 파일에 다음과 같이 프로젝트 설정을 추가합니다.

```
AdditionalLinkerFlags=-ObjC
AdditionalShippingLinkerFlags=-ObjC
AdditionalPlistData=<key>CFBundleURLTypes</key> <array>    <dict>            <key>CFBundleURLSchemes</key>           <array>               <string>gLinkSample</string>        </array>    </dict>   </array><key>NSAppTransportSecurity</key><dict><key>NSAllowsArbitraryLoads</key><true/></dict> <key>LSApplicationQueriesSchemes</key><array><string>navercafe</string><string>naversearchapp</string><string>naversearchthirdlogin</string></array>    <key>CFBundleURLTypes</key><array><dict><key>CFBundleTypeRole</key><string>Editor</string><key>CFBundleURLSchemes</key><array><string>gLinkSample</string></array></dict></array><key>NSPhotoLibraryUsageDescription</key><string>Access your photos to create a post.</string>
```

**Build.cs** 파일에 다음과 같이 프레임워크 설정을 추가합니다.

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
    PublicAdditionalFrameworks.Add(
        new UEBuildFramework(
            "ApiGateway",
            "../../ThirdPartyFrameworks/iOS/ApiGateway.embeddedframework.zip"
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

### 3. 초기화

PLUG SDK가 지원하는 언어에 따라 다음과 같이 PLUG SDK를 초기화합니다.

#### 3.1 PLUG SDK 초기화(한국어만 지원 - 네이버 카페)

한국어만 지원하는 PLUG SDK를 초기화할 때는 다음과 같은 초기화 정보를 설정합니다.

- [네이버 아이디로 로그인 개발자 센터](https://developers.naver.com/products/login/api)에서 애플리케이션을 등록하고 받은 클라이언트 아이디(ClientId)와 클라이언트 시크릿(ClientSecret)
- [네이버 카페](http://section.cafe.naver.com/)에서 카페를 개설하고 받은 카페 ID
- [네이버 아이디로 로그인 개발자 센터](https://developers.naver.com/products/login/api)에 애플리케이션을 등록할 때 입력한 URL Scheme

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    UCafeSdkBlueprintLibrary::Init("U5ZHoj_OStOHOJ8mec_s", "piPHPA9i4E", 28334359);
}
```

#### 3.2 PLUG SDK 초기화(외국어만 지원) 

외국어만 지원하는 PLUG SDK를 초기화할 때는 다음과 같은 초기화 정보를 설정합니다.

- [PLUG SDK 제휴 신청](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)을 통해 받은 컨슈머 키(Consumer Key) 와 컨슈머 시크릿(Consumer Secret)
- [PLUG SDK 제휴 신청](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)을 통해 받은 Community No 와 Lounge No 

- consumerKey: 커뮤니티를 개설하고 받은 컨슈머 키(Consumer Key)
- consumerSecretKey: 커뮤니티를 개설하고 받은 컨슈머 시크릿(Consumer Secret Key)
- cummunityNo: 커뮤니티를 개설하고 받은 커뮤니티 No(cummunityNo)
- loungeNo: 라운지를 개설하고 받은 라운지 No(cummunityNo)

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    /**
     * @param consumerKey       컨슈머 키
     * @param consumerSecretKey 컨슈머 시크릿 키 
     * @param communityNo       커뮤니티 번호
     * @param loungeNo          라운지 번호                      
     */
     UCafeSdkBlueprintLibrary::InitGlobal("PLUGKEY", "PLUGSECRET", 1, 58);
}
```

### 4. PLUG SDK 시작

초기화가 완료되면 PLUG SDK를 실행합니다.

#### 4.1 StartHome() 메서드

StartHome() 메서드는 PLUG SDK를 시작하는 메서드입니다.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void StartHome();
```

#### 4.2 ShowWidgetWhenUnloadSdk() 메서드

ShowWidgetWhenUnloadSdk() 메서드 PLUG SDK에서 접기 버튼을 눌렀을 때 위젯이 화면에 노출되도록 설정하는 메서드입니다.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void ShowWidgetWhenUnloadSdk(bool bUse);
```

#### 4.3 SetUseVideoRecord() 메서드

SetUseVideoRecord() 메서드는 PLUG SDK 위젯에 동영상 녹화 버튼을 노출하도록 설정하는 메서드입니다 (iOS 9.0 이상).

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void SetUseVideoRecord(bool bUse);
```

#### 4.4 콜백 델리게이트

콜백 델리게이트를 설정해 PLUG SDK에서 발생하는 사용자 이벤트를 콜백 함수로 전달합니다.

콜백 델리게이트를 통해 호출되는 메서드로 PLUG SDK 실행/종료, 글작성(이미지/동영상 첨부 개수), 가입, 댓글 작성, 투표 등을 실행할 수 있습니다.

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

## Files and Folders

|폴더 및 파일 이름	|설명|
|---|---|
|guide/	|PLUG SDK 적용 가이드가 있는 폴더|
|lib/	|Android용 PLUG SDK 라이브러리와 iOS용 PLUG SDK 라이브러리 파일이 있는 폴더|
|sample/	|샘플 프로젝트가 있는 폴더|
|LICENSE	|라이선스 파일 |
|README.md	|리드미 파일|

## Dependent Libraries

PLUG SDK를 사용하려면 다음 라이브러리를 프로젝트에 추가해 함께 빌드해야 합니다. 라이브러리는 샘플 프로젝트에 포함돼 있습니다. 

### Android용 라이브러리 

- Android Support Library v4
- Android Support Custom Tabs
- Android Support RecyclerView
- [네이버 아이디 로그인](https://nid.naver.com/devcenter/docs.nhn?menu=Android)
- [NAVER Volleyer](http://mvnrepository.com/artifact/com.navercorp.volleyextensions/volleyer)(2.0.1 버전 사용 중)
- [Volley](http://mvnrepository.com/artifact/com.mcxiaoke.volley/library/)(1.0.2 버전 사용 중)
- [Google Gson](http://mvnrepository.com/artifact/com.google.code.gson/gson)(2.3.1 버전 사용 중)
- [Glide](http://mvnrepository.com/artifact/com.github.bumptech.glide/glide)(3.6.1 버전 사용 중)
- [Otto](http://mvnrepository.com/artifact/com.squareup/otto)(1.3.8 버전 사용 중)  
- hmac(2.3.1 버전 사용중) 

### iOS용 라이브러리 

- [네이버 아이디 로그인](https://nid.naver.com/devcenter/docs.nhn?menu=IOS)(4.0.7 버전)
- [AFNetworking](https://github.com/AFNetworking/AFNetworking)(3.1.0 버전 )

>  AFNetworking 2.x 버전과 3.x 버전 모두 사용할 수 있습니다. PLUG SDK 테스트는 AFNetworking 3.1.0 버전으로 진행했습니다.

- [SDWebImage](https://github.com/rs/SDWebImage)(3.8.2 버전)
- [FLAnimatedImage](https://github.com/Flipboard/FLAnimatedImage)(1.0.12 버전)
- ApiGateway-1.5.0 

## License 

PLUG SDK의 저작권은 네이버(주)에 있습니다.

```
NAVER Cafe SDK for Unreal Engine

Copyright 2016 NAVER Corp.
All rights reserved.

Unauthorized use, modification and redistribution of this software are strongly prohibited.
```


## PLUG SDK 2.x, 3.x 버전은 더 이상 지원되지 않습니다.
