#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

////ջ�Ľṹ�Ķ���
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* arr;
//	int top;      //��Ч���ݸ���
//	int capacity; //�ڴ�ռ��С
//}ST;
//
////ջ�ĳ�ʼ��
//void StackInit(ST* pst)
//{
//	pst->arr = NULL;
//	pst->top = pst->capacity = 0;
//}
//
////��ջ
//void StackPush(ST* pst, STDataType x)
//{
//	//����
//	if (pst->top == pst->capacity)
//	{
//		//�ж�ջ���ڴ�ռ��Ƿ�Ϊ��
//		//��Ϊ�գ�������4��STDataType���ʹ�С�Ŀռ�
//		//����Ϊ�գ�������2��
//		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
//		//���ٿռ�
//		STDataType* tmp = (STDataType*)realloc(pst->arr, sizeof(STDataType) * newcapacity);
//		//�ж��ڴ�ռ��Ƿ�����ɹ�
//		if (tmp == NULL)
//		{
//			perror("realloc");
//			exit(1);
//		}
//		//���ݳɹ�
//		pst->arr = tmp;
//		pst->capacity = newcapacity;
//	}
//	//��������
//	pst->arr[pst->top++] = x;
//}
//
////�ж�ջ�е������Ƿ�Ϊ��
//bool StackEmpty(ST* pst)
//{
//	//ջ�ĵ�ַ����ΪNULL
//	assert(pst);
//	return pst->top == 0;
//}
//
////��ջ
//void StackPop(ST* pst)
//{
//	//�ж�ջ�е������Ƿ�Ϊ��
//	assert(!StackEmpty(pst));
//	pst->top--;
//}
//
////ȡջ��������
//STDataType StackTop(ST* pst)
//{
//	//�ж�ջ�������Ƿ�Ϊ��
//	assert(!StackEmpty(pst));
//	//����ջ��������
//	return pst->arr[pst->top - 1];
//}
//
////����ջ�е�����
//void StackDestory(ST* pst)
//{
//	//pst����Ϊ��
//	assert(pst);
//	if (pst->arr)
//	{
//		free(pst->arr);
//	}
//	pst->arr = NULL;
//	pst->top = pst->capacity = 0;
//}
//
//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//void QuickSortNoR(int* arr, int left, int right)
//{
//	//����һ��ջ
//	ST st;
//
//	//��ʼ��ջ
//	StackInit(&st);
//
//	//��ջ --- �ҵ���
//	StackPush(&st, right);
//	StackPush(&st, left);
//
//	//ֻҪջ�е����ݲ�Ϊ0���Ͳ���ֹͣ����
//	while (!StackEmpty(&st))
//	{
//		//ȡ����ջ����Ԫ��
//		//ע���Լ���ǰ����ջ˳��
//		int begin = StackTop(&st);
//		StackPop(&st);
//
//		int end = StackTop(&st);
//		StackPop(&st);
//
//		//��ȡ����������е������±� [begin , end]
//		//ʹ��lomutoǰ��ָ�����һ�׼ֵ
//		int key = begin;
//		int prev = begin;
//		int pcur = prev + 1;
//
//		while (pcur <= end)
//		{
//			if (arr[pcur] < arr[key] && prev++ != pcur)
//			{
//				Swap(&arr[prev], &arr[pcur]);
//			}
//
//			pcur++;
//		}
//
//		Swap(&arr[key], &arr[prev]);
//		key = prev;
//
//		//begin key end
//		//����������������������
//		if (begin < key - 1)
//		{
//			//��ջ
//			StackPush(&st, key - 1);
//			StackPush(&st, left);
//		}
//
//		if (key + 1 < end)
//		{
//			//��ջ
//			StackPush(&st, end);
//			StackPush(&st, key + 1);
//		}
//	}
//
//	//����ջ
//	StackDestory(&st);
//}


//int main()
//{
//	int arr[] = { 4, 7, 5, 8, 7, 6, 3, 7, 1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	QuickSort(arr, 0, size - 1);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


////�鲢����
//void MergeMid(int* arr, int left, int right, int *tmp)
//{
//	//�ݹ����ֹ����
//	if (left >= right)
//	{
//		return;
//	}
//
//	//�ֽ�
//	int mid = left + (right - left) / 2;
//
//	//�����м�ֵ���±�mid����ԭ���л��ֳ�������������
//	//���������䣺[left��mid]  ���������䣺[mid + 1��right]
//	//�������������е��м�ֵ���±�mid
//	MergeMid(arr, left, mid, tmp);
//	MergeMid(arr, mid + 1, right, tmp);
//
//	//�������е��⣬˵�������Ѿ�������ϣ������ٻ�����ȥ��
//	//�ϲ�
//	//���ı�ԭ���е� left �� right ��λ��
//	int begin = left;
//	int end = mid;
//	int rev = mid + 1;
//	int cur = right;
//
//	//ָ��tmp���±�����
//	int index = left;
//	//����������������[begin��end] [rev��cur]
//	while (begin <= end && rev <= cur)
//	{
//		if (arr[begin] < arr[rev])
//		{
//			tmp[index++] = arr[begin++];
//		}
//		else
//		{
//			tmp[index++] = arr[rev++];
//		}
//	}
//
//	//�������е��⣬˵��begin > end �� rev > cur
//	//�����
//	if (begin <= end)
//	{
//		while (begin <= end)
//		{
//			tmp[index++] = arr[begin++];
//		}
//	}
//	else
//	{
//		while (rev <= cur)
//		{
//			tmp[index++] = arr[rev++];
//		}
//	}
//
//	//��tmp�е�Ԫ�ؿ�����ԭ������
//	memcpy(arr, tmp, sizeof(int) * (right + 1));
//}
//
//void MergeSort(int* arr, int n)
//{
//	//����һ����ԭ����һ������ڴ�ռ䣬������ʱ��Ŵ����������е�Ԫ��
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	MergeMid(arr, 0, n - 1, tmp);
//
//	//��������ڴ�ռ仹������ϵͳ
//	free(tmp);
//	tmp = NULL;
//}


//�ǵݹ�汾�Ĺ鲢����
void MergeSortNoR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	int gap = 1;

	while (gap < n)
	{
		//����gap�������飬�����ϲ�
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin = i;
			int end = i + gap - 1;
			int rev = i + gap;
			int cur = i + gap + gap - 1;
			int index = i;
			
			//û����������
			if (rev >= n)
			{
				//����ѭ����gap�����������ٽ���ѭ��
				break;  
			}
			//�����е�Ԫ�ظ�������gap��
			if (cur >= n)
			{
				cur = n - 1;
			}
			//�����������кϲ�
			while (begin <= end && rev <= cur)
			{
				if (arr[begin] < arr[rev])
				{
					tmp[index++] = arr[begin++];
				}
				else
				{
					tmp[index++] = arr[rev++];
				}
			}

			if (begin <= end)
			{
				while (begin <= end)
				{
					tmp[index++] = arr[begin++];
				}
			}
			else
			{
				while (rev <= cur)
				{
					tmp[index++] = arr[rev++];
				}
			}

			//������õ������е�Ԫ�ؿ�����ԭ����
			memcpy(arr + i, tmp + i, sizeof(int) * (cur - i + 1));
		}
		gap *= 2;
	}
}

int main()
{
	int arr[] = { 3, 5, 7, 1, 2, 8, 9, 4, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	MergeSortNoR(arr, size);
	
	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
    return 0;
}