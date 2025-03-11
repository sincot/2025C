#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

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

//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

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

//ת�Ʊ�
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
		printf("����������������:>  ");
		scanf("%d %d", &a, &b);
		printf("������������Ӧ�ı���:>");
		scanf("%d", &input);
		int(*pf[5])(int, int) = { 0, Add, Sub, Mul, Div };
		
		if (input >= 1 && input <= 4)
		{
			int ret = (*pf[input])(a, b);
			printf("%d\n", ret);
		}
		else if(input == 0)
		{
			printf("�˳�������\n");
			break;
		}
		else
		{
			printf("���ַǷ�\n");
		}
	} while (input);

	return 0;
}
*/

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

//����д��
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
		printf("s2��s1��ת�õ����ַ���\n");
	}
	else
	{
		printf("s2����s1��ת�õ����ַ���\n");
	}

	return 0;
}
*/


//��ȷд��
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
		printf("s2��s1��ת�õ����ַ���\n");
	}
	else
	{
		printf("s2����s1��ת�õ����ַ���\n");
	}

	return 0;
}
*/

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
/*
int main()
{
	int arr[4][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int k = 0;//Ҫ���ҵ�����
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
			printf("��ά�����д���%d\n", k);
			break;
		}
	}

	return 0;
}
*/

/*
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
����Ϊ4�����ɷ��Ĺ���:
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
*/

//����
/*
int main()
{
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char x = 0;

	if (x != a && x == c && x == d && x != d)//a��,b��,c��,d��
	{
		if (x != a && x == c && x != d)//a��,b��,c��,d��
		{
			if (x != a && x != c && x == d && x != d)//a��,b��,c��,d��
			{
				if (x == a && x != c && x == d && x != d)//a��,b��,c��,d��
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
			printf("������%c", killer);
		}
	}
}

int main()
{
	FindKiller();
	return 0;
}
*/

//����Ļ�ϴ�ӡ������ǡ�
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//
//����

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


//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
//���磺
//�������Ԫ���ǣ�1��2��3��4��5��1��2��3��4��6
//ֻ��5��6ֻ����1�Σ�Ҫ�ҳ�5��6.

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
����
KiKi����ĳ��ĳ���ж����죬��������ʵ�֡�������ݺ��·ݣ�������һ��������ж����졣
����������
�������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
���������
���ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж����졣
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

//�����˽�⺯��atoi�Ĺ��ܣ�ѧϰʹ�ã���ģ��ʵ��atoi������
/*
����˵����
str��ָ��Ҫת�����ַ�����ָ�롣���ַ������԰�����ѡ��ǰ���ո񣬽����ǿ�ѡ�� + �� - ���ţ�Ȼ����һϵ�������ַ���
ת�����̻���������һ���������ַ�ʱֹͣ��

����ֵ��
��ת���ɹ���atoi �������ؽ��ַ���ת���õ�������ֵ��
���ַ������ܱ���ȷת��Ϊ�����������ַ���Ϊ�ջ��߲�������Ч�������ַ������������� 0��

����ԭ��
����ǰ���ո񣺺��������������ַ�����ͷ�����пհ��ַ�����ո��Ʊ�������з��ȣ���
������ţ����ż���Ƿ���� + �� - ���š������ + ���ţ�������ԣ������ - ���ţ�ת����Ľ����Ϊ������
ת�����֣��ӵ�һ�������ַ���ʼ��������������ȡ�����ַ���ֱ�������������ַ�Ϊֹ������Щ�����ַ���ϳ�һ��������
���ؽ��������ת���õ�������ֵ��
*/

//ʹ�ú���
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

//ģ��ʵ��
/*
int simulate_atoi(const char* str)
{
	while (isspace(*str))//ȡ���ַ���ǰ�Ŀհ��ַ�
	{
		str++;
	}
	int sign = 1;//����
    //���������
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
		//�ж�sum��ֵ�Ƿ����int�������ܴ洢���������
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

