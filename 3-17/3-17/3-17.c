#define _CRT_SECURE_NO_WARNINGS

//顺序表
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
*/
/*
//定义结构体
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//增容函数
void SLCheckCapacity(SL* sl)
{
	assert(sl);
	
	if (sl->size == sl->capacity)
	{
	    int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
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
	sl->arr[sl->size] = x;
	sl->size++;
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
	assert(sl && sl->size);
	sl->size--;
}

//头删
void SLPopFront(SL* sl)
{
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//指定位置前插入数据
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

//指定位置后插入数据
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

//指定位置删除数据
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	for (int i = pos; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//销毁
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//打印
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPopBack(&sl);
	SLPopFront(&sl);

	return 0;
}
*/

/*
int removeElement(int* nums, int numsSize, int val)
{
	int dst = 0;
	int src = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			dst++;
		}
		src++;
	}
	return dst;
}
*/

/*
int removeDuplicates(int* nums, int numsSize)
{
	int dst = 0;
	int src = dst + 1;

	while (src < numsSize)
	{
		if (nums[src] != nums[dst])
		{
			dst++;
			if (dst == src)
			{
				nums[dst] = nums[src];
			}
			
		}
		src++;
	}

	return dst + 1;
}
*/






#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//定义结构体
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化顺序表
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//增容函数
void SLCheckCapacity(SL* sl)
{
	assert(sl);
	if (sl->size == sl->capacity)
	{
		//检查是否有空间
		int newcapacity = sl->capacity == 0 ? 4 : 2 * sl->capacity;
		//检查是否要增容
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
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
		sl->arr[i] = sl->arr[i - 1];;
	}
	sl->arr[0] = x;
	sl->size++;
}

//尾删
void SLPopback(SL* sl)
{
	assert(sl && sl->size);
	sl->size--;
}

//头删
void SLPopFront(SL* sl)
{
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//指定位置前插入
void SLInsertFront(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(&sl);
	for (int i = sl->size; i < pos; i++)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
	sl->size++;
}

//指定位置后插入
void SLInsertBack(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(&sl);
	for (int i = sl->size; i > pos + 1; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos + 1] = x;
}

//指定位置删除
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	SLCheckCapacity(&sl);
	for (int i = pos; i > sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//销毁
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//打印
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i > sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

int main()
{
	SL sl;
	SLPushBack(&sl, 1);
	
	return 0;
}
