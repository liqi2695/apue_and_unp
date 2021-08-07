# shell工具



## cut  先切割，再输出第几列；通常与grep连用确定日志

```
cut [ ] filename
```

参数：

* -d 按什么类型切割
* -f切割第几列



利用grep和cut来找自己想要的文件，比如：

```
//输入ifconfig ，假设输出以下内容
inet_addr:192.168.43.37 Boast:0.0.0.0
app:fjdsufa ccc:r24r32
cklp:fsdaf dfsa:fsdfsf
```

加入要从上述文件中找到192的IP地址并输出，那么可以通过以下命令

```bash
ifconfig | grep "inet_addr" | cut -d : if 1
```







## sed "流式"处理

一次处理一行，每次将每行都存入缓冲区，然后用sed处理缓冲区内容，处理完成后输送给屏幕。接着处理下一行.......    **文件内容不改变**

基本用法:

```bash
sed [ ] 'command' filename	

#例子
sed "2a mei nv" sed.txt
#将mei nv插入文件sen.txt的第二行后面的（注意，只是在显示的多了mei nv ，原文件并不改变）

sed "/wo/d" sed.txt
#删除sed.txt中包含wo的行，并输出在屏幕 （原文件不变）

sed "s/wo/ni" sed.txt
#将sed.txt中的wo换成ni并且输出（原不变）

sed -e "2d" -e "s/wo/ni" sed.txt
#执行多个指令的时候加 -e
```

sed的具体参数：https://www.cnblogs.com/ggjucheng/archive/2013/01/13/2856901.html





## awk 文本编辑

将文件逐行读入，以空格为分割进行切片，再对切片后的部分进行分析处理

格式：https://www.jianshu.com/p/cae3cccd2ee6

```
awk [ ] '匹配的内容{执行的操作}'
```



## sort 排序

格式：

```
sort(选项)(参数)
```

参数：

* -n 按照数值大小排序
* -r 相反的顺序排序
* -t 排序时的分隔字符
* -k 按照那一列为标准排序（一般配合-t分割完使用）

假设有文件:

```
//sort.txt
dd:60:40
bb:30:23
aa:150:45
mm:100:23
```

```bash
sort -t : -nrk 3 sort.txt
#用:分割后按照第三列数值大小 从大到小排序
```

