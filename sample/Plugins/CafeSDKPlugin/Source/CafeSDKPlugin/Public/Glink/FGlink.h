
#pragma once


class FGlink {
public:
    static const FString NaverLoginClientId;
    static  const FString NaverLoginClientSecret;
    static const int CafeId;
    
    FGlink();
    virtual void executeMain() {}
    
    void executeArticlePost(int menuId, FString subject, FString content);
    
    void executeArticlePostWithImage(int menuId, FString subject, FString content, FString filePath);
    
    void executeArticlePostWithVideo(int menuId, FString subject, FString content, FString filePath);

};
