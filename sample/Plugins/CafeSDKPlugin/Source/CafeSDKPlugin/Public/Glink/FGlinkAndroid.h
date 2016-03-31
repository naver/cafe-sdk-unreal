
#pragma once

#include "Core.h"
#include "FGlink.h"
#include "Android/AndroidJava.h"
#include "Runtime/Launch/Public/Android/AndroidJNI.h"


class FAndroidJavaGlink
{
public:
    FAndroidJavaGlink();
    
    void Init(FString ClientId, FString ClientSecret, int32 CafeId) const;
    
    void StartHome() const;
    void StartNotice() const;
    void StartEvent() const;
    void StartMenu() const;
    void StartProfile() const;
    
private:
    static FName GetClassName();
    
    FJavaClassMethod GetClassStaticMethod(const char* MethodName, const char* FuncSig) const;
    
    void StartTab(const FJavaClassMethod& JavaClassMethod) const;
    
    jclass Class;
    FJavaClassMethod InitMethod;
    FJavaClassMethod StartHomeMethod;
    FJavaClassMethod StartNoticeMethod;
    FJavaClassMethod StartEventMethod;
    FJavaClassMethod StartMenuMethod;
    FJavaClassMethod StartProfileMethod;
};


class FGlinkAndroid : public FGlink
{
public:
    FGlinkAndroid();
    void executeMain();
    
    void executeArticlePost(int32 menuId, FString subject, FString content);
    
    void executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath);
    
    void executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath);
    
private:
    FAndroidJavaGlink Glink;
};
