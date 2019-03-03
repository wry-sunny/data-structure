#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>



typedef int ElemType;


typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;


typedef struct LinkList
{
	Node head; 
	int count;
}LinkList, *pLinkList;


void InitLinkList(pLinkList list);		//初始化单链表

void InsertElemToList(pLinkList list, ElemType val, int pos);		//在指定位置插入结点

void DeleteElemOfList(pLinkList list, int pos);		//删除指定位置结点

void BeInsertElemToList(pLinkList list, ElemType val, int pos);		//在指定位置前插入结点

void ShowList(pLinkList list);		//打印单链表

void Assemblage(pLinkList list1, pLinkList list2, pLinkList list3);		//3,设计算法实现 A：=A∪（B∩C）


#endif