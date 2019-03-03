#include "CycLinkList.h"
#include "LinkList.h"
#include "LinkListQuestion.h"


int main()
{
	//LinkList list;
	//InitLinkList(&list);
	//for (int i = 0; i < 10; ++i)
	//{
	//	InsertElemToList(&list, i*10, i);
	//}
	//ShowList(&list);
	//BeInsertElemToList(&list, 110, 3);
	//ShowList(&list);

	//int res = 0;
	//FindKAfter(&list, 3, &res);
	//printf("%d\n",res);

	//Reverse(&list);

	//ShowList(&list);

	//MakeRing(&list);   //制造一个有环单链表

	//IsRingList(&list);


	//LinkList list1;
	//LinkList list2;
	//InitLinkList(&list1);
	//InitLinkList(&list2);
	//for (int i = 0; i < 5; ++i)
	//{
	//	InsertElemToList(&list1, i * 10, i);
	//}

	//for (int i = 0; i < 5; ++i)
	//{
	//	InsertElemToList(&list2, i * 20, i);
	//}
	//if (TwoListMeet(&list1, &list2) != 0)
	//{
	//	printf("两个单链表的第一个交点为短单链表的第%d个结点\n", TwoListMeet(&list1, &list2));
	//}
	//else
	//{
	//	printf("两个单链表没有相交\n");
	//}



	LinkList listA;
	LinkList listB;
	LinkList listC;
	InitLinkList(&listA);
	InitLinkList(&listB);
	InitLinkList(&listC);

	InsertElemToList(&listA, 4, 0);
	InsertElemToList(&listA, 6, 1);
	InsertElemToList(&listA, 7, 2);

	InsertElemToList(&listB, 4, 0);
	InsertElemToList(&listB, 8, 1);
	InsertElemToList(&listB, 9, 2);
	InsertElemToList(&listB, 10, 3);

	InsertElemToList(&listC, 3, 0);
	InsertElemToList(&listC, 4, 1);
	InsertElemToList(&listC, 10, 2);
	InsertElemToList(&listC, 12, 3);
	InsertElemToList(&listC, 15, 4);

	Assemblage(&listA,&listB,&listC);
	ShowList(&listA);
}