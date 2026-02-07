@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM ============================================================
REM VCSI-SUAVPLUGIN build helper (VS2019 x64 + Qt 6.5.3)
REM Run this from the repo root, or set ROOT below.
REM ============================================================

REM If you run this from repo root, leave ROOT as %CD%.
set "ROOT=%CD%"

set "BUILD_DIR=%ROOT%\build"

set "QT6_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6"
set "QT6_GUITOOLS_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6GuiTools"
set "QT6_QML_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6Qml"

set "GEN=Visual Studio 16 2019"
set "ARCH=x64"
set "CONFIG=Release"

REM ============================================================
REM Ensure build dir exists
REM ============================================================
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

pushd "%BUILD_DIR%" || exit /b 1
taskkill /F /IM vcsi.exe

echo.
echo [1/2] Configuring CMake...
echo.

cmake .. -G "%GEN%" -A %ARCH% ^
    -DQt6_DIR="%QT6_DIR%" ^
    -DQt6GuiTools_DIR="%QT6_GUITOOLS_DIR%" ^
    -DQt6Qml_DIR="%QT6_QML_DIR%"

if errorlevel 1 (
    echo.
    echo Configure failed.
    popd
    exit /b 1
)

echo.
echo [2/2] Building (%CONFIG%)...
echo.

cmake --build . --config %CONFIG%

if errorlevel 1 (
    echo.
    echo Build failed.
    popd
    exit /b 1
)

echo.
echo Done.
popd
exit /b 0