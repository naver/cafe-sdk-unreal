
#pragma once

#if PLATFORM_ANDROID
#include "Core.h"
#include "FGlink.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"


class FGlinkAndroid : public FGlink, public FJavaClassObject
{
public:
    FGlinkAndroid();
    void executeMain();
    
    void executeArticlePost(int menuId, FString subject, FString content);
    
    void executeArticlePostWithImage(int menuId, FString subject, FString content, FString filePath);
    
    void executeArticlePostWithVideo(int menuId, FString subject, FString content, FString filePath);
    
private:
    static FName GetClassName();
    FJavaClassMethod initMethod;
    FJavaClassMethod executeMainMethod;
//    FJavaClassMethod executeArticlePostMethod;
//    FJavaClassMethod executeArticlePostWithImageMethod;
//    FJavaClassMethod executeArticlePostWithVideoMethod;
    
};
#endif