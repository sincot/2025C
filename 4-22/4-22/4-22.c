#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/*
//创建N个随机数，写入到文件中
void CreateData()
{
	//造数据，再多少自己定，这里为了方便观察，造100个数据
	int n = 100;

	//生成随机数种子
	srand(time(0));

	//创建一个文件，文件名为data.txt
	const char* file = "data.txt";

	//以写的方式打开文件
	FILE* fin = fopen(file, "w");

	//判断文件是否打开成功
	if (fin == NULL)
	{
		perror("fopen file fail!");
		exit(1);
	}

	//造n个随机数
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;

		//往文件中输入该随机数
		fprintf(fin, "%d\n", x);
	}

	//关闭文件
	fclose(fin);
}

int CompareInt(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

//返回实际读取到的数据个数，没有数据返回0
//为了避免每次读取数据时，都要打开数据源文件，在这里传指向源文件的指针
int ReadNDataSortToFile(FILE* fout, int n, const char* dstfile)
{
	//创建一个内存空间大小为n个int整型的数组
	int x = 0;
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		perror("malloc error!");
		return 0;
	}

	//读取n个数据
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		//从之前打开的文件中读取数据
		//判断是否能够读取到n个数据，即判断fscanf是否读取到EOF
		if (fscanf(fout, "%d", &x) == EOF)
		{
			break;
		}
		arr[j++] = x;
	}

	//使用函数qsort来排序
	//判断j是否为0，即是否读取到了数据，若一个数据都没有读取到，那么就没必要排序了
	if (j == 0)
	{
		free(arr);
		return 0;
	}
	qsort(arr, j, sizeof(int), CompareInt);

	//以写的方式打开dstfile文件
	FILE* fin = fopen(dstfile, "w");
	if (fin == NULL)
	{
		free(arr);
		perror("fopen dstfile fail!");
		return 0;
	}

	//将排序好的数据写入文件dstfile
	for (int i = 0; i < j; i++)
	{
		fprintf(fin, "%d\n", arr[i]);
	}

	free(arr);
	fclose(fin);

	return j;
}

//创建一个函数，用来将文件file1与文件file2，归并到文件mfile中
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//以读的方式打开文件flie1
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		perror("fopen file1 fail!");
		exit(4);
	}

	//以读的方式打开文件flie2
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		perror("fopen file2 fail!");
		exit(5);
	}

	//以写的方式打开文件mflie
	FILE* mfin = fopen(mfile, "w");
	if (mfin == NULL)
	{
		perror("fopen mfile fail!");
		exit(6);
	}

	//归并
	int x1 = 0;
	int x2 = 0;
	int ret1 = fscanf(fout1, "%d", &x1);
	int ret2 = fscanf(fout2, "%d", &x2);
	//读取到的数据不能为EOF
	while (ret1 != EOF && ret2 != EOF)
	{
		if (x1 < x2)
		{
			//往mfile文件中写入x1与x2中的较小值
			fprintf(mfin, "%d\n", x1);
			ret1 = fscanf(fout1, "%d", &x1);
		}
		else
		{
			fprintf(mfin, "%d\n", x2);
			ret2 = fscanf(fout2, "%d", &x2);
		}
	}

	//处理剩余的数据
	while (ret1 != EOF)
	{
		fprintf(mfin, "%d\n", x1);
		ret1 = fscanf(fout1, "%d", &x1);
	}

	while (ret2 != EOF)
	{
		fprintf(mfin, "%d\n", x2);
		ret2 = fscanf(fout2, "%d", &x2);
	}
	//关闭文件file1,file2,mfile
	fclose(fout1);
	fclose(fout2);
	fclose(mfin);
}

