#include "SeqList.h"

//结构体的初始化
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//打印顺序表中的数据
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

void SLCheckCapacity(SL* sl)
{
	//判断是否需要增容
	if (sl->size == sl->capacity)
	{
		//判断是否有内存，即capacity是否为0
		int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
		//将realloc强制类型转换为与指针相同的类型，方便tmp指针接收
		//realloc的两个参数分别为要增容空间的起始地址，需要增多大的字节内存空间
		//千万不要直接用sl->arr去接收动态内存成功开辟后返回来的地址
		//避免动态内存开辟失败后，返回NULL，将指向原来空间的指针赋为NULL
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
		//判断是否成功申请开辟内存空间
		//如果没有就把错误信息打印出来，然后直接退出整个程序
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		sl->arr = tmp;
		sl->capacity = newcapacity;
	}
}

//尾插
void SLPushBack(SL* sl, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	sl->arr[sl->size++] = x;
}

//头插
void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > 0; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[0] = x;
	sl->size++;
}

//尾删
void SLPopBack(SL* sl)
{
	//断言sl指针是否为NULL；
	//删除数据需要考虑一种特殊情况，就是没有数据
	//所以要判断是否有效数据是否为0，也就是sl->size是否为0
	assert(sl && sl->size);
	sl->size--;
}

//头删
void SLPopFront(SL* sl)
{

	//断言sl指针是否为NULL；
	//删除数据需要考虑一种特殊情况，就是没有数据
	//所以要判断是否有效数据是否为0，也就是sl->size是否为0
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//指定位置pos前插入数据
void SLInsiteFront(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > pos; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
	sl->size++;
}

//指定位置pos后插入数据
void SLInsiteBack(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > pos + 1; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos + 1] = x;
	sl->size++;
}

//指定位置pos处删除数据
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	for (int i = pos; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//查找数据
int SLFind(SL* sl, SLDataType x)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//销毁
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->size = sl->capacity = 0;
}


