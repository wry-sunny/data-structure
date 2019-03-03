#ifndef __CYCDOULIST_H
#define __CYCDOULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct CycNode
{
	struct CycNode *prev;
	ElemType data;
	struct CycNode *next;
}CycNode;


typedef struct CycDouList
{
	CycNode *head;
	int count;
}CycDouList, *pCycDouList;

void InitCycDouList(pCycDouList list);		//��ʼ������

void InsertCycDouList(pCycDouList list, ElemType value, int pos);	//���뺯��

void DeleteCycDouList(pCycDouList list, int pos);		//ɾ������

void ShowCycDouList(pCycDouList list);		//��ӡ����������ĳ���

void FindCycDouList(pCycDouList list,int n);		//���Һ���

#endif