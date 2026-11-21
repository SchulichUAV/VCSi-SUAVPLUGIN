@echo off
setlocal EnableExtensions

REM ============================================================
REM VCSI-SUAVPLUGIN build helper (VS2019 x64 + Qt 6.5.3)
REM Use --configure to refresh the generated project without cleaning.
REM ============================================================

set "BUILD_DIR=build"

set "QT6_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6"
set "QT6_GUITOOLS_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6GuiTools"
set "QT6_QML_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6Qml"

set "GEN=Visual Studio 16 2019"
set "ARCH=x64"
set "CONFIG=Release"

if not "%~1"=="" if /I not "%~1"=="--configure" (
    echo Usage: install.bat [--configure]
    exit /b 2
)

pushd "%~dp0" || exit /b 1
if /I "%~1"=="--configure" goto configure
if not exist "%BUILD_DIR%\CMakeCache.txt" goto configure
if not exist "%BUILD_DIR%\SuavPlugin.sln" goto configure
if not exist "%BUILD_DIR%\sw\SuavPlugin.vcxproj" goto configure
if not exist "%BUILD_DIR%\sw\InstallSuavPlugin.vcxproj" goto configure
echo Reusing the CMake configuration in %BUILD_DIR%.
goto build

:configure
echo Configuring CMake...
cmake -S . -B "%BUILD_DIR%" -G "%GEN%" -A %ARCH% ^
    -DQt6_DIR="%QT6_DIR%" ^
    -DQt6GuiTools_DIR="%QT6_GUITOOLS_DIR%" ^
    -DQt6Qml_DIR="%QT6_QML_DIR%"

if errorlevel 1 (
    echo.
    echo Configure failed.
    popd
    exit /b 1
)

:build
taskkill /F /IM vcsi.exe
echo Building and installing SuavPlugin (%CONFIG%)...
cmake --build "%BUILD_DIR%" --config %CONFIG% --target InstallSuavPlugin --parallel

if errorlevel 1 (
    echo.
    echo Build or installation failed.
    popd
    exit /b 1
)

echo.
echo Done.
popd
exit /b 0
