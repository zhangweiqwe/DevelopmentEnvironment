package cn.wsgwz.myapplication;

import android.util.Log;

public class Jni {
    private static final String TAG = "Jni";

    static {
        Log.d(TAG, "--> Jni");
        System.load("/data/data/cn.wsgwz.myapplication/demo.so");
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


    public void print(){
        Log.d(TAG, "print()");

        try {
            Log.d(TAG,stringFromJNI());
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
