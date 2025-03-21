//��ϰʹ�ö�̬�ڴ���ص�4�������������Թ۲졣
//malloc��calloc��realloc��free

#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		return 1;
	}
	for (i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	int* q = (int*)calloc(10, sizeof(int));
	if (q == NULL)
	{
		return 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", q[i]);
	}
	printf("\n");

	int* str = (int*)realloc(p, 20 * sizeof(int));
	if (str == NULL)
	{
		return 1;
	}
	p = str;
	for (i = 0; i < 20; i++)
	{
		p[i] = i;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", p[i]);
	}

	free(p);
	free(q);
	p = q = NULL;

	return 0;
}
*/

/*
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
	int* tmp = (int*)malloc(2 * numsSize * sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		tmp[numsSize + i] = tmp[i] = nums[i];
	}
	*returnSize = numsSize * 2;

	return tmp;
}
*/

/*
int main()
{
	int* arr1 = (int*)malloc(5 * sizeof(int));
	int* arr2 = (int*)malloc(5 * sizeof(int));
	int* arr3 = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		arr1[i] = arr2[i] = arr3[i] = i;
	}
	int* pf[3] = { arr1, arr2, arr3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", pf[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int	j = 0;
	// Ϊ�����������ڴ棬������3��
	int** arr = (int**)malloc(3 * sizeof(int*));
	if (arr == NULL)
	{
		perror("malloc");
		return 1;
	}

	// Ϊÿһ�з����ڴ棬ÿ����5��Ԫ��
	for (i = 0; i < 3; i++) 
	{
		arr[i] = (int*)malloc(5 * sizeof(int));
		if (arr[i] == NULL)
		{
			perror("malloc");
			// �ͷ��Ѿ�������ڴ�
			for (j = 0; j < i; j++)
			{
				free(arr[j]);
			}
			free(arr);
			return 1;
		}
	}

	// ʹ���±���ʲ���ֵ
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = i + j;
		}
	}

	// ʹ���±���ʲ���ӡ
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// �ͷ��ڴ�
	for (i = 0; i < 3; i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	return 0;
}