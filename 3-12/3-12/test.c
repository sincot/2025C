#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <math.h>
//模拟实现memcpy函数
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

//模拟实现memmove函数
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
变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
比如1461 可以拆分成（1和461）, （14和61）, （146和1), 如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
例如：
655 = 6 * 55 + 65 * 5
1461 = 1 * 461 + 14 * 61 + 146 * 1
求出 5位数中的所有 Lily Number。
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
有一个整数序列（可能有重复的整数），现删除指定的某一个整数，
输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。

第一行输入一个整数(0≤N≤50)。
第二行输入N个整数，输入用空格分隔的N个整数。
第三行输入想要进行删除的一个整数。

输出为一行，删除指定数字之后的序列
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