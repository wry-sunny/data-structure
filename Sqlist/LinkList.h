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


void InitLinkList(pLinkList list);

void InsertElemToList(pLinkList list, ElemType val, int pos);

void DeleteElemOfList(pLinkList list, int pos);

void ShowList(pLinkList list);

void Reverse(pLinkList list);		//½«µ¥Á´±íÄæÖÃ




#endif