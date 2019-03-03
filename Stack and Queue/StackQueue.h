#ifndef __STACKQUEUE_H
#define __STACKQUEUE_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct stack
{
	int *data;
	int top;
}Stack, *pStack;

typedef struct Que
{
	Stack sta;
	Stack stb;
}Que, *pQue;

#define SIZE 5


void Initque(pQue que);


#endif