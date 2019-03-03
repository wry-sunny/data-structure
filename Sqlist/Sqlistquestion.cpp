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





void InorderList(SqList *va, int x)                 /*9,��дһ�㷨����x���뵽˳�����ʵ�λ���ϣ��Ա��ָñ��������*/
{
	assert(va != NULL);

	int tmp = 0;
	int i = 0;
	for (; i < va->length; i++)
	{
		if (va->elem[i]>=x)
		{
			tmp = va->elem[i];
			va->elem[i] = x;
			x = tmp;
		}
	}
	va->elem[i] = tmp;
	va->length++;
	//printf("insert success\n");
}


void Compare(SqList *A, SqList *B)					 //10,�Ƚ�A,B�Ĵ�С
{
	int i = 0;
	int j = 0;
	if (A->length > A->listsize || B->length > B->listsize)
	{
		return;
	}
	if (A->elem != NULL && B->elem != NULL)
	{  
		while (i <= A->length && j <= B->length)
		{
			if (A->elem[i] == B->elem[j])
			{
				i++;
				j++;
			}
			else
			{
				break;
			}
		}
		if (A->elem[i] == B->elem[j])
		{
			printf("A = B\n");	
		}
		if (A->elem[i] > B->elem[j])
		{
			printf("A > B\n");		
		}
		if (A->elem[i] < B->elem[j])
		{
			printf("A < B\n");		
		}
	}
}


void ReverseList(SqList *relist)                         /*11,ʵ��˳��������*/
{
	assert(relist != NULL);

	int n = relist->length;
	for (int i = 0;; i++, n--)
	{
		if (i >= n)
		{
			break;
		}
		else
		{
			int tmp = relist->elem[i];
			relist->elem[i] = relist->elem[n];
			relist->elem[n] = tmp;
		}
	}
}


void LinkListMerge(pLinkList listA, pLinkList listB)			//12,��A���B��鲢��һ����Ԫ��ֵ�ݼ��������е����Ա�C
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


void DeleteSameElem(SqList *A, SqList *B, SqList *C)				//13,��A��ɾȥ��B���г�������C���г��ֵ�Ԫ��
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (A->elem[i] != NULL && B->elem[i] != NULL && C->elem[i] != NULL)
	{
		if (A->elem[i] < B->elem[j] || A->elem[i] < C->elem[k])
		{
			i++;
		}
		else if (A->elem[i] > B->elem[j])
		{
			j++;
		}
		else if (A->elem[i] > C->elem[k])
		{
			k++;
		}

		if (B->elem[j] == C->elem[k])
		{
			if (A->elem[i] < B->elem[j])
			{
				i++;
			}
			else if (A->elem[i] > B->elem[j])
			{
				j++;
				k++;
			}
			else
			{
				DeleteSqList(A, i);
				i++;
				j++;
				k++;
			}
		}
	}
}


void SelectDifferentElem(SqList *A, SqList *B)				//14,��̬����ʵ�֣�A-B��U (B-A)
{
	int i = 0;

	while (i < B->length)
	{
		int j = 0;
		while(j < A->length)
		{
			if (A->elem[j] == B->elem[i])
			{
				break;
			}
			j++;
		}
		if (j < A->length)
		{
			DeleteSqList(A, j);
		}
		else
		{
			InsertSqList(A, j, B->elem[i]);
		}
		i++;
	}
}


void AMergeB(SqList *A, SqList *B)					//16,����˳����������ִ�� C=AUB
{
	int i = 0;
	int j = 0;
	while (i < A->length && j < B->length)
	{
		if (B->elem[j] < A->elem[i])
		{
			InsertSqList(A, i, B->elem[j]);
			j++;
		}
		else if (B->elem[j] == A->elem[i])
		{
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	if (j < B->length)
	{
		for (; j < B->length; j++)
		{
			InsertSqList(A, i, B->elem[j]);
		}
	}
}