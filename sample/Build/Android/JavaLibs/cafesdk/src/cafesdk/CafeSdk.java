
package cafesdk;

import android.widget.Toast;
import android.app.Activity;
import com.naver.glink.android.sdk.Glink;


public class CafeSdk {
    public void startHome(final Activity activity) {
        activity.runOnUiThread(new Runnable() {
            public void run() {
                Glink.startHome(activity);
            }
        });
    }
}
