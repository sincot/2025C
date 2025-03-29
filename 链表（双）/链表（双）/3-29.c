/*
#include "List.h"

//ͷ���ĳ�ʼ��

void LTInit(LTNode** pphead)
{
	//�������ĵ�ַ����ΪNULL
	assert(pphead);
	//����Чֵ
	*pphead = LTBuyNode(-1);
}


LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//������������ݣ���ֵ���ã�
LTNode* LTDestory(LTNode* phead)
{
	//������Ϊ��
	assert(phead);
	//����ָ��pcur��������
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		//����nextָ��洢pcur����һ�����ĵ�ַ
		LTNode* next = pcur->next;
		//��pcur��ָ��Ľ��Ŀռ��ͷŵ�
		free(pcur);
		pcur = next;
	}
	//����ѭ����˵���Ѿ�����ͷ���
	free(phead);
	phead = NULL;

	return phead;
}

int main()
{
	LTNode* plist = LTInit(-1);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushFront(plist, 100);
	LTDestory(plist);
	plist = NULL;

	return 0;
}
*/


//ջ

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
//����ջ�Ľṹ
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//ָ��ջ����λ��
	int capacity;//ջ������
}ST;

//��ʼ��
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	//�������ĵ�ַ����ΪNULL
	assert(ps);
	//�жϿռ��Ƿ��㹻
	if (ps->top == ps->capacity)
	{
		//�ж��ڴ��Ƿ�Ϊ0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//����һ����ʱָ���������¿��ٵ��ڴ������صĵ�ַ
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		//������ʧ��
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//��������
	ps->arr[ps->top++] = x;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//��ջ
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	//��ջ��ֻ��Ҫ��Ч���ݸ�������һ������
	ps->top--;
}

//��ȡջ��������
STDataType StackTop(ST* ps)
{
	//�ж�ջ�Ƿ�Ϊ��
	assert(!StackEmpty(ps));
	//����ջ��������
	return ps->arr[ps->top - 1];
}

//��ȡջ����ЧԪ�ظ���
STDataType StackSize(ST* ps)
{
	return ps->top;
}

//����ջ�е�����
void StackDestory(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->top = ps->capacity = 0;
}

int main()
{
	//����һ�����
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	STDataType top = StackTop(&st);
	printf("%d", top);

	return 0;
}
*/



/*
//����ջ�Ľṹ
typedef char STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//ָ��ջ����λ��
	int capacity;//ջ������
}ST;

//��ʼ��
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	//�������ĵ�ַ����ΪNULL
	assert(ps);
	//�жϿռ��Ƿ��㹻
	if (ps->top == ps->capacity)
	{
		//�ж��ڴ��Ƿ�Ϊ0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//����һ����ʱָ���������¿��ٵ��ڴ������صĵ�ַ
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		//������ʧ��
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//��������
	ps->arr[ps->top++] = x;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//��ջ
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	//��ջ��ֻ��Ҫ��Ч���ݸ�������һ������
	ps->top--;
}

//��ȡջ��������
STDataType StackTop(ST* ps)
{
	//�ж�ջ�Ƿ�Ϊ��
	assert(!StackEmpty(ps));
	//����ջ��������
	return ps->arr[ps->top - 1];
}

//��ȡջ����ЧԪ�ظ���
STDataType StackSize(ST* ps)
{
	return ps->top;
}

//����ջ�е�����
void StackDestory(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->top = ps->capacity = 0;
}

//**************************************������ջ��ʵ�ִ���***************************************

bool isValid(char* s)
{
	//����һ���ṹ��
	ST st;
	StackInit(&st);
	//����Ĳ���
	//����һ��ָ������������ַ���
	char* pi = s;
	while (*pi != '\0')
	{
		//��������ջ
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		else
		{
			//�ж�ջ���Ƿ�Ϊ��,��ֻ��һ�������ŵ�ʱ����ܳ�������
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}
			//���������ţ�ȡջ����Ԫ����*pi��ƥ��
			//ȡջ������
			STDataType top = StackTop(&st);
			if ((top == '(' && *pi == ')') || (top == '[' && *pi == ']') || (top == '{' && *pi == '}'))
			{
				StackPop(&st);
			}
			else
			{
				StackDestory(&st);
				return false;
			}
		}
		pi++;
	}
	//����һһƥ���ˣ���ôջ���һ��Ϊ��
	//Ҳ�п��ܴ����ַ�����ֻ��һ��Ԫ�ص����
	//�����ᵼ��ջ��Ϊ�գ���������ѭ��
	//����Ҫ�ж�ջ�Ƿ�Ϊ�գ���������Ŀ�������ʾ
	//Ϊ�շ���true����Ϊ�շ���false
	bool ret = StackEmpty(&st) ? true : false;
	StackDestory(&st);
	return ret;
}
*/

//����
/*
//���н��Ľṹ
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//������еĽṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;
}Queue;

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	//�����е������ṹ���Ա
	//����ΪNULL����������һ���ն���
	pq->phead = pq->ptail = NULL;
}

//���--��β
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//Ϊ��������ݿ��ٽ��ռ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
    //��ʼ��newnode�ռ�
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	//��ô�ж϶���Ϊ��---���е�ͷ���Ϊ��
	if (pq->phead == NULL)
	{
		//��ʱnewnode��Ϊβ���ҲΪͷ���
		pq->phead = pq->ptail = newnode;
	}
	//���в�Ϊ��
	else
	{
		//ֱ����β���ĺ������
		pq->ptail->next = newnode;
		//newnodeΪ�µĶ�β���
		pq->ptail = newnode;
	}
}


//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//ʲôʱ�����Ϊ��---���е�ͷ���Ϊ��
	return pq->phead == NULL;
}

//����--��ͷ
void QueuePop(Queue* pq)
{
	//�пղ���
	assert(!QueueEmpty(pq));
	//ֻ��һ����������£�
	// ��ͷ����β������Ϊ��
	if (pq->phead == pq->ptail)
	{
		//free��ͷ����β���ͬʱҲfree����
		//��Ϊ��ʱ����ָ�����ͬһ�����
		free(pq->phead);
		//ͷ��β������Ϊ��
		pq->phead = pq->ptail = NULL;
	}
	//��ͷ������һ�����洢����
	QueueNode* next = pq->phead->next;
	//��ͷ���free��
	free(pq->phead);
	//�ٽ�nextָ��Ľ�㸳ֵ��ps->phead����Ϊ�µ�ͷ���
	pq->phead = next;
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	//���в���Ϊ��
	assert(pq);
	//ȡ��ͷ����
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	//���в���Ϊ��
	assert(pq);
	//ȡ��β����
	return pq->ptail->data;
}

//���е�����
void QueueDeatory(Queue* pq)
{
	//���в���Ϊ��
	assert(pq);
	//����һ��ָ��pcur�������մ�ͷ��㿪ʼ��������
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		//����һ��ָ��next������pcur����һ�����ĵ�ַ
		QueueNode* next = pcur->next;
		//��pcur��ָ��Ľ����ڴ�ռ��ͷŵ�
		free(pcur);
		//�ٽ�next��ֵ��ֵ��pcur
		pcur = next;
	}
	//�ٽ�phead��ptailָ�붼��ΪNULL
	pq->phead = pq->ptail = NULL;
}


//�����е���ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	//���в���Ϊ��
	assert(pq);
	//����һ��ָ��pcur����������
	QueueNode* pcur = pq->phead;
	//����һ����������pcur��Ϊ��ʱ����++
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}
*/
/*
int QueueSize(Queue* pq)
{
	//���в���Ϊ��
	assert(pq);

	return pq->size;
}
*/

