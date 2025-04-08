#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//栈的结构的定义
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;      //有效数据个数
	int capacity; //内存空间大小
}ST;

//栈的初始化
void StackInit(ST* pst)
{
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

//入栈
void StackPush(ST* pst, STDataType x)
{
	//增容
	if (pst->top == pst->capacity)
	{
		//判断栈的内存空间是否为空
		//若为空，则申请4个STDataType类型大小的空间
		//若不为空，则增容2倍
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		//开辟空间
		STDataType* tmp = (STDataType*)realloc(pst->arr, sizeof(STDataType) * newcapacity);
		//判断内存空间是否申请成功
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//增容成功
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}
	//插入数据
	pst->arr[pst->top++] = x;
}

//判断栈中的数据是否为空
bool StackEmpty(ST* pst)
{
	//栈的地址不能为NULL
	assert(pst);
	return pst->top == 0;
}

//出栈
void StackPop(ST* pst)
{
	//判断栈中的数据是否为空
	assert(!StackEmpty(pst));
	pst->top--;
}

//取栈顶的数据
STDataType StackTop(ST* pst)
{
	//判断栈中数据是否为空
	assert(!StackEmpty(pst));
	//返回栈顶的数据
	return pst->arr[pst->top - 1];
}

//获取栈中的有效数据个数
int StackSize(ST* pst)
{
	//pst不能为空
	assert(pst);
	return pst->top;
}

//销毁栈中的数据
void StackDestory(ST* pst)
{
	//pst不能为空
	assert(pst);
	if (pst->arr)
	{
		free(pst->arr);
	}
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}


//**************************************以上是栈的相关操作*******************************
/*
//定义队列的结构
typedef struct
{
	ST pushST; //专门用来入数据的栈
	ST popST;  //专门用来出数据的栈
} MyQueue;

//初始化队列
MyQueue* myQueueCreate()
{
	//定义一个指向队列的指针
	//为队列开辟MyQueue大小的内存空间，之后销毁时记得释放这部分内存空间
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	//初始化栈 --- 调用函数SatckInit
	StackInit(&pq->pushST);
	StackInit(&pq->popST);

	//该函数的返回值类型为MyQueue*
	//说明要返回一个队列的地址，直接将我们定义好的pq返回
	return pq;
}

//入队 --- 将数据全部入到pushST栈中
void myQueuePush(MyQueue* obj, int x)
{
	//入栈 --- 调用函数StackPush
	StackPush(&obj->pushST, x);
}

//出队
//若栈popST为空，则将pushST中的数据全部入栈到popST中
//若栈popST不为空，直接将对栈popST执行出栈操作
int myQueuePop(MyQueue* obj)
{
	//判断栈popST是否为空 --- 判断栈是否为空 --- 调用函数StackEmpty
	if (StackEmpty(&obj->popST))
	{
		//要将pushST中的数据全部入栈到popST中
		//就得要知道pushST中有多少个数据，求栈中有多少个数据 --- 调用函数StackSize
		while (StackSize(&obj->pushST))
		{
			//将pushST中栈顶的数据入栈到popST中
			//取栈顶的数据 --- 调用函数StackTop
			StackPush(&obj->popST, StackTop(&obj->pushST));
			
			//将pushSt中的数据删除
			StackPop(&obj->pushST);
		}
	}

	//函数的返回值为int，说明要将这个队头数据给返回
	//由于之后要将栈顶的数据给删除，所以需要事先将popST中栈顶的数据用变量保存起来，最后再返回
	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return top;
}

//取队头数据 --- 与出队相同的操作
int myQueuePeek(MyQueue* obj)
{
	//判断popST是否为空
	if (StackEmpty(&obj->popST))
	{
		while (StackSize(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	//由于不用删除栈顶的数据，所以可以直接将栈顶的数据给返回
	return StackTop(&obj->popST);
}

//判断队列是否为空
bool myQueueEmpty(MyQueue* obj)
{
	//怎么判断队列是否为空？
	//当pushST与popST两个栈都为空时，则可说明队列为空
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

//销毁队列
void myQueueFree(MyQueue* obj)
{
	//先将队列结构中的两个栈给销毁
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);

	//之前为队列开辟了内存空间，要将它还给操作系统，直接free掉，然后手动置空
	free(obj);
	obj = NULL;
}
*/




//定义循环队列的结构
typedef struct
{
	int* arr; //既然以数组的结构实现循环队列，那么结构体的成员变量中一定得要有数组
    //为什么这里的数组的数据类型为int*
	//观察后面的myCircularQueueEnQueue函数，往队列中插入的数据为int类型，那么数组也是得为int*类型
	int front; //表示队头
	int rear; //表示队尾
	//之后还得要知道队列的长度为多少，为了将队列的长度k保存起来，在这里定义一个结构体成员变量
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


