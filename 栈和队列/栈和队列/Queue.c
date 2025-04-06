/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	return pq->ptail->data;
}

//获取队列中有效数据个数
int QueueSize(Queue* pq)
{
	assert(pq);
	//定义一个变量size来统计队列的有效数据个数
	int size = 0;
	//定义一个指针pcur来遍历队列
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
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

int main()
{
	//定义一个指向队列的指针
	Queue* q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueDestory(&q);

	return 0;
}
*/