#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//冒泡排序
void BubbleSort(int* arr, int n)
{
	//定义一个变量flag，初始化为1，假设待排序的序列是升序的
	int flag = 1;
	//趟数
	for (int i = 0; i < n - 1; i++)
	{
		//每趟排序的具体过程
		for (int j = 0; j < n - 1 - i; j++)
		{
			//若下标为 j 的数据大于下标为 j + 1的数据,那么就将两个数据进行交换
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				
				//进入到了if语句中，说明待排序的序列不是升序的，此时将flag赋值为0
				flag = 0;
			}
		}

		//每趟冒泡排序交换后，判断flag是否为1，若为1，跳出循环
		if (1 == flag)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}