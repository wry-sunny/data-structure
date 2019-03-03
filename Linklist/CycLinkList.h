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

void InitCycList(pCycLinkList list);		//初始化函数

void InsertCycList(pCycLinkList list, ElemType val, int pos);		//插入函数

void DeleteCycList(pCycLinkList list, int pos);		//删除指定结点函数

void ShowCycList(pCycLinkList list);		//打印函数及链表长度



#endif