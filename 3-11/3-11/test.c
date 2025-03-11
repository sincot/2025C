#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

/*
void reserve(char arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	int k = 0;
	scanf("%d", &k);
	char arr[] = "ABCD";
	int len = strlen(arr);
	k = k % len;
	reserve(arr, k);
	reserve(arr + k, len - k);
	reserve(arr, len);
	printf("%s", arr);

	return 0;
}
*/

//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

/*
void reserve(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		
		if ((arr[left] % 2 == 0) && (arr[right] % 2 == 0))
		{
			right--;
		}
		if ((arr[left] % 2 != 0) && (arr[right] % 2 == 0))
		{
			left++;
		}
		if ((arr[left] % 2 == 0) && (arr[right] % 2 != 0))
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[] = { 3,4,6,5,3,2,7,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	reserve(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
*/

/*
void reserve(char arr[])
{
	int len = strlen(arr);
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[10000] = { 0 };
	while (gets(arr))
	{
		reserve(arr);
	}
	printf("%s", arr);

	return 0;
}
*/

//转移表
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
	printf("******************************\n");
	printf("*******   1.Add 2.Sub  *******\n");
	printf("*******   3.Mul 4.Div  *******\n");
	printf("*******     0.exit     ******\n");
	printf("******************************\n");
}

int main()
{
	menu();
	int input = 0;
	int a = 0;
	int b = 0;
	do
	{
		printf("请输入两个操作数:>  ");
		scanf("%d %d", &a, &b);
		printf("请输入符号相对应的编码:>");
		scanf("%d", &input);
		int(*pf[5])(int, int) = { 0, Add, Sub, Mul, Div };
		
		if (input >= 1 && input <= 4)
		{
			int ret = (*pf[input])(a, b);
			printf("%d\n", ret);
		}
		else if(input == 0)
		{
			printf("退出计算器\n");
			break;
		}
		else
		{
			printf("数字非法\n");
		}
	} while (input);

	return 0;
}
*/

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//错误写法
/*
void reserve(char arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int Func(char str1[], char str2[])
{
    char* const cur = str1;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;
	if (len1 != len2)
	{
		return 0;
	}

	for (i = 0; i <= len1; i++)
	{
		str1 = cur;
		reserve(str1, i);
		reserve(str1 + i, len1 - i);
		reserve(str1, len1);
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	int ret = Func(s1, s2);

	if (ret == 1)
	{
		printf("s2是s1旋转得到的字符串\n");
	}
	else
	{
		printf("s2不是s1旋转得到的字符串\n");
	}

	return 0;
}
*/


//正确写法
/*
void reserve(char arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int Func(char str1[], char str2[])
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;
	if (len1 != len2)
	{
		return 0;
	}
	char tmp[100];
	strcpy(tmp, str1);

	for (i = 0; i <= len1; i++)
	{
		strcpy(tmp, str1);
		reserve(tmp, i);
		reserve(tmp + i, len1 - i);
		reserve(tmp, len1);
		if (strcmp(tmp, str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	int ret = Func(s1, s2);

	if (ret == 1)
	{
		printf("s2是s1旋转得到的字符串\n");
	}
	else
	{
		printf("s2不是s1旋转得到的字符串\n");
	}

	return 0;
}
*/

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
/*
int main()
{
	int arr[4][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int k = 0;//要查找的数字
	scanf("%d", &k);
	int i = 0;
	int j = 0;
	while (1)
	{
		if (arr[i][j] < k)
		{
			i++;
		}
		else if (arr[i][j] > k)
		{
			i--;
			j++;
		}
		else
		{
			printf("二维数组中存在%d\n", k);
			break;
		}
	}

	return 0;
}
*/

/*
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/

//有误
/*
int main()
{
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char x = 0;

	if (x != a && x == c && x == d && x != d)//a真,b真,c真,d假
	{
		if (x != a && x == c && x != d)//a真,b真,c假,d真
		{
			if (x != a && x != c && x == d && x != d)//a真,b假,c真,d真
			{
				if (x == a && x != c && x == d && x != d)//a假,b真,c真,d真
				{
					printf("%c", x);
				}
			}
		}
	}

	return 0;
}
*/

/*
void FindKiller()
{
	char killer = 'a';
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("凶手是%c", killer);
		}
	}
}

int main()
{
	FindKiller();
	return 0;
}
*/

