#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
int main()
{
	int a = 20;
	int* pa = &a;
	*pa = 30;
	printf("%d", a);

	return 0;
}
*/

/*
int main()
{
	char a = 10;
	short b = 20;
	int c = 30;

	char* pa = &a;
	short* pb = &b;
	int* pc = &c;

	printf("%zd\n", sizeof(pa));
	printf("%zd\n", sizeof(pb));
	printf("%zd\n", sizeof(pc));

	return 0;
}
*/

/*
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	*pa = 0;

	return 0;
}

int main()
{
	int c = 0x11223344;
	char* pc = (char*)&c;
	*pc = 0;

	return 0;
}
*/

/*
int main()
{
	char a = 10;
	short b = 10;
	int c = 10;

	char* pa = &a;
	short* pb = &b;
	int* pc = &c;

	printf("pa   = %p\n", pa);
	printf("pa+1 = %p\n", pa + 1);
	printf("pa-1 = %p\n", pa - 1);
	printf("pb   = %p\n", pb);
	printf("pb+1 = %p\n", pb + 1);
	printf("pb-1 = %p\n", pb - 1);
	printf("pc   = %p\n", pc);
	printf("pc+1 = %p\n", pc + 1);
	printf("pc-1 = %p\n", pc - 1);
	return 0;
}
*/

/*
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = &arr[0];
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("\n");

	for (i = sz - 1; i >= 0; i--)
	{
		printf("%d ", *(p + i));
	}

	p = &arr[sz - 1];
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p--;
	}
	return 0;
}
*/

/*
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[0];
	int* q = &arr[sz];
	while (p < q)
	{
		printf("%d ", *p);
		p++;
	}

	return 0;
}
*/

/*
int simulate_strlen(char* p)
{
	char* q = p;
	while (*q)
	{
		q++;
	}

	return q - p;
}

int main()
{
	char arr[] = "watergraphically@gmail.com";
	int ret = simulate_strlen(arr);
	printf("%d ", ret);

	return 0;
}
*/

/*
int main()
{
	const int n = 10;
	n = 100;
	printf("%d ", n);

	return 0;
}
*/

/*
int main()
{
	const int n = 10;
	int* p = &n;
	*p = 100;

	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int b = 100;
	const int* pa = &a;
	*p = 100;
	p = &b;

	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int b = 100;
	int* const p = &a;
	*p = 100;
	p = &b;

	return 0;
}
*/

/*
int main()
{
	int* p;
	*p = 10;

	return 0;
}
*/

/*
void Swap(int x, int y)
{
	int z = x;
	x = y;
	y = z;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("交换前：a = %d -- b = %d\n", a, b);
	Swap(a, b);
	printf("交换后：a = %d -- b = %d\n", a, b);

	return 0;
}
*/

/*
void Swap(int* px, int* py)
{
	int z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("交换前：a = %d -- b = %d\n", a, b);
	Swap(&a, &b);
	printf("交换后：a = %d -- b = %d\n", a, b);

	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int* p = &a;
	int** p = &p;

	return 0;
}
*/

/*
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[3] = { arr1, arr2, arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int(*pf)(int, int) = &Add;
	printf("%d", (*pf)(4, 7));

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int main()
{
	int(*pf1)(int, int) = Add;
	int(*pf2)(int, int) = Sub;
	int(*parr[2])(int, int) = { Add, Sub };

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("*********************************\n");
	printf("*****    1.Add      2.Sub   *****\n");
	printf("*****    3.Mul      4.Div   *****\n");
	printf("*****         0.exit        *****\n");
	printf("*********************************\n");
}

int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int z = 0;
	do
	{
		menu();
		printf("请选择:>  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个操作数：>");
			scanf("%d %d", &a, &b);
			z = Add(a, b);
			printf("%d\n", z);
			break;
		case 2:
			printf("请输入两个操作数：>");
			scanf("%d %d", &a, &b);
			z = Sub(a, b);
			printf("%d\n", z);
			break;
		case 3:
			printf("请输入两个操作数：>");
			scanf("%d %d", &a, &b);
			z = Mul(a, b);
			printf("%d\n", z);
			break;
		case 4:
			printf("请输入两个操作数：>");
			scanf("%d %d", &a, &b);
			z = Div(a, b);
			printf("%d\n", z);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("*********************************\n");
	printf("*****    1.Add      2.Sub   *****\n");
	printf("*****    3.Mul      4.Div   *****\n");
	printf("*****         0.exit        *****\n");
	printf("*********************************\n");
}

int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int z = 0;
	int(*parr[5])(int, int) = { 0, Add, Sub, Mul, Div };
	do
	{
		menu();
		printf("请选择:>  ");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d %d", &a, &b);
			z = parr[input](a, b);
			printf("%d\n", z);
		}
		else if (0 == input)
		{
			printf("退出计算器\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入:>");
			break;
		}
	} while (input);

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("*********************************\n");
	printf("*****    1.Add      2.Sub   *****\n");
	printf("*****    3.Mul      4.Div   *****\n");
	printf("*****         0.exit        *****\n");
	printf("*********************************\n");
}

void calc(int(*pf)(int, int))
{
	int a = 0;
	int b = 0;
	printf("请输入两个操作数:>  ");
	scanf("%d %d", &a, &b);
	int c = pf(a, b);
	printf("计算结果为:> %d\n", c);
}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择:>  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
*/