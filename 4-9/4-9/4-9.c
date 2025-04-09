#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//定义循环队列的结构
typedef struct
{
	int* arr;
	int front; //表示队头
	int rear; //表示队尾
	int capacity;//记录循环队列的长度
} MyCircularQueue;

//初始化循环队列
MyCircularQueue* myCircularQueueCreate(int k)
{
	//定义一个指针，指向循环队列
	//为循环队列开辟MyCircularQueue大小的内存空间
	MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	//将指针里的成员初始化
	//初始化数组 --- 为数组申请k + 1个int*大小的内存空间
	pq->arr = (int*)malloc(sizeof(int*) * (k + 1));
	//初始化指向队头和队尾的变量 --- 事先指向下标为0的位置
	pq->front = pq->rear = 0;
	//初始化capacity --- 将k直接赋值给capacity
	pq->capacity = k;

	//观察函数的返回值为MyCircularQueue*
	//说明要将循环队列的地址返回，直接将定义好的pq给返回
	return pq;
}

//判断循环队列中的数据是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	//怎么判断队列中的数据是否为空
	//当指向队头的变量front等于指向队尾的变量rear时
	//即可说明队列中的数据为空
	return obj->front == obj->rear;
}

//判断循环队列中的数据是否为满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	//怎么判断队列中的数据是否满了
	//当(rear + 1） % (k + 1)等于front时
	//即可说明队列中的数据满了
	return (obj->rear + 1) % (obj->capacity + 1) == (obj->front);
}

//向循环队列中插入数据
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//判断队列的空间是否满了 --- 调用函数myCircularQueueIsFull
	if (myCircularQueueIsFull(obj))
	{
		//若队列中的数据满了，就不能再插入数据了，直接返回false
		return false;
	}

	//代码运行到这，即可说明队列中的数据还没有满
	//往rear指向的位置插入数据
	obj->arr[obj->rear++] = value;

	//rear++后，需要阻止rear越界，构成循环结构
	obj->rear %= obj->capacity + 1;

	//插入成功，返回true
	return true;
}

//删除循环队列中的元素
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	//要删除数据总得有数据可删吧？即队列中的数据不能为空
	//判断队列中的数据是否为空 --- 调用函数myCircularQueueIsFull
	if (myCircularQueueIsFull(obj))
	{
		//若队列中的数据为空，则返回false
		return false;
	}
	//代码运行到这，即可说明队列中的数据不为空
	//删除数据直接将front++即可
	obj->front++;
	//那么就要分析front直接++，可不可能越界呢？
	//可能会越界，所以需要向rear那样来组织front越界，构成循环结构
	obj->front %= obj->capacity + 1;

	//删除成功，返回true
	return true;
}

//取循环队列队头的数据
int myCircularQueueFront(MyCircularQueue* obj)
{
	//要获取到数据，首先队列中的数据不能为空
	//所以要先判断队列是否为空 --- 调用函数myCircularQueueIsEmpty
	if (myCircularQueueIsEmpty(obj))
	{
		//若队列中的数据为空，则返回-1
		return -1;
	}

	//代码运行到这，说明队列中的数据不为空
	//直接将下标为front的数据给返回
	return obj->arr[obj->front];
}

//取循环队列队尾的数据
int myCircularQueueRear(MyCircularQueue* obj)
{
	//要获取到数据，首先队列中的数据不能为空
	//所以要先判断队列是否为空 --- 调用函数myCircularQueueIsEmpty
	if (myCircularQueueIsEmpty(obj))
	{
		//若队列中的数据为空，则返回-1
		return -1;
	}

	//定义一个变量保存rear前的下标
	int prev = obj->rear - 1;

	//若rear的下标为0，这就意味着rear-1后，prev会越界,所以需要特殊处理
	if (obj->rear == 0)
	{
		prev = obj->capacity + 1;
	}

	//此时prev指向的位置就为队尾的数据，直接将下标为prev的数据返回
	return obj->arr[prev];
}

//销毁循环队列中的数据
void myCircularQueueFree(MyCircularQueue* obj)
{
	//将为数组开辟的内存空间给free掉
	if (obj->arr)
	{
		free(obj->arr);
	}
	//将为循环队列开辟的内存空间给free掉，并且手动置空
	free(obj);
	obj = NULL;
}
*/

/*
//括号的匹配

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
	//定义结构体
	ST st;

	StackInit(&st);
	//定义一个指针来遍历字符串
	char* pi = s;

	while (*pi != '\0')
	{
		//入栈
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		//出栈
		else
		{
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}

			char ch = StackTop(&st);
			if ((ch == '(' && *pi == ')') || (ch == '[' && *pi == ']') || (ch == '{' && *pi == '}'))
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
	bool ret = StackEmpty(&st) ? true : false;
	StackDestory(&st);
	return ret;
}
*/