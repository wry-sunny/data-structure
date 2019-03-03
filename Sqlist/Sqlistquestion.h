#ifndef __SQLISTQUESTION_H
#define __SQLISTQUESTION_H

#include "SqList.h"
#include "Sqlistquestion.h"
#include "LinkList.h"

void InorderList(SqList *va, int x);		/*9,试写一算法，将x插入到顺序表的适当位置上，以保持该表的有序性*/

void Compare(SqList *A, SqList *B);			//10,比较A,B的大小

void ReverseList(SqList * relist);			/*11,实现顺序表的逆置*/

void LinkListMerge(pLinkList listA, pLinkList listB);			//12,将A表和B表归并成一个按元素值递减有序排列的线性表C

void DeleteSameElem(SqList *A, SqList *B, SqList *C);				//在A中删去在B表中出现又在C表中出现的元素

void SelectDifferentElem(SqList *A, SqList *B);					//14,静态链表实现（A-B）U (B-A)

void AMergeB(SqList *A, SqList *B);					//16,两个顺序表递增有序，执行 C=AUB

#endif