#include <stdio.h>

//void Swap(int* px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
////hoare�汾���һ�׼ֵ
//int QuickHoare(int* arr, int left, int right)
//{
//	//�����׼ֵ��ʼΪ��������˵�Ԫ��
//	int key = left;
//	left += 1;
//
//	while (left <= right)
//	{
//		//����right���������ұȻ�׼ֵС��Ԫ��
//		while (left <= right && arr[right] > arr[key])
//		{
//			right--;
//		}
//		//�������е��⣬˵��right�Ѿ��ҵ���
//
//		//����left���������ұȻ�׼ֵ���Ԫ��
//		while (left <= right && arr[left] < arr[key])
//		{
//			left++;
//		}
//		//�������е��⣬˵��left�Ѿ��ҵ���
//
//		//���������ж� left �� right ��Ĵ�С��ϵ
//		if (left <= right)
//		{
//			Swap(&arr[left++], &arr[right--]);
//		}
//	}
//
//	//�������е��⣬˵��left > right
//	//��ʱ����׼ֵ�ŵ��±�Ϊ right ��
//	Swap(&arr[key], &arr[right]);
//
//	return right;
//}
//
////lomutoǰ��ָ�� 
//int QuickLomuto(int* arr, int left, int right)
//{
//	int key = left;
//
//	//��������ǰ�����
//	int prev = left;
//	int pcur = prev + 1;
//
//	//pcur����Խ��
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
//	//�������е��⣬˵�� pcur �Ѿ�Խ����
//	//�� key �� prevָ���Ԫ�ؽ��н���
//	Swap(&arr[key], &arr[prev]);
//
//	//��ʱprevָ���Ԫ�ؾ���Ҫ�ҵ���׼ֵ
//	return prev;
//}

////��������
//void QuickSort(int* arr, int left, int right)
//{
//	//�ݹ���ֹ������
//	if (left >= right)
//	{
//		return;
//	}
//	//�һ�׼ֵ
//	int key = QuickLomuto(arr, left, right);
//
//	//�ݹ���������
//	QuickSort(arr, left, key - 1);
//
//	//�ݹ���������
//	QuickSort(arr, key + 1, right);
//}


int main()
{
	int arr[] = {4, 2, 9, 3, 8, 6, 5, 1, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, size - 1);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}