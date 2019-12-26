#!/bin/sh

#按照第1列的数字，升级排序
function sort_nk()
{
	sort -nk 1 -t: wc.txt
}

#按照第1列的数字，降序排序
function sort_nk_r()
{
	sort -nk 1 -r -t: wc.txt
}

function main()
{
	sort_nk_r;
}

main;
