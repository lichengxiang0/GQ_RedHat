#include <stdio.h>

void myprintf(long res)
{
	printf( " result=%d\n ",res );
}

void main()
{
	int i;
	long result = 0;
	for(i=0;i<=100;i++)
	{
		result += 1;
	}
	myprintf(result);
}
