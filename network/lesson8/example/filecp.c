#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char **argv)
{
	int fd_s;
	int fd_t;
	char buf[512];
	int count = 0;
	
	/* 1.��Դ�ļ� */
	fd_s = open(argv[1],O_RDONLY);
	
	/* 2.��Ŀ���ļ� */
	fd_t = open(argv[2],O_RDWR|O_CREAT,0666);
	
	/* 3.��ȡԴ�ļ����� */
	while( ( count = read(fd_s,buf,512) ) > 0 )
	{
		/* 4.����ȡ��Դ�ļ�����д��Ŀ���ļ� */
		write(fd_t,buf,count);
	}
	/* �ر��ļ� */
	close( fd_s );
	close( fd_t );
}
