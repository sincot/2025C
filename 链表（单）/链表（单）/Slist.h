#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//���Ķ���
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//�������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//�������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//�������βɾ
void SLTPopBack(SLTNode** pphead);

//�������ͷɾ
void SLTPopFront(SLTNode** pphead);

//��ָ��λ��posǰ��������
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//��ָ��λ��pos���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��ָ��λ��pos������
void SLTErase(SLTNode** pphead, SLTNode* pos);

//ɾ��ָ��λ��pos֮�������
void SLTEraseAfter(SLTNode* pos);

//�������������
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

//���������
void SLTDestory(SLTNode** pphead);