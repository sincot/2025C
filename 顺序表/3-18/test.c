#include "SeqList.h"


int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushFront(&sl, 0);
	SLPopBack(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLInsiteFront(&sl, 1, 5);
	SLInsiteBack(&sl, 1, 6);
	SLDelete(&sl, 1);
	int ret = SLFind(&sl, 6);
	if (ret >= 0)
	{
		printf("找到了，下标是%d\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	//SLPrint(&sl);

	return 0;
}


