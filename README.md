Battle of the Compilers: A Survey of C++ Compilers
------------

### Authors

- Rabia Akhtar
- Emily Jin
- Chris Terrazas

Battle of the Compilers is written in C++ and surveys four top C++ compilers: G++, Clang, Intel C++, Microsoft C++. We measure three aspects of the compilers performance: `compile time`, `run time`, and `executable file size`. To be able to understand this tutorial, first read the Design Document to understand the previous research, design decisions, and structure of the test suites. Then read the [documentation](Documentation/) of all of the files in our test suite in the documentation folder.

### Requirements

  - [G++ Compiler](https://gcc.gnu.org/)<br/>
  - [Clang Compiler](https://clang.llvm.org/get_started.html)
  - [Intel C++ Compiler](https://software.intel.com/en-us/c-compilers)
  - [Microsoft C++ Compiler](https://visualstudio.microsoft.com/vs/features/cplusplus/)


All source code was tested and compiled with `C++17`.
The testing system currently utilizes `Makefiles` in each target directory along with `Shell` scripts.


### Documentation

There is substantial documentation for each of the data structures and algorithms
tested. Within these documents you can view the numerous functions utilized
along with their specifics.

You can find the documentation [here](Documentation/).

### Data

We have collected various amounts of data utilizing the [Intel SDE](https://software.intel.com/en-us/articles/intel-software-development-emulator) along with our own analysis via the test suites. All data is stored in the `IntelSDE_Data` directory.

You can find all the data [here](IntelSDE_Data/).

### Running Test Suites

There are two options to run the test suites.<br/>
- Run individual test suites within a specific directory:<br/>
`$ make` for compilation. <br/>
`$ make suites` for execution of program. <br/>
- Run all test suites from top level of project directory:<br/>
`$ sh RunTestSuites.sh` for compilation and execution of all test suites. <br/>
- No test suites were written for the Microsoft compiler. Those tests must be compiled and executed manually in the Developer Command Prompt for VS with the following commands:<br/>
`cl /std:c++17 /O2 /d2cgsummary /FAs /Fa<assemblyFile> <sourceFile>` for compilation. <br/>
`<program_name> 2>buf.txt` for exectution of program. <br/>

### Running Intel SDE
There are two main tools we use in the Intel SDE. We use the [Histogram Tool](https://software.intel.com/en-us/articles/intel-software-development-emulator#inpage-nav-1-4) and the [XED Disassembler](https://software.intel.com/en-us/articles/intel-software-development-emulator#inpage-nav-1-9). Here is an example of how to to generate the necessary files for the `list` data structure into the `IntelSDE_Data` directory on MacOS:
```
### For the Histogram File ###
 $ ./sde -mix -omix ~/cpp-class-project/IntelSDE_Data/DataStructures/list/g++list/sde-mix-out-g++_list.txt -iform -- ~/cpp-class-project/DataStructures/list/list_gcc
 $ ./sde -mix -omix ~/cpp-class-project/IntelSDE_Data/DataStructures/list/clangg++list/sde-mix-out-clangg++_list.txt -iform -- ~/cpp-class-project/DataStructures/list/list_clang
 $ ./sde -mix -omix ~/cpp-class-project/IntelSDE_Data/DataStructures/list/icpclist/sde-mix-out-icpc-list.txt -iform -- ~/cpp-class-project/DataStructures/list/list_intel

### For the XED Disassembler File ###
 $ ./xed -i ~/cpp-class-project/DataStructures/list/list_gcc > ~/cpp-class-project/IntelSDE_Data/DataStructures/list/g++list/g++dis-list.txt
 $ ./xed -i ~/cpp-class-project/DataStructures/list/list_clang > ~/cpp-class-project/IntelSDE_Data/DataStructures/list/clang++list/clang++dis-list.txt
 $ ./xed -i ~/cpp-class-project/DataStructures/list/list_intel > ~/cpp-class-project/IntelSDE_Data/DataStructures/list/icpclist/icpcdis-list.txt
```

On Windows 10:
```
### For the Histogram File ###
sde -mix -omix "C:\Users\<username>\cpp-class-project\IntelSDE_Data\DataStructures\list\msvc\sde-list-ms.txt" -iform -- "C:\Users\<username>\cpp-class-project\DataStructures\list\list.exe"

### For the XED Disassembler File ###
xed -i "C:\Users\<username>\cpp-class-project\DataStructures\list\list.exe" > "C:\Users\<username>\cpp-class-project\IntelSDE_Data\DataStructures\list\msvc\xed-list-ms.txt"
```
