#include "Slist.h"

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

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//创建空结点
	SLTNode* newnode = SLTBuyNode(x);
	//头结点为空
	//将新创建好的结点赋值给*pphead
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//头结点不为NULL
	else
	{
		//创建pcur指针，遍历链表
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			//继续往下遍历
			pcur = pcur->next;
		}
		//跳出循环后，说明pcur->next为空
		//而此时pcur就指向尾结点
		pcur->next = newnode;
	}
}

//单链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//传过来的地址不能为空，链表本身可以为空，即*pphead可以为空
	assert(pphead);
	//创建空结点
	SLTNode* newnode = SLTBuyNode(x);
	//newnode与头结点链接
	newnode->next = *pphead;
	//newnode成为新的头结点
	*pphead = newnode;
}

//单链表的尾删
void SLTPopBack(SLTNode** pphead)
{
	//传过来的地址不能为空
	//链表不能为空
	assert(pphead && *pphead);
	
	//只有一个结点
	//*pphead加括号的原因是，->操作符的优先级大于*
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//有一个以上的结点
	else
	{
		//定义两个指针pcur,ptail
	    //pcur来找尾结点的前一个结点
	    //ptail来找尾结点
		SLTNode* pcur = NULL;
		SLTNode* ptail = *pphead;

		//让patil去遍历链表找尾结点
		while (ptail->next)
		{
			//将ptail赋值给pcur
			pcur = ptail;
			ptail = ptail->next;
		}
		//将尾结点向操作系统申请的内存空间释放掉
		free(ptail);
		//手动置为NULL
		ptail = NULL;
		pcur->next = NULL;
	}	
}

//单链表的头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//定义指针next将头结点的下一个结点的地址存储起来
	SLTNode* next = (*pphead)->next;
	//将头结点向操作系统申请的空间归还给操作系统
	free(*pphead);
	//将新的头结点的地址赋值给*pphead
	*pphead = next;
}

//在指定位置pos前插入数据
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	//创建空结点
	SLTNode* newnode = SLTBuyNode(x);
	//pos指向的结点为头结点
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	//pos指向的结点不为头结点
	else
	{
		//创建pcur指针去遍历链表
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		//跳出循环，说明找到了pos的前一个结点
		pcur->next = newnode;
		newnode->next = pos;
	}	
}

//在指定位置pos后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	//创建空结点
	SLTNode* newnode = SLTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除指定位置pos的数据
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	//pos指向的结点为头结点
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		//创建指针pos遍历链表，找到pos位置之前的结点
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			//继续往下遍历
			pcur = pcur->next;
		}
		//跳出循环，说明找到了pos位置之前的结点
		//pcur pos pos->next
		pcur = pos->next;
		//free掉pos
		free(pos);
		//手动置为NULL
		pos = NULL;
	}
}

//删除指定位置pos之后的数据
void SLTEraseAfter(SLTNode* pos)
{
	//pos指针不能为空,pos之后的结点不能为空
	assert(pos && pos->next);
	//创建del指针，用来表示要删除的数据
	SLTNode* del = pos->next;
	//pos del del->next
	pos->next = del->next;
	free(del);
	del = NULL;
}

//查找链表的数据
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	//创建pcur指针去遍历链表
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//跳出循环，说明找不到x，故返回NULL
	return NULL;
}

//销毁链表的数据
void SLTDestory(SLTNode** pphead)
{
	//链表不能为空，传过来的指针不能为空
	asserrt(pphead && *pphead);
	//创建指针pcur，遍历链表，依次销毁结点
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		//创建一个指针来存放pcur后面结点的地址
		//为了销毁pcur之后能找到其后面的结点
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}