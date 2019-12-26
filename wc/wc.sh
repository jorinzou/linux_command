#/bin/sh

#c统计，以字节数来计算
function wc_c()
{
	wc -c a.txt
}

#w,以字符数来统计
function wc_m()
{
	wc -m a.txt
}

#l，统计有多少行
function wc_l()
{
	wc -l a.txt
}

#w，统计有多少个词（word）
function wc_w()
{
	wc -w a.txt
}

#L，统计字节数最长的行，按照字节数统计
function wc_L()
{
	wc -L a.txt
}

#wc统计行数，词数，字节数,文件名
function wc_all()
{
	wc a.txt
}

function main()
{
	wc_all;	
}

main;
