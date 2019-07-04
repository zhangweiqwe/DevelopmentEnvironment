@echo off
adb push F:\AndroidStudioWorspaces\MyApplication27\app\src\main\cpp\output\native-lib /sdcard/demo
adb shell "su -c 'cp sdcard/demo /data/local'"
adb shell "su -c 'chmod 777 /data/local/demo'"
adb shell "su -c './data/local/demo'"

echo success!!
pause