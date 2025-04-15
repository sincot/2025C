#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//选择排序
void SelectSort(int* arr, int n)
{
	//定义两个变量begin与end
	//begin指向数组下标为0的位置，end指向数组下标为n - 1的位置
	int begin = 0;
	int end = n - 1;

	//只要begin所指向的数组下标小于end所指向的数组的下标，循环就不会停止
	while (begin < end)
	{
		//定义两个变量min与max
		//min指向的位置与begin相同，max指向的位置与begin相同
		int min = begin;
		int max = begin;

		//让min遍历序列寻找begin~end范围内最小的数据的下标
		//让max遍历序列寻找begin~end范围内最大的数据的下标
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}

		//找到begin~end范围内的最小值与最大值的下标后
		//将数组下标为min的数据与数组下标为begin的数据进行交换
		//将数组下标为mmax的数据与数组下标为end的数据进行交换

		//进行特殊处理
		//当max所指向的位置与begin的相同或min指向的位置与end相同时
		//变换max所指向的位置，让max指向min所指向的位置
		if (max == begin)
		{
			max = min;
		}

		Swap(&arr[begin], &arr[min]);
		Swap(&arr[end], &arr[max]);

		//交换完毕后，begin++，end--，缩小序列的范围
		begin++;
		end--;
	}
}

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
	SelectSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
