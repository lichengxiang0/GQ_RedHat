#include <sys/time.h>
#include <stdio.h>

void fun(void)
{
	int i,j;
	int res;
	
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			res += j;
		
}

int main(void)
{
	int time;
	struct timeval tv1,tv2;
	
	gettimeofday(&tv1,NULL);
	
	fun();
	
	gettimeofday(&tv2,NULL);

	//printf("miaoshu is %d,weimiao is %d\n",tv.tv_sec,tv.tv_usec);
	printf( "miaoshu is %d,weimiao is %d\n",( tv2.tv_sec - tv1.tv_sec ),( tv2.tv_usec - tv1.tv_usec ) );
	return 0;	
}