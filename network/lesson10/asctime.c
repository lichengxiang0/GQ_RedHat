#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ctime;
	struct tm * localtm;
	char *asctm;
	
	ctime = time(NULL);  /* ��ȡ����ʱ�� */
	
	localtm = localtime(&ctime );  /* ������ʱ��ת��Ϊ����ʱ�� */
	
	asctm = asctime(localtm);  /* ��struct tm��ʽ��ʱ��ת��Ϊ�ַ��� */
	
	//printf("localtime hour is %d,min is %d\n",localtm->tm_hour,localtm->tm_min);
	printf("asctime is %s\n",asctm);
	
	return 0;	
}