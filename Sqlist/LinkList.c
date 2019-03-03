#include "SqList.h"
#include "Sqlistquestion.h"
#include "LinkList.h"

static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;

	return s;
}

void InitLinkList(pLinkList list)
{
	list->count = 0;

	list->head.next = NULL;
}

void InsertElemToList(pLinkList list, ElemType val, int pos)
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	Node *p = &list->head;

	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	Node *s = BuyNode(val, p->next);

	p->next = s;

	list->count++;
}


void DeleteElemOfList(pLinkList list, int pos)
{
	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	Node *p = &list->head;


	while (pos > 1)
	{
		p = p->next;
		pos--;
	}

	Node *q = p->next;
	p->next = q->next;

	free(q);

	list->count--;
}


void ShowList(pLinkList list)
{
	assert(&list->head != NULL);

	Node *p = &list->head;

	while (p->next != NULL)
	{
		p = p->next;
		printf("%d  ", p->data);
		
	}
}


void Reverse(pLinkList list)		//将单链表逆置
{
	assert(list != NULL);
	struct Node *p = NULL;
	struct Node *q = list->head.next;
	if (q == NULL)
	{
		return;
	}
	struct Node *m = q->next;

	while (q != NULL)
	{

		q->next = p;

		p = q;
		if (m == NULL)
		{
			break;
		}
		q = m;
		m = q->next;
	}

	list->head.next = p;
}


void LinkListMerge(pLinkList listA, pLinkList listB)			//将A表和B表归并成一个按元素值递减有序排列的线性表C
{
	assert(listA != NULL && listB != NULL);

	Node *p = listA->head.next;
	Node *q = listB->head.next;
	Node *pre = &listA->head;

	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			pre->next = p;
			pre = p;
			p = p->next;
		}
		else
		{
			pre->next = q;
			pre = q;
			q = q->next;
		}
	}
	if (p != NULL)
	{
		pre->next = p;
		pre = p;
		p = p->next;
	}
	if (q != NULL)
	{
		pre->next = q;
		pre = q;
		q = q->next;
	}
	Reverse(listA);
}
