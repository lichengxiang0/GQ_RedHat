#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm *tm;
	
	ctime = time(NULL);  /* ��ȡ����ʱ�� */
	
	tm = gmtime(&ctime);  /* ������ʱ��ת��Ϊ��׼ʱ�� */
	
	printf("hour is %d ,min is %d\n",tm->tm_hour,tm->tm_min);
	
	return 0;
}