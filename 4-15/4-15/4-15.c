#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//ѡ������
void SelectSort(int* arr, int n)
{
	//������������begin��end
	//beginָ�������±�Ϊ0��λ�ã�endָ�������±�Ϊn - 1��λ��
	int begin = 0;
	int end = n - 1;

	//ֻҪbegin��ָ��������±�С��end��ָ���������±꣬ѭ���Ͳ���ֹͣ
	while (begin < end)
	{
		//������������min��max
		//minָ���λ����begin��ͬ��maxָ���λ����begin��ͬ
		int min = begin;
		int max = begin;

		//��min��������Ѱ��begin~end��Χ����С�����ݵ��±�
		//��max��������Ѱ��begin~end��Χ���������ݵ��±�
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

		//�ҵ�begin~end��Χ�ڵ���Сֵ�����ֵ���±��
		//�������±�Ϊmin�������������±�Ϊbegin�����ݽ��н���
		//�������±�Ϊmmax�������������±�Ϊend�����ݽ��н���

		//�������⴦��
		//��max��ָ���λ����begin����ͬ��minָ���λ����end��ͬʱ
		//�任max��ָ���λ�ã���maxָ��min��ָ���λ��
		if (max == begin)
		{
			max = min;
		}

		Swap(&arr[begin], &arr[min]);
		Swap(&arr[end], &arr[max]);

		//������Ϻ�begin++��end--����С���еķ�Χ
		begin++;
		end--;
	}
}

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
	SelectSort(arr, size);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
