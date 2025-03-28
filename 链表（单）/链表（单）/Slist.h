#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//结点的定义
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单链表的尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//单链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//单链表的尾删
void SLTPopBack(SLTNode** pphead);

//单链表的头删
void SLTPopFront(SLTNode** pphead);

//在指定位置pos前插入数据
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在指定位置pos后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//删除指定位置pos的数据
void SLTErase(SLTNode** pphead, SLTNode* pos);

//删除指定位置pos之后的数据
void SLTEraseAfter(SLTNode* pos);

//查找链表的数据
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//链表的销毁
void SLTDestory(SLTNode** pphead);