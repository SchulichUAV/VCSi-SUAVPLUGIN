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

## 2. Build and Install

Open PowerShell as Administrator in the repository root. Save your work in VCSi before running [install.bat](install.bat), since the script closes any running VCSi instance.

```powershell
git submodule update --init --recursive
.\install.bat
```

The script builds the Release plugin and copies the DLL into the VCSi plugin directory. It expects Qt 6.5.3 for MSVC 2019 x64 at `C:\Qt\6.5.3\msvc2019_64`. If Qt is installed elsewhere, update the Qt paths in the script.

Keep `build/` between runs so CMake can reuse its configuration and compiled dependencies. Run `.\install.bat --configure` after adding or removing source files, updating the MAVSDK submodule, or changing Qt paths. This refreshes the project files while keeping the existing build output.

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
