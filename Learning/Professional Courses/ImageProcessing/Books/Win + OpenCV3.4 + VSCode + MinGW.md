# Win + OpenCV3.4 + VSCode + MinGW 

## 一、安装MinGW

1.1 http://mingw-w64.org 下载mingw-w64-install.exe

1.2参数：

- (版本)`Version`
- (架构)`Architecture` 32位cpu 选择 i686，64位cpu 选择 x86_64
- (线程模式)`Threads` 开发 Windows 程序，需要选择 win32 ; 开发 Linux、Unix、Mac OS 等其他操作系统下的程序，需要选择 posix 。
- (异常处理机制)`Exception`有三种，根据机器情况进行选择
  - SJLJ (setjmp/longjmp) 兼容性好，32位或64位架构都可以使用，但速度慢
  - DWARF (DW2, dwarf-2) 速度比SJLJ快，但只能用于32位架构，且有bug，尽量不用
  - SEH (zero overhead exception) 速度很快，但只能用于64位架构
    (编译版本)Build revision 选择最高的

1.3 加入环境变量

## 二、安装cmake

CMake下载地址：

　　　　**https://cmake.org/download/**

　　要选择二进制文件，即**Binary distributions**栏目。下载完后解压到自选路径。找到如下文件夹：![img](https://i.loli.net/2021/09/07/eVly9kSHg2jADCY.png)

添加路径到环境变量

## 三、生成Make Files

3.1 要先在**C:\Windows\System32\drivers\etc\hosts**文件最后追加,因为**cmake-gui**会下载一些文件，这些文件都在**raw.githubusercontent.com**上，如果不修改一下hosts，许多文件很可能会下载失败。

```json
# GitHub Start
52.74.223.119 github.com
192.30.253.119 gist.github.com
54.169.195.247 api.github.com
185.199.111.153 assets-cdn.github.com
151.101.76.133 raw.githubusercontent.com
151.101.108.133 user-images.githubusercontent.com
151.101.76.133 gist.githubusercontent.com
151.101.76.133 cloud.githubusercontent.com
151.101.76.133 camo.githubusercontent.com
151.101.76.133 avatars0.githubusercontent.com
151.101.76.133 avatars1.githubusercontent.com
151.101.76.133 avatars2.githubusercontent.com
151.101.76.133 avatars3.githubusercontent.com
151.101.76.133 avatars4.githubusercontent.com
151.101.76.133 avatars5.githubusercontent.com
151.101.76.133 avatars6.githubusercontent.com
151.101.76.133 avatars7.githubusercontent.com
151.101.76.133 avatars8.githubusercontent.com
# GitHub End
```

3.2 打开cmake-gui，选择源文件路径和保存路径 ==>  Configue :选择MinGW Makefiles 和Specify native compilers   ==>  Next  ==>选择gcc和g++路径 ==>Finish

​	执行过程中消息框会出现一堆红色信息，最后显示Configure done，是正常的。如果执行时中断，则存在其他问题。在执行完后，勾选**BUILD_opencv_world**，**WITH_OPENGL**,ENABLE_CXX11和**BUILD_EXAMPLES**，不勾选**WITH_IPP、WITH_MSMF**和**ENABLE_PRECOMPILED_HEADERS**（如果有的话），**CPU_DISPATCH**选空。如果要编译opencv_contrib，则需要在**OPENCV_EXTRA_MODULES_PATH** 把路径选择为解压的opencv_contrib文件中的“modules”文件夹。

3.3 再次点击**Configure，**这次执行完后仍有错误如下：

　　[![img](https://i.loli.net/2021/09/07/Pps4W9n5CIxdMRA.png)](https://img2018.cnblogs.com/common/1547375/202002/1547375-20200217163938233-454035303.png)

　　也就是说前面虽然修改了hosts，但是有些文件仍然没有成功下载，解决的方法就是手动下载它们。可以用浏览器访问下载链接，或者使用迅雷等下载器进行下载。CMakeDownloadLog.txt文件中列出了所有丢失文件的下载链接，比如：

　　　　[**https://raw.githubusercontent.com/opencv/opencv_3rdparty/759a23e24ab787a0979f8a93103dcc3105ec10c1/ffmpeg/opencv_ffmpeg.dll**](https://raw.githubusercontent.com/opencv/opencv_3rdparty/759a23e24ab787a0979f8a93103dcc3105ec10c1/ffmpeg/opencv_ffmpeg.dll)

　　一个个访问这些链接，下载后放到OpenCV源文件里.cache的相应子文件夹中替代原缓存文件（下载的文件重命名为相应地缓存文件名并删除原缓存文件）。这样从头到尾下载CMakeDownloadLog.txt中列出的所有丢失文件，之后，再次**Configure**，理论上不会出现红色的错误消息了。然后点击**Generate**，正常的话会显示非红色的消息Generate Done**。**

https://greasyfork.org/zh-CN/scripts/412245-github-%E5%A2%9E%E5%BC%BA-%E9%AB%98%E9%80%9F%E4%B8%8B%E8%BD%BD 下载说明

## 编译ＯｐｅｎＣＶ

CMD到MakeFiles所在文件夹，执行**minGW32-make**命令，或者使用多线程**minGW32-make -j 4**命令;完成后，输入minGW32-make install 来装载

如果编译错误，根据错误信息修改文件内容（一般加宏定义就好了）

配置环境变量\bin	（D:\opencv\build\x64\MinGW64\install\x64\mingw\bin）

## 配置VSC

ｌａｕｎｃｈ．ｊｓｏｎ

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "opencv3.4.2 debuge",
            "type": "cppdbg",
            "request": "launch",
/*
            "program": "${workspaceFolder}/${fileBasenameNoExtension}.o",
*/
            "program": "${workspaceFolder}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "F:/MinGW/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": false
                }
            ],
            "preLaunchTask": "opencv compile task"
        }
    ]
}
```

c_cpp_properties.json

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "D:\\ENV\\MinGW64\\mingw64\\x86_64-w64-mingw32\\include",//C++标准库
                "D:/opencv/build/include",//这里引入opencv源文件路径,下面两个地址都是
                "${workspaceFolder}/**",
//"F:/opencv/opencv3.4.2/build/x64/mingw/install/include",
                "D:/opencv/build/include/opencv",
                "D:/opencv/build/include/opencv2"
//"D:/MinGW64/mingw64/x86_64-w64-mingw32/include/c++/",
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:\\MinGW\\mingw64\\bin\\gcc.exe",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}
```

