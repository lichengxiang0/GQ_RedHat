#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	pid_t pid;
	
 	pid = fork();	
 	
 	if ( pid > 0 )  //父进程
 	{
 		printf("This is father process\n");
 		exit(0);	
 	}
 	else  //子进程
 	{
 		printf(" This is child process\n ");
 		exit(0);
 	}

	printf("pid is %d\n",pid);

	exit(0);

}

