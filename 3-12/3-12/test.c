#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <math.h>
//ģ��ʵ��memcpy����
/*
void* simulate_memcpy(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return (int*)ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 0 };
	int* ret = simulate_memcpy(arr2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(ret+i));
	}

	return 0;
}
*/

//ģ��ʵ��memmove����
/*
void* simulate_memmove(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;
	
	if(dest < src)
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	simulate_memmove(arr + 2, arr, 20);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/

/*
����ˮ�ɻ��� - Lily Number������������֣����м��ֳ��������֣�
����1461 ���Բ�ֳɣ�1��461��, ��14��61��, ��146��1), ������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
���磺
655 = 6 * 55 + 65 * 5
1461 = 1 * 461 + 14 * 61 + 146 * 1
��� 5λ���е����� Lily Number��
*/
/*
int main()
{
	int i = 0;
	for (i = 10000; i < 100000; i++)
	{
		int j = 0;
		int sum = 0;
		for (j = 10; j <= 10000; j *= 10)
		{
			sum = sum + (i % j) * (i / j);
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/

/*
��һ���������У��������ظ�������������ɾ��ָ����ĳһ��������
���ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣

��һ������һ������(0��N��50)��
�ڶ�������N�������������ÿո�ָ���N��������
������������Ҫ����ɾ����һ��������

���Ϊһ�У�ɾ��ָ������֮�������
*/
/*
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int arr[50] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%d ", &arr[i]);
	}
	int k = 0;
	scanf("%d", &k);
	for (i = 0; i < n; i++)
	{
		if (arr[i] != k)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	int arr[50] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int k = 0;
	scanf("%d", &k);

	for (i = 0; i < n; i++)
	{
		if (arr[i] != k)
		{
			arr[j] = arr[i];
			j++;
		}
	}

	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/