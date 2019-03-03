#include "DoubleList.h"
#include "CycDouList.h"

int main()
{

	CycDouList list;

	InitCycDouList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertCycDouList(&list, i * 10, i);
	}
	
	ShowCycDouList(&list);
	FindCycDouList(&list, 3);

	DeleteCycDouList(&list, 1);
	ShowCycDouList(&list);
	DeleteCycDouList(&list, 1);
	ShowCycDouList(&list);
	DeleteCycDouList(&list, 1);
	ShowCycDouList(&list);
	DeleteCycDouList(&list, 1);
	ShowCycDouList(&list);
	DeleteCycDouList(&list, 1);
	ShowCycDouList(&list);

}