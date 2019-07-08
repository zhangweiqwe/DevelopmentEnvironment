@echo off
::有这个标记的，是打了注释的

::@echo %~dp0


adb push %~dp0\app\src\main\cpp\native-lib /sdcard/test.so
::adb push %~dp0app\build\intermediates\transforms\stripDebugSymbol\debug\0\lib\arm64-v8a\libnative-lib.so /sdcard/demo.so
adb shell "su -c 'cp sdcard/test.so /data/local/'"
adb shell "su -c 'chmod 777 /data/local/test.so'"
adb shell "su -c './data/local/test.so'"

::adb shell "su -c 'cat /proc/13638/maps'"

::ps -e | grep 进程名

::adb push %~dp0app\build\intermediates\transforms\dexBuilder\debug\0\cn\wsgwz\myapplication\Jni.dex /sdcard/Jni.dex
::adb shell "su -c 'cp sdcard/Jni.dex /data/data/cn.wsgwz.myapplication/'"

echo success!!
pause