#include "Question.h"
#include "Stack.h"
#include <ctype.h>

/*
//7,判断表达式括号是否匹配
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


//8,对逆波兰式（后缀表达式）进行求值
//逆波兰式（后缀表达式）求值方法：如果当前字符为变量或者为数字，则压栈，如果是运算符，
//则将栈顶两个元素弹出作相应运算，结果再入栈，最后当表达式扫描完后，栈里的就是结果。
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



//9,假设以带头结点的循环链表表示队列，并且设一个指针指向队尾元素结点,编写相应的队列初始化、入队列和出队列的算法。
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



//11、利用顺序表实现优先队列的插入和删除操作。
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
//14、编程实现将中缀表达式转成前缀表达式，如a+b*(c-d)-e/f转成-+a*b-cd/ef。
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

void InflxtoPrefix(pStack stack, char *s)				//14,编程实现将中缀表达式转成前缀表达式
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
//15、定义一个新的栈结构，在该结构中有一个获取当前栈内最小值Min的函数，
//要求在该栈中调用入栈Push，出栈Pop和获取最小值Min的时间复杂度都为O(1).
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