int main()
{
	CreateData();

	//生成3个文件,file1,flie2,mflie
	const char* file1 = "file1.txt";
	const char* file2 = "file2.txt";
	const char* mfile = "mfile.txt";

	//以读的方式打开文件data.txt
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen data.txt fail!");
		exit(3);
	}

	//每次读10个数据
	ReadNDataSortToFile(fout, 10, file1);
	ReadNDataSortToFile(fout, 10, file2);

	//循环归并
	while (1)
	{
		MergeFile(file1, file2, mfile);

		//删除文件file1与file2 --- 使用函数remove
		remove(file1);
		remove(file2);

		//将文件mfile重命名为file1 --- 使用函数rename
		rename(mfile, file1);

		//每次都读取10个数据
		//判断文件data.txt中是否还有数据
		//没有数据了，说明文件归并结束，归并好的数据在文件file1中
		if (ReadNDataSortToFile(fout, 10, file2) == 0)
		{
			break;
		}
	}

	fclose(fout);
	return 0;
}
*/

/*
//计数排序
void CountSort(int* arr, int n)
{
	//找当前序列的最大值与最小值
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
        
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	//确定新建数组的大小
	int range = max - min + 1;
	int *count = (int*)malloc(sizeof(int) * range);
	if(count == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	//初始化新建数组 --- 使用函数memset，将数组全部初始化为0
	memset(count, 0, sizeof(int) * range);

	//统计相同元素出现的次数
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;  //arr[i] - min 代表下标
	}

	//将count数组中的数据还原到原数组
	int index = 0;  //原数组下标的索引
	
	//遍历count数组
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
}

int main()
{
	int arr[] = { 101, 108, 108, 103, 101, 105, 101 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	CountSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/

//非递归版本的快速排序 --- 队列

//定义链表的结点的结构
typedef int QDataType;
typedef struct QueueListNode
{
	QDataType data;//链表的结点所存储的数据
	struct QueueListNode* next; //指向下一个结点的指针
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	QueueNode* phead; //指向头结点的指针
	QueueNode* ptail; //指向尾结点的指针
}Queue;

//队列的初始化
void QueueInit(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	//将两个指针置为空
	pq->phead = pq->ptail = NULL;
}

//入队
void QueuePush(Queue* pq, QDataType x)
{
	//队列的地址不能为空
	assert(pq);
	//为将要插入的结点开辟内存空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;
	//若队列中数据为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//若队列中数据不为空
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//判断队列中是否为空
bool QueueEmpty(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	return pq->phead == NULL;
}

//出队列
void QueuePop(Queue* pq)
{
	//队列中是否为空
	assert(!QueueEmpty(pq));
	//若队列中只有一个结点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//定义一个指针next将头结点的下一结点存储起来
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	return pq->phead->data;
}

//销毁队列的数据
void QueueDestory(Queue* pq)
{
	assert(pq);
	//定义一个指针pcur来遍历队列
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		//定义一个指针next将下一个结点的地址存储起来
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//队列中的数据销毁后，将队列中的两个指针都置为NULL
	pq->phead = pq->ptail = NULL;
}

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void QuickSortQueue(int* arr, int left, int right)
{
	//创建一个队列
	Queue q;

	//初始化队列
	QueueInit(&q);

	//入队列
	QueuePush(&q, left);
	QueuePush(&q, right);

	//只要队列中的数据不为0，就不会停止排序
	while (!QueueEmpty(&q))
	{
		//取两次队头的数据
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);

		//获取待排序的序列的左右下标 [begin , end]
		//使用lomuto前后指针来找基准值
		int key = begin;
		int front = begin;
		int rear = begin + 1;

		while (rear <= end)
		{
			if (arr[rear] < arr[key] && front++ != rear)
			{
				Swap(&arr[front], &arr[rear]);
			}

			rear++;
		}

		Swap(&arr[key], &arr[front]);
		key = front;

		// begin key end
		//处理左子序列与右子序列
		if (begin < key - 1)
		{
			//入队列
			QueuePush(&q, begin);
			QueuePush(&q, key - 1);
		}

		if (key + 1 < end)
		{
			//入队列
			QueuePush(&q, key + 1);
			QueuePush(&q, end);
		}
	}

	//销毁队列
	QueueDestory(&q);
}

int main()
{
	int arr[] = { 4, 2, 9, 3, 8, 6, 5, 1, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSortQueue(arr, 0, size - 1);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}