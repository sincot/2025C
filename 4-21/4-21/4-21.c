#define _CRT_SECURE_NO_WARNINGS_
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//����N���������д�뵽�ļ���
void CreateData()
{
	//�����ݣ��ٶ����Լ���������Ϊ�˷���۲죬��100������
	int n = 1000;

	//�������������
	srand(time(0));

	//����һ���ļ����ļ���Ϊdata.txt
	const char *file = "data.txt";

	//��д�ķ�ʽ���ļ�
	FILE *fin = fopen(file, "w");

	//�ж��ļ��Ƿ�򿪳ɹ�
	if (fin == NULL)
	{
		perror("fopen file fail!");
		exit(1);
	}

	//��n�������
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;

		//���ļ�������������
		fprintf(fin, "%d\n", x);
	}

	//�ر��ļ�
	fclose(fin);
}

void CompareInt(const void *e1, const void *e2)
{
	return *(int*)e1 - *(int*)e2;
}

//����ʵ�ʶ�ȡ�������ݸ�����û�����ݷ���0
//Ϊ�˱���ÿ�ζ�ȡ����ʱ����Ҫ������Դ�ļ��������ﴫָ��Դ�ļ���ָ��
int ReadNDataSortToFile(FILE *fout, int n, const char *dstfile)
{
	//����һ���ڴ�ռ��СΪn��int���͵�����
	int x = 0;
	int *arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		perror("malloc error!");
		exit(2);
	}

	//��ȡn������
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		//��֮ǰ�򿪵��ļ��ж�ȡ����
		//�ж��Ƿ��ܹ���ȡ��n�����ݣ����ж�fscanf�Ƿ��ȡ��EOF
		if (fscanf(fout, "%d", &x) == EOF)
		{
			free(arr);
			arr = NULL;
			break;
		}
		arr[j++] = x;
	}

	//ʹ�ú���qsort������
	//�ж�j�Ƿ�Ϊ0�����Ƿ��ȡ�������ݣ���һ�����ݶ�û�ж�ȡ������ô��û��Ҫ������
	if (j == 0)
	{
		free(arr);
		arr = NULL;
		return 0;
	}
	qsort(arr, j, sizeof(int), CompareInt);

	//��д�ķ�ʽ��dstfile�ļ�
	FILE *fin = fopen(dstfile, "w");
	if (fin == NULL)
	{
		free(arr);
		arr = NULL;
		perror("fopen dstfile fail!");
		return 0;
	}

	//������õ�����д���ļ�dstfile
	for (int i = 0; i < j; i++)
	{
		fprintf(fin, "%d\n", arr[i]);
	}

	free(arr);
	arr = NULL;
	fclose(fin);

	return j;
}

//����һ���������������ļ�file1���ļ�file2���鲢���ļ�mfile��
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//�Զ��ķ�ʽ���ļ�flie1
	FILE *fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		perror("fopen file1 fail!");
		exit(4);
	}

	//�Զ��ķ�ʽ���ļ�flie2
	FILE *fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		perror("fopen file2 fail!");
		exit(5);
	}

	//��д�ķ�ʽ���ļ�mflie
	FILE *mfin = fopen(mfile, "w");
	if (mfin == NULL)
	{
		perror("fopen mfile fail!");
		exit(6);
	}
	
	//�鲢
	int x1 = 0;
	int x2 = 0;
	int ret1 = fscanf(fout1, "%d", &x1);
	int ret2 = fscanf(fout2, "%d", &x2);
	//��ȡ�������ݲ���ΪEOF
	while (ret1 != EOF && ret2 != EOF)
	{
		if (x1 < x2)
		{
			//��mfile�ļ���д��x1��x2�еĽ�Сֵ
			fprintf(mfin, "%d\n", x1);
			ret1 = fscanf(fout1, "%d", &x1);
		}
		else
		{
			fprintf(mfin, "%d\n", x2);
			ret2 = fscanf(fout2, "%d", &x2);
		}
	}

	//����ʣ�������
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
	//�ر��ļ�file1,file2,mfile
	fclose(fout1);
	fclose(fout2);
	fclose(mfin);
}

int main()
{
	CreateData();

	//����3���ļ�,file1,flie2,mflie
	const char *file1 = "file1.txt";
	const char *file2 = "file2.txt";
	const char *mfile = "mfile.txt";

	//�Զ��ķ�ʽ���ļ�data.txt
	FILE *fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen data.txt fail!");
		exit(3);
	}

	//ÿ�ζ�10������
	ReadNDataSortToFile(fout, 100, file1);
	ReadNDataSortToFile(fout, 100, file2);

	//ѭ���鲢
	while (1)
	{
		MergeFile(file1, file2, mfile);

		//ɾ���ļ�file1��file2 --- ʹ�ú���remove
		remove(file1);
		remove(file2);

		//���ļ�mfile������Ϊfile1 --- ʹ�ú���rename
		rename(mfile, file1);

		//ÿ�ζ���ȡ10������
		//�ж��ļ�data.txt���Ƿ�������
		//û�������ˣ�˵���ļ��鲢�������鲢�õ��������ļ�file1��
		if (ReadNDataSortToFile(fout, 100, file2) == 0)
		{
			break;
		}
	}

	fclose(fout);
	return 0;
}
*/


