//复习栈的相关操作
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//栈的结构的定义
//与顺序表类似
typedef int STDataType;
typedef struct StackNode
{
	STDataType* arr;//底层是数组结构
	int top;//有效数据个数
	int capacity;//内存空间大小
}STNode;

//栈的初始化---传址调用
void StackInit(STNode* pst)
{
	assert(pst);
	//初始化
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

//入栈
void StackPush(STNode* pst, STDataType x)
{
	//增容
	if (pst->top == pst->capacity)
	{
		//判断capacity是否为0，为0就开辟4个字节的空间
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		//动态内存开辟
		STNode* tmp = (STNode*)realloc(pst->arr, newcapacity * sizeof(STNode));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//开辟成功
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}
	pst->arr[pst->top++] = x;
}

//判空
bool StackEmpty(STNode* pst)
{
	assert(pst);
	return pst->top == 0;
}

//出栈
void StackPop(STNode* pst)
{
	//判断栈是否为空
	assert(!StackEmpty(pst));
	pst->top--;
}

//取栈顶元素
STDataType StackTop(STNode* pst)
{
	assert(!StackEmpty(pst));
	return pst->arr[pst->top - 1];
}

//统计栈的元素个数
int StackSize(STNode* pst)
{
	return pst->top;
}

//销毁栈的数据
void StackDestory(STNode* pst)
{
	assert(pst);
	if (pst->arr)
	{
		free(pst->arr);
	}
	pst->top = pst->capacity = 0;
}

int main()
{
	STNode st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	STDataType top = StackTop(&st);
	printf("%d ", top);

	return 0;
}
*/


/*
//复习队列的相关操作
//定义结点的结构
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	//定义两个指针
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	//头尾指针均为NULL
	pq->phead = pq->ptail = NULL;
}

//入队---队尾
void QueuePush(Queue* pq, QDataType x)
{
	asseert(pq);
	//开辟内存空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//判断队列
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//出队---队头
void QueuePop(Queue* pq)
{
	//判空
	assert(!QueueEmpty(pq));
	//只有一个结点的情况
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//存储头结点的下一个结点
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//取队头的数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->ptail->data;
}

//统计队列中数据的个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* pcur = pq->phead;
	
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

//销毁列队的数据
void QueueDestory(Queue* pq)
{
	assert(pq);
	//遍历
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//置空
	pq->phead = pq->ptail = NULL;
}

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QDataType head = QueueFront(&q);
	QDataType tail = QueueBack(&q);
	printf("%d ", head);
	printf("%d ", tail);
	QueueDestory(&q);

	return 0;
}
*/

int main()
{
	int arr[100] = { 0 };
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

//void PrintTopK(int k);



#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define N 20
int main()
{

	int a[N] = { 0 }, b[N] = { 0 };
	int i, j, k, anum, bnum, c[N + N];
	scanf("%d", &anum);   //输入数组a元素个数
	for (i = 0; i < anum; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &bnum);   //输入数组b元素个数
	for (i = 0; i < bnum; i++)
	{
		scanf("%d", &b[i]);
	}
	/***** 在数组a和b都有数据时比较两个数组 *****/
	/********** Begin *********/
	int* pa = &a[0];
	int* pb = &b[0];
	j = 1;
	k = 1;

	while (j < anum && k < bnum)
	{
		if (*pa > *pb)
		{
			printf("%d ", *pb);
			pb++;
			k++;
		}
		else
		{
			printf("%d ", *pa);
			pa++;
			j++;
		}
	}

	if (j < anum)
	{
		for (; j < anum; j++)
		{
			printf("%d ", pa[j]);
		}
	}
	else
	{
		for (; k < bnum; k++)
		{
			printf("%d ", pb[k]);
		}
	}

	return 0;
}