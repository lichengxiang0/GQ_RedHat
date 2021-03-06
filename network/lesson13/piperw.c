/**************************
*函数名：piperw.c
*函数功能：创建无名管道，用于父子间通讯
*创建时间：20170608
*创建人：李呈祥
******************************/
/* 1.创建子进程  2.创建管道 3.通讯 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int pipefd[2];
	char c_buf[10];
	
	pipe(pipefd);   /* 创建管道 */
	
	pid = fork();   /* 创建子进程 */

	if ( pid > 0 )
	{
		/*父进程写入数据*/
		write(pipefd[1],"hello",6);
		wait();
		close(pipefd[1]);
		
		exit(0);	
	}
	
	if ( pid == 0 )
	{
		/* 子进程 */
		read(pipefd[0],c_buf,6);
		printf( "child read is %s\n",c_buf );
		close(pipefd[0]);	
		exit(0);
	}
	
	return 0;	
}
