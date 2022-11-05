@echo off

@REM set lib\x64 as working dir and run the executable
START /D %~dp0\..\lib\x64 %~dp0\LoginServer_x64.exe