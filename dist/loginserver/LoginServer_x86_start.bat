@echo off

@REM tell qt where to look for platforms
set QT_QPA_PLATFORM_PLUGIN_PATH=%~dp0\..\lib\x86\platforms

@REM set lib\x86 as working dir and run the executable
start /D %~dp0\..\lib\x86 LoginServer_x86.exe