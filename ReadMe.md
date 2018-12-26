
---
2018-12-26

项目初始化，将Robot-Controller中的iec-runtime运行系统内容迁出，删除与IO，伺服和RC交互部分，剥离出单纯的虚拟机任务为完成单元函数等内容做铺垫。
GLOBAL变量来自于PLC程序main函数中定义的所有变量，按照INPUT，IN_OUT，OUTPUT，LOCAL变量顺序输入，在经过虚拟机单元模拟任务后将这些值输出至return_global_info.txt文件中。