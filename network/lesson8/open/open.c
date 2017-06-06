/*******************************************************
*文件名：open.c
*创建时间：2017-5-26
*创建人：李呈祥
*文件说明：练习linux中的open函数
*********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/**********************************************
*这个是打开成功的例子
*************************************************/
void main()
{
	int fd;

	fd = open( "/home/hello.c",O_RDWR );

	if ( fd < 0 )
	{
		printf( "open file fail!\n" );
	}
	close(fd);
}


#if 0
/**********************
*变形
*
************************/
void main()
{
	int fd;

	fd = open( "/home/hello1.c",O_RDWR|O_CREAT,0755 );

	if ( fd < 0 )
	{
		printf( "open file fail!\n" );
	}

}
#endif