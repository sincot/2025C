#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//�洢����Ч����
	struct ListNode* prev;//ָ����һ������ָ��
	struct ListNode* next;//ָ����һ������ָ��
}LTNode;

//�ս��Ĵ���
LTNode* LTBuyNode(LTDataType x);

//Ϊ�ս�㿪���ڴ�ռ�
LTNode* LTBuyNode(LTDataType x);

//�ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);

//˫�����β��
void LTPushBack(LTNode* phead, LTDataType x);

//˫�����ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//˫�����βɾ
void LTPopBack(LTNode* phead);

//˫�����ͷɾ
void LTPopFront(LTNode* phead);

//˫��������ݵĲ���
LTNode* LTFind(LTNode* phead, LTDataType x);

//��ָ��λ��posǰ��������
void LTInsertAfter(LTNode* pos, LTDataType x);

//��ָ��λ��pos���������
void LTInsertBefore(LTNode* pos, LTDataType x);

//ɾ��ָ��λ��pos��������
void LTErase(LTNode* pos);

//����˫��������ݣ���ַ���ã�
//void LTDestory(LTNode** pphead);

//����˫��������ݣ���ֵ���ã�
LTNode* LTDestory(LTNode* phead);