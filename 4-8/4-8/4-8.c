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


//**************************************������ջ����ز���*******************************
/*
//������еĽṹ
typedef struct
{
	ST pushST; //ר�����������ݵ�ջ
	ST popST;  //ר�����������ݵ�ջ
} MyQueue;

//��ʼ������
MyQueue* myQueueCreate()
{
	//����һ��ָ����е�ָ��
	//Ϊ���п���MyQueue��С���ڴ�ռ䣬֮������ʱ�ǵ��ͷ��ⲿ���ڴ�ռ�
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	//��ʼ��ջ --- ���ú���SatckInit
	StackInit(&pq->pushST);
	StackInit(&pq->popST);

	//�ú����ķ���ֵ����ΪMyQueue*
	//˵��Ҫ����һ�����еĵ�ַ��ֱ�ӽ����Ƕ���õ�pq����
	return pq;
}

//��� --- ������ȫ���뵽pushSTջ��
void myQueuePush(MyQueue* obj, int x)
{
	//��ջ --- ���ú���StackPush
	StackPush(&obj->pushST, x);
}

//����
//��ջpopSTΪ�գ���pushST�е�����ȫ����ջ��popST��
//��ջpopST��Ϊ�գ�ֱ�ӽ���ջpopSTִ�г�ջ����
int myQueuePop(MyQueue* obj)
{
	//�ж�ջpopST�Ƿ�Ϊ�� --- �ж�ջ�Ƿ�Ϊ�� --- ���ú���StackEmpty
	if (StackEmpty(&obj->popST))
	{
		//Ҫ��pushST�е�����ȫ����ջ��popST��
		//�͵�Ҫ֪��pushST���ж��ٸ����ݣ���ջ���ж��ٸ����� --- ���ú���StackSize
		while (StackSize(&obj->pushST))
		{
			//��pushST��ջ����������ջ��popST��
			//ȡջ�������� --- ���ú���StackTop
			StackPush(&obj->popST, StackTop(&obj->pushST));
			
			//��pushSt�е�����ɾ��
			StackPop(&obj->pushST);
		}
	}

	//�����ķ���ֵΪint��˵��Ҫ�������ͷ���ݸ�����
	//����֮��Ҫ��ջ�������ݸ�ɾ����������Ҫ���Ƚ�popST��ջ���������ñ�����������������ٷ���
	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return top;
}

//ȡ��ͷ���� --- �������ͬ�Ĳ���
int myQueuePeek(MyQueue* obj)
{
	//�ж�popST�Ƿ�Ϊ��
	if (StackEmpty(&obj->popST))
	{
		while (StackSize(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	//���ڲ���ɾ��ջ�������ݣ����Կ���ֱ�ӽ�ջ�������ݸ�����
	return StackTop(&obj->popST);
}

//�ж϶����Ƿ�Ϊ��
bool myQueueEmpty(MyQueue* obj)
{
	//��ô�ж϶����Ƿ�Ϊ�գ�
	//��pushST��popST����ջ��Ϊ��ʱ�����˵������Ϊ��
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

//���ٶ���
void myQueueFree(MyQueue* obj)
{
	//�Ƚ����нṹ�е�����ջ������
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);

	//֮ǰΪ���п������ڴ�ռ䣬Ҫ������������ϵͳ��ֱ��free����Ȼ���ֶ��ÿ�
	free(obj);
	obj = NULL;
}
*/




//����ѭ�����еĽṹ
typedef struct
{
	int* arr; //��Ȼ������Ľṹʵ��ѭ�����У���ô�ṹ��ĳ�Ա������һ����Ҫ������
    //Ϊʲô������������������Ϊint*
	//�۲�����myCircularQueueEnQueue�������������в��������Ϊint���ͣ���ô����Ҳ�ǵ�Ϊint*����
	int front; //��ʾ��ͷ
	int rear; //��ʾ��β
	//֮�󻹵�Ҫ֪�����еĳ���Ϊ���٣�Ϊ�˽����еĳ���k���������������ﶨ��һ���ṹ���Ա����
	int capacity;//��¼ѭ�����еĳ���
} MyCircularQueue;

