#include "SLTlist.h"

//链表的打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		//找到下一个结点
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//根据x创建结点
SLTNode* SLTBuyNode(SLTDataType x)
{
	//根据x创建结点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//判断newnode是否创建成功
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

//链表的尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//若参数为NULL，会造成空指针异常
	//判断参数是否为有效结点，所以pphead不能为空
	//如果*pphead为空，说明它指向的第一个结点的地址为空
	//如果pphead为空，说明这里的传参是错误的。
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//链表为空,即phead为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//链表不为空
	else
	{
		//找尾结点
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//找到了尾结点
		ptail->next = newnode;
	}
	
}

//链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//若参数为NULL，会造成空指针异常
	//判断参数是否为有效结点，所以pphead不能为空
	//如果*pphead为空，说明它指向的第一个结点的地址为空
	//如果pphead为空，说明这里的传参是错误的。
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//链表的尾删
void SLTPopBack(SLTNode** pphead)
{
	//*pphead为空，说明第一个结点为空
	assert(pphead && *pphead);
	//只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找prev和ptail
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		//找尾结点
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//链表的头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//找到头结点的下一个结点
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}






