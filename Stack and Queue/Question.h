#ifndef __QUESTION_H
#define __QUESTION_H

#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


//˳���
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


//������
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
int MatchingBrackets(char *s);						//7,�жϱ��ʽ�����Ƿ�ƥ��

int Compute(char *s, pStack stack);					//8,���沨��ʽ����׺���ʽ��������ֵ


//9,�����Դ�ͷ����ѭ�������ʾ���У�������һ��ָ��ָ���βԪ�ؽ��,��д��Ӧ�Ķ��г�ʼ��������кͳ����е��㷨��
void InitLinkQueue(pCycLinkQueue list);

void PushLinkQueue(pCycLinkQueue list, ElemType *res);

void PopLinkQueue(pCycLinkQueue list, int pos);

void ShowList(pCycLinkQueue list);

//11������˳���ʵ�����ȶ��еĲ����ɾ��������
void InitSqList(SqList *list);

int PushSqList(SqList *list, int pos, int val,int pri);

int PopSqList(SqList *list);
*/


void InflxtoPrefix(pStack stack, char *s);				//14,���ʵ�ֽ���׺���ʽת��ǰ׺���ʽ



//15������һ���µ�ջ�ṹ���ڸýṹ����һ����ȡ��ǰջ����СֵMin�ĺ�����
//Ҫ���ڸ�ջ�е�����ջPush����ջPop�ͻ�ȡ��СֵMin��ʱ�临�Ӷȶ�ΪO(1).
int Push(pStack stack, ElemType val);

int Pop(pStack stack, ElemType *res);

int GetMin(pStack stack);


#endif