#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm *tm;
	
	ctime = time(NULL);  /* 获取日历时间 */
	
	tm = gmtime(&ctime);  /* 将日历时间转化为标准时间 */
	
	printf("hour is %d ,min is %d\n",tm->tm_hour,tm->tm_min);
	
	return 0;
}