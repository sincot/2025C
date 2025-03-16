/*
void rotate(int* nums, int numSize, int k)
{
	k %= numSize;
	while (k--)
	{
		int tmp = nums[numSize - 1];
		for (int i = numSize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tmp;
	}
}
*/

/*
void rotate(int* nums, int numsSize, int k)
{
	//创建新数组
	int newnums[numsSize] = { 0 };
	//向右轮转k次，将结果保存在临时数组中
	for (int i = 0; i < numsSize; i++)
	{
		newnums[(i + k) % numsSize] = nums[i];
	}
	//降临时数组中的数据拷贝到原数组中
	memmove(nums, newnums);
}
*/

/*
//逆置函数
void reverse(int* nums, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k) {

	k %= numsSize;
	reverse(nums, numsSize - k);
	reverse(nums + numsSize - k, k);
	reverse(nums, numsSize);

}
*/

/*
//静态顺序表
typedef int SLDataType;//给int重命名，方便之后操做其它类型的数据
#define N 6
typedef struct SeqList
{
	SLDataType a[N];   //定长数组
	int size;          //有效数据个数
}SL;
*/

/*
//动态顺序表----底层的数组空间在不断变化，空间不够可增容
typedef int SLDataType;//给int重命名，方便之后操做其它类型的数据
typedef struct SeqList
{
	SLDataType* a;
	int size;          //有效数据个数
	int capacity;      //空间容量  
};
*/


/*
//顺序表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化
void* SLInit(SL* sl)
{
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//增容函数
void SLCheckCapacity(SL* sl)
{
	if (sl->capacity == sl->size)
	{
		//判断数组中是否有内存空间
		int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
		//开辟的内存空间的单位是字节
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
	//判断是否要增容
	SLCheckCapacity(sl);
	sl->arr[sl->size] = x;
	sl->size++;
}

//头插
void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
	//判断是否要增容
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
	//sl:限制参数不能直接给NULL
	//sl->size:顺序表为空
	assert(sl && sl->size);
	sl->size--;
}

//头删
void SLPopFront(SL* sl)
{
	//sl:限制参数不能直接给NULL
	//sl->size:顺序表为空
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//打印顺序表
void SLPrint(SL* sl)
{
	int i = 0;
	for (i = 0; i < sl->size; i++)
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
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

	return 0;
}
*/

