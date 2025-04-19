#include <stdio.h>

//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
////hoare版本的找基准值
//int QuickHoare(int* arr, int left, int right)
//{
//	//假设基准值开始为序列最左端的元素
//	int key = left;
//	left += 1;
//
//	while (left <= right)
//	{
//		//先让right从右向左找比基准值小的元素
//		while (left <= right && arr[right] > arr[key])
//		{
//			right--;
//		}
//		//代码运行到这，说明right已经找到了
//
//		//再让left从左向右找比基准值大的元素
//		while (left <= right && arr[left] < arr[key])
//		{
//			left++;
//		}
//		//代码运行到这，说明left已经找到了
//
//		//接下来来判断 left 与 right 间的大小关系
//		if (left <= right)
//		{
//			Swap(&arr[left++], &arr[right--]);
//		}
//	}
//
//	//代码运行到这，说明left > right
//	//此时将基准值放到下标为 right 处
//	Swap(&arr[key], &arr[right]);
//
//	return right;
//}
//
////lomuto前后指针 
//int QuickLomuto(int* arr, int left, int right)
//{
//	int key = left;
//
//	//定义两个前后变量
//	int prev = left;
//	int pcur = prev + 1;
//
//	//pcur不能越界
//	while (pcur <= right)
//	{
//		if (arr[pcur] < arr[key] && prev++ != pcur)
//		{
//			Swap(&arr[prev], &arr[pcur]);
//		}
//
//		pcur++;
//	}
//
//	//代码运行到这，说明 pcur 已经越界了
//	//将 key 与 prev指向的元素进行交换
//	Swap(&arr[key], &arr[prev]);
//
//	//此时prev指向的元素就是要找到基准值
//	return prev;
//}

////快速排序
//void QuickSort(int* arr, int left, int right)
//{
//	//递归终止的条件
//	if (left >= right)
//	{
//		return;
//	}
//	//找基准值
//	int key = QuickLomuto(arr, left, right);
//
//	//递归左子序列
//	QuickSort(arr, left, key - 1);
//
//	//递归右子序列
//	QuickSort(arr, key + 1, right);
//}


int main()
{
	int arr[] = {4, 2, 9, 3, 8, 6, 5, 1, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, size - 1);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}