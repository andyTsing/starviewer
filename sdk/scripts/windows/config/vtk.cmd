set SourceDir=%UserProfile%\Downloads\VTK-6.1.0

if %BuildType% == debug (
    set CMakeBuildType=Debug
    set BuildDir=%SourceDir%-build-debug
    set InstallPrefix=%SystemDrive%/VTK/6.1.0d
)
if %BuildType% == release (
    set CMakeBuildType=RelWithDebInfo
    set BuildDir=%SourceDir%-build-release
    set InstallPrefix=%SystemDrive%/VTK/6.1.0
)

REM ============== Nothing should need to be changed below this line ==============

set CMakeOptions=-DCMAKE_BUILD_TYPE:STRING=%CMakeBuildType% ^
                 -DCMAKE_INSTALL_PREFIX:PATH="%InstallPrefix%" ^
                 -DVTK_Group_Qt:BOOL=TRUE ^
                 -DVTK_QT_VERSION:STRING=5

set VtkDir=%InstallPrefix%/lib/cmake/vtk-6.1
