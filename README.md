# VCSi-SUAVPLUGIN

Schulich UAVs custom VCSi GCS plugin

# SUAV VCSi Plugin Setup Guide

This guide details the prerequisites, build process, and installation steps for the SUAV VCSi Plugin.

## 1. Prerequisites

Before beginning, ensure your environment meets the following requirements:

* **Operating System:** Windows 10 or later.
* **Compiler:** CMake with MSVC 2019 Compiler (Visual Studio 2019) installed.
* **VCSi Package:** Ensure the VCSi Download Package is installed.
* **Python Environment:** Required for MAVLink header generation.
    * Install Python 3.x and ensure it is added to your system PATH.
    * Install the required dependency:
      pip install future
* **Qt Framework:** Qt 6.5.3 (Requires account creation).

### Important Qt Installation Notes

The VCSi plugin explicitly requires **Qt 6.5.3**, which in turn requires **MSVC 2019**.

1. Download the online installer from Qt Download (https://doc.qt.io/qt-6/get-and-install-qt.html).
2. Run the installer and select **Custom Installation**.
3. Select the **"Archive"** category and click the **"Filter"** (or "Show") dropdown to reveal older versions.
4. Expand the **Qt** dropdown and check **Qt 6.5.3**.
    * Note: Ensure you **deselect** Android, MinGW, and WebAssembly components to save space.

---

## 2. Primary Setup & Build

We now build MAVSDK from source directly within the project. Follow these steps carefully.

### Run as Administrator

Open your terminal (PowerShell or Command Prompt) as **Administrator**. 

Why? The build script attempts to automatically copy the compiled DLL into C:\Program Files\LMCDL\, which requires elevated permissions.

### Build Configuration

1. Navigate to the top-level directory of the project VCSi-SUAVPLUGIN).
2. Clean any old build artifacts (if rebuilding):
   rmdir /s /q build
3. Configure the build:
   cmake -B build -S . -G "Visual Studio 16 2019" -A x64 ^
    -DQt6_DIR="C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6" ^
    -DQt6GuiTools_DIR="C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6GuiTools" ^
    -DQt6Qml_DIR="C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6Qml" ^
    -DQt6QmlTools_DIR="C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6QmlTools" ^
    -DQt6WidgetsTools_DIR="C:/Qt/6.5.3/msvc2019_64/lib/cmake/Qt6WidgetsTools"
4. Build the project:
   cmake --build build --config Release

### Testing with SITL (Software In The Loop)

To test the plugin without a physical drone, use ArduPilot SITL.

The Connection Logic

Step 1: Start SITL

Run the following command (from WSL or your simulation environment). Replace the IP with your Windows machine's IP if necessary, but the default usually works:

python3 sim_vehicle.py -v ArduPlane --console --map --out=udp:x.x.x.x:14550

Step 2: Start the Plugin

Launch the VCSI application. The plugin will automatically start listening on udpin://0.0.0.0:14550.

Troubleshooting Connection

If the plugin is stuck on "Attempting to connect":

* Open Windows Firewall with Advanced Security.
* Check Inbound Rules.
* Ensure vcsi.exe allows UDP traffic on port 14550.