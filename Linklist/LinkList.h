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


void InitLinkList(pLinkList list);		//��ʼ��������

void InsertElemToList(pLinkList list, ElemType val, int pos);		//��ָ��λ�ò�����

void DeleteElemOfList(pLinkList list, int pos);		//ɾ��ָ��λ�ý��

void BeInsertElemToList(pLinkList list, ElemType val, int pos);		//��ָ��λ��ǰ������

void ShowList(pLinkList list);		//��ӡ������

void Assemblage(pLinkList list1, pLinkList list2, pLinkList list3);		//3,����㷨ʵ�� A��=A�ȣ�B��C��


#endif