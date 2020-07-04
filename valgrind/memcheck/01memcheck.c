/*
*使用未初始化的内存
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[5];
	char str2[32];
	strcpy(str2,str);
	return 0;
}