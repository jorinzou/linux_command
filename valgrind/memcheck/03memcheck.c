/*
*内存越界
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *p = malloc(5);
	int i = 0;
	for(i; i <= 5; ++i){
		p[i] = i;
	}
	free(p);
	return 0;
}