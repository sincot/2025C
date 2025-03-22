//链表

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//定义结构体
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//创建空结点
SLTNode* SLTBuyNode(SLTDataType x)
{
	//创建空结点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//打印链表
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//链表的尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//当链表为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//当链表不为空
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

//链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//链表的尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//找到尾结点的前一个结点
	SLTNode* prev = NULL;
	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		prev = ptail;
		ptail = ptail->next;
	}
	prev->next = NULL;
	free(ptail);
	ptail = NULL;
}

//链表的头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//链表的查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//跳出循环走到了这里，说明了链表为空，没有找到x
	//那么就返回NULL
	return NULL;
}

//在指定位置pos之前插入数据
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);
	//pos就是头结点
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		//找到pos之前的位置
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//找到了pos之前的位置
		prev->next = newnode;
		newnode->next = pos;
	}
}

//在指定位置pos之后插入数据
void SLTInsertBack(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除指定位置pos的数据
void SLTDelete(SLTNode** pphead, SLTNode* pos)
{
	//指定位置的地址可不能为空
	assert(pphead && *pphead && pos);
	//找到poss之前的结点
	SLTNode* prev = *pphead;
	//pos就是头结点
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//找到pos之前的结点
		prev->next = pos->next;
		//释放掉pos的内存空间，再手动置空
		free(pos);
		pos = NULL;
	}
}

//删除指定位置pos之后的数据
void SLTDeleteBack(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//销毁链表
void SLTDistory(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

//创建链表
void test1()
{
	//创建结点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//初始化
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	//链接
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	SLTNode* plist = node1;
	SLTDistory(&plist);
	
	SLTNode* pfind = SLTFind(plist, 2);
	SLTInsetFront(&plist, pfind, 5);
	SLTPrint(plist);
	SLTPrint(plist);
	if (pfind)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	
}


void test2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPopBack(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
}



void test3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTNode* pfind = plist;
	SLTInsertBack(pfind, 2);
	SLTDeleteBack(&plist, pfind);
	SLTPrint(plist);
}


int main()
{
	test1();
	//test2();
	//test3();

	return 0;
}
*/

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	
}ListNode;

struct ListNode* removeElements(struct ListNode* head, int val)
{
	//创建空链表
	ListNode* newHead = NULL;//要返回的新头结点
	ListNode* newtail = NULL;

	ListNode* pcur = head;//它去遍历链表
	while (pcur)
	{
		//把链表中不为val值的结点尾插至新的链表中
		if (pcur->val != val)
		{
			//尾插
			//链表为空
			if (newHead == NULL)
			{
				newHead = newtail = pcur;
			}
			else
			{
				//链表非空
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if (newtail != NULL)
	{
		newtail->next = NULL;
	}

	return newHead;
}