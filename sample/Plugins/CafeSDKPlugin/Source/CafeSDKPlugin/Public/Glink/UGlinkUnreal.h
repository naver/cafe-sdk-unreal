#pragma once
#include "FGlink.h"
#include "UGlinkUnreal.generated.h"

UCLASS()
class CAFESDKPLUGIN_API UGlinkUnreal : public UObject {
    GENERATED_UCLASS_BODY()
public:
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void executeMain();
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void executeArticlePost(int32 menuId, FString subject, FString content);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath);
    
    UFUNCTION(BlueprintCallable, Category = "Naver CafeSDK")
    void executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath);
    
private:
    FGlink *glink;
};
