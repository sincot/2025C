#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int arr[] = { 4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	BubbleSort(arr, size);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


////排序整数
//int CompareInt(const void* e1, const void* e2)
//{
//	//比较两个整数之间的大小关系 --- 两数相减
//	return (*(int*)e1 - *(int*)e2);
//}
//
//int main()
//{
//	int arr[] = { 4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	//arr代表待排序首元素的地址
//	//size代表待排序的元素个数
//	//sizeof(arr[0])代表待排序序列的每个元素的大小
//	//
//	qsort(arr, size, sizeof(arr[0]), CompareInt);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//int CompareSS(const void* e1, const void* e2)
//{
//	//比较两个字符串之间的大小 --- 使用字符串函数strcmp
//	return strcmp(((Tec*)e1)->name, ((Tec*)e2)->name);
//}
//
//int main()
//{
//	struct Tec arr[] = { {"shicheng", 'c', 9.98 }, {"cuiyan", 'f', 10.62 },
//						 {"yuxi", 'g', 23.99}, {"huanxing", "a", 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareSS);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//
//	return 0;
//}



//int CompareByCharac(const void* e1, const void* e2)
//{
//	//字符的比较也可以直接相减
//	return (((Tec*)e1)->character - ((Tec*)e2)->character);
//}
//
//int main()
//{
//	struct Tec arr[] = { {"shicheng", 'c', 9.98 }, {"cuiyan", 'f', 10.62 },
//						 {"yuxi", 'g', 23.99}, {"huanxing", 'a', 8.57}};
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareByCharac);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//
//	return 0;
//}

////待排序的结构体的定义
//typedef struct Tec
//{
//	char name[20];
//	char character;
//	double salary;
//}Tec;
//
//int CompareBySalary(const void* e1, const void* e2)
//{
//	double ret = ((Tec*)e1)->salary - ((Tec*)e2)->salary;
//
//	return ret >= 0 ? 1 : -1;
//}
//
//int main()
//{
//	struct Tec arr[] = { {"shicheng", 'c', 9.98 }, {"cuiyan", 'f', 10.62 },
//						 {"yuxi", 'g', 23.99}, {"huanxing", 'a', 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%.2f\t", arr[i].salary);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareBySalary);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%.2f\t", arr[i].salary);
//	}
//
//	return 0;
//}


//待排序的结构体的定义
typedef struct Tec
{
	char name[20];
	int age;
	char character;
	double salary;
}Tec;

void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//int CompareName(const void* e1, const void* e2)
//{
//	return strcmp(((Tec*)e1)->name, ((Tec*)e2)->name);
//}

//int CompareAge(const void* e1, const void* e2)
//{
//	return ((Tec*)e1)->age - ((Tec*)e2)->age;
//}

//int CompareCharac(const void* e1, const void* e2)
//{
//	return ((Tec*)e1)->character - ((Tec*)e2)->character;
//}

int CompareSalary(const void* e1, const void* e2)
{
	double ret = ((Tec*)e1)->salary - ((Tec*)e2)->salary;

	return ret >= 0 ? 1 : -1;
}

//冒泡排序
void BubbleSort(void *base, int n, int width, int(*cmp)(const void* e1, const void *e2))
{
	int flag = 1;
	//趟数
	for (int i = 0; i < n - 1; i++)
	{
		//每趟排序的具体过程
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}

		if (1 == flag)
		{
			break;
		}
	}
}

int main()
{
	struct Tec arr[] = { {"shicheng", 23, 'c', 9.98 }, {"cuiyan", 29, 'f', 10.62 },
								 {"yuxi", 25, 'g', 23.99}, {"huanxing", 19, 'a', 8.57} };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f\t", arr[i].salary);
	}
	printf("\n");
	BubbleSort(arr, size, sizeof(arr[0]), CompareSalary);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f\t", arr[i].salary);
	}

	return 0;
}

//int main()
//{
//	struct Tec arr[] = { {"shicheng", 23, 'c', 9.98 }, {"cuiyan", 29, 'f', 10.62 },
//								 {"yuxi", 25, 'g', 23.99}, {"huanxing", 19, 'a', 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareCharac);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//
//	return 0;
//}

//int main()
//{
//	struct Tec arr[] = { {"shicheng", 23, 'c', 9.98 }, {"cuiyan", 29, 'f', 10.62 },
//								 {"yuxi", 25, 'g', 23.99}, {"huanxing", 19, 'a', 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d\t", arr[i].age);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareAge);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d\t", arr[i].age);
//	}
//
//	return 0;
//}

//int main()
//{
//	struct Tec arr[] = { {"shicheng", 23, 'c', 9.98 }, {"cuiyan", 29, 'f', 10.62 },
//								 {"yuxi", 25, 'g', 23.99}, {"huanxing", 19, 'a', 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	printf("排序前：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareName);
//
//	printf("排序后：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	
//	return 0;
//}

