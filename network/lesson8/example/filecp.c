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
	
	/* 1.打开源文件 */
	fd_s = open(argv[1],O_RDONLY);
	
	/* 2.打开目标文件 */
	fd_t = open(argv[2],O_RDWR|O_CREAT,0666);
	
	/* 3.读取源文件数据 */
	while( ( count = read(fd_s,buf,512) ) > 0 )
	{
		/* 4.将读取的源文件数据写入目标文件 */
		write(fd_t,buf,count);
	}
	/* 关闭文件 */
	close( fd_s );
	close( fd_t );
}
