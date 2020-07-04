/*
*双重释放（double free）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p = NULL;

void fun1(void)
{
	free(p);
}

void fun2(void)
{
	free(p);
}

int main(void)
{
	p = malloc(100);
	fun1();
	fun2();
	return 0;
}