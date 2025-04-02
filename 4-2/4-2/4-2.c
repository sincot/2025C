//�ѵ���ز���

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��˳��ṹʵ�ֶ�

//����ѵĽṹ
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;  //�ײ�������
	int size;         //��Ч���ݸ���
	int capacity;     //�ڴ�ռ�Ĵ�С
}HP;

//�ѵĳ�ʼ��---���ѵĵ�ַ
void HeapInit(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//�ѵ�����
void HeapDestory(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	if (php->arr)
	{
		free(php->arr);
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}

//��������
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���ϵ����㷨
//childΪ�²��뺢�ӽ����±�
void AdjustUp(HPDataType* arr, int child)
{
	//ѭ������
	while (child > 0)
	{
		//��ú��ӽ��ĸ��׽����±�
		int parent = (child - 1) / 2;
		//С��: <  С����С
		//���: >  ����Ҵ�
		if (arr[child] < arr[parent])
		{
			//����
			Swap(&arr[child], &arr[parent]);
			//�±�������
			child = parent;
		}
		else
		{
			break;
		}
	}
}
//�����в�������
void HeapPush(HP* php, HPDataType x)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	//��ô�����в��������أ�
	//Ҫ�������ݵ��ж϶ѵ��ڴ��Ƿ��㹻�ɣ�
	//�жϿռ��Ƿ��㹻
	if (php->size == php->capacity)
	{
		//�ж�capacity�Ƿ�Ϊ��
		//��Ϊ������4��HPDataType��С���ڴ�ռ�
		//����Ϊ�գ���2������
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newcapacity * sizeof(HPDataType));
		//�ж��Ƿ����ݳɹ�
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		//���ݳɹ�
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	//�ռ��㹻
	php->arr[php->size] = x;
	//�������ݺ�Ҫ��������Ȼ���Ƕѽṹ
	//������Ҫ���ϵ������ݣ�ʹ������Ȼ���Ƕѽṹ
	//�������������е����ģ����Բ���������
	//Ҫ֪���²�������±꣬���Բ���Ҫ��size
	AdjustUp(php->arr, php->size);
}

//�ж϶��е���Ч�����Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	//��sizeΪ0ʱ��˵������û����Ч����
	return php->size == 0;
}

//���µ����㷨
//�ӵ�һ����㿪ʼ���µ���
void AdjustDown(HPDataType* arr, int parent, int n)
{
	//���ݸ������±꣬�ҵ������ӽ����±�
	int child = 2 * parent + 1;
	//�����±겻��Խ�磬��childҪС����Ч���ݸ���n
	while (child < n)
	{
		//��ѣ����ӽ�㵱��ֵ���Ľ�� ���: <
		//С�ѣ����ӽ�㵱��ֵ��С�Ľ�� С��: >
		if (arr[child] < arr[child + 1])
		{
			child++;
		}
		//���� ---- ���: >    С��: <  
		//�Һ��ӽ����±겻��Խ��
		if (child + 1 < n && arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			//��������
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}	
	}
}

//����---ɾ���Ѷ�������
void HeapPop(HP* php)
{
	//Ҫɾ�����ݣ����ȵ�Ҫ�ж϶��е���Ч�����Ƿ�Ϊ��
	assert(!HeapEmpty(php));
	//�����ѵ׺ͶѶ�������
	Swap(&php->arr[0], &php->arr[php->size]);
	//ɾ���Ѷ�������
	php->size--;
	//��������---���µ����㷨
	//�������������е����ģ����Բ���Ҫ������
	//�����Ǵӵ�һ����㿪ʼ����������Ҫ֪����һ�������±�
	//���⻹Ҫ��������������ݸ��������Բ���Ҫ��size
	AdjustDown(php->arr, 0, php->size);
}

//��ӡ�ѵ�����
void HeapPrint(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}


int main()
{
	HP ph;

	return 0;
}