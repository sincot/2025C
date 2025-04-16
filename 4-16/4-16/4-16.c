#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//堆排序
//向下调整算法
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向下调整算法
void AdjustDown(int* arr, int parent, int n)
{
	int child = 2 * parent + 1;

	while (child < n)
	{
		//建小堆：arr[child] > arr[child + 1]
		//建大堆：arr[child] < arr[child + 1]
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}

		//建小堆：arr[child] < arr[parent]
		//建大堆：arr[child] > arr[parent]
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

//向上调整算法
void AdjustUp(int* arr, int child)
{
	while (child > 0)
	{
		int parent = (child - 1) / 2;

		//建小堆：arr[child] < arr[parent]
		//建大堆：arr[child] > arr[parent]
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
	//建堆 -- 向上调整建大堆
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}

	//调整为升序序列
	//定义一个变量end来表示堆中最后结点的下标
	int end = n - 1;
	while (end > 0)
	{
		//将堆顶的数据与堆底的数据交换
		Swap(&arr[0], &arr[end]);

		//向上调整算法
		AdjustDown(arr, 0, end);

		end--;
	}
}
/*
void HeapSort(int* arr, int n)
{
	//建堆 -- 向下调整建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}

	//调整为升序序列
	//定义一个变量end来表示堆中最后结点的下标
	int end = n - 1;
	while (end > 0)
	{
		//将堆顶的数据与堆底的数据交换
		Swap(&arr[0], &arr[end]);

		//向下调整算法
		AdjustDown(arr, 0, end);

		end--;
	}
}
*/


int main()
{
	int arr[] = { 19, 37, 56, 29, 20, 17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}