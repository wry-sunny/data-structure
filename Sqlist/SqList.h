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
	int *elem;   //  指向存储数据元素的空间的指针
	int length;  //  当前存储数据的个数
	int listsize;  //  当前分配的存储空间的大小
}SqList;

void InitSqList(SqList *list);

// 在顺序表的指定位置pos插入数据val
int InsertSqList(SqList *list, int pos, int val);

// 在顺序表的第一个位置插入数据
int InsertHead(SqList *list, int val);

// 在顺序表的最后一个位置插入数据
int InsertTail(SqList *list, int val);

// 删除指定位置的数据
int DeleteSqList(SqList *list, int pos);

// 删除第一个数据元素
int DeleteHead(SqList *list);

// 删除最后一个数据元素
int DeleteTail(SqList *list);

// 查找val所在的位置(最后一次出现的位置)
int FindVal(SqList *list, int val);

void DestroySqList(SqList *list);





#endif