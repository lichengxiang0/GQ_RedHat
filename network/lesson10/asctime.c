#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm * localtm;
	char *asctm;
	
	ctime = time(NULL);  /* 获取日历时间 */
	
	localtm = localtime(&ctime );  /* 将日历时间转化为本地时间 */
	
	asctm = asctime(localtm);  /* 将struct tm格式的时间转化为字符串 */
	
	//printf("localtime hour is %d,min is %d\n",localtm->tm_hour,localtm->tm_min);
	printf("asctime is %s\n",asctm);
	
	return 0;	
}