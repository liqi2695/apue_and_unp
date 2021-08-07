# shell的基本知识

运行脚本:

```
chmod +x ./test.sh      //给执行程序权限
./test.sh      //执行程序
```

定义变量以及使用变量：

```
your_name="liqi"
echo ${your_name}



#!/bin/bash
my_name = "liqi"
readonly my_name    //readonly  只读变量
my_name="wwww"   //此程序运行会出错


unset my_name    //删除变量

```

字符串:单引号和双引号。单引号对于引号内容无论是什么都会**原样**输出，双引号允许引号内容有**转义以及变量**的部分。

计算字符串长度   提取字符串：

```bash
string="test"
echo ${#string} //输出4
echo ${string}  //输出test

str="liqi is a nice boy"
echo ${str:1:4}  //输出 iqi     (空格也算)

echo `expr index "$string" io`  //查找i或o字母出现的位置，谁先出现就计算哪个.输出4 
//注意这里是反引号
```

shell数组：

```
array_name=(v1 v2 v3)    #中间用空格隔开

echo ${array_name[@]}   #用@获取数组中所有元素
```







shell传递参数：脚本内获取参数的方式就是通过**$n** ，$0表示执行的文件名字 $1传递的第一个参数 $2传递的第二个参数.......

![image-20210806100001067](C:\Users\liqi\AppData\Roaming\Typora\typora-user-images\image-20210806100001067.png)







shell的运算：

expr是表达式计算的工具，能够完成表达式的求值操作 **使用的是反引号` 而不是单引号‘ **

```bash
#!/bin/bash

val=`expr 2 + 2`
echo "两数和 : $val"

:EOF
注意点1：表达式和运算符之间有空格，2+2是错的，必须写成2 + 2
注意点2：完成的表达式要被` `包含
EOF
```



**各种运算符的手册** ：https://www.runoob.com/linux/linux-shell-basic-operators.html



shell的输入输出：

```
#!/bin/bash
read name            //read相当于cin
echo "$name it my baby"

echo -e "ok! \n"  //  \n表示换行
echo -e "ok! \c"  // \c表示不换行

echo "liqi is a handsome boy" > file.txt 
//将liqi is a handsome boy 写入文件file.txt中

```

printf：**%s %c %d %f **分别代表字符串，整型，字符，实数（以小数形式输出）

```
跟c语言的printf大同小异吧
```

for;while;until 的用法：https://www.runoob.com/linux/linux-shell-process-control.html





shell函数：跟c一样的啊； 注意函数传参数的时候是在函数体内部，通过**$n**的方式获取参数(从1开始)

函数返回值通过**$?**来获取

```
#!/bin/bash
add(){
	echo "第一个参数为 $1"
	echo "第二个参数为 $2" 
}
add   
```

**注意，$10并不能获取第十个参数，获取第十个参数需要${10}。对于n大于等于10，获取参数需要用${n}来。**







shell输入输出重定向：  > 新输入会覆盖原来内容；  >> 新输入将在最后一行插入





shell的文件包含：相当于c中引入.h文件，shell中可以通过以下方式引入：

```
. filename    #空格别忘了
or
source filename
```

