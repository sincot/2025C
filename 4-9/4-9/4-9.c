#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//����ѭ�����еĽṹ
typedef struct
{
	int* arr;
	int front; //��ʾ��ͷ
	int rear; //��ʾ��β
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
*/

/*
//���ŵ�ƥ��

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
	//����ṹ��
	ST st;

	StackInit(&st);
	//����һ��ָ���������ַ���
	char* pi = s;

	while (*pi != '\0')
	{
		//��ջ
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		//��ջ
		else
		{
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}

			char ch = StackTop(&st);
			if ((ch == '(' && *pi == ')') || (ch == '[' && *pi == ']') || (ch == '{' && *pi == '}'))
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
	bool ret = StackEmpty(&st) ? true : false;
	StackDestory(&st);
	return ret;
}
*/