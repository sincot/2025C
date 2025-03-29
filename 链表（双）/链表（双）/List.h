#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//存储的有效数据
	struct ListNode* prev;//指向上一个结点的指针
	struct ListNode* next;//指向下一个结点的指针
}LTNode;

//空结点的创建
LTNode* LTBuyNode(LTDataType x);

//为空结点开辟内存空间
LTNode* LTBuyNode(LTDataType x);

//判断链表是否为空
bool LTEmpty(LTNode* phead);

//双链表的尾插
void LTPushBack(LTNode* phead, LTDataType x);

//双链表的头插
void LTPushFront(LTNode* phead, LTDataType x);

//双链表的尾删
void LTPopBack(LTNode* phead);

//双链表的头删
void LTPopFront(LTNode* phead);

//双链表的数据的查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//在指定位置pos前插入数据
void LTInsertAfter(LTNode* pos, LTDataType x);

//在指定位置pos后插入数据
void LTInsertBefore(LTNode* pos, LTDataType x);

//删除指定位置pos处的数据
void LTErase(LTNode* pos);

//销毁双链表的数据（传址调用）
//void LTDestory(LTNode** pphead);

//销毁双链表的数据（传值调用）
LTNode* LTDestory(LTNode* phead);