//堆的相关操作
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//以顺序结构实现堆
/*
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
	php->size++;
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
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		//调整 ---- 大堆: >    小堆: <  
		//右孩子结点的下标不能越界
		if (arr[child] < arr[parent])
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
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	//删除堆顶的数据
	php->size--;
	//调整数据---向下调整算法
	//调整是在数组中调整的，所以参数要有数组
	//由于是从第一个结点开始调整，所以要知道第一个结点的下标
	//另外还要清楚调整的总数据个数，所以参数要有size
	AdjustDown(php->arr, 0, php->size);
}

//取堆顶数据
HPDataType HeapTop(HP* php)
{
	//堆的地址不能为空
	assert(php);
	//堆顶的数据就是数组下标为0的数据
	return php->arr[0];
}

//打印堆的数据
void HeapPrint(HP* php)
{
	//堆的地址不能为空
	//assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

//频繁取堆顶数据，然后再将堆顶的数据删除
void test1()
{
	HP hp;
	HeapInit(&hp);

	HeapPush(&hp, 56);
	HeapPush(&hp, 10);
	HeapPush(&hp, 15);
	HeapPush(&hp, 30);
	HeapPrint(&hp);

	while (!HeapEmpty(&hp))
	{
		int top = HeapTop(&hp);
		printf("%d ", top);
		HeapPop(&hp);
	}
	HeapDestory(&hp);
}
*/

/*
//交换函数
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向下调整算法
//从第一个结点开始向下调整
void AdjustDown(int* arr, int parent, int n)
{
	//根据父结点的下标，找到它的子结点的下标
	int child = 2 * parent + 1;
	//数组下标不能越界，即child要小于有效数据个数n
	while (child < n)
	{
		//大堆：找子结点当中值最大的结点 大堆: <
		//小堆：找子结点当中值最小的结点 小堆: >
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		//调整 ---- 大堆: >    小堆: <  
		//右孩子结点的下标不能越界
		if (arr[child] > arr[parent])
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

//向上调整算法
void AdjustUp(int* arr, int child)
{
	//循环调整
	while (child > 0)
	{
		//求该孩子结点的父亲结点的下标
		int parent = (child - 1) / 2;
		//小堆: <  小堆找小
		//大堆: >  大堆找大
		if (arr[child] > arr[parent])
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

//堆排序 --- 运用堆的思想来排序
void HeapSort(int* arr, int n)
{
	
	//第一步： 建堆 --- 向下调整建堆
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
		//AdjustDown(arr, i, n);
	//}
	

	//第一步： 建堆 --- 向上调整建堆
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}

	//第二步：  将堆顶的数据和最后一个数据交换位置
	//然后再减减size，再向下调整堆，重复上述的步骤
	int end = n - 1;
	while (end > 0)
	{
		//将堆顶的数据和最后一个数据交换位置
		Swap(&arr[0], &arr[end]);
		//再向下调整堆
		AdjustDown(arr, 0, end);
		//再减减
		end--;
	}
}

int main()
{
	//test1();
	int arr[6] = { 19, 15, 20, 17, 13, 10 };
	HeapSort(arr, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/


/*
//TOP-K问题
//产生数据
void CreatNData()
{
	//造数据---造10万个数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, 'w');
	if (fin == NULL)
	{
		perror("fopen");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		//产生随机数---产生0~1000000的数字
		int x = (rand() + i) % 1000000;
		//将它们存入文件中
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

//向下调整算法
//从第一个结点开始向下调整
void AdjustDown(int* arr, int parent, int n)
{
	//根据父结点的下标，找到它的子结点的下标
	int child = 2 * parent + 1;
	//数组下标不能越界，即child要小于有效数据个数n
	while (child < n)
	{
		//大堆：找子结点当中值最大的结点 大堆: <
		//小堆：找子结点当中值最小的结点 小堆: >
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		//调整 ---- 大堆: >    小堆: <  
		//右孩子结点的下标不能越界
		if (arr[child] < arr[parent])
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

void TOP_K()
{
	//规定要求取几个数据
	int k = 0;
	printf("请输入K：");
	scanf("%d", &k);

	//在该代码路径下创建一个文件data.txt
	//该指针不能被修改，所以用const来修饰，更安全一些
	const char* file = "data.txt"; 
	//往data.txt文件中读数据
	FILE* fout = fopen(file, "r");
	//判断文件是否打开成功
	if (fout == NULL)
	{
		perror("fopen");
		exit(1);
	}
	//找最大的前K个数据，建小堆
	//动态开辟一个数组来存储前K个数据
	int* minHeap = (int*)malloc(sizeof(int) * k);
	//判断空间开辟是否成功
	if (minHeap == NULL)
	{
		perror("malloc");
		exit(2);
	}
	//读取文件的数据，文件的读取用fscanf
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//目前minHeap并不是堆结构
	//接下来向下调整建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		//调用AdjustDown函数
		AdjustDown(minHeap, i, k);
	}
	//遍历剩下的n - k个数据，跟堆顶相比较
	//数据大的替换堆顶元素
	
	//定义一个变量存储读取到的数据
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//让x与minHeap中的堆顶数据进行比较
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			//替换完毕之后，向下调整，使之成为堆结构
			AdjustDown(minHeap, 0, k);
		}
	}
	//已经遍历完了剩下的n-k个数据
	//前k个数据已经是n个数据中最大的
	//打印这前k个数据
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}

	//关闭文件
	fclose(fout);
}
*/


//链式结构的二叉树

//定义链式结构的二叉树
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;