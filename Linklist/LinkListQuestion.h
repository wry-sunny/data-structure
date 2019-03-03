#ifndef __LINKLISTQUESTION_H
#define __LINKLISTQURSTION_H

#include "LinkList.h"
#include<math.h>

int FindKAfter(pLinkList list, int k, ElemType *res);    //找出倒数第k个结点

void Reverse(pLinkList list);		//将单链表逆置

int TwoListMeet(pLinkList list1, pLinkList list2);  //判断两个单链表是否相交

void MakeIntersectList(pLinkList listone, pLinkList listtwo); //制造相交单链表

void IsRingList(pLinkList list);   //判断单链表是否有环

void MakeRing(pLinkList list);	 //创造一个有环单链表

#endif