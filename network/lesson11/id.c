#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t id = 0;
	id = getpid();	

	printf("process id is %d\n",id);	

	return 0;
}


