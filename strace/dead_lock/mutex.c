#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

int data = 0;

pthread_mutex_t mutex1;

/*初始化互斥锁*/
void InitMutex(void)
{
	pthread_mutex_init(&mutex1,NULL);   
}

/*销毁互斥锁*/
void DestoryMutex(void)
{
	pthread_mutex_destroy(&mutex1);
}

void* Thread3Task(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex1);
		printf("Thread3Task:data=%d\n",data);
		pthread_mutex_unlock(&mutex1);
	}
}

void* Thread2Task(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex1);
		printf("Thread2Task:data=%d\n",data);
		pthread_mutex_unlock(&mutex1);
	}
}

void* Thread1Task(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex1);
		getchar();/*模拟线程Thread1Task处理业务，一直不释放锁*/
		data++;
		pthread_mutex_unlock(&mutex1);
	}
}

int main(void)
{
	InitMutex();
	
	pthread_t t1;
	pthread_create(&t1,NULL,Thread1Task,NULL);
	pthread_setname_np(t1, "Thread1Task");
	sleep(2);
	
	pthread_t t2;
	pthread_create(&t2,NULL,Thread2Task,NULL);
	pthread_setname_np(t2, "Thread2Task");
	
	pthread_t t3;
	pthread_create(&t3,NULL,Thread3Task,NULL);
	pthread_setname_np(t3, "Thread3Task");
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	DEBUG_INFO("main thread exit");
	DestoryMutex();
	return 0;
}