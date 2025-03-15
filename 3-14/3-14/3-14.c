#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
//ʹ��memcpy����
/*
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	memcpy(arr2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}
*/

//ģ��ʵ��memcpy����
/*
void* simulate_memcpy(void* dest, const void* src, int num)
{
	assert(dest && src);
	while (num--)
	{
		*(((char*)dest)++) = *(((char*)src)++);
	}
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	simulate_memcpy(arr2, arr1, 20);

	return 0;
}
*/

/*
void* simulate_memcpy(void* dest, const void* src, int num)
{
	assert(dest && src);
	while (num--)
	{
		*(((char*)dest))++ = *(((char*)src))++;
	}
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	simulate_memcpy(arr2, arr1, 20);

	return 0;
}
*/


//ʹ��memmove����
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memmove(arr, arr + 2, 20);

	return 0;
}
*/


//ģ��ʵ��memmove����
/*
void* simulate_memmove(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;

	while (num--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}

	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	simulate_memmove(arr, arr + 2, 20);

	return 0;
}
*/

/*
void* simulate_memmove(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;

	while (num--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}

	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	simulate_memmove(arr + 2, arr, 20);

	return 0;
}
*/

/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memmove(arr + 2, arr, 20);

	return 0;
}
*/

/*
void* simulate_memmove(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;

	//��ǰ���
	if (dest < src)
	{
		while (num--)
		{
			*((char*)dest)++ = *((char*)src)++;
 		}
	}
	//�Ӻ���ǰ
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	simulate_memmove(arr + 2, arr, 20);

	return 0;
}
*/

//ʹ��memset����
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	memset(arr, 1, 10);

	return 0;
}
*/

/*
int main()
{
	char arr[] = "watergraphically@gmail.com";
	memset(arr + 2, '*', 10);
	printf("%s", arr);

	return 0;
}
*/


//ʹ��memcmp����
/*
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[] = { 1,2,3,4,5,6,8,9,11 };

	char arr3[] = "watergraphically";
	char arr4[] = "watergeographliy";

	int ret1 = memcmp(arr1, arr2, 28);
	int ret2 = memcmp(arr3, arr4, 7);

	if (ret1 > 0)
	{
		printf("arr1 > arr2\n");
	}
	else if (ret1 < 0)
	{
		printf("arr1 < arr2\n");
	}
	else
	{
		printf("arr1 == arr2\n");
	}

	if (ret2 > 0)
	{
		printf("ret3 > ret4\n");
	}
	else if (ret2 < 0)
	{
		printf("ret3 < ret4\n");
	}
	else
	{
		printf("ret3 == ret4\n");
	}

	return 0;
}
*/

//ʹ��malloc����
/*
int main()
{
	//���ٿռ�
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	//ʹ�ÿռ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	return 0;
}
*/

//ʹ��calloc����
/*
int main()
{
	//�����ڴ�
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("calloc");
		return 1;
	}
	//ʹ���ڴ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	return 0;
}
*/

//ʹ��realloc����
/*
int  main()
{
	//�����ڴ�
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	//ʹ���ڴ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	//����
	int* tmp = (int*)realloc(p, 20 * sizeof(int));
	if (tmp == NULL)
	{
		perror("realloc");
		return 1;
	}
	p = tmp;

	for (i = 10; i < 20; i++)
	{
		p[i] = i;
	}
	return 0;
}
*/

/*
int main()
{
	//�����ڴ�
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	//ʹ���ڴ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	//�ͷ��ڴ�
	free(p);
	p = NULL;

	return 0;
}
*/
