package com.naver.cafe;

import android.Manifest;
import android.app.Activity;
import android.os.Handler;
import android.os.Looper;
import android.widget.Toast;
import com.naver.glink.android.sdk.Glink;
import com.naver.glink.android.sdk.Glink.OnClickAppSchemeBannerListener;
import com.naver.glink.android.sdk.Glink.OnJoinedListener;
import com.naver.glink.android.sdk.Glink.OnPostedArticleListener;
import com.naver.glink.android.sdk.Glink.OnPostedCommentListener;
import com.naver.glink.android.sdk.Glink.OnSdkStartedListener;
import com.naver.glink.android.sdk.Glink.OnSdkStoppedListener;
import com.naver.glink.android.sdk.NaverIdLogin;

public class CafeSdk {

  private static Handler sHandler = new Handler(Looper.getMainLooper());
  private static boolean sInitializedListeners;

  private static native void nativeOnSdkStarted();

  private static native void nativeOnSdkStopped();

  private static native void nativeOnClickAppSchemeBanner(String appScheme);

  private static native void nativeOnJoined();

  private static native void nativeOnPostedArticle(int menuId, int imageCount, int videoCount);

  private static native void nativeOnPostedComment(int articleId);

  private static native void nativeOnVoted(int articleId);

  private static native void nativeOnWidgetScreenshotClick();

  private static native void nativeOnRecordFinished(String uri);

  private static native void nativeOnLoggedIn(boolean success);

  private static native void nativeOnGetProfile(String jsonString);

  public void init(Activity activity, String clientId, String clientSecret, int cafeId) {
    if (activity == null) return;

    Glink.init(activity, clientId, clientSecret, cafeId);
    initListeners(activity);
  }

  public void initGlobal(Activity activity, String clientId, int cafeId) {
    if (activity == null) return;

    Glink.initGlobal(activity, clientId, cafeId);
    initListeners(activity);
  }

  private void initListeners(final Activity activity) {
    if (sInitializedListeners) return;
    sInitializedListeners = true;

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
        if (Glink.checkPermission(activity, Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
          nativeOnWidgetScreenshotClick();
        } else {
          String message = "권한이 없어 사진 첨부를 할 수 없습니다. 설정 > 앱 > 해당 게임에서 저장 권한을 확인해 주세요.";
          Toast.makeText(activity, message, Toast.LENGTH_LONG).show();

          sHandler.postAtTime(new Runnable() {
            @Override public void run() {
              Glink.startWidget(activity);
            }
          }, 100);
        }
      }
    });

    Glink.setOnRecordFinishListener(new Glink.OnRecordFinishListener() {
      @Override public void onRecordFinished(String uri) {
        Glink.startVideoWrite(activity, uri);
      }
    });
  }

  public void startMore(Activity activity) {
    // do nothing.
  }

  public void login(Activity activity) {
    NaverIdLogin.login(activity, new Glink.OnLoggedInListener() {
      @Override public void onLoggedIn(boolean success) {
        nativeOnLoggedIn(success);
      }
    });
  }

  public void logout(Activity activity) {
    NaverIdLogin.logout(activity);
  }

  public boolean isLogin(Activity activity) {
    return NaverIdLogin.isLogin(activity);
  }

  public void getProfile(Activity activity) {
    NaverIdLogin.getProfile(activity, new NaverIdLogin.OnGetProfileListener() {
      @Override public void onResult(String jsonString) {
        nativeOnGetProfile(jsonString == null ? "" : jsonString);
      }
    });
  }
}
