#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//�ṹ��Ķ���
typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

//����Ĵ�ӡ
void SLTPrint(SLTNode* phead);

//�����β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//�����ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//�����βɾ
void SLTPopBack(SLTNode** pphead);

//�����ͷɾ
void SLTPopFront(SLTNode** pphead);