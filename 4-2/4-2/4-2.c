//堆的相关操作

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//以顺序结构实现堆

//定义堆的结构
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;  //底层是数组
	int size;         //有效数据个数
	int capacity;     //内存空间的大小
}HP;

//堆的初始化---传堆的地址
void HeapInit(HP* php)
{
	//堆的地址不能为空
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//堆的销毁
void HeapDestory(HP* php)
{
	//堆的地址不能为空
	assert(php);
	if (php->arr)
	{
		free(php->arr);
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}

//交换函数
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向上调整算法
//child为新插入孩子结点的下标
void AdjustUp(HPDataType* arr, int child)
{
	//循环调整
	while (child > 0)
	{
		//求该孩子结点的父亲结点的下标
		int parent = (child - 1) / 2;
		//小堆: <  小堆找小
		//大堆: >  大堆找大
		if (arr[child] < arr[parent])
		{
			//交换
			Swap(&arr[child], &arr[parent]);
			//下标向上移
			child = parent;
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
	//怎么往堆中插入数据呢？
	//要插入数据得判断堆的内存是否足够吧？
	//判断空间是否足够
	if (php->size == php->capacity)
	{
		//判断capacity是否为空
		//若为空增加4个HPDataType大小的内存空间
		//若不为空，则2倍增容
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newcapacity * sizeof(HPDataType));
		//判断是否增容成功
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		//增容成功
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	//空间足够
	php->arr[php->size] = x;
	//插入数据后，要满足它仍然还是堆结构
	//所以需要向上调整数据，使得它仍然还是堆结构
	//调整是在数组中调整的，所以参数有数组
	//要知道新插入结点的下标，所以参数要有size
	AdjustUp(php->arr, php->size);
}

//判断堆中的有效数据是否为空
bool HeapEmpty(HP* php)
{
	//堆的地址不能为空
	assert(php);
	//当size为0时，说明堆中没有有效数据
	return php->size == 0;
}

//向下调整算法
//从第一个结点开始向下调整
void AdjustDown(HPDataType* arr, int parent, int n)
{
	//根据父结点的下标，找到它的子结点的下标
	int child = 2 * parent + 1;
	//数组下标不能越界，即child要小于有效数据个数n
	while (child < n)
	{
		//大堆：找子结点当中值最大的结点 大堆: <
		//小堆：找子结点当中值最小的结点 小堆: >
		if (arr[child] < arr[child + 1])
		{
			child++;
		}
		//调整 ---- 大堆: >    小堆: <  
		//右孩子结点的下标不能越界
		if (child + 1 < n && arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			//继续向下
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}	
	}
}

//出堆---删除堆顶的数据
void HeapPop(HP* php)
{
	//要删除数据，首先得要判断堆中的有效数据是否为空
	assert(!HeapEmpty(php));
	//交换堆底和堆顶的数据
	Swap(&php->arr[0], &php->arr[php->size]);
	//删除堆顶的数据
	php->size--;
	//调整数据---向下调整算法
	//调整是在数组中调整的，所以参数要有数组
	//由于是从第一个结点开始调整，所以要知道第一个结点的下标
	//另外还要清楚调整的总数据个数，所以参数要有size
	AdjustDown(php->arr, 0, php->size);
}

//打印堆的数据
void HeapPrint(HP* php)
{
	//堆的地址不能为空
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}


int main()
{
	HP ph;

	return 0;
}