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

void InitCycDouList(pCycDouList list);		//初始化函数

void InsertCycDouList(pCycDouList list, ElemType value, int pos);	//插入函数

void DeleteCycDouList(pCycDouList list, int pos);		//删除函数

void ShowCycDouList(pCycDouList list);		//打印函数及链表的长度

void FindCycDouList(pCycDouList list,int n);		//查找函数

#endif