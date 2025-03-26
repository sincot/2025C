//双向链表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//定义双向链表的结构体
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//存储的数据
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;


//创建结点
LTNode* LTBuyNode(LTDataType x)
{
	//创建新节点
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	newnode->data = x;
	newnode->prev = newnode;
	newnode->next = newnode;

	return newnode;
}

//初始化结点
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//双向链表的打印
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//双向链表的尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->prev
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//双向链表的头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//双向链表的尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
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
	assert(phead);
	LTNode* del = phead->next;
	//phead del del->next
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

//在指定位置pos前插入数据
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

//查找链表中的数据
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

//双向链表的数据的销毁
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	free(phead);
	phead = NULL;
}

int main()
{
	LTNode* plist = LTInit(-1);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	//LTInsertFront(plist->next->next->next->next, 100);
	//LTInsertBack(plist->next, 100);
	LTDestory(plist);
	free(plist);
	plist = NULL;
	
	LTNode* pfind = LTFind(plist, 100);
	if (pfind)
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}
	
	//LTPrint(plist);
	//LTPushFront(plist, 100);
	//LTPopFront(plist);
	//LTPrint(plist);

	return 0;
}
*/


//单链表
/*
typedef int SLTDataType;
//定义单链表结构体
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//创建结点
SLTNode* SLTBuyNode(SLTDataType x)
{
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


//单链表的初始化
void SLTInit(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	*pphead = SLTBuyNode(x);
}


//单链表的打印
void SLTPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//单链表的查找
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

	return NULL;
}

//单链表的尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
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

//单链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//单链表的尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//只有一个结点
	if ((*pphead)->next == NULL)
	{
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

//单链表的头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//在指定位置pos前插入数据
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);
	SLTNode* newnode = SLTBuyNode(x);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
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
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == (*pphead))
	{
		//头删
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//链表的销毁
void SLTDestory(SLTNode** pphead)
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

int main()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushFront(&plist, 100);
	//SLTPopBack(&plist);
	//SLTPopFront(&plist);
	//SLTNode* pfind = SLTFind(plist, 4);
	//SLTInsertBack(pfind, 200);
	//SLTErase(&plist, pfind);
	SLTDestory(&plist);

	if (pfind)
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}

	SLTPrint(plist);
	return 0;
}
*/

/*
//顺序表
//顺序表结构体的定义
typedef int SLDataType;
typedef struct SeqList
{
	int size;//有效数据个数
	int capacity;//内存空间大小
	SLDataType* arr;
}SL;

//顺序表的初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//打印链表
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//增容函数
void SLCheckCapacity(SL* ps)
{
	//size和capacity相等则说明需要增容
	if (ps->size == ps->capacity)
	{
		//判断capacity中是否有元素
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//开辟空间
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//顺序表的尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//顺序表的头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//销毁数据
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

int main()
{
	SL* sl;
	return 0;
}
*/