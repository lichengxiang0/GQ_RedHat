#include <stdio.h>

void main()
{
	FILE *fp;
	
	fp = fopen("/home/hello3.c","w+");
		
	fclose(fp);	
}
