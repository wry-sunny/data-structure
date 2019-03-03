#include "Stack.h"
#include "Queue.h"
#include "Question.h"


int main()
{
	//Stack stack;

	//InitStack(&stack);
	//
	//for (int i = 0; i < 12; ++i)
	//{
	//	if (!Push(&stack, i))
	//	{
	//		printf("push fail\n");
	//		DestoryStack(&stack);
	//		return 0;
	//	}
	//}

	//ElemType val;
	//while (Pop(&stack, &val))
	//{
	//	printf("%d\n", val);
	//}

	//DestoryStack(&stack);

	//Push(&stack, 10);



	//char *s = "(3*[5+4*{[3+5]*[40-2*(5-3)]})";

	//if ( MatchingBrackets(s) == 1)
	//{
	//	printf("表达式括号匹配\n");
	//}
	//else
	//{
	//	printf("表达式括号不匹配\n");
	//}



	//char *s = "435*+23*-";
	//Stack stack;
	//InitStack(&stack);
	//ElemType val = Compute(s, &stack);
	//printf("%d\n", val);

	/*CycLinkQueue LinkQueue;
	InitLinkQueue(&LinkQueue);
	PushLinkQueue(&LinkQueue, 3);
	PushLinkQueue(&LinkQueue, 9);
	ShowList(&LinkQueue);
	ElemType res;
	PopLinkQueue(&LinkQueue, &res);
	printf("%d\n",res);
	PopLinkQueue(&LinkQueue, &res);
	printf("%d\n", res);*/


	//SqList list;
	//InitSqList(&list);
	//PushSqList(&list, 0, 3, 3);
	//PushSqList(&list, 1, 8, 4);
	//PushSqList(&list, 2, 45, 1);
	//PushSqList(&list, 3, 2, 2);
	//printf("%d\n",PopSqList(&list));
	//printf("%d\n", PopSqList(&list));
	//printf("%d\n", PopSqList(&list));
	//printf("%d\n", PopSqList(&list));


	//Stack stack;
	//InitStack(&stack);
	//char *s = "a+b*(c-d)-e/f";
	//InflxtoPrefix(&stack, s);

	Stack stack;
	InitStack(&stack);
	Push1(&stack, 1);
	Push1(&stack, 4);
	Push1(&stack, 3);

	printf("%d\n",GetMin(&stack));

	return 0;
}