#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//ð������
void BubbleSort(int* arr, int n)
{
	//����һ������flag����ʼ��Ϊ1�����������������������
	int flag = 1;
	//����
	for (int i = 0; i < n - 1; i++)
	{
		//ÿ������ľ������
		for (int j = 0; j < n - 1 - i; j++)
		{
			//���±�Ϊ j �����ݴ����±�Ϊ j + 1������,��ô�ͽ��������ݽ��н���
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				
				//���뵽��if����У�˵������������в�������ģ���ʱ��flag��ֵΪ0
				flag = 0;
			}
		}

		//ÿ��ð�����򽻻����ж�flag�Ƿ�Ϊ1����Ϊ1������ѭ��
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

	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort(arr, size);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}