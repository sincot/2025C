#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
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
	//���в���Ϊ��
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	//���в���Ϊ��
	assert(!QueueEmpty(pq));
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

//*************************************8�����Ƕ��еĲ���ʵ��*******************************************
typedef struct
{
	//������������
	Queue q1;
	Queue q2;
} MyStack;

//��ʼ��ջ
MyStack* myStackCreate()
{
	//����һ��ָ��pstָ��һ��ջ
	//Ϊջ����һ��ջ��С���ڴ�ռ�
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//��ʼ��ջ�е���������
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	//����ĺ����ķ���ֵΪMyStack*
	//������Ҫ����һ��ָ��ջ��ָ�룬���ǽ�����õ�ָ�������
	return pst;
}

//��ջ --- ��Ϊ�յĶ�����������
void myStackPush(MyStack* obj, int x)
{
	//�ж��ĸ�����Ϊ��
	//�ж϶����Ƿ�Ϊ�գ����Ե��ú���QueueEmpty
	//����е��ú���QueuePush
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

//��ջ --- ���ǿն����е�size-1��������ӵ�һ���ն����У��ٽ�ԭ�ǿն��е�ʣ�����ݸ�����ȥ
int myStackPop(MyStack* obj)
{
	//��������ĸ�����Ϊ��
	//�������q1Ϊ�ն��У�����q2Ϊ�ǿն���
	Queue* emp = &obj->q1;
	Queue* nonemp = &obj->q2;
	//������������
	if (QueueEmpty(&obj->q2))
	{
		emp = &obj->q2;
		nonemp = &obj->q1;
	}
	//����֪���ĸ�����Ϊ�գ��ĸ�����Ϊ�ǿ���
	//����nonemp����size�����ݣ���nonemp�е�size - 1������
	//��ӵ�emp�У������һ�����ݸ�����ȥ
	//ֻҪ������1���Ͳ���ֹͣ��emp��������
	//��ȡ�����е���Ч���ݸ������Ե��ú��� --- QueueSize
	while (QueueSize(nonemp) > 1)
	{
		//������
		//��nonemp�Ķ�ͷ����һ��һ�����뵽�ն�����
		//��ȡ���еĶ�ͷ���� --- ���ú���QueueFront
		QueuePush(emp, QueueFront(nonemp));
		//�����ݣ���nonemp�е�size-1�����ݶ�����
		//Ϊʲô��Ҫ����nonemp�е������أ�
		//��ȻҪ��nonemp�е����ݵ��뵽emp�У��Ǿͱ���nonemp�в�������Щ������
		//�������Ҫɾ�����ݣ�������ȥ
		QueuePop(nonemp);
	}
	//�������е�����һ�У�˵��nonemp��ֻ��һ��������
	//�۲�ú����ķ���ֵΪint��˵��Ҫ��nonemp�е�Ψһ���ݷ���
	//����һ������top������nonemp��Ψһ������
	int top = QueueFront(nonemp);
	//��nonemp�е����ݳ���ȥ
	QueuePop(nonemp);
	//����ջ��������
	return top;
}

//ȡջ�������� --- ֱ��ȡ�ǿն��е�β��������
int myStackTop(MyStack* obj)
{
	//�ж��ĸ�����Ϊ��
	//ȡ��β�����ݿ��Ե��ú��� --- QueueBack
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

//�ж�ջ�Ƿ�Ϊ��
bool myStackEmpty(MyStack* obj)
{
	//��ô�ж�ջΪ�գ�
	//������q1Ϊ�գ��Ҷ���q2ҲΪ��ʱ�������ջΪ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//����ջ������
void myStackFree(MyStack* obj)
{
	//��ջ�е��������е����ݸ�����
	//���ٶ��е����� --- ���ú���QueueDestory
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	//��Ϊ����ջ�Ŀռ���ͷŵ�
	free(obj);
	obj = NULL;
}
*/












