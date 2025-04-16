#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//������
//���µ����㷨
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���µ����㷨
void AdjustDown(int* arr, int parent, int n)
{
	int child = 2 * parent + 1;

	while (child < n)
	{
		//��С�ѣ�arr[child] > arr[child + 1]
		//����ѣ�arr[child] < arr[child + 1]
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}

		//��С�ѣ�arr[child] < arr[parent]
		//����ѣ�arr[child] > arr[parent]
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
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
	while (child > 0)
	{
		int parent = (child - 1) / 2;

		//��С�ѣ�arr[child] < arr[parent]
		//����ѣ�arr[child] > arr[parent]
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int n)
{
	//���� -- ���ϵ��������
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}

	//����Ϊ��������
	//����һ������end����ʾ�����������±�
	int end = n - 1;
	while (end > 0)
	{
		//���Ѷ���������ѵ׵����ݽ���
		Swap(&arr[0], &arr[end]);

		//���ϵ����㷨
		AdjustDown(arr, 0, end);

		end--;
	}
}
/*
void HeapSort(int* arr, int n)
{
	//���� -- ���µ��������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}

	//����Ϊ��������
	//����һ������end����ʾ�����������±�
	int end = n - 1;
	while (end > 0)
	{
		//���Ѷ���������ѵ׵����ݽ���
		Swap(&arr[0], &arr[end]);

		//���µ����㷨
		AdjustDown(arr, 0, end);

		end--;
	}
}
*/


int main()
{
	int arr[] = { 19, 37, 56, 29, 20, 17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, size);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}