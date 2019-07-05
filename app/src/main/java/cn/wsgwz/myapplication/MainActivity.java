package cn.wsgwz.myapplication;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.io.File;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

import dalvik.system.DexClassLoader;

/*
编译执行 工程目录demo.bat
 */
public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    // Used to load the 'native-lib' library on application startup.
    /*static {
        System.loadLibrary("native-lib");
    }
*/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.d(TAG, "-->" + getClassLoader().getClass().getCanonicalName());
        // Example of a call to a native method
        final TextView tv = findViewById(R.id.sample_text);
        //final Jni jni = new Jni();
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //tv.setText(jni.stringFromJNI());

                //LibHelper.unloadAllNativeLibs();
                //LibHelper.unloadNativeLibs(MainActivity.this,"demo.so");
            }
        });


        final TextView tv0 = findViewById(R.id.sample_text_0);
        tv0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*Jni.load();
                tv0.setText(jni.stringFromJNI());*/

                test(MainActivity.this);
            }
        });
        //tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //public native String stringFromJNI();
    public static void test(Context context) {
        DexClassLoader dexClassLoader = new DexClassLoader("/data/data/cn.wsgwz.myapplication/", "/data/data/cn.wsgwz.myapplication/", "/data/data/cn.wsgwz.myapplication/", context.getClassLoader());

        try {
            Class<Object> clazz = (Class<Object>) dexClassLoader.loadClass("cn.wsgwz.myapplication.Jni");
            Log.d(TAG, "loaded class: " + clazz);
            Log.d(TAG, "loaded clazz.hashCode(): " + clazz.hashCode());
            Log.d(TAG, "class loader: " + clazz.getClassLoader());
            Log.d(TAG, "class loader parent: " + clazz.getClassLoader().getParent());
            Constructor constructor = clazz.getConstructor();
            constructor.setAccessible(true);
            Object o = constructor.newInstance();
            Method print = clazz.getDeclaredMethod("print");
            print.setAccessible(true);
            print.invoke(o);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
