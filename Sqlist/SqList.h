#ifndef __SQLIST_H
#define __SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LEN 10
#define TRUE 1
#define FALSE 0

typedef struct
{
	int *elem;   //  ָ��洢����Ԫ�صĿռ��ָ��
	int length;  //  ��ǰ�洢���ݵĸ���
	int listsize;  //  ��ǰ����Ĵ洢�ռ�Ĵ�С
}SqList;

void InitSqList(SqList *list);

// ��˳����ָ��λ��pos��������val
int InsertSqList(SqList *list, int pos, int val);

// ��˳���ĵ�һ��λ�ò�������
int InsertHead(SqList *list, int val);

// ��˳�������һ��λ�ò�������
int InsertTail(SqList *list, int val);

// ɾ��ָ��λ�õ�����
int DeleteSqList(SqList *list, int pos);

// ɾ����һ������Ԫ��
int DeleteHead(SqList *list);

// ɾ�����һ������Ԫ��
int DeleteTail(SqList *list);

// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)
int FindVal(SqList *list, int val);

void DestroySqList(SqList *list);





#endif