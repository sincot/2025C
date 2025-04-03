//�ѵ���ز���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��˳��ṹʵ�ֶ�
/*
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
	php->size++;
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
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		//���� ---- ���: >    С��: <  
		//�Һ��ӽ����±겻��Խ��
		if (arr[child] < arr[parent])
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
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	//ɾ���Ѷ�������
	php->size--;
	//��������---���µ����㷨
	//�������������е����ģ����Բ���Ҫ������
	//�����Ǵӵ�һ����㿪ʼ����������Ҫ֪����һ�������±�
	//���⻹Ҫ��������������ݸ��������Բ���Ҫ��size
	AdjustDown(php->arr, 0, php->size);
}

//ȡ�Ѷ�����
HPDataType HeapTop(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);
	//�Ѷ������ݾ��������±�Ϊ0������
	return php->arr[0];
}

//��ӡ�ѵ�����
void HeapPrint(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	//assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

//Ƶ��ȡ�Ѷ����ݣ�Ȼ���ٽ��Ѷ�������ɾ��
void test1()
{
	HP hp;
	HeapInit(&hp);

	HeapPush(&hp, 56);
	HeapPush(&hp, 10);
	HeapPush(&hp, 15);
	HeapPush(&hp, 30);
	HeapPrint(&hp);

	while (!HeapEmpty(&hp))
	{
		int top = HeapTop(&hp);
		printf("%d ", top);
		HeapPop(&hp);
	}
	HeapDestory(&hp);
}
*/

/*
//��������
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���µ����㷨
//�ӵ�һ����㿪ʼ���µ���
void AdjustDown(int* arr, int parent, int n)
{
	//���ݸ������±꣬�ҵ������ӽ����±�
	int child = 2 * parent + 1;
	//�����±겻��Խ�磬��childҪС����Ч���ݸ���n
	while (child < n)
	{
		//��ѣ����ӽ�㵱��ֵ���Ľ�� ���: <
		//С�ѣ����ӽ�㵱��ֵ��С�Ľ�� С��: >
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		//���� ---- ���: >    С��: <  
		//�Һ��ӽ����±겻��Խ��
		if (arr[child] > arr[parent])
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

//���ϵ����㷨
void AdjustUp(int* arr, int child)
{
	//ѭ������
	while (child > 0)
	{
		//��ú��ӽ��ĸ��׽����±�
		int parent = (child - 1) / 2;
		//С��: <  С����С
		//���: >  ����Ҵ�
		if (arr[child] > arr[parent])
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

//������ --- ���öѵ�˼��������
void HeapSort(int* arr, int n)
{
	
	//��һ���� ���� --- ���µ�������
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
		//AdjustDown(arr, i, n);
	//}
	

	//��һ���� ���� --- ���ϵ�������
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}

	//�ڶ�����  ���Ѷ������ݺ����һ�����ݽ���λ��
	//Ȼ���ټ���size�������µ����ѣ��ظ������Ĳ���
	int end = n - 1;
	while (end > 0)
	{
		//���Ѷ������ݺ����һ�����ݽ���λ��
		Swap(&arr[0], &arr[end]);
		//�����µ�����
		AdjustDown(arr, 0, end);
		//�ټ���
		end--;
	}
}

int main()
{
	//test1();
	int arr[6] = { 19, 15, 20, 17, 13, 10 };
	HeapSort(arr, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/


/*
//TOP-K����
//��������
void CreatNData()
{
	//������---��10�������
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, 'w');
	if (fin == NULL)
	{
		perror("fopen");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		//���������---����0~1000000������
		int x = (rand() + i) % 1000000;
		//�����Ǵ����ļ���
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

//���µ����㷨
//�ӵ�һ����㿪ʼ���µ���
void AdjustDown(int* arr, int parent, int n)
{
	//���ݸ������±꣬�ҵ������ӽ����±�
	int child = 2 * parent + 1;
	//�����±겻��Խ�磬��childҪС����Ч���ݸ���n
	while (child < n)
	{
		//��ѣ����ӽ�㵱��ֵ���Ľ�� ���: <
		//С�ѣ����ӽ�㵱��ֵ��С�Ľ�� С��: >
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		//���� ---- ���: >    С��: <  
		//�Һ��ӽ����±겻��Խ��
		if (arr[child] < arr[parent])
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

void TOP_K()
{
	//�涨Ҫ��ȡ��������
	int k = 0;
	printf("������K��");
	scanf("%d", &k);

	//�ڸô���·���´���һ���ļ�data.txt
	//��ָ�벻�ܱ��޸ģ�������const�����Σ�����ȫһЩ
	const char* file = "data.txt"; 
	//��data.txt�ļ��ж�����
	FILE* fout = fopen(file, "r");
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (fout == NULL)
	{
		perror("fopen");
		exit(1);
	}
	//������ǰK�����ݣ���С��
	//��̬����һ���������洢ǰK������
	int* minHeap = (int*)malloc(sizeof(int) * k);
	//�жϿռ俪���Ƿ�ɹ�
	if (minHeap == NULL)
	{
		perror("malloc");
		exit(2);
	}
	//��ȡ�ļ������ݣ��ļ��Ķ�ȡ��fscanf
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//ĿǰminHeap�����Ƕѽṹ
	//���������µ�������
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		//����AdjustDown����
		AdjustDown(minHeap, i, k);
	}
	//����ʣ�µ�n - k�����ݣ����Ѷ���Ƚ�
	//���ݴ���滻�Ѷ�Ԫ��
	
	//����һ�������洢��ȡ��������
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//��x��minHeap�еĶѶ����ݽ��бȽ�
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			//�滻���֮�����µ�����ʹ֮��Ϊ�ѽṹ
			AdjustDown(minHeap, 0, k);
		}
	}
	//�Ѿ���������ʣ�µ�n-k������
	//ǰk�������Ѿ���n������������
	//��ӡ��ǰk������
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}

	//�ر��ļ�
	fclose(fout);
}
*/


//��ʽ�ṹ�Ķ�����

//������ʽ�ṹ�Ķ�����
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;