/***************************************
*�ļ�����creat.c
*����ʱ�䣺2017-5-26
*�����ˣ������
*�ļ�˵������ϰcreat�������÷�
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

