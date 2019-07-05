@echo off
::有这个标记的，是打了注释的

@echo %~dp0


::adb push %~dp0\app\src\main\cpp\output\native-lib /sdcard/demo
adb push %~dp0app\build\intermediates\transforms\stripDebugSymbol\debug\0\lib\arm64-v8a\libnative-lib.so /sdcard/demo.so
adb shell "su -c 'cp sdcard/demo.so /data/data/cn.wsgwz.myapplication/'"
adb shell "su -c 'chmod 777 /data/data/cn.wsgwz.myapplication/demo.so'"
::adb shell "su -c './data/data/cn.wsgwz.myapplication/demo'"


adb push %~dp0app\build\intermediates\transforms\dexBuilder\debug\0\cn\wsgwz\myapplication\Jni.dex /sdcard/Jni.dex
adb shell "su -c 'cp sdcard/Jni.dex /data/data/cn.wsgwz.myapplication/'"

echo success!!
pause