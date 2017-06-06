#include <stdio.h>

void main()
{
	FILE *fp;
	char c_buf[15];
	
	fp = fopen("/home/hello3.c","r+");

	fread(c_buf,1,10,fp);
	c_buf[10] = '\0';
	printf( "now we read is %s\n",c_buf );
		
	fclose(fp);	
}
