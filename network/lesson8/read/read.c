/*******************************************************
*�ļ�����open.c
*����ʱ�䣺2017-5-26
*�����ˣ������
*�ļ�˵������ϰlinux�е�open����
*********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/**********************************************
*����Ǵ򿪳ɹ�������
*************************************************/
void main()
{
	int fd;
	char buf[10];

	fd = open( "/home/hello.c",O_RDWR );

	if ( fd < 0 )
	{
		printf( "open file fail!\n" );
	}

	read(fd,buf,5);
	buf[5] = '\0';
	printf("buf is %s\n",buf);

	close(fd);
}


#if 0
/**********************
*����
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