#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;


typedef struct CycNode
{
	ElemType data;
	struct CycNode *next;
}CycNode;


typedef struct CycLinkList
{
	CycNode *head;
	int count;
}CycLinkList, *pCycLinkList;

void InitCycList(pCycLinkList list);		//��ʼ������

void InsertCycList(pCycLinkList list, ElemType val, int pos);		//���뺯��

void DeleteCycList(pCycLinkList list, int pos);		//ɾ��ָ����㺯��

void ShowCycList(pCycLinkList list);		//��ӡ������������



#endif