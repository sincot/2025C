#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/*
//����N���������д�뵽�ļ���
void CreateData()
{
	//�����ݣ��ٶ����Լ���������Ϊ�˷���۲죬��100������
	int n = 100;

	//�������������
	srand(time(0));

	//����һ���ļ����ļ���Ϊdata.txt
	const char* file = "data.txt";

	//��д�ķ�ʽ���ļ�
	FILE* fin = fopen(file, "w");

	//�ж��ļ��Ƿ�򿪳ɹ�
	if (fin == NULL)
	{
		perror("fopen file fail!");
		exit(1);
	}

	//��n�������
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;

		//���ļ�������������
		fprintf(fin, "%d\n", x);
	}

	//�ر��ļ�
	fclose(fin);
}

int CompareInt(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

//����ʵ�ʶ�ȡ�������ݸ�����û�����ݷ���0
//Ϊ�˱���ÿ�ζ�ȡ����ʱ����Ҫ������Դ�ļ��������ﴫָ��Դ�ļ���ָ��
int ReadNDataSortToFile(FILE* fout, int n, const char* dstfile)
{
	//����һ���ڴ�ռ��СΪn��int���͵�����
	int x = 0;
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		perror("malloc error!");
		return 0;
	}

	//��ȡn������
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		//��֮ǰ�򿪵��ļ��ж�ȡ����
		//�ж��Ƿ��ܹ���ȡ��n�����ݣ����ж�fscanf�Ƿ��ȡ��EOF
		if (fscanf(fout, "%d", &x) == EOF)
		{
			break;
		}
		arr[j++] = x;
	}

	//ʹ�ú���qsort������
	//�ж�j�Ƿ�Ϊ0�����Ƿ��ȡ�������ݣ���һ�����ݶ�û�ж�ȡ������ô��û��Ҫ������
	if (j == 0)
	{
		free(arr);
		return 0;
	}
	qsort(arr, j, sizeof(int), CompareInt);

	//��д�ķ�ʽ��dstfile�ļ�
	FILE* fin = fopen(dstfile, "w");
	if (fin == NULL)
	{
		free(arr);
		perror("fopen dstfile fail!");
		return 0;
	}

	//������õ�����д���ļ�dstfile
	for (int i = 0; i < j; i++)
	{
		fprintf(fin, "%d\n", arr[i]);
	}

	free(arr);
	fclose(fin);

	return j;
}

//����һ���������������ļ�file1���ļ�file2���鲢���ļ�mfile��
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//�Զ��ķ�ʽ���ļ�flie1
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		perror("fopen file1 fail!");
		exit(4);
	}

	//�Զ��ķ�ʽ���ļ�flie2
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		perror("fopen file2 fail!");
		exit(5);
	}

	//��д�ķ�ʽ���ļ�mflie
	FILE* mfin = fopen(mfile, "w");
	if (mfin == NULL)
	{
		perror("fopen mfile fail!");
		exit(6);
	}

	//�鲢
	int x1 = 0;
	int x2 = 0;
	int ret1 = fscanf(fout1, "%d", &x1);
	int ret2 = fscanf(fout2, "%d", &x2);
	//��ȡ�������ݲ���ΪEOF
	while (ret1 != EOF && ret2 != EOF)
	{
		if (x1 < x2)
		{
			//��mfile�ļ���д��x1��x2�еĽ�Сֵ
			fprintf(mfin, "%d\n", x1);
			ret1 = fscanf(fout1, "%d", &x1);
		}
		else
		{
			fprintf(mfin, "%d\n", x2);
			ret2 = fscanf(fout2, "%d", &x2);
		}
	}

	//����ʣ�������
	while (ret1 != EOF)
	{
		fprintf(mfin, "%d\n", x1);
		ret1 = fscanf(fout1, "%d", &x1);
	}

	while (ret2 != EOF)
	{
		fprintf(mfin, "%d\n", x2);
		ret2 = fscanf(fout2, "%d", &x2);
	}
	//�ر��ļ�file1,file2,mfile
	fclose(fout1);
	fclose(fout2);
	fclose(mfin);
}

int main()
{
	CreateData();

	//����3���ļ�,file1,flie2,mflie
	const char* file1 = "file1.txt";
	const char* file2 = "file2.txt";
	const char* mfile = "mfile.txt";

	//�Զ��ķ�ʽ���ļ�data.txt
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen data.txt fail!");
		exit(3);
	}

	//ÿ�ζ�10������
	ReadNDataSortToFile(fout, 10, file1);
	ReadNDataSortToFile(fout, 10, file2);

	//ѭ���鲢
	while (1)
	{
		MergeFile(file1, file2, mfile);

		//ɾ���ļ�file1��file2 --- ʹ�ú���remove
		remove(file1);
		remove(file2);

		//���ļ�mfile������Ϊfile1 --- ʹ�ú���rename
		rename(mfile, file1);

		//ÿ�ζ���ȡ10������
		//�ж��ļ�data.txt���Ƿ�������
		//û�������ˣ�˵���ļ��鲢�������鲢�õ��������ļ�file1��
		if (ReadNDataSortToFile(fout, 10, file2) == 0)
		{
			break;
		}
	}

	fclose(fout);
	return 0;
}
*/

/*
//��������
void CountSort(int* arr, int n)
{
	//�ҵ�ǰ���е����ֵ����Сֵ
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
        
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	//ȷ���½�����Ĵ�С
	int range = max - min + 1;
	int *count = (int*)malloc(sizeof(int) * range);
	if(count == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	//��ʼ���½����� --- ʹ�ú���memset��������ȫ����ʼ��Ϊ0
	memset(count, 0, sizeof(int) * range);

	//ͳ����ͬԪ�س��ֵĴ���
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;  //arr[i] - min �����±�
	}

	//��count�����е����ݻ�ԭ��ԭ����
	int index = 0;  //ԭ�����±������
	
	//����count����
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
}

int main()
{
	int arr[] = { 101, 108, 108, 103, 101, 105, 101 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	CountSort(arr, size);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/

//�ǵݹ�汾�Ŀ������� --- ����

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

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void QuickSortQueue(int* arr, int left, int right)
{
	//����һ������
	Queue q;

	//��ʼ������
	QueueInit(&q);

	//�����
	QueuePush(&q, left);
	QueuePush(&q, right);

	//ֻҪ�����е����ݲ�Ϊ0���Ͳ���ֹͣ����
	while (!QueueEmpty(&q))
	{
		//ȡ���ζ�ͷ������
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);

		//��ȡ����������е������±� [begin , end]
		//ʹ��lomutoǰ��ָ�����һ�׼ֵ
		int key = begin;
		int front = begin;
		int rear = begin + 1;

		while (rear <= end)
		{
			if (arr[rear] < arr[key] && front++ != rear)
			{
				Swap(&arr[front], &arr[rear]);
			}

			rear++;
		}

		Swap(&arr[key], &arr[front]);
		key = front;

		// begin key end
		//����������������������
		if (begin < key - 1)
		{
			//�����
			QueuePush(&q, begin);
			QueuePush(&q, key - 1);
		}

		if (key + 1 < end)
		{
			//�����
			QueuePush(&q, key + 1);
			QueuePush(&q, end);
		}
	}

	//���ٶ���
	QueueDestory(&q);
}

int main()
{
	int arr[] = { 4, 2, 9, 3, 8, 6, 5, 1, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSortQueue(arr, 0, size - 1);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}