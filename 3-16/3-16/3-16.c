/*
void rotate(int* nums, int numSize, int k)
{
	k %= numSize;
	while (k--)
	{
		int tmp = nums[numSize - 1];
		for (int i = numSize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = tmp;
	}
}
*/

/*
void rotate(int* nums, int numsSize, int k)
{
	//����������
	int newnums[numsSize] = { 0 };
	//������תk�Σ��������������ʱ������
	for (int i = 0; i < numsSize; i++)
	{
		newnums[(i + k) % numsSize] = nums[i];
	}
	//����ʱ�����е����ݿ�����ԭ������
	memmove(nums, newnums);
}
*/

/*
//���ú���
void reverse(int* nums, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k) {

	k %= numsSize;
	reverse(nums, numsSize - k);
	reverse(nums + numsSize - k, k);
	reverse(nums, numsSize);

}
*/

/*
//��̬˳���
typedef int SLDataType;//��int������������֮������������͵�����
#define N 6
typedef struct SeqList
{
	SLDataType a[N];   //��������
	int size;          //��Ч���ݸ���
}SL;
*/

/*
//��̬˳���----�ײ������ռ��ڲ��ϱ仯���ռ䲻��������
typedef int SLDataType;//��int������������֮������������͵�����
typedef struct SeqList
{
	SLDataType* a;
	int size;          //��Ч���ݸ���
	int capacity;      //�ռ�����  
};
*/


/*
//˳���
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//��ʼ��
void* SLInit(SL* sl)
{
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//���ݺ���
void SLCheckCapacity(SL* sl)
{
	if (sl->capacity == sl->size)
	{
		//�ж��������Ƿ����ڴ�ռ�
		int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
		//���ٵ��ڴ�ռ�ĵ�λ���ֽ�
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		sl->arr = tmp;
		sl->capacity = newcapacity;
	}
}

//β��
void SLPushBack(SL* sl, SLDataType x)
{
	assert(sl);
	//�ж��Ƿ�Ҫ����
	SLCheckCapacity(sl);
	sl->arr[sl->size] = x;
	sl->size++;
}

//ͷ��
void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
	//�ж��Ƿ�Ҫ����
	SLCheckCapacity(sl);
	for (int i = sl->size; i > 0; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[0] = x;
	sl->size++;
}

//βɾ
void SLPopBack(SL* sl)
{
	//sl:���Ʋ�������ֱ�Ӹ�NULL
	//sl->size:˳���Ϊ��
	assert(sl && sl->size);
	sl->size--;
}

//ͷɾ
void SLPopFront(SL* sl)
{
	//sl:���Ʋ�������ֱ�Ӹ�NULL
	//sl->size:˳���Ϊ��
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//��ӡ˳���
void SLPrint(SL* sl)
{
	int i = 0;
	for (i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

	return 0;
}
*/

