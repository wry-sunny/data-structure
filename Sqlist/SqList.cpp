#include "SqList.h"
#include "Sqlistquestion.h"
#include "LinkList.h"

/*
	1������ռ䣬��ʹlist��elemָ��ָ�����ռ�
	2����list��length��listsize���ó�ʼֵ

	typedef struct
	{
		int *elem;   //  ָ��洢����Ԫ�صĿռ��ָ��
		int length;  //  ��ǰ�洢���ݵĸ���
		int listsize;  //  ��ǰ����Ĵ洢�ռ�Ĵ�С
	}SqList;
*/

//�ж��Ƿ�Ϊ��
static int IsEmpty(SqList *list)
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

//�ж��Ƿ�Ϊ��
static int IsFull(SqList *list)
{
	assert(list != NULL);

	if (list->length == list->listsize)
	{
		return TRUE;
	}

	return FALSE;
}

//����ռ�
static int ExpandSpace(SqList *list)
{
	assert(list != NULL);

	int change = list->listsize * 2;

	int * tmp = (int *)malloc(change * sizeof(int));
	assert(tmp != NULL);

	for (int i = 0; i < list->listsize; i++)
	{
		tmp[i] = list->elem[i];
	}

	list->listsize = change;
	list->elem = (int *)malloc(list->listsize * sizeof(int));
	assert(list->elem != NULL);

	return 1;
}

//��ʼ��˳���
void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;

	//printf("Init success\n");
}

//����˳���
void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);

	list->length = list->listsize = 0;

	//printf("Destroy success\n");
}

// ��˳����ָ��λ��pos��������val
int InsertSqList(SqList *list, int pos, int val)
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
	if (pos<=list->length)
	{
		for (int i = pos; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
		}
	}
	else if (pos == list->length+1)
	{
		list->elem[pos] = val;
	}
	else
	{
		printf("error:pos is big\n");
		return 0;
	}

	list->length++;

	//printf("insert success\n");

	return 1;
}

// ��˳���ĵ�һ��λ�ò�������
int InsertHead(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}
	if (list->length >= 1)
	{
		for (int i = 0; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
		}
	}
	else
	{
		list->elem[0] = val;
	}

	list->length++;

	//printf("insert head place success\n");

	return 1;

}

// 15,��˳�������һ��λ�ò�������
int InsertTail(SqList *list, int val)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("error:form is empty\n");
		return 0;
	}

	if (IsFull(list))
	{
		ExpandSpace(list);
	}

	list->elem[list->length] = val;

	list->length++;

	//printf("insert tail place success\n");

	return 1;
}

// ɾ��ָ��λ�õ�����
int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);
	if (pos < 0)
	{
		printf("error:pos is negative\n");
		return 0;
	}

	if (IsEmpty(list) || pos >= list->length)
	{
		printf("error:form is empty\n");
		return 0;
	}
	else
	{
		for (int i = pos; i < list->length; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = list->elem[i+1];
			list->elem[i + 1] = tmp;
		}
	}

	list->length--;

	//printf("delete success\n");

	return 1;
}

// ɾ����һ������Ԫ��
int DeleteHead(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("error:form is empty\n");
		return 0;
	}

	if (list->length > 1)
	{
		for (int i = 0; i < list->length; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = list->elem[i + 1];
			list->elem[i + 1] = tmp;
		}
	}
	else
	{
		list->elem[0] = NULL;
	}

	list->length--;

	//printf("delete head place success\n");

	return 1;
}

// ɾ�����һ������Ԫ��
int DeleteTail(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("error:form is empty\n");
		return 0;
	}

	list->elem[list->length - 1] = NULL;

	list->length--;

	//printf("delete tail place success\n");

	return 1;
}

// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)
int FindVal(SqList *list, int val)
{
	assert(list != NULL);

	int index = 0;

	if (IsEmpty(list))
	{
		printf("error:form is empty\n");
		return 0;
	}

	for (int i = 0; i < list->length - 1; i++)
	{
		if (list->elem[i] == val)
		{
			index = i;
		}
		else
		{
			printf("no found\n");
			return 0;
		}
	}
	printf("index=%d\n",index);
	return index;
}