#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//结构体的定义
typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead);

//链表的尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//链表的头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//链表的尾删
void SLTPopBack(SLTNode** pphead);

//链表的头删
void SLTPopFront(SLTNode** pphead);