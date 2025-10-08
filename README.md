# wxWidgetsDemo
Demo Application with wxWidgets (3.3.1); built with CMake and Ninja.

Note: Clang build not working at the moment...

# Pre-Requisite:
1) Install CMake (version 3.20 or greater); make sure it is included in PATH
2) Download Ninja and copy folder (containing ninja.exe) to PATH
3) (Optional) Install Clang LLVM and add bin folder to PATH

# Build Procedure
Option 1: Command Line
- from root folder:
    cmake --preset MSVC
    cmake --build --preset MSVV-Debug
- alternatively (if building with Clang):
    cmake --preset Clang
    cmake --build --preset Clang-Debug

Option 2: Visual Studio Code
- Open folder... (project root)
- From the CMake tab:
-- Configure: select Dev-MSVC (or alternatively Dev-Clang)
-- Build
Note: requires C++ extension

Option 3: Visual Studio
- Open a local folder (project root)
- Select configuration MSVC-Debug (or alternatively Clang-Debug)
- Build / Build All
