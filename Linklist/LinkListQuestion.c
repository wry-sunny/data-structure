#include "LinkListQuestion.h"
#include "LinkList.h"


int FindKAfter(pLinkList list, int k, ElemType *res)		//�ҳ�������k�����
{
	assert(list != NULL);

	if (k <= 0 || k > list->count)
	{
		return 0;
	}

	struct Node *p = list->head.next;
	struct Node *q = p;

	while (k > 0)
	{
		k--;
		p = p->next;
	}

	while (p != NULL)
	{
		p = p->next;
		q = q->next;
	}

	*res = q->data;

	return 1;
}



void Reverse(pLinkList list)		//������������
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



int TwoListMeet(pLinkList list1, pLinkList list2)		//�ж������������Ƿ��ཻ
{
	assert(list1 != NULL && list2 != NULL);
	struct Node *p = list1->head.next;
	struct Node *q = list2->head.next;
	if (list1->count > list2->count)
	{
		for (int i = 0; i < list1->count - list2->count; ++i)
		{
			p = p->next;
		}
	}
	else
	{
		for (int i = 0; i < list2->count - list1->count; ++i)
		{
			q = q->next;
		}
	}

	int count = 0;
	while (p != NULL && p != q)
	{
		p = p->next;
		q = q->next;
		count++;
	}

	if (p == NULL)
	{
		return 0;
	}

	return count;
}


void IsRingList(pLinkList list)   //�жϵ������Ƿ��л�
{
	assert(list != NULL);

	Node *p = list->head.next;
	Node *s = list->head.next;

	p = p->next;
	while (p != s)
	{
		p = p->next;
		if (p->next == NULL)
		{
			printf("no ring\n");
			return;
		}
		p = p->next;
		if (p->next == NULL)
		{
			printf("no ring\n");
			return;
		}

		s = s->next;
	}                          

	p = &list->head;

	int i = 0;

	while (p != s)
	{
		p = p->next;
		s = s->next;
		i++;
	}

	printf("�뻷���ǵ�%d�����\n", i);
}

void MakeRing(pLinkList list)      //����һ���л�������
{

	Node *p = &list->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = list->head.next->next->next;
}