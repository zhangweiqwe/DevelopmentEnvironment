package cn.wsgwz.myapplication;

import android.content.Context;
import android.util.Log;

public class Jni {


    private static final String TAG = "Jni";

    public static int i = 0;

    public static void load() {
        System.load("/data/data/cn.wsgwz.myapplication/demo" );
        i++;
    }

    /*public static void unLoad(Context context){
        //LibHelper.unloadAllNativeLibs();
        //LibHelper.unloadNativeLibs(context,"demo");
        LibraryLoader.ensureInitialized();

    }*/
    /*static {
        //System.loadLibrary("native-lib");
        //System.loadLibrary("/data/local/native-lib");
        //System.loadLibrary("/data/local/libnative-lib.so");

    }*/
    public native String stringFromJNI();
}
