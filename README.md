# Imgpro

C++ 编写的图像处理工具

## 背景

为学习 C++ 使用而创建的 vscode 项目。

## 编译

```bash
mkdir -p build
# 如果是 Windows 平台则使用下面的 cmd 命令：
# md build

cd build
cmake ..
cmake --build .
# 编译完成后在 build 目录下可以看到可执行文件 imgpro
```

## 使用

目前具有的功能和对应的指令选项如下：

|指令选项|功能|
|:--:|:--:|
|`-s`|图像对称|

### 图像对称

将图像的某半部分翻转后覆盖到另一半部分上。

指令格式：`./imgpro -s [-LRTB] <img_path>`

#### *参数 1（可选）

控制生成模式，默认为 `-L`

|参数可选项|含义|
|:--:|:--:|
|`-L`|左->右|
|`-R`|右->左|
|`-T`|上->下|
|`-B`|下->上|

#### 参数 2

要处理的图像路径

## 示例运行

```bash
./imgpro -s -L ../data/rabbit.jpg
# 结果保存在与原图片同目录下的 result_rabbit.jpg
```

## 开发调试

配置 .vscode 目录下相关文件以进行开发调试。

可参考 [使用VSCode和CMake构建跨平台的C/C++开发环境](https://www.cnblogs.com/iwiniwin/p/13705456.html)。