<img width="430" height="362" alt="image" src="https://github.com/user-attachments/assets/3e1bbfe1-07c9-423b-ac32-255254e6d126" />

# guesb
2010年写的逻辑猜数游戏

## Build
使用Visual Studio生成可执行文件。

打开Visual Studio installer
* 找到你当前用的vs版本 （例如VS2022） → 点 “修改”，
勾选 「使用 C++ 的桌面开发」，
然后在右侧 “可选组件”中勾选
C++ MFC for latest v143 build tools (x86 & x64)并安装组件（中文可能显示为“适用于v143生成工具的C++ MFC”）。

* 下载仓库代码，双击guesb.sln，用VS打开解决方案，然后在生成菜单中点击“生成解决方案”，会在release或Debug目录下生成exe可执行文件。

## 下载
已构建好的可执行文件发布在releases：
https://github.com/fatsnk/guesb/releases

## 玩法
Bulls and Cows（公牛和母牛），起源于19 世纪或更早的智力游戏。

​在这个游戏中，计算机随机生成 4 个互不相同的数字，玩家进行猜测，系统根据猜测给出提示（xA yB）。
* A表示位置与数字都对，B表示数字对位置不对。例如1A2B 表示猜对3个数，其中一个数位置对，另外2个位置不对。

可通过数字小键盘和Enter键控制游戏。
