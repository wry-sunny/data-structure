#include "LinkList.h"


static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;

	return s;
}

void InitLinkList(pLinkList list)			//��ʼ��������
{
	list->count = 0;

	list->head.next = NULL;
}

void InsertElemToList(pLinkList list, ElemType val, int pos)		//��ָ��λ�ò�����
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

void BeInsertElemToList(pLinkList list, ElemType val, int pos)		//��ָ��λ��ǰ������
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	Node *p = &list->head;

	while (pos > 1)
	{
		p = p->next;
		pos--;
	}

	Node *s = BuyNode(val, p->next);

	p->next = s;

	list->count++;
}

void DeleteElemOfList(pLinkList list, int pos)		//ɾ��ָ��λ�ý��
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


void ShowList(pLinkList list)		//��ӡ������
{
	assert(&list->head != NULL);

	Node *p = &list->head;

	while (p->next != NULL)
	{
		p = p->next;
		printf("%d  ", p->data);
		
	}
	printf("\n");
}


void Assemblage(pLinkList listA, pLinkList listB, pLinkList listC)		//3,����㷨ʵ�� A��=A�ȣ�B��C��
{
	assert(listA != NULL && listB != NULL && listC != NULL);

	Node *pa = listA->head.next;
	Node *pb = listB->head.next;
	Node *pc = listC->head.next;
	Node *pre = &listA->head;

	if (pa->data<pb->data || pa->data<pc->data)
	{
		pre->next = pa;
		pre = pa;
		pa = pa->next;
	}
	while (pa != NULL && pb != NULL && pc != NULL)
	{
		while (pb != NULL && pc != NULL)
		{
			if (pb->data < pc->data)
			{
				pb = pb->next;
			}
			else if (pb->data > pc->data)
			{
				pc = pc->next;
			}
			else
			{
				break;
			}
		}
		if (pb != NULL && pc != NULL)
		{			
			if (pre->next->data == pb->data)
			{
				pb = pb->next;
				pc = pc->next;
			}
			while (pa != NULL && pa->data < pb->data)
			{
				pre->next = pa;
				pre = pa;
				pa = pa->next;
			}

			if (pre->data != pb->data)
			{	
				while (pb != NULL && pc != NULL)
				{
					if (pb->data < pc->data)
					{
						pb = pb->next;
					}
					if (pb->data > pc->data)
					{
						pc = pc->next;
					}
					if (pb->data >= pc->data)
					{
						pre->next = pb;
						pre = pb;
						break;
					}
				}
			}
			else
			{
				pb = pb->next;
				pc = pc->next;
			}
		}
	}
}