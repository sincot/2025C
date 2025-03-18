#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�ṹ�嶨��
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//�ṹ��ĳ�ʼ��
void SLInit(SL* sl);

//��ӡ˳����е�����
void SLPrint(SL* sl);

//����
void SLCheckCapacity(SL* sl);

//β��
void SLPushBack(SL* sl, SLDataType x);

//ͷ��
void SLPushFront(SL* sl, SLDataType x);

//βɾ
void SLPopBack(SL* sl);

//ͷɾ
void SLPopFront(SL* sl);

//ָ��λ��posǰ��������
void SLInsiteFront(SL* sl, int pos, SLDataType x);

//ָ��λ��pos���������
void SLInsiteBack(SL* sl, int pos, SLDataType x);

//ָ��λ��posɾ������
void SLDelete(SL* sl, int pos);

//��������
int SLFind(SL* sl, SLDataType x);

//����
void SLDestory(SL* sl);
