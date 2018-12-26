
---
2018-12-26

项目初始化，将Robot-Controller中的iec-runtime运行系统内容迁出，删除与IO，伺服和RC交互部分，剥离出单纯的虚拟机任务为完成单元函数等内容做铺垫。
GLOBAL变量来自于PLC程序main函数中定义的所有变量，按照INPUT，IN_OUT，OUTPUT，LOCAL变量顺序输入，在经过虚拟机单元模拟任务后将这些值输出至return_global_info.txt文件中。

使用说明：
程序目录中添加经过iec-compiler和translator编译转换后的PLC二进制目标文件exec.obj，程序运行并在对应目录创建`plc_load_info.txt`，`plcloginfo.txt`和`return_global_info.txt`三个文件，前两个在iec-runtime中也附带，作用分别为加载目标文件时的信息，运行目标文件时的信息。第三个文件为经过运行后程序的全局变量即main函数中定义的所有变量，供QT程序读取使用。