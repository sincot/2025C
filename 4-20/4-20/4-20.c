#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

////栈的结构的定义
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* arr;
//	int top;      //有效数据个数
//	int capacity; //内存空间大小
//}ST;
//
////栈的初始化
//void StackInit(ST* pst)
//{
//	pst->arr = NULL;
//	pst->top = pst->capacity = 0;
//}
//
////入栈
//void StackPush(ST* pst, STDataType x)
//{
//	//增容
//	if (pst->top == pst->capacity)
//	{
//		//判断栈的内存空间是否为空
//		//若为空，则申请4个STDataType类型大小的空间
//		//若不为空，则增容2倍
//		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
//		//开辟空间
//		STDataType* tmp = (STDataType*)realloc(pst->arr, sizeof(STDataType) * newcapacity);
//		//判断内存空间是否申请成功
//		if (tmp == NULL)
//		{
//			perror("realloc");
//			exit(1);
//		}
//		//增容成功
//		pst->arr = tmp;
//		pst->capacity = newcapacity;
//	}
//	//插入数据
//	pst->arr[pst->top++] = x;
//}
//
////判断栈中的数据是否为空
//bool StackEmpty(ST* pst)
//{
//	//栈的地址不能为NULL
//	assert(pst);
//	return pst->top == 0;
//}
//
////出栈
//void StackPop(ST* pst)
//{
//	//判断栈中的数据是否为空
//	assert(!StackEmpty(pst));
//	pst->top--;
//}
//
////取栈顶的数据
//STDataType StackTop(ST* pst)
//{
//	//判断栈中数据是否为空
//	assert(!StackEmpty(pst));
//	//返回栈顶的数据
//	return pst->arr[pst->top - 1];
//}
//
////销毁栈中的数据
//void StackDestory(ST* pst)
//{
//	//pst不能为空
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
//	//定义一个栈
//	ST st;
//
//	//初始化栈
//	StackInit(&st);
//
//	//入栈 --- 右到左
//	StackPush(&st, right);
//	StackPush(&st, left);
//
//	//只要栈中的数据不为0，就不会停止排序
//	while (!StackEmpty(&st))
//	{
//		//取两次栈顶的元素
//		//注意自己先前的入栈顺序
//		int begin = StackTop(&st);
//		StackPop(&st);
//
//		int end = StackTop(&st);
//		StackPop(&st);
//
//		//获取待排序的序列的左右下标 [begin , end]
//		//使用lomuto前后指针来找基准值
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
//		//处理左子序列与右子序列
//		if (begin < key - 1)
//		{
//			//入栈
//			StackPush(&st, key - 1);
//			StackPush(&st, left);
//		}
//
//		if (key + 1 < end)
//		{
//			//入栈
//			StackPush(&st, end);
//			StackPush(&st, key + 1);
//		}
//	}
//
//	//销毁栈
//	StackDestory(&st);
//}


//int main()
//{
//	int arr[] = { 4, 7, 5, 8, 7, 6, 3, 7, 1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	QuickSort(arr, 0, size - 1);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


////归并排序
//void MergeMid(int* arr, int left, int right, int *tmp)
//{
//	//递归的终止条件
//	if (left >= right)
//	{
//		return;
//	}
//
//	//分解
//	int mid = left + (right - left) / 2;
//
//	//根据中间值的下标mid，将原序列划分成左右两个序列
//	//左序列区间：[left，mid]  右序列区间：[mid + 1，right]
//	//继续找左右序列的中间值的下标mid
//	MergeMid(arr, left, mid, tmp);
//	MergeMid(arr, mid + 1, right, tmp);
//
//	//代码运行到这，说明序列已经二分完毕，不能再划分下去了
//	//合并
//	//不改变原序列的 left 与 right 的位置
//	int begin = left;
//	int end = mid;
//	int rev = mid + 1;
//	int cur = right;
//
//	//指向tmp的下标索引
//	int index = left;
//	//遍历两个序列区间[begin，end] [rev，cur]
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
//	//代码运行到这，说明begin > end 或 rev > cur
//	//分情况
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
//	//将tmp中的元素拷贝到原序列中
//	memcpy(arr, tmp, sizeof(int) * (right + 1));
//}
//
//void MergeSort(int* arr, int n)
//{
//	//创建一个与原数组一样大的内存空间，用来临时存放待排序序列中的元素
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	MergeMid(arr, 0, n - 1, tmp);
//
//	//将申请的内存空间还给操作系统
//	free(tmp);
//	tmp = NULL;
//}


//非递归版本的归并排序
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
		//根据gap来划分组，两两合并
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin = i;
			int end = i + gap - 1;
			int rev = i + gap;
			int cur = i + gap + gap - 1;
			int index = i;
			
			//没有右子序列
			if (rev >= n)
			{
				//跳出循环，gap扩大两倍后，再进入循环
				break;  
			}
			//右序列的元素个数不足gap个
			if (cur >= n)
			{
				cur = n - 1;
			}
			//两个有序序列合并
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

			//将排序好的序列中的元素拷贝到原序列
			memcpy(arr + i, tmp + i, sizeof(int) * (cur - i + 1));
		}
		gap *= 2;
	}
}

int main()
{
	int arr[] = { 3, 5, 7, 1, 2, 8, 9, 4, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	MergeSortNoR(arr, size);
	
	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
    return 0;
}