# Dev-CppPro

[Chinese README](README_CN.md)
## Introduction

Dev-CppPro is a lightweight, modern IDE for C/C++ inspired by Dev-C++, a very popular IDE that has been out of maintenance for many years.Dev-CppPro is designed to provide beginners and algorithmic competitors with a more modern, beautiful, and efficient development environment.

### Features

- Modern. Comes with a substitutable new version of MinGW or LLVM/Clang toolset, supports the latest standards such as C++17/20/23; introduces the CMake build system to support more third-party libraries; supports Windows/Linux/MacOS multi-platform development.
- Elegant. Use Fluent-like UI design, support high resolution screen, support dark mode.
- Efficient. Built with Qt6, takes up less than 60MB of memory and starts up fast.

## Build from source

- Clone this repo;

```shell
git clone https://github.com/MoonBite666/Dev-CppPro.git
```

- Build with QtCreator, just open the CMakeLists.txt file in QtCreator and build it.

- Or, build with CMake. You need to install Qt(>= 5.15) and CMake. Please refer to the CMake parameters below:

```
-DCMAKE_PREFIX_PATH=C:\Qt\6.7.2\mingw_64
-DCMAKE_GENERATOR:STRING=Ninja
-DCMAKE_CXX_COMPILER:FILEPATH=C:/Qt/Tools/mingw1120_64/bin/g++.exe
-DCMAKE_CXX_FLAGS_INIT:STRING=-DQT_QML_DEBUG
```
- And build with the following parameters:
```
--target all --parallel
```

## To Do

- [ ] Complete Highlighting model for editor.
- [ ] Complete File Managing functions.
- [ ] Fill Action Buttons.

## Acknowledgement

- Thanks to [@Liniyous](https://github.com/Liniyous) for developing a FluentUI-style component library for QWidget, [ElaWidgetTools](https://github.com/Liniyous/ElaWidgetTools).