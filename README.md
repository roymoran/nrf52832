## nRF52832 Template Project

Includes minimal template to start firmware project for nRF52832 SoC using ARM GCC Toolchain and VS Code to develop, test, build, and debug. Template includes generic sdk_config.h, linker files, and startup file found in nRF5 SDK directory. More info on SDK [configuration header](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v15.0.0%2Fsdk_config.html).

To build on top of template - modify code under src directory and manage #defines in `c_cpp_properties.json`. As you build your application, INC_FOLDERS and SRC_FILES found in `Makefile` should be modified to reflect those required by your application. 

Reference [nRF5 SDK documentation](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fstruct_sdk%2Fstruct%2Fsdk_nrf5_latest.html)
## Dependencies
- [GNU ARM Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- [nRF5 SDK](https://developer.nordicsemi.com/nRF5_SDK/)
- [nRF Command Line Tools](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools/Download#infotabs)
- [J-Link Software and Documentation Pack](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)
## System Setup
### Environment Variables
Define following system variables

**GNU_GCC**

Path to ARM embedded toolchain install

e.g. `/Applications/ARM`

**nRF5_SDK17**

Path to nRF5 SDK download

e.g. `/Users/roy/nordicsemi/sdk/nRF5_SDK_17.0.2_d674dde`

**GDB_SERVER**

Path to J-LINK GDB Server 

e.g. `/Applications/SEGGER/JLink_V720a/JLinkGDBServerCLExe`

### Configure Makefile.posix or Makefile.windows
Depending your OS, you must modify either Makefile.posix (Linux/macOS) or Makefile.windows found in the SDK directory (`${nRF5_SDK17}/components/toolchain/gcc/`).
Contents of my Makefile.posix on my macOS.
```makefile
GNU_INSTALL_ROOT ?= /Applications/ARM/bin/
GNU_VERSION ?= 10.2.1
GNU_PREFIX ?= arm-none-eabi
```

## Build and Flash Application Code + SoftDevice
To build and flash the MCU you can use the VS Code tasks. Alternatively, run make from the command line.

```bash
# see make commands available
$ make help
# generate DEBUG build
$ make
# generate release build with full compiler optimization and DEBUG flag turned off
$ make BUILD=release
# flash DEBUG program to nRF52832 DK
$ make flash
# flash release program
$ make BUILD=release flash
# flash softdevice to nRF52832 DK
$ make flash_softdevice
# erase program
$ make erase
# delete build output directory
$ make clean
```

SoftDevices are precompiled binaries in the form of hex files that contain the code that drive the BLE and/or ANT wireless protocol on the SoC. They are found in the SDK directory `${nRF5_SDK17}/components/softdevice/`. This template uses [S132](https://infocenter.nordicsemi.com/topic/sds_s132/SDS/s1xx/s130.html). [More info](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_gsg_ses%2FUG%2Fgsg%2Fsoftdevices.html) on SoftDevices and their compatibility with this and other nRF5 chips.
## Debug

Connect your nRF52832 DK over USB, set your breakpoints and hit F5.

Optionally use [Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)

## Different nRF52 DK
To get this template to work for other nRF52 DKs you will have to manually replace all references to nRF52832. Including the linker files, Makefile, startup files, svd file, c_cpp_properties.json, and launch.json. The softdevice being flashed should also be updated to one that is compatible with your SoC.
