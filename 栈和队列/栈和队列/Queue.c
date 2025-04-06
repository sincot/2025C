/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��������Ľ��Ľṹ
typedef int QDataType;
typedef struct QueueListNode
{
	QDataType data;//����Ľ�����洢������
	struct QueueListNode* next; //ָ����һ������ָ��
}QueueNode;

//������еĽṹ
typedef struct Queue
{
	QueueNode* phead; //ָ��ͷ����ָ��
	QueueNode* ptail; //ָ��β����ָ��
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	//������ָ����Ϊ��
	pq->phead = pq->ptail = NULL;
}

//���
void QueuePush(Queue* pq, QDataType x)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	//Ϊ��Ҫ����Ľ�㿪���ڴ�ռ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;
	//������������Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//�����������ݲ�Ϊ��
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}	
}

//�ж϶������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	return pq->phead == NULL;
}

//������
void QueuePop(Queue* pq)
{
	//�������Ƿ�Ϊ��
	assert(!QueueEmpty(pq));
	//��������ֻ��һ�����
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//����һ��ָ��next��ͷ������һ���洢����
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	return pq->ptail->data;
}

//��ȡ��������Ч���ݸ���
int QueueSize(Queue* pq)
{
	assert(pq);
	//����һ������size��ͳ�ƶ��е���Ч���ݸ���
	int size = 0;
	//����һ��ָ��pcur����������
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

//���ٶ��е�����
void QueueDestory(Queue* pq)
{
	assert(pq);
	//����һ��ָ��pcur����������
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		//����һ��ָ��next����һ�����ĵ�ַ�洢����
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//�����е��������ٺ󣬽������е�����ָ�붼��ΪNULL
	pq->phead = pq->ptail = NULL;
}

int main()
{
	//����һ��ָ����е�ָ��
	Queue* q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueDestory(&q);

	return 0;
}
*/