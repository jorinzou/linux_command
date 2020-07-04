#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#include "socket_client.h"
#include "cmd.h"

int read_config_file(void)
{
    char config_path[1024] = {};
    getcwd(config_path,sizeof(config_path)-1);
    strcat(config_path,"/config");
    DEBUG_INFO("%s",config_path);
    FILE *config_file = fopen(config_path,"r");
    if (NULL == config_file){
        DEBUG_INFO("fopen config failed");
        return -1;
    }

    char *s = fgets(ip_str,sizeof(ip_str),config_file);
    DEBUG_INFO("ip_str=%s",ip_str);
    s = strtok(ip_str,"=");
    DEBUG_INFO("s=%s,ip_str=%s",s,ip_str);    
    fclose(config_file);
    return 0;
}

int main_loop(void)
{
    pthread_t t1;
    pthread_create(&t1,NULL,client_do_pthread,NULL);

    pthread_t t2;
    pthread_create(&t2,NULL,cmd_do_pthread,NULL);

    pthread_t t3;
    pthread_create(&t2,NULL,test_send_thread,NULL);

    while(1){
        sleep(100);
    }
	return 0;
}

int main(void)
{
//#define DEFINE_DAEMON

    read_config_file();
#ifdef DEFINE_DAEMON
     pid_t pid = fork();
    switch(pid){
        case 0://成为守护进程
            main_loop();
        break;

        default:
            exit(1);
        break;
    }
#else
    main_loop();
#endif
    return 0;
}
