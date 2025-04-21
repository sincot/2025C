#define _CRT_SECURE_NO_WARNINGS_
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//创建N个随机数，写入到文件中
void CreateData()
{
	//造数据，再多少自己定，这里为了方便观察，造100个数据
	int n = 1000;

	//生成随机数种子
	srand(time(0));

	//创建一个文件，文件名为data.txt
	const char *file = "data.txt";

	//以写的方式打开文件
	FILE *fin = fopen(file, "w");

	//判断文件是否打开成功
	if (fin == NULL)
	{
		perror("fopen file fail!");
		exit(1);
	}

	//造n个随机数
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;

		//往文件中输入该随机数
		fprintf(fin, "%d\n", x);
	}

	//关闭文件
	fclose(fin);
}

void CompareInt(const void *e1, const void *e2)
{
	return *(int*)e1 - *(int*)e2;
}

//返回实际读取到的数据个数，没有数据返回0
//为了避免每次读取数据时，都要打开数据源文件，在这里传指向源文件的指针
int ReadNDataSortToFile(FILE *fout, int n, const char *dstfile)
{
	//创建一个内存空间大小为n个int整型的数组
	int x = 0;
	int *arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		perror("malloc error!");
		exit(2);
	}

	//读取n个数据
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		//从之前打开的文件中读取数据
		//判断是否能够读取到n个数据，即判断fscanf是否读取到EOF
		if (fscanf(fout, "%d", &x) == EOF)
		{
			free(arr);
			arr = NULL;
			break;
		}
		arr[j++] = x;
	}

	//使用函数qsort来排序
	//判断j是否为0，即是否读取到了数据，若一个数据都没有读取到，那么就没必要排序了
	if (j == 0)
	{
		free(arr);
		arr = NULL;
		return 0;
	}
	qsort(arr, j, sizeof(int), CompareInt);

	//以写的方式打开dstfile文件
	FILE *fin = fopen(dstfile, "w");
	if (fin == NULL)
	{
		free(arr);
		arr = NULL;
		perror("fopen dstfile fail!");
		return 0;
	}

	//将排序好的数据写入文件dstfile
	for (int i = 0; i < j; i++)
	{
		fprintf(fin, "%d\n", arr[i]);
	}

	free(arr);
	arr = NULL;
	fclose(fin);

	return j;
}

//创建一个函数，用来将文件file1与文件file2，归并到文件mfile中
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//以读的方式打开文件flie1
	FILE *fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		perror("fopen file1 fail!");
		exit(4);
	}

	//以读的方式打开文件flie2
	FILE *fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		perror("fopen file2 fail!");
		exit(5);
	}

	//以写的方式打开文件mflie
	FILE *mfin = fopen(mfile, "w");
	if (mfin == NULL)
	{
		perror("fopen mfile fail!");
		exit(6);
	}
	
	//归并
	int x1 = 0;
	int x2 = 0;
	int ret1 = fscanf(fout1, "%d", &x1);
	int ret2 = fscanf(fout2, "%d", &x2);
	//读取到的数据不能为EOF
	while (ret1 != EOF && ret2 != EOF)
	{
		if (x1 < x2)
		{
			//往mfile文件中写入x1与x2中的较小值
			fprintf(mfin, "%d\n", x1);
			ret1 = fscanf(fout1, "%d", &x1);
		}
		else
		{
			fprintf(mfin, "%d\n", x2);
			ret2 = fscanf(fout2, "%d", &x2);
		}
	}

	//处理剩余的数据
	while (ret1 != EOF)
	{
		fprintf(mfin, "%d\n", x1);
		ret1 = fscanf(fout1, "%d", &x1);
	}

	while (ret2 != EOF)
	{
		fprintf(mfin, "%d\n", x2);
		ret2 = fscanf(fout2, "%d", &x2);
	}
	//关闭文件file1,file2,mfile
	fclose(fout1);
	fclose(fout2);
	fclose(mfin);
}

int main()
{
	CreateData();

	//生成3个文件,file1,flie2,mflie
	const char *file1 = "file1.txt";
	const char *file2 = "file2.txt";
	const char *mfile = "mfile.txt";

	//以读的方式打开文件data.txt
	FILE *fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen data.txt fail!");
		exit(3);
	}

	//每次读10个数据
	ReadNDataSortToFile(fout, 100, file1);
	ReadNDataSortToFile(fout, 100, file2);

	//循环归并
	while (1)
	{
		MergeFile(file1, file2, mfile);

		//删除文件file1与file2 --- 使用函数remove
		remove(file1);
		remove(file2);

		//将文件mfile重命名为file1 --- 使用函数rename
		rename(mfile, file1);

		//每次都读取10个数据
		//判断文件data.txt中是否还有数据
		//没有数据了，说明文件归并结束，归并好的数据在文件file1中
		if (ReadNDataSortToFile(fout, 100, file2) == 0)
		{
			break;
		}
	}

	fclose(fout);
	return 0;
}
*/


