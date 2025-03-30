#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
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

//��������Queue�����У�
typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

//���--��β
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//���в�Ϊ��
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//����--��ͷ
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

//ȡ��ͷ����
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

//���е�����
void QueueDeatory(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
}

//�����е���ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

//*****************���нṹ��ʵ�ַ�ʽ********************************

//�ṹ��ĳ�ʼ��
MyStack* myStackCreate()
{
	//����һ��ָ��pst
	//�����ϵͳ����ջ��С���ڴ�ռ�
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//�Ե�ǰջ�ṹ�е���������q1��q2���г�ʼ��
	//���г�ʼ��ֱ�ӵ��ú���QueueInit
	//QueueInit�Ĳ����ǵ�ַ������Ҫȡ��ַ
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

//��ջ
void myStackPush(MyStack* obj, int x)
{
	//����Ϊ�յĶ����в�������
	//���ж��ĸ�����Ϊ�գ��ٽ����ݲ��벻Ϊ�յĶ���
	//�ж϶����Ƿ�Ϊ�տ��Ե��ú���QueueEmpty
	if (!QueueEmpty(&obj->q1))//��q1���в�Ϊ�գ�����q1�����в�������
	{
		//��Ӳ������Ե��ú���QueuePush
		QueuePush(&obj->q1, x);
	}
	else//��q2���в�Ϊ�գ�����q2�����в�������
	{
		QueuePush(&obj->q2, x);
	}
}

//��ջ
int myStackPop(MyStack* obj)
{
	//�Ѳ�Ϊ�ն���ǰ��size - 1������Ų����һ�������У��ٽ����һ�����ݳ���
	//�ж��ĸ�����Ϊ�գ������ȼ���q1����Ϊ�գ�q2���в�Ϊ��
	Queue* emp = &obj->q1;
	Queue* nonemp = &obj->q2;
	//����������ټ�ʱ����
	//����q2���ǿ��б�
	if (QueueEmpty(&obj->q2))
	{
		emp = &obj->q2;
		nonemp = &obj->q1;
	}
	//��ȡ�ǿն�������ЧԪ�صĸ������Ե��ú���QueueSize
	//���ǿն����е���Ч���ݸ�������һ
	//����Ҫ���ǿն��е�ǰsize-1������Ų���ն������ٽ����һ�����ݳ���
	//���ǿն��е���Ч���ݸ���Ϊһ������Ų�����ݣ�ֱ�ӽ������ݳ��Ӽ���
	while (QueueSize(nonemp) > 1)
	{
		//Ų���ݣ�ȡ�ǿն��еĶ�ͷ���ٽ���������ӵ��ն�����
		//ȡ��ͷ�����ݿ��Ե��ú���QueueFront
		//��ӿ��Ե��ú���QueuePush
		QueuePush(emp, QueueFront(nonemp));
		//�ٽ���ͷ�����ݳ�������Ҳ����Ҫ�Ѷ�ͷ����������
		//���ӿ��Ե��ú���QueuePop
		QueuePop(nonemp);
	}
	//����ѭ����˵���ǿն�����ֻʣ��һ������
	//����ֱ��ȡ��ͷ��������
	//����һ�����������ն�ͷ���ݵķ���ֵ
	int top = QueueFront(nonemp);
	//����Ψһ�������ٳ���ȥ
	QueuePop(nonemp);
	return top;
}

//ȡջ������
int myStackTop(MyStack* obj)
{
	//ȡ�ǿն�����β��������
	//�ж��ĸ�����Ϊ��,�ĸ����в�Ϊ�գ���ȡ�ĸ����ж�β������
	if (!QueueEmpty(&obj->q1))
	{
		//ֱ��ȡ��β����,���ú���QueueBack
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
    //��q1����Ϊ��,q2����ҲΪ��ʱ����˵��ջΪ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//����
void myStackFree(MyStack* obj)
{
	//�����ٶ��е��ڴ�ռ䣬ֱ�ӵ��ú���QueueDestory
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	//������ջ���ڴ�ռ�
	free(obj);
	obj = NULL;
}
*/


//����ջ�Ľṹ
typedef char STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
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
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
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
	ps->top--;
}

//��ȡջ��������
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
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



typedef struct
{
	//��������ջpushST��popST
	ST pushST;
	ST popST;
} MyQueue;

//���еĳ�ʼ��
MyQueue* myQueueCreate()
{
	//�����ϵͳ������д�С�Ŀռ�
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	//��ջ���г�ʼ�����������Ե��ú���StackInit
	StackInit(&pq->pushST);
	StackInit(&pq->popST);

	return pq;
}

//���
void myQueuePush(MyQueue* obj, int x)
{
	//ֱ����pushST�в�������
	//��ջ�������Ե��ú���StackPush
	StackPush(&obj->pushST, x);
}

//����
int myQueuePop(MyQueue* obj)
{
	//Ҫ�����popSTΪ��ʱ��popST��Ϊ��ʱ
	//�ж�ջ�Ƿ�Ϊ��,���Ե��ú���StackEmpty
	//��popSTΪ�գ���Ҫ��pushST�е�����ȫ���洢��popST��
	// Ȼ���ٳ�popSTջ��������
	//��ջ�������Ե��ú���StackPop
	if (StackEmpty(&obj->popST))
	{
		//Ų����
		//�ж�pushST�Ƿ�Ϊ��
		//��Ϊ����ѭ��Ų������
		while (!StackEmpty(&obj->pushST))
		{
			//��pushST�е�ջ�������뵽popST��
			StackPush(&obj->popST, StackTop(&obj->pushST));
			//�ٽ�pushST�е�ջ������ɾ����Ҳ���ǳ�����
			//��ջ����ֱ�ӵ��ú���StackPop
			StackPop(&obj->pushST);
		}
	}
	//û�н���if��˵��popST��Ϊ�գ���ֱ��ȡpopST��ջ������
	//�Ƚ�popST��ջ�����ݴ洢������������Ϊ����ֵ
	//��Ϊ֮�󻹻�ɾ��popST��ջ��������
	//ȡջ�����ݿ��Ե��ú���StackTop
	int top = StackTop(&obj->popST);
	//ɾ��ջ�����ݣ�Ҳ����ִ�г�ջ����,���ú���STackPop
	StackPop(&obj->popST);

	return top;
}

//ȡ��ͷ����
int myQueuePeek(MyQueue* obj)
{
	//�߼�ͬ���Ӳ���
	//Ҫ�����popSTΪ��ʱ��popST��Ϊ��ʱ
	//�ж�ջ�Ƿ�Ϊ��,���Ե��ú���StackEmpty
	//��popSTΪ�գ���Ҫ��pushST�е�����ȫ���洢��popST��
	//Ȼ���ٳ�popSTջ��������
	//��ջ�������Ե��ú���StackPop
	if (StackEmpty(&obj->popST))
	{
		//Ų����
		//�ж�pushST�Ƿ�Ϊ��,��Ϊ����ѭ��Ų������
		while (!StackEmpty(&obj->pushST))
		{
			//��pushST�е�ջ�������뵽popST��
			StackPush(&obj->popST, StackTop(&obj->pushST));
			//�ٽ�pushST�е�ջ������ɾ����Ҳ���ǳ�����
			//��ջ����ֱ�ӵ��ú���StackPop
			StackPop(&obj->pushST);
		}
	}
	//û�н���if��˵��popST��Ϊ�գ���ֱ��ȡpopST��ջ������
	//ȡջ�����ݿ��Ե��ú���StackTop
	return StackTop(&obj->popST);
}

//�ж϶����Ƿ�Ϊ��
bool myQueueEmpty(MyQueue* obj)
{
	//Ҫ�ж϶����Ƿ�Ϊ�գ���Ҫ�ж�����ջpushST��popST�Ƿ�Ϊ��
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

//���ٶ���
void myQueueFree(MyQueue* obj)
{
	//���ٶ��е��ڴ�ռ�
	//���Ƚ��������ջ�������٣����Ե��ú���StackDestory
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);
    //�ͷŶ��е��ڴ�ռ�
	free(obj);
	obj = NULL;
}


//�����ֵܱ�ʾ��
struct TreeNode
{
	struct Node* child;    //��߿�ʼ�ĵ�һ�����ӽ��
	struct Node* brother;  //ָ�����ұߵ���һ���ֵܽ��  
	int data;              //����е�������
};