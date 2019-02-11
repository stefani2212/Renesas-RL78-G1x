echo off
cls
set Path=%path%;D:\GnuWin32\bin
rem make.exe TRG=04_FwBtn_HwVer_1 HW_VER=_HW_VER_1 PART=STM32F031x6 --ignore-errors %1 %2 %3
rem make.exe TRG=04_FwBtn_HwVer_2 HW_VER=_HW_VER_2 PART=STM32F051x8 --ignore-errors %1 %2 %3
make.exe TRG=IvecoWL HW_VER=_HW_VER_1 PART=STM32F303xC --ignore-errors %1 %2 %3
