#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "score.h"
using namespace std;

SS* readdatafromfile(int *N)
{
	cout <<"\n\n-----------第一步：从文件读取学生成绩信息----------\n"<<endl;
	SS *stu;
	int count = 0;
	int index = 0;
	FILE *fp = NULL;

	fp = fopen("data.txt", "r");
	if (fp!=NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		cout << "failed to open the info file" << endl;
		getchar();
	}
	cout << "学生的数目为：" << count << endl;
	
	stu = (SS*)malloc(count * sizeof(SS));
	for (int i = 0; i < count; i++)
	{
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyscore,&stu[index].experimentscore, &stu[index].finalscore);
		printf("* 学号：%s      姓名:%s      平时成绩：%4.2f分      实验成绩：%4.2f分      期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyscore,stu[index].experimentscore, stu[index].finalscore);
		index++;
	}

	fclose(fp);
	getchar();
	return stu;
}

void calcuscore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalscore = 0.2*stu[i].dailyscore+ 0.2*stu[i].experimentscore + 0.6*stu[i].finalscore;
		printf("* 学号：%s	姓名:%s		总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalscore);

	}

	getchar();
}

int cmpbigtosmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);

	if ((*aa).generalscore < (*bb).generalscore)  
		return 1;

	else if ((*aa).generalscore > (*bb).generalscore) 
		return -1;

	else
		return 0;

}

void sortscore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpbigtosmall);

}

void printout(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalscore);
	}

	getchar();
}