package com.naver.cafe;

//import com.epicgames.ue4.GameActivity;
import com.naver.glink.android.sdk.Glink;
import com.naver.glink.android.sdk.Glink.OnClickAppSchemeBannerListener;
import com.naver.glink.android.sdk.Glink.OnJoinedListener;
import com.naver.glink.android.sdk.Glink.OnPostedArticleListener;
import com.naver.glink.android.sdk.Glink.OnPostedCommentListener;
import com.naver.glink.android.sdk.Glink.OnSdkStartedListener;
import com.naver.glink.android.sdk.Glink.OnSdkStoppedListener;

public class CafeSdk {

  private static native void nativeOnSdkStarted();

  private static native void nativeOnSdkStopped();

  private static native void nativeOnClickAppSchemeBanner(String appScheme);

  private static native void nativeOnJoined();

  private static native void nativeOnPostedArticle(int menuId, int imageCount, int videoCount);

  private static native void nativeOnPostedComment(int articleId);

  private static native void nativeOnVoted(int articleId);

  private static native void nativeOnWidgetScreenshotClick();

  private static native void nativeOnRecordFinished(String uri);

  public void init(String clientId, String clientSecret, int cafeId) {
    Glink.init(clientId, clientSecret, cafeId);

    Glink.setOnSdkStartedListener(new OnSdkStartedListener() {
      @Override public void onSdkStarted() {
        nativeOnSdkStarted();
      }
    });

    Glink.setOnSdkStoppedListener(new OnSdkStoppedListener() {
      @Override public void onSdkStopped() {
        nativeOnSdkStopped();
      }
    });

    Glink.setOnClickAppSchemeBannerListener(new OnClickAppSchemeBannerListener() {
      @Override public void onClickAppSchemeBanner(final String appScheme) {
        nativeOnClickAppSchemeBanner(appScheme);
      }
    });

    Glink.setOnJoinedListener(new OnJoinedListener() {
      @Override public void onJoined() {
        nativeOnJoined();
      }
    });

    Glink.setOnPostedArticleListener(new OnPostedArticleListener() {
      @Override public void onPostedArticle(int menuId, int imageCount, int videoCount) {
        nativeOnPostedArticle(menuId, imageCount, videoCount);
      }
    });

    Glink.setOnPostedCommentListener(new OnPostedCommentListener() {
      @Override public void onPostedComment(final int articleId) {
        nativeOnPostedComment(articleId);
      }
    });

    Glink.setOnVotedListener(new Glink.OnVotedListener() {
      @Override public void onVoted(int articleId) {
        nativeOnVoted(articleId);
      }
    });

    Glink.setOnWidgetScreenshotClickListener(new Glink.OnWidgetScreenshotClickListener() {
      @Override public void onScreenshotClick() {
        nativeOnWidgetScreenshotClick();
      }
    });

    Glink.setOnRecordFinishListener(new Glink.OnRecordFinishListener() {
      @Override public void onRecordFinished(String uri) {
        // Glink.startVideoWrite(GameActivity.Get(), -1, null, null, uri);
      }
    });
  }
}
