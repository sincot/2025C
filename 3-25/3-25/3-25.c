#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
/*
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* detectCycle(struct ListNode* head)
{
	//创建快慢指针
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
		{
			//找相遇点
			//相遇点和头结点到入环第一个结点的距离相等
			ListNode* pcur = head;
			//从头结点开始遍历
			while (pcur != slow)
			{
				pcur = pcur->next;
				slow = slow->next;
			}
			//跳出了循环说明pcur与slow相等
			//此时，它们两指向的位置就是入环第一个结点
			return pcur;
		}
	}

	return NULL;
}
*/


//定义双向链表的结构
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;


//为空结点开辟内存空间
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	newnode->data = x;
	//为了构成循环结构，让它的prev指针和next指针都指向它自己
	newnode->prev = newnode->next = newnode;

	return newnode;
}

/*
//双向链表的初始化
void LTInit(LTNode** pphead)
{
	//头结点的地址不能为空
	assert(pphead);
	//传无效数值
	*pphead = LTBuyNode(-1);
}
*/

//双向链表的初始化
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//双向链表的打印
void LTPrint(LTNode* phead)
{
	//定义指针去遍历双向链表
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->data);
		//向后移动
		pcur = pcur->next;
	}
}

//只有头结点一个结点的情况下，判断链表是否为空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	//若phead->next == phead说明链表中只剩下它一个结点
	//如果为空，返回true
	return phead->next == phead;
}

//查找双向链表中的数据
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	//定义一个指针pcur去遍历链表
	LTNode* pcur = phead->next;
	while (pcur)
	{
		//找到了
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//没找到
	return NULL;
}

//双向链表的尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(1);
	//链接phead phead->prev newnode
	//先从后边的newnode改变
	newnode->prev = phead->prev;
	newnode->next = phead;
    //再改变phead 和 phead->prev
	//将尾结点与newnode链接起来
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//双向链表的头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(2);
	//链接phead phead->prev newnode
	newnode->prev = phead;
	newnode->next = phead->next;

	phead->next->prev = newnode;
	phead->next = newnode;
}

//双向链表的尾删
void LTPopBack(LTNode* phead)
{
	//判断链表是否为空
	//若为空，函数返回的是true，逻辑非之后，为false，执行断言操作
	//若不为空，函数返回的是false，逻辑非之后，为true，不执行断言操作
	assert(!LTEmpty(phead));

	LTNode* del = phead->prev;
	//phead del del->prev
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}

//双向链表的头删
void LTPopFront(LTNode* phead)
{
	assert(!LTEmpty(phead));
	//phead del del->next
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

//在指定位置pos之前插入数据
void LTInsertFront(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	//pos->prev newnode pos
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

//在指定位置pos之后插入数据
void LTInsertBack(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//删除pos位置的结点
void LTErase(LTNode* pos)
{
	assert(pos);
	//pos->prev pos pos->next
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//销毁链表的数据
//方法1：传址调用
/*
void LTDestory(LTNode** pphead)
{
	assert(pphead && *pphead);
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(*pphead);
	*pphead = NULL;
}
*/

//方法2：传值调用
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}

void test01()
{
	LTNode* plist = LTInit(-1);
	LTDestory(plist);
	plist = NULL;
}

int main()
{
	test01();
	return 0;
}
