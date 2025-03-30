#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;
}Queue;

//定义两个Queue（队列）
typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

//入队--队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//队列不为空
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//出队--队头
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

//取队头数据
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

//队列的销毁
void QueueDeatory(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
}

//队列中的有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

//*****************队列结构是实现方式********************************

//结构体的初始化
MyStack* myStackCreate()
{
	//定义一个指针pst
	//向操作系统申请栈大小的内存空间
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//对当前栈结构中的两个队列q1和q2进行初始化
	//队列初始化直接调用函数QueueInit
	//QueueInit的参数是地址，所以要取地址
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

//入栈
void myStackPush(MyStack* obj, int x)
{
	//往不为空的队列中插入数据
	//先判断哪个队列为空，再将数据插入不为空的队列
	//判断队列是否为空可以调用函数QueueEmpty
	if (!QueueEmpty(&obj->q1))//若q1队列不为空，则往q1队列中插入数据
	{
		//入队操作可以调用函数QueuePush
		QueuePush(&obj->q1, x);
	}
	else//若q2队列不为空，则往q2队列中插入数据
	{
		QueuePush(&obj->q2, x);
	}
}

//出栈
int myStackPop(MyStack* obj)
{
	//把不为空队列前的size - 1个数据挪到另一个队列中，再将最后一个数据出队
	//判断哪个队列为空，我们先假设q1队列为空，q2队列不为空
	Queue* emp = &obj->q1;
	Queue* nonemp = &obj->q2;
	//若假设错误，再及时调整
	//发现q2才是空列表
	if (QueueEmpty(&obj->q2))
	{
		emp = &obj->q2;
		nonemp = &obj->q1;
	}
	//获取非空队列中有效元素的个数可以调用函数QueueSize
	//若非空队列中的有效数据个数大于一
	//则需要将非空队列的前size-1个数据挪到空队列中再将最后一个数据出队
	//若非空队列的有效数据个数为一，则不用挪动数据，直接将该数据出队即可
	while (QueueSize(nonemp) > 1)
	{
		//挪数据，取非空队列的队头，再将该数据入队到空队列中
		//取队头的数据可以调用函数QueueFront
		//入队可以调用函数QueuePush
		QueuePush(emp, QueueFront(nonemp));
		//再将队头的数据出出来，也就是要把队头的数据销毁
		//出队可以调用函数QueuePop
		QueuePop(nonemp);
	}
	//跳出循环，说明非空队列中只剩下一个数据
	//可以直接取队头的数据了
	//定义一个变量来接收队头数据的返回值
	int top = QueueFront(nonemp);
	//将这唯一的数据再出出去
	QueuePop(nonemp);
	return top;
}

//取栈顶数据
int myStackTop(MyStack* obj)
{
	//取非空队列中尾结点的数据
	//判断哪个队列为空,哪个队列不为空，就取哪个队列队尾的数据
	if (!QueueEmpty(&obj->q1))
	{
		//直接取队尾操作,调用函数QueueBack
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
    //当q1队列为空,q2队列也为空时，可说明栈为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//销毁
void myStackFree(MyStack* obj)
{
	//先销毁队列的内存空间，直接调用函数QueueDestory
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	//再销毁栈的内存空间
	free(obj);
	obj = NULL;
}
*/


//定义栈的结构
typedef char STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top++] = x;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//出栈
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	ps->top--;
}

//读取栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

//获取栈中有效元素个数
STDataType StackSize(ST* ps)
{
	return ps->top;
}

//销毁栈中的数据
void StackDestory(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->top = ps->capacity = 0;
}



typedef struct
{
	//定义两个栈pushST和popST
	ST pushST;
	ST popST;
} MyQueue;

//队列的初始化
MyQueue* myQueueCreate()
{
	//向操作系统申请队列大小的空间
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	//对栈进行初始化操作，可以调用函数StackInit
	StackInit(&pq->pushST);
	StackInit(&pq->popST);

	return pq;
}

//入队
void myQueuePush(MyQueue* obj, int x)
{
	//直接往pushST中插入数据
	//入栈操作可以调用函数StackPush
	StackPush(&obj->pushST, x);
}

//出队
int myQueuePop(MyQueue* obj)
{
	//要分情况popST为空时，popST不为空时
	//判断栈是否为空,可以调用函数StackEmpty
	//若popST为空，需要将pushST中的数据全部存储到popST中
	// 然后再出popST栈顶的数据
	//出栈操作可以调用函数StackPop
	if (StackEmpty(&obj->popST))
	{
		//挪数据
		//判断pushST是否为空
		//不为空则循环挪动数据
		while (!StackEmpty(&obj->pushST))
		{
			//将pushST中的栈顶数据入到popST中
			StackPush(&obj->popST, StackTop(&obj->pushST));
			//再将pushST中的栈顶数据删除，也就是出数据
			//出栈操作直接调用函数StackPop
			StackPop(&obj->pushST);
		}
	}
	//没有进入if，说明popST不为空，则直接取popST的栈顶数据
	//先将popST的栈顶数据存储起来，用于作为返回值
	//因为之后还会删除popST的栈顶的数据
	//取栈顶数据可以调用函数StackTop
	int top = StackTop(&obj->popST);
	//删除栈顶数据，也就是执行出栈操作,调用函数STackPop
	StackPop(&obj->popST);

	return top;
}

//取队头数据
int myQueuePeek(MyQueue* obj)
{
	//逻辑同出队操作
	//要分情况popST为空时，popST不为空时
	//判断栈是否为空,可以调用函数StackEmpty
	//若popST为空，需要将pushST中的数据全部存储到popST中
	//然后再出popST栈顶的数据
	//出栈操作可以调用函数StackPop
	if (StackEmpty(&obj->popST))
	{
		//挪数据
		//判断pushST是否为空,不为空则循环挪动数据
		while (!StackEmpty(&obj->pushST))
		{
			//将pushST中的栈顶数据入到popST中
			StackPush(&obj->popST, StackTop(&obj->pushST));
			//再将pushST中的栈顶数据删除，也就是出数据
			//出栈操作直接调用函数StackPop
			StackPop(&obj->pushST);
		}
	}
	//没有进入if，说明popST不为空，则直接取popST的栈顶数据
	//取栈顶数据可以调用函数StackTop
	return StackTop(&obj->popST);
}

//判断队列是否为空
bool myQueueEmpty(MyQueue* obj)
{
	//要判断队列是否为空，则要判断两个栈pushST和popST是否为空
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

//销毁队列
void myQueueFree(MyQueue* obj)
{
	//销毁队列的内存空间
	//首先将定义的两栈进行销毁，可以调用函数StackDestory
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);
    //释放队列的内存空间
	free(obj);
	obj = NULL;
}


//孩子兄弟表示法
struct TreeNode
{
	struct Node* child;    //左边开始的第一个孩子结点
	struct Node* brother;  //指向其右边的下一个兄弟结点  
	int data;              //结点中的数据域
};