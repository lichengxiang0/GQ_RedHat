#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	
 	pid = fork();	
 	
 	if ( pid > 0 )  //父进程
 	{
		wait(NULL);
 		printf("This is father process\n");
		exit(0);	
 	}
 	else  //子进程
 	{
		execl( "/bin/ls","ls","/home",NULL );
 		printf(" This is child process\n ");
 		exit(0);
 	}

	printf("pid is %d\n",pid);

	exit(0);

}

