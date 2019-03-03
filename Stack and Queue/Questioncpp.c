#include "Question.h"
#include "Stack.h"
#include <ctype.h>

/*
//7,�жϱ��ʽ�����Ƿ�ƥ��
int MatchingBrackets(char *s)						
{
	int sbt = 0;
	int mbt = 0;
	int bbt = 0;
	while (*s != '\0')
	{
		if (*s == '(')
			sbt++;
		if (*s == ')')
			sbt--;
		if (*s == '[')
			mbt++;
		if (*s == ']')
			mbt--;
		if (*s == '{')
			bbt++;
		if (*s == '}')
			bbt--;

		if (sbt < 0 || mbt < 0 || bbt < 0)
		{
			return 0;
		}

		*s++;
	}
	if (sbt == 0 && mbt == 0 && bbt == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


//8,���沨��ʽ����׺���ʽ��������ֵ
//�沨��ʽ����׺���ʽ����ֵ�����������ǰ�ַ�Ϊ��������Ϊ���֣���ѹջ��������������
//��ջ������Ԫ�ص�������Ӧ���㣬�������ջ����󵱱��ʽɨ�����ջ��ľ��ǽ����
int Compute(char *s, pStack stack)
{
	ElemType high;
	ElemType low;

	while (*s != '\0')
	{
		if (isdigit(*s))
		{
			Push(stack, *s);
		}
		else if (*s == '+')
		{
			Pop(stack, &high);
			Pop(stack, &low);
			Push(stack, high + low - 48);
		}
		else if (*s == '-')
		{
			Pop(stack, &high);
			Pop(stack, &low);
			Push(stack, low - high + 48);
		}
		else if (*s == '*')
		{
			Pop(stack, &high);
			Pop(stack, &low);
			Push(stack, (high - 48) * (low - 48) + 48);
		}
		else if (*s == '/')
		{
			Pop(stack, &high);
			Pop(stack, &low);
			Push(stack, (low - 48) / (high - 48) + 48);
		}
		*s++;
	}
	ElemType val;
	Pop(stack, &val);
	return val - 48;
}



//9,�����Դ�ͷ����ѭ�������ʾ���У�������һ��ָ��ָ���βԪ�ؽ��,��д��Ӧ�Ķ��г�ʼ��������кͳ����е��㷨��
static Node *BuyNode(ElemType val)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;

	return s;
}

void InitLinkQueue(pCycLinkQueue list)
{
	list->count = 0;
	list->tail = NULL;
	list->head.next = NULL;
}

void PushLinkQueue(pCycLinkQueue list, ElemType val)
{
	Node *s = BuyNode(val);

	if (list->count == 0)
	{
		list->head.next = s;
	}
	else
	{
		list->tail->next = s;
	}
	s->next = list->head.next;

	list->count++;

	list->tail = s;
}

void PopLinkQueue(pCycLinkQueue list, ElemType *res)
{
	Node *q = list->head.next;
	list->head.next = q->next;
	list->tail->next = list->head.next;
	*res = q->data;
	free(q);

	list->count--;
}

void ShowList(pCycLinkQueue list)
{
	Node *p = &list->head;

	while (p != list->tail)
	{
		p = p->next;
		printf("%d  ", p->data);
	}
	printf("\n");
}



//11������˳���ʵ�����ȶ��еĲ����ɾ��������
static int IsEmpty(SqList *list)
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsFull(SqList *list)
{
	assert(list != NULL);

	if (list->length == list->listsize)
	{
		return TRUE;
	}

	return FALSE;
}

static int ExpandSpace(SqList *list)
{
	ElemType *s = (ElemType *)malloc(sizeof(ElemType)* list->listsize * 2);
	ElemType *p = (ElemType *)malloc(sizeof(ElemType)* list->listsize * 2);
	assert(s != NULL);

	for (int i = 0; i < list->length; ++i)
	{
		p[i] = list->prior[i];
		s[i] = list->elem[i];
	}

	free(list->elem);
	free(list->prior);
	list->elem = s;
	list->prior = p;
	list->listsize *= 2;
}

void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
	list->prior = (int *)malloc(sizeof(int)* LEN);

}

int PushSqList(SqList *list, int pos, int val,int pri)
{
	assert(list != NULL);
	if (pos < 0)
	{
		printf("error:pos is negative\n");
		return 0;
	}

	if (IsFull(list))
	{
		ExpandSpace(list);
	}
	if (pos <= list->length)
	{
		for (int i = pos; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
			int tmp2 = list->prior[i];
			list->prior[i] = pri;
			pri = tmp;
		}
	}
	else if (pos == list->length + 1)
	{
		list->elem[pos] = val;
		list->prior[pos] = pri;
	}
	else
	{
		printf("error:pos is big\n");
		return 0;
	}

	list->length++;


	return 1;
}

int PopSqList(SqList *list)
{
	assert(list != NULL);
	int data = 0;
	if (IsEmpty(list))
	{
		printf("error:form is empty\n");
		return 0;
	}
	else
	{
		int min = 0;
		for (int i = 1; i < list->length; i++)
		{
			if (list->prior[min] > list->prior[i])
			{
				min = i;
			}
		}
		data = list->elem[min];
		for (int i = min; i < list->length; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = list->elem[i + 1];
			list->elem[i + 1] = tmp;

			tmp = list->prior[i];
			list->prior[i] = list->prior[i + 1];
			list->prior[i + 1] = tmp;
		}
	}

	list->length--;


	return data;
}
*/
//14�����ʵ�ֽ���׺���ʽת��ǰ׺���ʽ����a+b*(c-d)-e/fת��-+a*b-cd/ef��
/*
static int PriorSign(char a)
{
	switch (a)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	}
}

void InflxtoPrefix(pStack stack, char *s)				//14,���ʵ�ֽ���׺���ʽת��ǰ׺���ʽ
{
	ElemType res;
	char arr[100] = { 0 };
	int i = 0;
	while (*s != '\0')
	{
		*s++;
	}
	*s--;
	while (*s != NULL)
	{
		if (isalpha(*s))
		{
			arr[i++] = *s;
		}
		else if (*s == ')')
		{
			Push(stack,*s);
		}
		else if (*s == '(')
		{
			while (stack->data[(stack->top-1)] != ')')
			{
				Pop(stack,&res);
				arr[i++] = res;
			}
			Pop(stack, &res);
		}
		else
		{
			while(stack->top != 0 && stack->data[(stack->top-1)] != ')')
			{
				if (PriorSign(*s) < PriorSign(stack->data[(stack->top -1)]))
				{
					Pop(stack, &res);
					arr[i++] = res;
				}
				else
				{
					break;
				}
			}
			Push(stack, *s);
		}
		*s--;
	}
	while (stack->top != 0)
	{
		Pop(stack, &res);
		arr[i++] = res;
	}
	
	while(i > -1)
	{
		printf("%c",arr[i]);
		i--;
	}
}

*/
//15������һ���µ�ջ�ṹ���ڸýṹ����һ����ȡ��ǰջ����СֵMin�ĺ�����
//Ҫ���ڸ�ջ�е�����ջPush����ջPop�ͻ�ȡ��СֵMin��ʱ�临�Ӷȶ�ΪO(1).
int Push1(pStack stack, ElemType val)
{
	assert(stack != NULL);

	if (IsFull(stack))
	{
		Expand(stack);
		if (IsFull(stack))
		{
			return FALSE;
		}
	}

	stack->data[stack->top++] = val;

	return TRUE;
}

int Pop1(pStack stack, ElemType *res)
{
	assert(stack != NULL);

	if (IsEmpty(stack))
	{
		return FALSE;
	}

	*res = stack->data[--stack->top];

	return TRUE;
}

int GetMin(pStack stack)
{
	int min = stack->data[(stack->top - 1)];
	int i = 0;
	int j = stack->top - 1;
	while (i < stack->top-1)
	{
		if (min > stack->data[j - 1])
		{
			min = stack->data[j - 1];
		}
		i++;
		j--;
	}
	return min;
}