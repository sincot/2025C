#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//结构体定义
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//结构体的初始化
void SLInit(SL* sl);

//打印顺序表中的数据
void SLPrint(SL* sl);

//增容
void SLCheckCapacity(SL* sl);

//尾插
void SLPushBack(SL* sl, SLDataType x);

//头插
void SLPushFront(SL* sl, SLDataType x);

//尾删
void SLPopBack(SL* sl);

//头删
void SLPopFront(SL* sl);

//指定位置pos前插入数据
void SLInsiteFront(SL* sl, int pos, SLDataType x);

//指定位置pos后插入数据
void SLInsiteBack(SL* sl, int pos, SLDataType x);

//指定位置pos删除数据
void SLDelete(SL* sl, int pos);

//查找数据
int SLFind(SL* sl, SLDataType x);

//销毁
void SLDestory(SL* sl);
