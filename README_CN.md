# Dev-CppPro

## 项目介绍

Dev-CppPro 是一个为C/C++设计的轻量级现代IDE。它的灵感来源于Dev-C++ —— 一款非常受欢迎的IDE，但是它已经停止维护很多年了。Dev-CppPro 旨在为广大初学者和算法竞赛者提供一个更现代、更美观、更高效的开发环境。

### 特性

- 更现代。附带可更换的新版MinGW或LLVM/Clang工具集，支持C++17/20/23等最新标准；引入CMake构建系统，支持更多的第三方库；支持Windows/Linux/MacOS多平台开发。
- 更美观。使用类Fluent UI设计，支持高分屏，支持黑暗模式。
- 更高效。使用Qt6构建，占用内存小于60MB，启动速度快；

## 从源代码构建

- 拉取本仓库；

```shell
git clone https://github.com/MoonBite666/Dev-CppPro.git
```

- 使用QtCreator打开CMakeLists.txt文件并构建项目；

- 也可使用CMake构建项目，需要安装Qt(>=5.15)和CMake。 请参考下面的CMake参数：

```
-DCMAKE_PREFIX_PATH=C:\Qt\6.7.2\mingw_64
-DCMAKE_GENERATOR:STRING=Ninja
-DCMAKE_CXX_COMPILER:FILEPATH=C:/Qt/Tools/mingw1120_64/bin/g++.exe
-DCMAKE_CXX_FLAGS_INIT:STRING=-DQT_QML_DEBUG
```
- 构建参数：
```
--target all --parallel
```

## To Do

- [ ] 完成编辑器高亮Model。
- [ ] 完成文件管理相关方法。
- [ ] 添加更多动作按钮。

## 致谢

- 感谢[@Liniyous](https://github.com/Liniyous)开发的[ElaWidgetTools](https://github.com/Liniyous/ElaWidgetTools)，一套为QWidget设计的FluentUI风格组件库。