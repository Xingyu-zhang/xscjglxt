#include <iostream>
#include <windows.h>
#include "score.h"

int main()
{
	
	getchar();

	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("******************************\n\n");

	int N = 0;        
	SS  *pstu = NULL;   

	pstu = readdatafromfile(&N);
	calcuscore(pstu, N);
	sortscore(pstu, N);
	printout(pstu, N);
	free(pstu);

	getchar();
	return 0;
}