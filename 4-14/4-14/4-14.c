#include <stdio.h>

//ֱ�Ӳ������� --- ����Ϊ����������飬�Լ��������Ԫ�ظ���
void InsertSort(int* arr, int n)
{
	//ѭ��������������
	for (int i = 0; i < n - 1; i++)
	{
		//����һ������endʼ��ָ���������е����һ��
		int end = i;

		//����һ�������洢�±�Ϊend + 1������
		int tmp = arr[end + 1];

		//ѭ���Ƚ�
		while (end >= 0)
		{
			//���±�Ϊend�����ݴ���tmp�д洢������
			//�ͽ��±�Ϊend�����ݷ����±�Ϊend + 1��λ�ô�
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

		//�������е��⣬�����˴�ʱend����0
		//��ʱ��tmp�е����ݸ�ֵ�������±�Ϊend + 1��λ��
		//��һ�����ǽ�С�����ݷ��������ǰ��Ĳ���
		arr[end + 1] = tmp;
	}
}

//ϣ������ --- ����Ϊ����������飬�Լ��������Ԫ�ظ���
void ShellSort(int* arr, int n)
{
	//����gap���ó�ʼgap��ֵΪ�����Ԫ�ظ���
	int gap = n;

	//Ԥ����
	while (gap > 1)
	{
		//��n�����ݷֳ�gap��
		gap = gap / 3 + 1;

		//��ÿ�����ݽ���ֱ�Ӳ�������
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

	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	ShellSort(arr, size);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
