#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
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
	//队列不能为空
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	//队列不能为空
	assert(!QueueEmpty(pq));
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

//*************************************8以上是队列的操作实现*******************************************
typedef struct
{
	//定义两个队列
	Queue q1;
	Queue q2;
} MyStack;

//初始化栈
MyStack* myStackCreate()
{
	//定义一个指针pst指向一个栈
	//为栈开辟一个栈大小的内存空间
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//初始化栈中的两个队列
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	//这里的函数的返回值为MyStack*
	//表明你要返回一个指向栈的指针，我们将定义好的指针给返回
	return pst;
}

//入栈 --- 往为空的队列中入数据
void myStackPush(MyStack* obj, int x)
{
	//判断哪个队列为空
	//判断队列是否为空，可以调用函数QueueEmpty
	//入队列调用函数QueuePush
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

//出栈 --- 将非空队列中的size-1个数据入队到一个空队列中，再将原非空队列的剩下数据给出出去
int myStackPop(MyStack* obj)
{
	//随机定义哪个队列为空
	//假设队列q1为空队列，队列q2为非空队列
	Queue* emp = &obj->q1;
	Queue* nonemp = &obj->q2;
	//假设错误，则调整
	if (QueueEmpty(&obj->q2))
	{
		emp = &obj->q2;
		nonemp = &obj->q1;
	}
	//现在知道哪个队列为空，哪个队列为非空了
	//假设nonemp中有size个数据，将nonemp中的size - 1个数据
	//入队到emp中，最后将那一个数据给出出去
	//只要还大于1，就不会停止往emp中入数据
	//获取队列中的有效数据个数可以调用函数 --- QueueSize
	while (QueueSize(nonemp) > 1)
	{
		//入数据
		//将nonemp的队头数据一个一个的入到空队列中
		//获取队列的队头数据 --- 调用函数QueueFront
		QueuePush(emp, QueueFront(nonemp));
		//出数据，将nonemp中的size-1个数据都销毁
		//为什么还要销毁nonemp中的数据呢？
		//既然要将nonemp中的数据导入到emp中，那就表明nonemp中不再有那些数据了
		//所以最后要删除数据，即出出去
		QueuePop(nonemp);
	}
	//代码运行到了这一行，说明nonemp中只有一个数据了
	//观察该函数的返回值为int，说明要将nonemp中的唯一数据返回
	//定义一个变量top来接收nonemp中唯一的数据
	int top = QueueFront(nonemp);
	//将nonemp中的数据出出去
	QueuePop(nonemp);
	//返回栈顶的数据
	return top;
}

//取栈顶的数据 --- 直接取非空队列的尾结点的数据
int myStackTop(MyStack* obj)
{
	//判断哪个对列为空
	//取队尾的数据可以调用函数 --- QueueBack
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

//判断栈是否为空
bool myStackEmpty(MyStack* obj)
{
	//怎么判断栈为空？
	//当队列q1为空，且队列q2也为空时，则表明栈为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//销毁栈的数据
void myStackFree(MyStack* obj)
{
	//将栈中的两个队列的数据给销毁
	//销毁队列的数据 --- 调用函数QueueDestory
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	//将为开辟栈的空间给释放掉
	free(obj);
	obj = NULL;
}
*/












