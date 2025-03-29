#include "List.h"

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
	//为了构成循环结构，要prev和next指针指向自己
	newnode->prev = newnode->next = newnode;

	return newnode;
}

//双链表的尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	//头结点不能为空
	assert(phead);
    //创建空结点
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->prev
	//第一步：先将newnode与phead链接
	newnode->next = phead;
	//第二步：将newnode与尾结点（phead->prev）链接起来
	newnode->prev = phead->prev;
	//第三步：将尾结点（phead->prev）与newnode链接起来
	phead->prev->next = newnode;
	//第四步：将phead与newnode链接起来
	phead->prev = newnode;
}

//双链表的头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	//头结点不能为空
	assert(phead);
	//创建空结点
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	//第一步：先将newnode与phead->next链接
	newnode->next = phead->next;
	//第二步：将newnode与phead链接
	newnode->prev = phead;
	//第三步：将phead->next与newnode链接起来
	phead->next->prev = newnode;
	//第四步：将phead与newnode链接起来
	phead->next = newnode;
}

//判断双链表是否为空
/*
bool LTEmpty(LTNode* phead)
{
	//链表不能为空
	assert(phead);
	if (phead->next == phead)
	{
		return true;
	}

	return false;
}
*/

bool LTEmpty(LTNode* phead)
{
	//链表不能为空
	assert(phead);

	return phead->next == phead;
}

//双链表的尾删
void LTPopBack(LTNode* phead)
{
	//双链表不能为空
	//若为空，返回true，取反之后为false，执行assert
	//若不为空，返回false，取反之后为true，不执行assert
	assert(!LTEmpty(phead));
	//为了方便表示尾结点的前一个结点
	//将尾结点用指针del表示
	LTNode* del = phead->prev;
	//phead del del->prev
	phead->prev = del->prev;
	del->prev->next = phead;
	//将删除的结点的内存空间free掉
	free(del);
	//手动置为空
	del = NULL;
}

//双链表的头删
void LTPopFront(LTNode* phead)
{
	//双链表不能为空
	//若为空，返回true，取反之后为false，执行assert
	//若不为空，返回false，取反之后为true，不执行assert
	assert(!LTEmpty(phead));
	//为了方便表示头结点的下下个结点
	//将头结点的下一个结点的指针用指针del表示
	LTNode* del = phead->next;
	//phead del del->next
	phead->next = del;
	del->next->prev = phead;
	//将删除的结点的内存空间free掉
	free(del);
	//手动置为空
	del = NULL;
}

//双链表中数据的查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	//头结点不能为空
	assert(phead);
	//创建一个pcur指针去遍历链表
	//当pcur等于phead时，跳出循环
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//跳出了循环，说明遍历完了
	//仍然找不到x,返回NULL
	return NULL;
}

//在指定位置pos前插入数据
void LTInsertAfter(LTNode* pos, LTDataType x)
{
	//指向pos结点的地址不能为空
	assert(pos);
	//创建空结点
	LTNode* newnode = LTBuyNode(x);
	//pos->prev newnode pos
	//第一步：将newnode与pos链接起来
	newnode->next = pos;
	//第二步：将newnode与pos->prev链接起来
	newnode->prev = pos->prev;
	//第三步：将pos->prev与newnode链接起来
	pos->prev->next = newnode;
	//第四步：将pos与newnode链接起来
	pos->prev = newnode;
}

//在指定位置pos后插入数据
void LTInsertBefore(LTNode* pos, LTDataType x)
{
	//pos所指向的结点的地址不能为空
	assert(pos);
	//创建空结点
	LTNode* newnode = LTBuyNode(x);
	//pos newnode pos->next
	//第一步：将newnode与pos->next链接
	newnode->next = pos->next;
	//第二步：将newnode与pos链接
	newnode->prev = pos;
	//第三步：将pos->next与newnode链接起来
	pos->next->prev = newnode;
	//第四步：将pos与newnode链接起来
	pos->next = newnode;
}

//删除指定位置pos处的数据
void LTErase(LTNode* pos)
{
	//pos指针所指向的结点的地址不能为空
	assert(pos);
	//pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	//将pos结点的内存空间free掉
	free(pos);
	pos = NULL;
}

//销毁双链表的数据（传址调用）
/*
void LTDestory(LTNode** pphead)
{
	//传过来的地址不能为空
	assert(pphead);
	//创建一个指针pcur，来遍历链表
	//从头结点的下一个结点开始
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		//创建一个指针next，用于存储pcur的下一个结点
		//用于pcur的向下遍历
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//跳出循环，说明pcur已经执行了头结点
	//将头结点的内存空间也释放掉，才完成了销毁链表的数据操作
	free(*pphead);
	//手动置空
	*pphead = NULL;
}
*/
