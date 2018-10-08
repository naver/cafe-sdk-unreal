# PLUG SDK

The PLUG SDK is a dedicated in-app community library for mobile games, which lets mobile gamers use community features without leaving games while they are playing. It is easy to apply the PLUG SDK to your project.

As a proven SDK, which has been used in many mobile games, this lets you simply and quickly add community features in your game.
 
![PLUG SDK](http://static.naver.net/m/cafe/glink/promotion/cafe_sdk_open/img_intro1_20151111.png)

## How To Get Started 

### Become a Partner

You should apply to our partner program to apply the PLUG SDK to your app. Please fill out the form after downloads and send it via email.

- [Downloads of partnership registration form](https://github.com/naver/cafe-sdk-android/raw/master/guide/alliance/%EB%84%A4%EC%9D%B4%EB%B2%84%EC%B9%B4%ED%8E%98SDK_%EC%A0%9C%ED%9C%B4%EC%96%91%EC%8B%9D_%EA%B2%8C%EC%9E%84%EC%82%AC%EB%AA%85_%EA%B2%8C%EC%9E%84%EB%AA%85_ver.2.0.0.xlsx)
- Email address of a partnership contact: <a href="mailto:dl_naverplugpartner@navercorp.com">dl_naverplugpartner@navercorp.com</a>

You can manage the PLUG SDK content on the Settings page from your computer after the partnership process is completed. 

### Documentation

- [PLUG documents](https://github.com/naver/cafe-sdk-unreal/wiki)
- [Downloads of latest library and sample project files](https://github.com/naver/cafe-sdk-unreal/archive/master.zip)
  
## Communication 

If you have any questions regarding working this SDK, please [visit our issue page for unreal](https://github.com/naver/cafe-sdk-unreal/issues).
  
## Usages 

### 1. Requirements 

|Engine Version	|Description|
|---|---|
|4.13	|Version in which video recording is available for iOS (see "[Unreal Engine 4.13 Release Notes](https://docs.unrealengine.com/latest/INT/Support/Builds/ReleaseNotes/2016/4_13/index.html)")|
|4.11	|Minimal version in which the PLUG SDK is available for iOS (see "[flag issue : iOS -ObjC setting at Other Linker Flags](https://github.com/EpicGames/UnrealEngine/pull/1775)", permission required)|

### 2. Configure a Project 

Copy and paste the **Plugins/CafeSDKPlugin** folder to your project, which is included in the sample project you downloaded, and configure the development environment for your operating system.

> For more information about PLUG SDK for each operating system, visit the GitHub repository.
> - [GitHub repository for Android PLUG SDK](https://github.com/naver/cafe-sdk-android)
> - [GitHub repository for iOS PLUG SDK](https://github.com/naver/cafe-sdk-ios)

#### 2.1 For Android

Copy and paste the file and folder below from the **Build/Android** folder which is included in the sample project you downloaded.

- ManifestApplicationAdditions.txt
- JavaLibs folders

#### 2.2 For iOS

Add the project configuration in the **DefaultEngine.ini** file as follows:

```
AdditionalLinkerFlags=-ObjC
AdditionalShippingLinkerFlags=-ObjC
AdditionalPlistData=<key>CFBundleURLTypes</key> <array>    <dict>            <key>CFBundleURLSchemes</key>           <array>               <string>gLinkSample</string>        </array>    </dict>   </array><key>NSAppTransportSecurity</key><dict><key>NSAllowsArbitraryLoads</key><true/></dict> <key>LSApplicationQueriesSchemes</key><array><string>navercafe</string><string>naversearchapp</string><string>naversearchthirdlogin</string></array>    <key>CFBundleURLTypes</key><array><dict><key>CFBundleTypeRole</key><string>Editor</string><key>CFBundleURLSchemes</key><array><string>gLinkSample</string></array></dict></array><key>NSPhotoLibraryUsageDescription</key><string>Access your photos to create a post.</string>
```

Add the framework configuration in the **Build.cs** file as follows:

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

### 3. Initialize the PLUG SDK

Initializing the PLUG SDK will vary depending on the supported language.

#### 3.1 Support for Korean only (NAVER Cafe)

Configure the initialization information below to initialize the PLUG SDK that supports Korean only.

- Client ID (ClientId) and client secret (ClientSecret) you received after registering your application in [NAVER Login Developers](https://developers.naver.com/products/login/api)
- Cafe ID you received after creating your Cafe in [NAVER Cafe](http://section.cafe.naver.com/)
- URL Scheme you entered after registering your application in [NAVER Login Developers](https://developers.naver.com/products/login/api)

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    UCafeSdkBlueprintLibrary::Init("U5ZHoj_OStOHOJ8mec_s", "piPHPA9i4E", 28334359);
}
```

#### 3.2 Support for languages other than Korean 

Configure the initialization information below to initialize the PLUG SDK that supports languages other than Korean.

- Consumer key, Consumer secret key you received through the process of [Become a Partner](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)
- Community No and Lounge No you received through the process of [Become a Partner](https://github.com/naver/cafe-sdk-ios/wiki/%5B%ED%95%9C%5D%20%EA%B8%80%EB%A1%9C%EB%B2%8C%20%EB%84%A4%EC%9D%B4%EB%B2%84%20%EC%B9%B4%ED%8E%98%20%EC%82%AC%EC%9A%A9)

```cpp
if (FCafeSDKPluginModule::IsAvailable())
{
    /**
     * @param consumerKey       
     * @param consumerSecretKey
     * @param communityNo       
     * @param loungeNo                       
     */
     UCafeSdkBlueprintLibrary::InitGlobal("PLUGKEY", "PLUGSECRET", 1, 58);
}
```

### 4. Start the PLUG SDK

Start the PLUG SDK after initialization is completed.

#### 4.1 StartHome() method

The StartHome() method starts the PLUG SDK.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void StartHome();
```

#### 4.2 ShowWidgetWhenUnloadSdk() method

The ShowWidgetWhenUnloadSdk() method displays a widget with the fold button selected in the PLUG SDK.

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void ShowWidgetWhenUnloadSdk(bool bUse);
```

#### 4.3 SetUseVideoRecord() method

The SetUseVideoRecord() method displays a video record button in the PLUG SDK widget (for iOS 9.0 or later).

```cpp
UFUNCTION(BlueprintCallable, Category = "Naver CafeSdk")
static void SetUseVideoRecord(bool bUse);
```

#### 4.4 Callback delegate

Enabling a callback delegate passes user events occurred in the PLUG SDK to the callback function.

A method called via the callback delegate can execute actions such as start/stop of PLUG SDK, compose post (number of attached images and videos), join, add comments, vote, and so on.

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

|Name	|Description|
|---|---|
|guide/	|Folder for PLUG SDK documentation|
|lib/	|Folder for Android and iOS PLUG SDK libraries|
|sample/	|Folder for sample project|
|LICENSE	|License file|
|README.md	|Readme file|

## Dependent Libraries 

You should add the following libraries to your project and build together with the PLUG SDK in order to use the PLUG SDK. The libraries are included in the sample project. 

### For Android 

- Android Support Library v4
- Android Support Custom Tabs
- Android Support RecyclerView
- [NAVER Login](https://nid.naver.com/devcenter/docs.nhn?menu=Android)
- [NAVER Volleyer](http://mvnrepository.com/artifact/com.navercorp.volleyextensions/volleyer) (version 2.0.1)
- [Volley](http://mvnrepository.com/artifact/com.mcxiaoke.volley/library/) (version 1.0.2)
- [Google Gson](http://mvnrepository.com/artifact/com.google.code.gson/gson) (version 2.3.1)
- [Glide](http://mvnrepository.com/artifact/com.github.bumptech.glide/glide) (version 3.6.1)
- [Otto](http://mvnrepository.com/artifact/com.squareup/otto) (version 1.3.8)
- hmac (version 2.3.1)

### For iOS 

- [NAVER Login](https://nid.naver.com/devcenter/docs.nhn?menu=IOS) (version 4.0.7)
- [AFNetworking](https://github.com/AFNetworking/AFNetworking) (version 3.1.0)

>  Both 2.x and 3.x versions are available. The PLUG SDK is tested on AFNetworking 3.1.0.

- [SDWebImage](https://github.com/rs/SDWebImage) (version 3.8.2)
- [FLAnimatedImage](https://github.com/Flipboard/FLAnimatedImage) (version 1.0.12)
- ApiGateway-1.5.0 

## License 

The intellectual property right of the PLUG SDK is owned by NAVER Corporation.

```
NAVER Cafe SDK for Unreal Engine

Copyright 2016 NAVER Corp.
All rights reserved.

Unauthorized use, modification and redistribution of this software are strongly prohibited.
```

## PLUG SDK 2.x, 3.x versions are no longer supported
