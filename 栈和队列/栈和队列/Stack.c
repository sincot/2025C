/*
//ջ
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//ջ�Ľṹ�Ķ���
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;      //��Ч���ݸ���
	int capacity; //�ڴ�ռ��С
}ST;

//ջ�ĳ�ʼ��
void StackInit(ST* pst)
{
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

//��ջ
void StackPush(ST* pst, STDataType x)
{
	//����
	if (pst->top == pst->capacity)
	{
		//�ж�ջ���ڴ�ռ��Ƿ�Ϊ��
		//��Ϊ�գ�������4��STDataType���ʹ�С�Ŀռ�
		//����Ϊ�գ�������2��
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		//���ٿռ�
		STDataType* tmp = (STDataType*)realloc(pst->arr, sizeof(STDataType) * newcapacity);
		//�ж��ڴ�ռ��Ƿ�����ɹ�
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//���ݳɹ�
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}
	//��������
	pst->arr[pst->top++] = x;
}

//�ж�ջ�е������Ƿ�Ϊ��
bool StackEmpty(ST* pst)
{
	//ջ�ĵ�ַ����ΪNULL
	assert(pst);
	return pst->top == 0;
}

//��ջ
void StackPop(ST* pst)
{
	//�ж�ջ�е������Ƿ�Ϊ��
	assert(!StackEmpty(pst));
	pst->top--;
}

//ȡջ��������
STDataType StackTop(ST* pst)
{
	//�ж�ջ�������Ƿ�Ϊ��
	assert(!StackEmpty(pst));
	//����ջ��������
	return pst->arr[pst->top - 1];
}

//��ȡջ�е���Ч���ݸ���
int StackSize(ST* pst)
{
	//pst����Ϊ��
	assert(pst);
	return pst->top;
}

//����ջ�е�����
void StackDestory(ST* pst)
{
	//pst����Ϊ��
	assert(pst);
	if (pst->arr)
	{
		free(pst->arr);
	}
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

int main()
{
	//����һ��ָ��ջ��ָ��
	ST* st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	int size = StackSize(&st);
	printf("%d ", size);
	StackDestory(&st);

	return 0;
}
*/
