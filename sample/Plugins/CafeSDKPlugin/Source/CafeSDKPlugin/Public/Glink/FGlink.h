
#pragma once


class FGlink {
public:
    static const FString NaverLoginClientId;
    static const FString NaverLoginClientSecret;
    static const int CafeId;
    
    virtual void executeMain() = 0;
    
    virtual void executeArticlePost(int32 menuId, FString subject, FString content) = 0;
    
    virtual void executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath) = 0;
    
    virtual void executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath) = 0;
};
