#ifndef __LINKLISTQUESTION_H
#define __LINKLISTQURSTION_H

#include "LinkList.h"
#include<math.h>

int FindKAfter(pLinkList list, int k, ElemType *res);    //�ҳ�������k�����

void Reverse(pLinkList list);		//������������

int TwoListMeet(pLinkList list1, pLinkList list2);  //�ж������������Ƿ��ཻ

void MakeIntersectList(pLinkList listone, pLinkList listtwo); //�����ཻ������

void IsRingList(pLinkList list);   //�жϵ������Ƿ��л�

void MakeRing(pLinkList list);	 //����һ���л�������

#endif