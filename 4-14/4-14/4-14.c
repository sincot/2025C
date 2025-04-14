#include <stdio.h>

//直接插入排序 --- 参数为待排序的数组，以及该数组的元素个数
void InsertSort(int* arr, int n)
{
	//循环遍历整个数组
	for (int i = 0; i < n - 1; i++)
	{
		//定义一个变量end始终指向有序序列的最后一项
		int end = i;

		//定义一个变量存储下标为end + 1的数据
		int tmp = arr[end + 1];

		//循环比较
		while (end >= 0)
		{
			//若下标为end的数据大于tmp中存储的数据
			//就将下标为end的数据放在下标为end + 1的位置处
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}

		//代码运行到这，表明了此时end等于0
		//这时将tmp中的数据赋值给数组下标为end + 1的位置
		//这一步就是将小的数据放在数组的前面的操作
		arr[end + 1] = tmp;
	}
}

//希尔排序 --- 参数为待排序的数组，以及该数组的元素个数
void ShellSort(int* arr, int n)
{
	//定义gap，让初始gap的值为数组的元素个数
	int gap = n;

	//预排序
	while (gap > 1)
	{
		//将n个数据分成gap组
		gap = gap / 3 + 1;

		//对每组数据进行直接插入排序
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			arr[end + gap] = tmp;
		}
	}
}

int main()
{
	int arr[] = {4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	ShellSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
