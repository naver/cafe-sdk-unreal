
package cafesdk;

import android.widget.Toast;
import android.app.Activity;

import com.naver.glink.android.sdk.Glink;
import com.naver.glink.android.sdk.Glink.OnClickAppSchemeBannerListener;
import com.naver.glink.android.sdk.Glink.OnJoinedListener;
import com.naver.glink.android.sdk.Glink.OnPostedArticleListener;
import com.naver.glink.android.sdk.Glink.OnPostedCommentListener;
import com.naver.glink.android.sdk.Glink.OnSdkStartedListener;
import com.naver.glink.android.sdk.Glink.OnSdkStoppedListener;

public class CafeSdk {
    
    public void init(String clientId, String clientSecret, int cafeId) {
    	Glink.init(clientId, clientSecret, cafeId);
    	
        Glink.setOnSdkStartedListener(new OnSdkStartedListener() {
            @Override
            public void onSdkStarted() {
                nativeOnSdkStarted();
            }
        });
        
        Glink.setOnSdkStoppedListener(new OnSdkStoppedListener() {
			@Override
			public void onSdkStopped() {
				nativeOnSdkStopped();
			}
		});
		
		Glink.setOnClickAppSchemeBannerListener(new OnClickAppSchemeBannerListener() {
			@Override
			public void onClickAppSchemeBanner(final String appScheme) {
					nativeOnClickAppSchemeBanner(appScheme);
			}			
		});
		
		Glink.setOnJoinedListener(new OnJoinedListener() {
			@Override
			public void onJoined() {
				nativeOnJoined();
			}
		});
		
		Glink.setOnPostedArticleListener(new OnPostedArticleListener() {
			@Override
			public void onPostedArticle(final int menuId) {
				nativeOnPostedArticle(menuId);
			}
		});
		
		Glink.setOnPostedCommentListener(new OnPostedCommentListener() {
			@Override
			public void onPostedComment(final int articleId) {
				nativeOnPostedComment(articleId);
			}
		});
    }
    
    private native void nativeOnSdkStarted();
    private static native void nativeOnSdkStopped();
	private static native void nativeOnClickAppSchemeBanner(String appScheme);
	private static native void nativeOnJoined();
	private static native void nativeOnPostedArticle(int menuId);
	private static native void nativeOnPostedComment(int articleId);
}
