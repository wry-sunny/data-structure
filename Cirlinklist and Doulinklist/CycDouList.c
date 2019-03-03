#include "CycDouList.h"

void InitCycDouList(pCycDouList list)		//初始化函数
{
	assert(list != NULL);
	list->head = NULL;
	list->count = 0;
}

static CycNode *BuyNode(ElemType value, CycNode *prev, CycNode* next)
{
	CycNode * s = (CycNode *)malloc(sizeof(CycNode));
	assert(s != NULL);

	s->data = value;

	if (prev == NULL || next == NULL)
	{
		s->next = s->prev = s;
	}
	else
	{
		s->next = next;
		s->prev = prev;
	}

	return s;
}

static void Insert(ElemType value, pCycDouList list, CycNode* p)
{
	CycNode *s = BuyNode(value, p, p->next);

	p->next->prev = s;
	p->next = s;

	list->count++;
}

void InsertCycDouList(pCycDouList list, ElemType value, int pos)		//插入函数
{
	assert(list != NULL);

	if (list->head == NULL)
	{
		CycNode *s = BuyNode(value, NULL, NULL);
		list->head = s;
		list->count++;
		return;
	}

	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	CycNode *p = list->head;

	if (pos == 0)
	{
		p = p->prev;
		Insert(value, list, p);
		list->head = list->head->prev;
	}
	else
	{
		while (pos > 1)
		{
			p = p->next;
			pos--;
		}

		Insert(value, list, p);
	}
}

void DeleteCycDouList(pCycDouList list, int pos)		//删除函数
{
	assert(list != NULL);

	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	if (list->head->next == list->head)
	{
		free(list->head);
		list->head = NULL;
		list->count--;
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

void ShowCycDouList(pCycDouList list)		//打印函数及链表的长度
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

	printf("%d  \n", p->data);
	printf("len = %d\n", list->count);
}


void FindCycDouList(pCycDouList list,int n)			//查找函数
{
	assert(list != NULL);
	if (n < 0 || n > list->count)
	{
		printf("count is error\n");
		return;
	}

	CycNode *p = list->head;

	for (int i = 1; i < n; i++)
	{
		p = p->next;
	}
	printf("%d\n",p->data);
}