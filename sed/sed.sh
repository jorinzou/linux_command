#!/bin/bash

#替换操作,替换文本中的字符,book替换成books，原文件不会被修改
function sed_s()
{
	sed 's/book/books/' ./file.txt 
}

#替换第一行为匹配的行,原文件会被修改
function sed_s_i()
{
	sed -i 's/TEST/test/' ./file.txt
}

#替换所有的匹配项
function sed_s_i_g()
{
	sed -i 's/test/apple/g' ./file.txt
}

#删除
function sed_d()
{
	#删除空白行,加上-i会修改原文件
	#sed -i '/^$/d' ./file.txt

	#删除第2行
	#sed -i '2d' ./file.txt
	
	#删除第2行，到文件末尾所有行
	#sed -i '2,$d' ./file.txt

	#删除文件最后一行
	#sed -i '$d' ./file.txt

	#删除开头是"2"的行
	sed -i '/^2/d' ./file.txt
}

#&
function sed_m()
{
	#将172.16.8.1替换成172.16.8.1:9090
	sed -i 's/^172.16.8.1/&:9090/' ./file.txt
}

#e，多点编辑
function sed_e()
{
	#删除第1到第5行，并把“1”替换成"sugar"
	sed -i -e '1,5d' -e 's/1/sugar/g' ./file.txt
}

#w命令
function sed_w()
{
	#读取a文件中所有关于“test”的行，并写入b.txt
	sed -n '/test/w ./b.txt' ./a.txt
}

#a 追加到后面
function sed_a()
{
	#把this is a test line 追加到 test行的后面
	#sed -i '/^test/a\this is a test line' ./a.txt

	#在第2行之后插入"this is a test line"
	sed -i '2a\this is a test line' ./b.txt
}

#追加到前面
function sed_i()
{
	#将this is a test line 插入到test的行前面 
	#sed -i '/^test/i\this is a test line' ./a.txt

	#在第5行前面插入this is a test line
	sed -i '5i\this is a test line' ./a.txt
}

#y命令
function sed_y()
{
	#第1到第10行的test转换成TEST
	sed -i '1,$y/test/TEST/' a.txt
}

#q命令
function sed_q()
{
	#打印完第2行退出sed命令
	sed '2q' ./a.txt
}

function main()
{
	sed_q;
}

main;
