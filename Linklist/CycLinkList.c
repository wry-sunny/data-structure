#include "CycLinkList.h"

void InitCycList(pCycLinkList list)		//初始化函数
{
	assert(list != NULL);

	list->count = 0;
	list->head = NULL;
}

static CycNode *BuyNode(ElemType val, CycNode *next)		
{
	CycNode *s = (CycNode *)malloc(sizeof(CycNode));
	assert(s != NULL);

	s->data = val;
	if (next != NULL)
	{
		s->next = next;
	}
	else
	{
		s->next = s;
	}

	return s;
}

void InsertCycList(pCycLinkList list, ElemType val, int pos)		//插入函数
{
	if (list->head == NULL)
	{
		list->head = BuyNode(val, NULL);
		list->count++;
		return;
	}

	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	CycNode *p = list->head;

	int pos2 = pos != 0 ? pos : list->count;

	while (pos2 > 1)
	{
		p = p->next;
		pos2--;
	}

	CycNode *s = BuyNode(val, p->next);
	p->next = s;

	if (pos == 0)
	{
		list->head = s;
	}

	list->count++;
}

void DeleteCycList(pCycLinkList list, int pos)		//删除指定结点函数
{
	assert(list != NULL && list->head != NULL);

	if (list->head->next == list->head)
	{
		free(list->head);
		list->head = NULL;
		list->count--;
		return;
	}

	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	CycNode *p = list->head;

	if (pos == 1)
	{
		while (p->next != list->head)
		{
			p = p->next;
		}

		list->head = list->head->next;
	}
	else
	{
		while (pos > 2)
		{
			p = p->next;
			pos--;
		}
	}

	CycNode *q = p->next;
	p->next = q->next;

	free(q);
	list->count--;
}

void ShowCycList(pCycLinkList list)		//打印函数及链表长度
{
	assert(list != NULL);
	if (list->head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	CycNode *p = list->head;

	while (p->next != list->head)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("data=%d,len=%d  \n", p->data,list->count);
}