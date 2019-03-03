#ifndef __QUESTION_H
#define __QUESTION_H

#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


//顺序表
//#define LEN 10
//#define TRUE 1
//#define FALSE 0
//
//typedef struct
//{
//	int *elem;   
//	int length;  
//	int listsize; 
//	int *prior;
//}SqList;


//单链表
//typedef int ElemType;
//
//
//typedef struct Node
//{
//	ElemType data;
//	struct Node *next;
//}Node;
//
//
//typedef struct CycLinkQueue
//{
//	Node head;
//	Node *tail;
//	int count;
//}CycLinkQueue, *pCycLinkQueue;

/*
int MatchingBrackets(char *s);						//7,判断表达式括号是否匹配

int Compute(char *s, pStack stack);					//8,对逆波兰式（后缀表达式）进行求值


//9,假设以带头结点的循环链表表示队列，并且设一个指针指向队尾元素结点,编写相应的队列初始化、入队列和出队列的算法。
void InitLinkQueue(pCycLinkQueue list);

void PushLinkQueue(pCycLinkQueue list, ElemType *res);

void PopLinkQueue(pCycLinkQueue list, int pos);

void ShowList(pCycLinkQueue list);

//11、利用顺序表实现优先队列的插入和删除操作。
void InitSqList(SqList *list);

int PushSqList(SqList *list, int pos, int val,int pri);

int PopSqList(SqList *list);
*/


void InflxtoPrefix(pStack stack, char *s);				//14,编程实现将中缀表达式转成前缀表达式



//15、定义一个新的栈结构，在该结构中有一个获取当前栈内最小值Min的函数，
//要求在该栈中调用入栈Push，出栈Pop和获取最小值Min的时间复杂度都为O(1).
int Push(pStack stack, ElemType val);

int Pop(pStack stack, ElemType *res);

int GetMin(pStack stack);


#endif