task.json

```json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
           {
            "label": "opencv3.4.5 compile task",
            "type": "shell",
            "command": "g++",	
// "command": "D:\\MinGW64\\mingw64\\bin\\g++.exe",
            "args": [     "-g",  "${file}",  "-o",  "${file}.o",//这里添加动态链接库
//  "${fileBasenameNoExtension}.o",  
//"${workspaceFolder}\\${fileBasenameNoExtension}.exe",
                        "-I","D:/opencv/build/include",
//"D:/opencv3.4.5/opencv/build/x64/buildByMinGW/install/include",
                        "-I","D:/opencv/build/include/opencv",
                        "-I","D:/opencv/build/include/opencv2",
                        "-L", "D:/opencv/build/x64/mingw/lib",
                        "-l", "libopencv_world341"//一定要加
                ],

            "options": {
                "cwd": "D:\\MinGW64\\mingw64\\bin"
            },
            "problemMatcher": {    
                "owner": "cpp",      
                "fileLocation": [      
                    "relative",      
                    "${workspaceRoot}"      
//          "${workspaceFolder}"
                ],      
                "pattern": {      
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",      
                    "file": 1,      
                    "line": 2,      
                    "column": 3,      
                    "severity": 4,      
                    "message": 5     
/*
"regexp": "^([^\\\\s].*)\\\\((\\\\d+,\\\\d+)\\\\):\\\\s*(.*)$",
              "file": 1,
              "location": 2,
              "message": 3
*/ 
                }      
            } 
  "group": {
      "kind": "build",
      "isDefault": true
  }
        }


    ]
}
```



## 编译

```c++
g++ -o test test.cpp -I/usr/local/include -I/usr/local/include/opencv -I/usr/local/include/opencv2 -L /usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lpthread

参数解释:

    gcc -i 参数说明:包含头文件 -include和-I参数  

    gcc -l 参数说明: libopencv_core330  完整dll文件名,上面args载入的就是D:/opencv/build/x64/mingw/lib/libopencv_core330.dll.a
```

