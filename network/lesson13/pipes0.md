###Welcome to use MarkDown

#无名管道通讯
 
##1. 通讯目的  
	1. 数据传输  
	2. 资源共享  
	3. 通知事件  
	4. 进程控制  
 
##2. Linux进程间通讯  
	1. 什么叫IPC？  
	答：interprocess communication  
	   linux进程间通讯的主要方式有：  
	   		1. 无名管道（pipe）  
	   		2. 无名管道(FIFO)  
	   		3. 信号(signal)  
	   		4. 消息队列  
	   		5. 共享内存  
	   		6. 信号量  
	   		7. 套接字（socket）
	   		
	2. 由三部分发展而来？   
	答：
		- UNIX进程间通讯  
	   	- 基于System V进程间通讯
	   	- POSIX进程间通讯  
	   	
##3. 管道通讯  
	3.1 概念：一个进程在管道的尾部写入数据，另一个进程从管道的头部读出数据。管道包括无名管道和有名管道两种，前者只能用于父进程和子进程间的通讯，后者可用于运行于同一个系统中的任意两个进程间的通讯  

	3.2 管道通讯的特点  
		- 管道通讯是单向的，有固定的读端和写端  
		- 数据被进程从管道读出后，在管道中该数据集就不存在了。  
		- 当进程去读取空管道的时候，进程会阻塞  
		- 当进程往满管道写入数据时，进程会阻塞  
		- 管道容量为64KB  

##4. 无名管道  
	在Linux中无名管道一旦创建，就如同操作文件。无名管道的读端相当于一个文件，写端也相当于一个文件  
	
	


```c
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



```
	

