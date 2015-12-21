
package cafesdk;

import android.widget.Toast;
import android.app.Activity;
import com.naver.glink.android.sdk.Glink;


public class CafeSdk {
    
    public void init(final String clientId, final String clientSecret, final int cafeId) {
        Glink.init(clientId, clientSecret, cafeId);
    }
    
    public void startHome(final Activity activity)
    {
        activity.runOnUiThread(new Runnable(){
            public void run()
            {
                Glink.startHome(activity);
            }
            });
    }
    
    public void startWrite(final Activity activity, final int menuId, final String subject, final String content)
    {
        activity.runOnUiThread(new Runnable(){
            public void run()
            {
                Glink.startWrite(activity, menuId, subject, content);
            }
        });
    }
    
    public void startImageWrite(final Activity activity, final int menuId, final String subject, final String content, final String filePath)
    {
        activity.runOnUiThread(new Runnable(){
            public void run()
            {
                Glink.startImageWrite(activity, menuId, subject, content, filePath);
            }
        });
    }
    
    public void startVideoWrite(final Activity activity, final int menuId, final String subject, final String content, final String filePath)
    {
        activity.runOnUiThread(new Runnable(){
            public void run()
            {
                Glink.startVideoWrite(activity, menuId, subject, content, filePath);
            }
        });
    }
    
}
