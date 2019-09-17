#pragma once
#ifndef __SCORE_H__
#define __SCORE_H__
#include <iostream>

typedef struct student
{
	char number[10];
	char name[10];
	float dailyscore;
	float finalscore;
	float experimentscore;
	float generalscore;
}SS;

SS* readdatafromfile(int *N);
void calcuscore(SS stu[], int N);
void sortscore(SS stu[], int N);
void printout(SS stu[], int N);

#endif