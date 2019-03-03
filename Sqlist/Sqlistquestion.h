#ifndef __SQLISTQUESTION_H
#define __SQLISTQUESTION_H

#include "SqList.h"
#include "Sqlistquestion.h"
#include "LinkList.h"

void InorderList(SqList *va, int x);		/*9,��дһ�㷨����x���뵽˳�����ʵ�λ���ϣ��Ա��ָñ��������*/

void Compare(SqList *A, SqList *B);			//10,�Ƚ�A,B�Ĵ�С

void ReverseList(SqList * relist);			/*11,ʵ��˳��������*/

void LinkListMerge(pLinkList listA, pLinkList listB);			//12,��A���B��鲢��һ����Ԫ��ֵ�ݼ��������е����Ա�C

void DeleteSameElem(SqList *A, SqList *B, SqList *C);				//��A��ɾȥ��B���г�������C���г��ֵ�Ԫ��

void SelectDifferentElem(SqList *A, SqList *B);					//14,��̬����ʵ�֣�A-B��U (B-A)

void AMergeB(SqList *A, SqList *B);					//16,����˳����������ִ�� C=AUB

#endif