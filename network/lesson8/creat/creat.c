/***************************************
*文件名：creat.c
*创建时间：2017-5-26
*创建人：李呈祥
*文件说明：练习creat函数的用法
**********************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
	int fd;

	fd = creat( "/home/hello3.c",0621 );

	if ( fd < 0 )
		printf( "creat file fail!\n" );
}

