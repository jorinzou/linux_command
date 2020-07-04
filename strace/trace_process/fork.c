#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//子进程直接退出,变成僵尸进程
void fork_child(void)
{
	while(1){
		sleep(1);
		exit(100);
	}
}

int main(void)
{
	while(1){
		sleep(1);
		pid_t pid = fork();
		if(pid == 0){
			fork_child();
		}
	}
	return 0;
}
