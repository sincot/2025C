/*
//栈
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

int main()
{
	//定义一个指向栈的指针
	ST* st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	int size = StackSize(&st);
	printf("%d ", size);
	StackDestory(&st);

	return 0;
}
*/
