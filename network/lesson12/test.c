#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	int count = 0;
	
//	pid = fork();   //vfork();
	pid = vfork();
	count++;
	printf("count = %d\n",count);

	exit(0);
}
