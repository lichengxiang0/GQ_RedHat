#include <stdio.h>

void main()
{
	FILE *fp;
	char *c_buf = "1234567890";	

	fp = fopen("/home/hello3.c","r+");
		
	fwrite(c_buf,5,1,fp);

	fclose(fp);	
}
