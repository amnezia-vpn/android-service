package org.amnezia.amneziavpn;

import android.content.Context;
import android.content.Intent;
import org.qtproject.qt5.android.bindings.QtService;
import android.util.Log;

public class AmneziaAndroidService extends QtService {

    private static final String TAG = "AmneziaAndroidService";

    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "Creating Service");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "Destroying Service");
    }
}
