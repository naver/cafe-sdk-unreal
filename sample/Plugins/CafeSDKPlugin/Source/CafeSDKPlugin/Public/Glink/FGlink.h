
#pragma once


class FGlink {
public:
    static const FString NaverLoginClientId;
    static  const FString NaverLoginClientSecret;
    static const int CafeId;
    
    virtual void executeMain() {}
    
    virtual void executeArticlePost(int32 menuId, FString subject, FString content) { }
    
    virtual void executeArticlePostWithImage(int32 menuId, FString subject, FString content, FString filePath){ }
    
    virtual void executeArticlePostWithVideo(int32 menuId, FString subject, FString content, FString filePath){ }

};
