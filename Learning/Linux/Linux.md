# Linux 学习手册

## 命令

### 1. tar

 i.  **作用**： tar命令是Unix/Linux系统中备份文件（**打包/解压**）的可靠方法，几乎可以工作于任何环境中，它的使用权限是所有用户。

ii.  **格式**：**tar [命令] [参数] 文件或目录** 

```shell
# 1. 将当前目录下的test文件夹打包为test.tgz
tar -czvf test.tgz tes; 

# 2.  将test.tgz解压到指定目录，如解压到/usr. 其中C必须大写
tar -xzvf test.tgz -C /usr；
```

iii. **命令**：（仅选一个）

- c: 建立压缩档案
- x：解压
- t：查看内容
- r：向压缩归档文件末尾追加文件
- u：更新原压缩包中的文件

iv. 参数：

- z：有gzip属性的
- j：有bz2属性的
- Z：有compress属性的
- v：显示所有过程
- O：将文件解开到标准输出

v. 特殊参数：

- f: 使用档案名字。**这是最后一个参数，后面只能接档案名。**

# 安装镜像源

url = https://blog.csdn.net/weixin_44144793/article/details/110174572	

参考：https://blog.csdn.net/Li060703/article/details/106075597

# 常用指令

#### 1. 查看系统版本 

uname -a