//在屏幕上打印杨辉三角。
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//
//……

/*
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	int arr[100][100] = { 0 };
	
	for (j = 0; j < n; j++)
	{
		for (i = 0; i <= j; i++)
		{
			if (i == 0 || i == j)
			{
				arr[i][j] = 1;
				printf("%d ", arr[i][j]);
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
*/


//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.

/*
int main()
{
	int arr[] = { 2,3,5,2,4,7,8,5,4,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int arr0[10] = { 0 };
	int arr1[10] = { 0 };
	int i = 0;
	int num0 = 0;
	int num1 = 0;
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] & 1) == 0)
		{
			arr0[i] = arr[i];
		}
		else
		{
			arr1[i] = arr[i];
		}
	}
	
	for (i = 0; i < sz; i++)
	{
		num0 ^= arr0[i];
	}
	for (i = 0; i < sz; i++)
	{
		num1 ^= arr1[i];
	}
	printf("%d %d", num0, num1);
	
	return 0;
}
*/

/*
int main()
{
	int arr[] = { 2,3,5,2,4,7,8,5,4,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int arr0[10] = { 0 };
	int arr1[10] = { 0 };
	int i = 0;
	int num0 = 0;
	int num1 = 0;
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] & 1) == 0)
		{
			arr0[i] = arr[i];
			num0 ^= arr0[i];
		}
		else
		{
			arr1[i] = arr[i];
			num1 ^= arr1[i];
		}
	}

	
//	for (i = 0; i < sz; i++)
//	{
//		num0 ^= arr0[i];
//	}
//	for (i = 0; i < sz; i++)
//	{
//		num1 ^= arr1[i];
//	}
	
	printf("%d %d", num0, num1);

	return 0;
}
*/

/*
描述
KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
输入描述：
多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
输出描述：
针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
*/
/*
int is_leap_year(int year)
{
	return ((year % 4 != 0 && year % 100 == 0) || (year % 400 == 0));
}

int main()
{
	int year = 0;
	int month = 0;
	while (scanf("%d %d", &year, &month) != EOF)
	{
		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) && (is_leap_year(year)))
		{
			arr[month] = 29;
		}
		printf("%d", arr[month]);
	}

	return 0;
}
*/

//自行了解库函数atoi的功能，学习使用，并模拟实现atoi函数。
/*
参数说明：
str：指向要转换的字符串的指针。该字符串可以包含可选的前导空格，接着是可选的 + 或 - 符号，然后是一系列数字字符。
转换过程会在遇到第一个非数字字符时停止。

返回值：
若转换成功，atoi 函数返回将字符串转换得到的整数值。
若字符串不能被正确转换为整数，例如字符串为空或者不包含有效的数字字符，函数将返回 0。

工作原理：
跳过前导空格：函数会首先跳过字符串开头的所有空白字符（如空格、制表符、换行符等）。
处理符号：接着检查是否存在 + 或 - 符号。如果有 + 符号，将其忽略；如果有 - 符号，转换后的结果将为负数。
转换数字：从第一个数字字符开始，函数会连续读取数字字符，直到遇到非数字字符为止。将这些数字字符组合成一个整数。
返回结果：返回转换得到的整数值。
*/

//使用函数
/*
int main()
{
	char arr1[] = "13579";
	char arr2[] = "   ++10086";
	char arr3[] = "abcd321";
	char arr4[] = "    -24680";

	int n1 = atoi(arr1);
	int n2 = atoi(arr2);
	int n3 = atoi(arr3);
	int n4 = atoi(arr4);

	printf("%d\n", n1);
	printf("%d\n", n2);
	printf("%d\n", n3);
	printf("%d\n", n4);

	return 0;
}
*/

//模拟实现
/*
int simulate_atoi(const char* str)
{
	while (isspace(*str))//取出字符串前的空白字符
	{
		str++;
	}
	int sign = 1;//正号
    //检查正负号
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}

	int sum = 0;
	while (isdigit(*str))
	{
		int num = *str - '0';
		//判断sum的值是否大于int整数所能存储的最大整数
		if (sum > (INT_MAX - num) / 10)
		{
			return (sign == 1) ? INT_MAX : INT_MIN;
		}

		sum = sum * 10 + num;
		str++;
	}

	return sign * sum;
}

int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int ret = simulate_atoi(arr);
	printf("%d", ret);

	return 0;
}
*/

