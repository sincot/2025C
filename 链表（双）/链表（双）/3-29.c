/*
#include "List.h"

//头结点的初始化

void LTInit(LTNode** pphead)
{
	//传过来的地址不能为NULL
	assert(pphead);
	//赋无效值
	*pphead = LTBuyNode(-1);
}


LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//销毁链表的数据（传值调用）
LTNode* LTDestory(LTNode* phead)
{
	//链表不能为空
	assert(phead);
	//创建指针pcur遍历链表
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		//创建next指针存储pcur的下一个结点的地址
		LTNode* next = pcur->next;
		//将pcur所指向的结点的空间释放掉
		free(pcur);
		pcur = next;
	}
	//跳出循环，说明已经到了头结点
	free(phead);
	phead = NULL;

	return phead;
}

int main()
{
	LTNode* plist = LTInit(-1);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushFront(plist, 100);
	LTDestory(plist);
	plist = NULL;

	return 0;
}
*/


//栈

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
//定义栈的结构
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//指向栈顶的位置
	int capacity;//栈的容量
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
	//传过来的地址不能为NULL
	assert(ps);
	//判断空间是否足够
	if (ps->top == ps->capacity)
	{
		//判断内存是否为0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//创建一个临时指针来接收新开辟的内存所返回的地址
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		//若增容失败
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//增容成功
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//插入数据
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
	//出栈，只需要有效数据个数减少一个即可
	ps->top--;
}

//读取栈顶的数据
STDataType StackTop(ST* ps)
{
	//判断栈是否为空
	assert(!StackEmpty(ps));
	//返回栈顶的数据
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

int main()
{
	//定义一个结点
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	STDataType top = StackTop(&st);
	printf("%d", top);

	return 0;
}
*/



/*
//定义栈的结构
typedef char STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//指向栈顶的位置
	int capacity;//栈的容量
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
	//传过来的地址不能为NULL
	assert(ps);
	//判断空间是否足够
	if (ps->top == ps->capacity)
	{
		//判断内存是否为0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//创建一个临时指针来接收新开辟的内存所返回的地址
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		//若增容失败
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//增容成功
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//插入数据
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
	//出栈，只需要有效数据个数减少一个即可
	ps->top--;
}

//读取栈顶的数据
STDataType StackTop(ST* ps)
{
	//判断栈是否为空
	assert(!StackEmpty(ps));
	//返回栈顶的数据
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

//**************************************以上是栈的实现代码***************************************

bool isValid(char* s)
{
	//定义一个结构体
	ST st;
	StackInit(&st);
	//具体的操作
	//定义一个指针变量来遍历字符串
	char* pi = s;
	while (*pi != '\0')
	{
		//左括号入栈
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		else
		{
			//判断栈顶是否为空,当只有一个有括号的时候可能出项该情况
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}
			//遇到右括号，取栈顶的元素与*pi相匹配
			//取栈顶数据
			STDataType top = StackTop(&st);
			if ((top == '(' && *pi == ')') || (top == '[' && *pi == ']') || (top == '{' && *pi == '}'))
			{
				StackPop(&st);
			}
			else
			{
				StackDestory(&st);
				return false;
			}
		}
		pi++;
	}
	//若都一一匹配了，那么栈最后一定为空
	//也有可能存在字符串中只有一个元素的情况
	//这样会导致栈不为空，且跳出了循环
	//所以要判断栈是否为空，可以用三目运算符表示
	//为空返回true，不为空返回false
	bool ret = StackEmpty(&st) ? true : false;
	StackDestory(&st);
	return ret;
}
*/

//队列
/*
//队列结点的结构
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

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	//队列中的两个结构体成员
	//都置为NULL，表明它是一个空队列
	pq->phead = pq->ptail = NULL;
}

//入队--队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//为插入的数据开辟结点空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
    //初始化newnode空间
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	//怎么判断队列为空---队列的头结点为空
	if (pq->phead == NULL)
	{
		//此时newnode即为尾结点也为头结点
		pq->phead = pq->ptail = newnode;
	}
	//队列不为空
	else
	{
		//直接往尾结点的后面插入
		pq->ptail->next = newnode;
		//newnode为新的队尾结点
		pq->ptail = newnode;
	}
}


//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//什么时候队列为空---队列的头结点为空
	return pq->phead == NULL;
}

//出队--队头
void QueuePop(Queue* pq)
{
	//判空操作
	assert(!QueueEmpty(pq));
	//只有一个结点的情况下，
	// 将头结点和尾结点均置为空
	if (pq->phead == pq->ptail)
	{
		//free掉头结点后，尾结点同时也free掉了
		//因为此时它们指向的是同一个结点
		free(pq->phead);
		//头和尾结点均置为空
		pq->phead = pq->ptail = NULL;
	}
	//将头结点的下一个结点存储起来
	QueueNode* next = pq->phead->next;
	//将头结点free掉
	free(pq->phead);
	//再将next指向的结点赋值给ps->phead，成为新的头结点
	pq->phead = next;
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	//队列不能为空
	assert(pq);
	//取队头数据
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	//队列不能为空
	assert(pq);
	//取队尾数据
	return pq->ptail->data;
}

//队列的销毁
void QueueDeatory(Queue* pq)
{
	//队列不能为空
	assert(pq);
	//定义一个指针pcur，让它凑从头结点开始遍历队列
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		//定义一个指针next，保存pcur的下一个结点的地址
		QueueNode* next = pcur->next;
		//将pcur所指向的结点的内存空间释放掉
		free(pcur);
		//再将next的值赋值给pcur
		pcur = next;
	}
	//再将phead和ptail指针都置为NULL
	pq->phead = pq->ptail = NULL;
}


//队列中的有效元素个数
int QueueSize(Queue* pq)
{
	//队列不能为空
	assert(pq);
	//定义一个指针pcur，遍历队列
	QueueNode* pcur = pq->phead;
	//定义一个计数器，pcur不为空时，就++
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}
*/
/*
int QueueSize(Queue* pq)
{
	//队列不能为空
	assert(pq);

	return pq->size;
}
*/

