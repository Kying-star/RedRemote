# 感谢大佬

# VSCode-C51

VSCode Keil C51 工程模板
![VSCode-C51](https://s2.ax1x.com/2020/01/30/1lLvTg.png)

[视频教程](https://www.bilibili.com/video/BV1DA411v7Cv/)

## VSCode 插件

感谢[MoonAndHaze](https://github.com/MoonAndHaze)使用本模版开发了一个 VSCode 插件，很大程度上降低了本模版的使用难度。
[插件项目地址](https://github.com/MoonAndHaze/C51ProjectGenerator)

## 版本更新

- 已修复文件路径带空格报错问题
- 已修复路径参数带有引号的 bug

## 文件夹说明

- src\ 存放代码文件
- output\ 编译过程生成的文件
- environment\ 51 启动文件和 LIB 静态连编文件

## 修改说明

### 1、修改 c_cpp_properties.json

```json
  "includePath": [
  "${workspaceFolder}/**",
  "‪D:/Program Files/Keil5/C51/INC/**",
],
```

将 includePath 中的 Keil 的路径修改为你自己的

### 2、修改 tasks.json

```json
  "args": [
    "${workspaceFolder}",
    "${workspaceFolder}\\src",
    "${workspaceFolder}\\environment",
    "main"
],
```

主要修改第四个参数"main"，这个相当于 Keil 中的工程名

### 3、修改 compile.bat

```bash
@echo off
set KEIL_BIN_FOLDER=D:\Program Files\Keil5\C51\BIN
```

将 KEIL_BIN_FOLDER 修改为你的 C51\BIN 的地址

## 注意事项

所有的代码文件必须放到 src 根目录下面，
编译时，点击终端-运行生成任务
