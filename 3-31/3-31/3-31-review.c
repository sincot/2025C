//��ϰջ����ز���
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//ջ�Ľṹ�Ķ���
//��˳�������
typedef int STDataType;
typedef struct StackNode
{
	STDataType* arr;//�ײ�������ṹ
	int top;//��Ч���ݸ���
	int capacity;//�ڴ�ռ��С
}STNode;

//ջ�ĳ�ʼ��---��ַ����
void StackInit(STNode* pst)
{
	assert(pst);
	//��ʼ��
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

//��ջ
void StackPush(STNode* pst, STDataType x)
{
	//����
	if (pst->top == pst->capacity)
	{
		//�ж�capacity�Ƿ�Ϊ0��Ϊ0�Ϳ���4���ֽڵĿռ�
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		//��̬�ڴ濪��
		STNode* tmp = (STNode*)realloc(pst->arr, newcapacity * sizeof(STNode));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//���ٳɹ�
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}
	pst->arr[pst->top++] = x;
}

//�п�
bool StackEmpty(STNode* pst)
{
	assert(pst);
	return pst->top == 0;
}

//��ջ
void StackPop(STNode* pst)
{
	//�ж�ջ�Ƿ�Ϊ��
	assert(!StackEmpty(pst));
	pst->top--;
}

//ȡջ��Ԫ��
STDataType StackTop(STNode* pst)
{
	assert(!StackEmpty(pst));
	return pst->arr[pst->top - 1];
}

//ͳ��ջ��Ԫ�ظ���
int StackSize(STNode* pst)
{
	return pst->top;
}

//����ջ������
void StackDestory(STNode* pst)
{
	assert(pst);
	if (pst->arr)
	{
		free(pst->arr);
	}
	pst->top = pst->capacity = 0;
}

int main()
{
	STNode st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	STDataType top = StackTop(&st);
	printf("%d ", top);

	return 0;
}
*/


/*
//��ϰ���е���ز���
//������Ľṹ
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//������еĽṹ
typedef struct Queue
{
	//��������ָ��
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	//ͷβָ���ΪNULL
	pq->phead = pq->ptail = NULL;
}

//���---��β
void QueuePush(Queue* pq, QDataType x)
{
	asseert(pq);
	//�����ڴ�ռ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	//�ж϶���
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//����---��ͷ
void QueuePop(Queue* pq)
{
	//�п�
	assert(!QueueEmpty(pq));
	//ֻ��һ���������
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//�洢ͷ������һ�����
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//ȡ��ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->ptail->data;
}

//ͳ�ƶ��������ݵĸ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* pcur = pq->phead;
	
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

//�����жӵ�����
void QueueDestory(Queue* pq)
{
	assert(pq);
	//����
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//�ÿ�
	pq->phead = pq->ptail = NULL;
}

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QDataType head = QueueFront(&q);
	QDataType tail = QueueBack(&q);
	printf("%d ", head);
	printf("%d ", tail);
	QueueDestory(&q);

	return 0;
}
*/

