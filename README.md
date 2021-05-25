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
Depending on OS used to build/develop you must modify either Makefile.posix (Linux/macOS) or Makefile.windows.

Contents of my Makefile.posix on my macOS.
```makefile
GNU_INSTALL_ROOT ?= /Applications/ARM/bin/
GNU_VERSION ?= 10.2.1
GNU_PREFIX ?= arm-none-eabi
```

## Build and Flash
To build source and flash the MCU you can use the VS Code tasks. Alternatively, run make from the command line.

```bash
# see make commands available
$ make help
# generate buld output
$ make
# flash program to nRF52832 DK
$ make flash
# erase program
$ make erase
# delete build output directory
$ make clean
```
## Debug

Connect your NRF52 DK over USB, set your breakpoints and hit F5.
