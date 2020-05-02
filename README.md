# nqdump
*A C++ tools to decrypt ncm,qmc0,qmc3,qmcflac to origin file*
*一个由C++编写的用于解密被网易云音乐或QQ音乐加密的文件的程序*
---
#####  This project depends on third-party libraries : Taglib
##### 本项目依赖第三方C++库：Taglib

** Instructions ** 
** 使用方法 **  

 ** On Linux ** 
```
##### 编译程序  
###### 在编译之前需要安装taglib库  
git clone https://github.com/crmmc/nqdump  
cd nqdump  
make  
make install  
##### 编译完成   
nqdump <input_file1> <input_file2> <input_file3> <...>   
###### 您可以使用 nqdump /home/crmmc/music/* 来转换路径 /home/crmmc/music/* 下所有可转换的文件,输出文件路径与输入文件路径相同   
```
---

** Porject Used code from other github projects **  
** 本项目使用了来自其他Github项目的部分代码 **  
https://github.com/MegrezZhu/qmcdump  
https://github.com/anonymous5l/ncmdump  

---

CRMMC ---- KGDsave Software Studio 