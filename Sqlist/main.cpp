#include "SqList.h"
#include "Sqlistquestion.h"
#include "LinkList.h"


int main()
{
	//SqList list;  
	//InitSqList(&list);
	//InsertSqList(&list, 0, 10);
	//InsertHead(&list, 11);
	//InsertTail(&list, 12);
	//DeleteSqList(&list, 0);
	//DeleteHead(&list);
	//DeleteTail(&list);
	//FindVal(&list, 10);
	//InsertSqList(&list, 0,40);
	//FindVal(&list, 40);
	//DestroySqList(&list);

	//SqList va;
	//InitSqList(&va);
	//InsertSqList(&va, 0, 2);
	//InsertSqList(&va, 1, 4);
	//InsertSqList(&va, 2, 8);
	//InorderList(&va,6);
	//for (int i = 0; i < va.length;i++)
	//{
	//	printf("%d\n",va.elem[i]);
	//}

	//SqList relist;  
	//InitSqList(&relist);
	//InsertSqList(&relist, 0, 10);
	//InsertSqList(&relist, 1, 11);
	//InsertSqList(&relist, 2, 12);
	//InsertSqList(&relist, 3, 13);
	//InsertSqList(&relist, 4, 14);
	//ReverseList(&relist);    
	//for (int i = 1; i <= relist.length;i++)
	//{
	//	printf("%d\n",relist.elem[i]);
	//}


	//SqList A;
	//InitSqList(&A);
	//InsertSqList(&A, 0, 2);
	//InsertSqList(&A, 1, 4);
	//InsertSqList(&A, 2, 6);

	//SqList B;
	//InitSqList(&B);
	//InsertSqList(&B, 0, 2);
	//InsertSqList(&B, 1, 4);
	//InsertSqList(&B, 2, 8);

	//Compare(*A, *B);

	//LinkList listA;
	//LinkList listB;
	//InitLinkList(&listA);
	//InitLinkList(&listB);
	//InsertElemToList(&listA, 4, 0);
	//InsertElemToList(&listA, 6, 1);
	//InsertElemToList(&listA, 7, 2);
	//InsertElemToList(&listB, 4, 0);
	//InsertElemToList(&listB, 8, 1);
	//InsertElemToList(&listB, 9, 2);
	//InsertElemToList(&listB, 10, 3);
	//LinkListMerge(&listA,&listB);
	//ShowList(&listA);


	//SqList A;
	//InitSqList(&A);
	//InsertSqList(&A, 0, 4);
	//InsertSqList(&A, 1, 6);
	//InsertSqList(&A, 2, 7);

	//SqList B;
	//InitSqList(&B);
	//InsertSqList(&B, 0, 6);
	//InsertSqList(&B, 1, 7);
	//InsertSqList(&B, 2, 8);

	//SqList C;
	//InitSqList(&C);
	//InsertSqList(&C, 0, 1);
	//InsertSqList(&C, 1, 6);
	//InsertSqList(&C, 2, 8);
	//DeleteSameElem(&A, &B, &C);
	//for (int i = 0; i < A.length;i++)
	//{
	//	printf("%d  ",A.elem[i]);
	//}


	//SqList A;
	//InitSqList(&A);
	//InsertSqList(&A, 0, 4);
	//InsertSqList(&A, 1, 6);
	//InsertSqList(&A, 2, 7);
	//InsertSqList(&A, 3, 2);
	//InsertSqList(&A, 4, 1);
	//InsertSqList(&A, 5, 15);
	//InsertSqList(&A, 6, 5);
	//InsertSqList(&A, 7, 8);
	//InsertSqList(&A, 8, 11);
	//InsertSqList(&A, 9, 20);

	//SqList B;
	//InitSqList(&B);
	//InsertSqList(&B, 0, 6);
	//InsertSqList(&B, 1, 7);
	//InsertSqList(&B, 2, 8);
	//InsertSqList(&B, 3, 10);
	//InsertSqList(&B, 4, 19);
	//InsertSqList(&B, 5, 40);
	//InsertSqList(&B, 6, 2);
	//InsertSqList(&B, 7, 4);
	//InsertSqList(&B, 8, 5);
	//InsertSqList(&B, 9, 50);

	//SelectDifferentElem(&A, &B);

	//for (int i = 0; i < A.length;i++)
	//{
	//	printf("%d  ",A.elem[i]);
	//}


	SqList A;
	InitSqList(&A);
	InsertSqList(&A, 0, 6);
	InsertSqList(&A, 1, 7);
	InsertSqList(&A, 2, 8);
	InsertSqList(&A, 3, 40);

	SqList B;
	InitSqList(&B);
	InsertSqList(&B, 0, 6);
	InsertSqList(&B, 1, 8);
	InsertSqList(&B, 2, 10);

	AMergeB(&A, &B);

	for (int i = 0; i < A.length;i++)
	{
		printf("%d  ",A.elem[i]);
	}
}