//��ʼ��ѭ������
MyCircularQueue* myCircularQueueCreate(int k)
{
	//����һ��ָ�룬ָ��ѭ������
	//Ϊѭ�����п���MyCircularQueue��С���ڴ�ռ�
	MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	//��ָ����ĳ�Ա��ʼ��
    //��ʼ������ --- Ϊ��������k + 1��int*��С���ڴ�ռ�
	pq->arr = (int*)malloc(sizeof(int*) * (k + 1));
	//��ʼ��ָ���ͷ�Ͷ�β�ı��� --- ����ָ���±�Ϊ0��λ��
	pq->front = pq->rear = 0;
	//��ʼ��capacity --- ��kֱ�Ӹ�ֵ��capacity
	pq->capacity = k;

	//�۲캯���ķ���ֵΪMyCircularQueue*
	//˵��Ҫ��ѭ�����еĵ�ַ���أ�ֱ�ӽ�����õ�pq������
	return pq;
}

//�ж�ѭ�������е������Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	//��ô�ж϶����е������Ƿ�Ϊ��
	//��ָ���ͷ�ı���front����ָ���β�ı���rearʱ
	//����˵�������е�����Ϊ��
	return obj->front == obj->rear;
}

//�ж�ѭ�������е������Ƿ�Ϊ��
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	//��ô�ж϶����е������Ƿ�����
	//��(rear + 1�� % (k + 1)����frontʱ
	//����˵�������е���������
	return (obj->rear + 1) % (obj->capacity + 1) == (obj->front);
}

//��ѭ�������в�������
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//�ж϶��еĿռ��Ƿ����� --- ���ú���myCircularQueueIsFull
	if (myCircularQueueIsFull(obj))
	{
		//�������е��������ˣ��Ͳ����ٲ��������ˣ�ֱ�ӷ���false
		return false;
	}
	//�������е��⣬����˵�������е����ݻ�û����
	//��rearָ���λ�ò�������
	obj->arr[obj->rear++] = value;

	//rear++����Ҫ��ֹrearԽ�磬����ѭ���ṹ
	obj->rear %= obj->capacity + 1;

	//����ɹ�������true
	return true;
}

//ɾ��ѭ�������е�Ԫ��
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	//Ҫɾ�������ܵ������ݿ�ɾ�ɣ��������е����ݲ���Ϊ��
	//�ж϶����е������Ƿ�Ϊ�� --- ���ú���myCircularQueueIsFull
	if (myCircularQueueIsFull(obj))
	{
		//�������е�����Ϊ�գ��򷵻�false
		return false;
	}
	//�������е��⣬����˵�������е����ݲ�Ϊ��
	//ɾ������ֱ�ӽ�front++����
	obj->front++;
	//��ô��Ҫ����frontֱ��++���ɲ�����Խ���أ�
	//���ܻ�Խ�磬������Ҫ��rear��������֯frontԽ�磬����ѭ���ṹ
	obj->front %= obj->capacity + 1;

	//ɾ���ɹ�������true
	return true;
}

//ȡѭ�����ж�ͷ������
int myCircularQueueFront(MyCircularQueue* obj)
{
	//Ҫ��ȡ�����ݣ����ȶ����е����ݲ���Ϊ��
	//����Ҫ���ж϶����Ƿ�Ϊ�� --- ���ú���myCircularQueueIsEmpty
	if (myCircularQueueIsEmpty(obj))
	{
		//�������е�����Ϊ�գ��򷵻�-1
		return -1;
	}

	//�������е��⣬˵�������е����ݲ�Ϊ��
	//ֱ�ӽ��±�Ϊfront�����ݸ�����
	return obj->arr[obj->front];
}

//ȡѭ�����ж�β������
int myCircularQueueRear(MyCircularQueue* obj)
{
	//Ҫ��ȡ�����ݣ����ȶ����е����ݲ���Ϊ��
	//����Ҫ���ж϶����Ƿ�Ϊ�� --- ���ú���myCircularQueueIsEmpty
	if (myCircularQueueIsEmpty(obj))
	{
		//�������е�����Ϊ�գ��򷵻�-1
		return -1;
	}

	//����һ����������rearǰ���±�
	int prev = obj->rear - 1;
	
	//��rear���±�Ϊ0�������ζ��rear-1��prev��Խ��,������Ҫ���⴦��
	if (obj->rear == 0)
	{
		prev = obj->capacity + 1;
	}

	//��ʱprevָ���λ�þ�Ϊ��β�����ݣ�ֱ�ӽ��±�Ϊprev�����ݷ���
	return obj->arr[prev];
}

//����ѭ�������е�����
void myCircularQueueFree(MyCircularQueue* obj)
{
	//��Ϊ���鿪�ٵ��ڴ�ռ��free��
	if (obj->arr)
	{
		free(obj->arr);
	}
	//��Ϊѭ�����п��ٵ��ڴ�ռ��free���������ֶ��ÿ�
	free(obj);
	obj = NULL;
}


