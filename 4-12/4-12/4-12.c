#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
//定义堆的结构
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;    //是使用数组来实现的
	int size;           //有效数据个数
	int capacity;       //内存空间的大小
}HP;

//堆的初始化
void HeapInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//交换数据
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* arr, int child)
{
	//不断的向上调整，直到child走到根结点时，就停止调整
	while (child > 0)
	{
		//已知孩子结点的下标，求其父结点的下标
		//父结点的下标 = （ 孩子结点的下标 - 1 ） /  2
		int parent = (child - 1) / 2;

		//建小堆：大的数据往下放，小的数据往上放，即arr[child] < arr[parent]时，需要调整
		//建大堆：大的数据往上放，小堆数据往下放，即arr[child] > arr[parent]时，需要调整
		if (arr[child] < arr[parent])
		{
			//孩子结点的数据与其父结点的数据进行交换
			Swap(&arr[child], &arr[parent]);

			//继续往上调整
			child = parent;
		}
		else
		{
			break;
		}
	}
}

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n)
{
	//由父结点的下标求其子结点的下标
	//子结点的下标 = （ 其父结点的下标 - 1 ）/ 2
	int child = 2 * parent + 1;

	//只要child不越界，就不会停止调整
	while (child < n)
	{
		//建小堆：求取父结点的子结点中值为最小的 即 arr[child] > arr[child + 1]
		//建大堆：求取父结点的子结点中值为最大的 即 arr[child] < arr[child + 1]
		//万一某个父结点只有一个孩子结点呢？那么child + 1后就会越界，所以需要特别处理
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}

		//将下标为child的结点与下标为parent的结点的值进行比较
		//建小堆：大的数据往下放，小的数据往上放，即arr[child] < arr[parent]时，需要调整
		//建大堆：大的数据往上放，小堆数据往下放，即arr[child] > arr[parent]时，需要调整
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);

			//继续向下调整
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//往堆中插入数据
void HeapPush(HP* php, HPDataType x)
{
	//堆的地址不能为空
	assert(php);

	//判断堆是否需要增容
	//如何判断？当有效数据个数size等于内存空间的大小capacity时，需要增容
	if (php->size == php->capacity)
	{
		//判断capacity是否为0
		//若为0，则赋值为4；若不为0，赋值为原来的两倍
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;

		//为数组开辟newcapcity个大小为sizeof(HP)的内存空间
		HP* tmp = (HP*)realloc(php->arr, sizeof(HP) * newcapacity);

		//判断内存是否开辟成功
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	
	//将数据x插入堆中
	php->arr[php->size] = x;

	//向上调整算法
	AdjustUp(php->arr, php->size);

	//最后有效数据个数size要++
	php->size++;
}

//判断堆中的数据是否为空
bool HeapEmpty(HP* php)
{
	//堆的地址不能为空
	assert(php);

	//当有效数据个数size等于0时，可以表明堆中的数据为空
	return php->size == 0;
}

//出堆 --- 出堆顶的数据
void HeapPop(HP* php)
{
	//判断堆中的元素是否为空
	assert(!HeapEmpty(php));

	//将堆顶的数据与堆尾的数据进行交换
	Swap(&php->arr[0], &php->arr[php->size - 1]);

	//交换完毕后，再将有效数据个数减1，即可将堆顶的数据删除
	php->size--;

	//向下调整算法，使非堆结构变为堆结构
	//对数组进行操作，所以参数有arr
	//由于是向下调整，所以是从根结点的开始，故需要知道根结点的下标
	//需要知道结点的有效数据个数才能避免越界访问
	AdjustDown(php->arr, 0, php->size);
}

//取堆顶数据
HPDataType HeapTop(HP* php)
{
	//堆中的有效数据个数不能为0
	assert(!HeapEmpty(php));

	//直接将数组下标为0的结点的值返回
	return php->arr[0];
}

//销毁堆中的数据
void HeapDestory(HP* php)
{
	assert(php);
	if (php->arr)
	{
		free(php->arr);
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}

int main()
{
	HP hp;
	HeapInit(&hp);

	HeapPush(&hp, 5);
	HeapPush(&hp, 20);
	HeapPush(&hp, 10);
	HeapPush(&hp, 25);
	HeapPush(&hp, 27);
	HeapPush(&hp, 30);
	HPDataType top = HeapTop(&hp);
	printf("%d ", top);

	return 0;
}
*/

/*
//直接插入排序
void InsertSort(int* arr, int n)
{
	//循环遍历插入
	for (int i = 0; i < n - 1; i++)
	{
		//定义一个变量end始终指向有序序列的最后一项
		int end = i;

		//再定义一个变量tmp保存end + 1的值
		//这个值就是将要插入至有序序列的数据
		int tmp = arr[end + 1];

		//循环遍历有序序列
		while (end >= 0)
		{
			//在有序序列中找比tmp值大的数据
			//而有序序列中的数据的下标从end开始
			//若找到了比tmp还要大的数据
			//将其往后移，即将下标为end的数据移动至下标为end + 1的位置处
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}

		arr[end + 1] = tmp;
	}	
}
*/

int main()
{
	int arr[] = { 3, 5, 9, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("排序前: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	InsertSort(arr, n);
	
	printf("排序后：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}