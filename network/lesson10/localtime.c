#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm * localtm;
	
	ctime = time(NULL);  /* ��ȡ����ʱ�� */
	
	localtm = localtime(&ctime );  /* ������ʱ��ת��Ϊ����ʱ�� */
	
	printf("localtime hour is %d,min is %d\n",localtm->tm_hour,localtm->tm_min);
	
	return 0;	
}