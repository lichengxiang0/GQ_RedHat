/**************************
*��������piperw.c
*�������ܣ����������ܵ������ڸ��Ӽ�ͨѶ
*����ʱ�䣺20170608
*�����ˣ������
******************************/
/* 1.�����ӽ���  2.�����ܵ� 3.ͨѶ */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int pipefd[2];
	char c_buf[10];
	
	pipe(pipefd);   /* �����ܵ� */
	
	pid = fork();   /* �����ӽ��� */

	if ( pid > 0 )
	{
		/*������д������*/
		write(pipefd[1],"hello",6);
		wait();
		close(pipefd[1]);
		
		exit(0);	
	}
	
	if ( pid == 0 )
	{
		/* �ӽ��� */
		read(pipefd[0],c_buf,6);
		printf( "child read is %s\n",c_buf );
		close(pipefd[0]);	
		exit(0);
	}
	
	return 0;	
}