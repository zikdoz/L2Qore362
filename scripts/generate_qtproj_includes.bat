@echo off

cd ../tools

pri-gen.exe ../Common/database
pri-gen.exe ../Common/enum
pri-gen.exe ../Common/interface
pri-gen.exe ../Common/type
pri-gen.exe ../Common/util

pri-gen.exe ../LoginServer/app
pri-gen.exe ../LoginServer/ui

pri-gen.exe ../GameServer/ui