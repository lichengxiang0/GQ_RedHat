#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm * localtm;
	
	ctime = time(NULL);  /* 获取日历时间 */
	
	localtm = localtime(&ctime );  /* 将日历时间转化为本地时间 */
	
	printf("localtime hour is %d,min is %d\n",localtm->tm_hour,localtm->tm_min);
	
	return 0;	
}