
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
    
    public void init() {
        Glink.setOnSdkStartedListener(new OnSdkStartedListener() {
            @Override
            public void onSdkStarted() {
                nativeOnSdkStarted();
            }
        });
    }
    
    public void showMessage(Activity activity) {
        nativeShowMessageBox();
    }
    
    private native void nativeOnSdkStarted();
    private native void nativeShowMessageBox();
}
