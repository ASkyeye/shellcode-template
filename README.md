# About

A generic win32-shellcode template using cmake wrapped around LLVM-MINGW for production purposes. Intended to replace and bridge the gaps between MSVC/VS & GNU/Make through clang and cmake. Existing cmake-based templates are either overly convuluted or are still heavily reliant on GNU make which I consider a limitation.

Template is known to function well on Linux, however, should work with the proper compiler, cmake, and Python version Windows as well as its intended to. At this time, I have not tested it, but will in the near future to ensure it does. Supports x86_64 and x86 targets respectively.

An example usage is given below on building the project.

![Example Usage](shellcode-template.gif)
