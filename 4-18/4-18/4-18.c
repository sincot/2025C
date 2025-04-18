#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int arr[] = { 4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	BubbleSort(arr, size);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


////��������
//int CompareInt(const void* e1, const void* e2)
//{
//	//�Ƚ���������֮��Ĵ�С��ϵ --- �������
//	return (*(int*)e1 - *(int*)e2);
//}
//
//int main()
//{
//	int arr[] = { 4, 9, 2, 8, 5, 7, 1, 3, 2, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	//arr�����������Ԫ�صĵ�ַ
//	//size����������Ԫ�ظ���
//	//sizeof(arr[0])������������е�ÿ��Ԫ�صĴ�С
//	//
//	qsort(arr, size, sizeof(arr[0]), CompareInt);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//int CompareSS(const void* e1, const void* e2)
//{
//	//�Ƚ������ַ���֮��Ĵ�С --- ʹ���ַ�������strcmp
//	return strcmp(((Tec*)e1)->name, ((Tec*)e2)->name);
//}
//
//int main()
//{
//	struct Tec arr[] = { {"shicheng", 'c', 9.98 }, {"cuiyan", 'f', 10.62 },
//						 {"yuxi", 'g', 23.99}, {"huanxing", "a", 8.57} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareSS);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//
//	return 0;
//}



//int CompareByCharac(const void* e1, const void* e2)
//{
//	//�ַ��ıȽ�Ҳ����ֱ�����
//	return (((Tec*)e1)->character - ((Tec*)e2)->character);
//}
//
//int main()
//{
//	struct Tec arr[] = { {"shicheng", 'c', 9.98 }, {"cuiyan", 'f', 10.62 },
//						 {"yuxi", 'g', 23.99}, {"huanxing", 'a', 8.57}};
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareByCharac);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//
//	return 0;
//}

////������Ľṹ��Ķ���
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
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%.2f\t", arr[i].salary);
//	}
//	printf("\n");
//	qsort(arr, size, sizeof(arr[0]), CompareBySalary);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%.2f\t", arr[i].salary);
//	}
//
//	return 0;
//}


//������Ľṹ��Ķ���
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

//ð������
void BubbleSort(void *base, int n, int width, int(*cmp)(const void* e1, const void *e2))
{
	int flag = 1;
	//����
	for (int i = 0; i < n - 1; i++)
	{
		//ÿ������ľ������
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

	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f\t", arr[i].salary);
	}
	printf("\n");
	BubbleSort(arr, size, sizeof(arr[0]), CompareSalary);

	printf("�����");
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
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c\t", arr[i].character);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareCharac);
//
//	printf("�����");
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
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d\t", arr[i].age);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareAge);
//
//	printf("�����");
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
//	printf("����ǰ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	printf("\n");
//	BubbleSort(arr, size, sizeof(arr[0]), CompareName);
//
//	printf("�����");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%8s\t", arr[i]);
//	}
//	
//	return 0;
//}

