@echo off
adb push F:\AndroidStudioWorspaces\MyApplication27\app\src\main\cpp\output\native-lib /sdcard/demo
adb shell "su -c 'cp sdcard/demo /data/local'"
adb shell "su -c 'chmod 777 /data/local/demo'"
adb shell "su -c './data/local/demo'"

:adb push F:\AndroidStudioWorspaces\MyApplication27\app\build\intermediates\transforms\stripDebugSymbol\debug\0\lib\arm64-v8a\libnative-lib.so /sdcard/demo
:adb shell "su -c 'cp sdcard/demo /data/data/cn.wsgwz.myapplication/'"
:adb shell "su -c 'chmod 777 /data/data/cn.wsgwz.myapplication/demo'"
:adb shell "su -c './data/data/cn.wsgwz.myapplication/demo'"

echo success!!
#pause