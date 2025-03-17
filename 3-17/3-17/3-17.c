#define _CRT_SECURE_NO_WARNINGS

//˳���
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
*/
/*
//����ṹ��
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//��ʼ��
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//���ݺ���
void SLCheckCapacity(SL* sl)
{
	assert(sl);
	
	if (sl->size == sl->capacity)
	{
	    int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
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
	SLCheckCapacity(sl);
	sl->arr[sl->size] = x;
	sl->size++;
}

//ͷ��
void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
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
	assert(sl && sl->size);
	sl->size--;
}

//ͷɾ
void SLPopFront(SL* sl)
{
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//ָ��λ��ǰ��������
void SLInsiteFront(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > pos; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
	sl->size++;
}

//ָ��λ�ú��������
void SLInsiteBack(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > pos + 1; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos + 1] = x;
	sl->size++;
}

//ָ��λ��ɾ������
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	for (int i = pos; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//����
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//��ӡ
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
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
	SLPushBack(&sl, 5);
	SLPopBack(&sl);
	SLPopFront(&sl);

	return 0;
}
*/

/*
int removeElement(int* nums, int numsSize, int val)
{
	int dst = 0;
	int src = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			dst++;
		}
		src++;
	}
	return dst;
}
*/

/*
int removeDuplicates(int* nums, int numsSize)
{
	int dst = 0;
	int src = dst + 1;

	while (src < numsSize)
	{
		if (nums[src] != nums[dst])
		{
			dst++;
			if (dst == src)
			{
				nums[dst] = nums[src];
			}
			
		}
		src++;
	}

	return dst + 1;
}
*/






#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//����ṹ��
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//��ʼ��˳���
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//���ݺ���
void SLCheckCapacity(SL* sl)
{
	assert(sl);
	if (sl->size == sl->capacity)
	{
		//����Ƿ��пռ�
		int newcapacity = sl->capacity == 0 ? 4 : 2 * sl->capacity;
		//����Ƿ�Ҫ����
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
	SLCheckCapacity(sl);
	sl->arr[sl->size++] = x;
}

//ͷ��
void SLPushFront(SL* sl, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > 0; i--)
	{
		sl->arr[i] = sl->arr[i - 1];;
	}
	sl->arr[0] = x;
	sl->size++;
}

//βɾ
void SLPopback(SL* sl)
{
	assert(sl && sl->size);
	sl->size--;
}

//ͷɾ
void SLPopFront(SL* sl)
{
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//ָ��λ��ǰ����
void SLInsertFront(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(&sl);
	for (int i = sl->size; i < pos; i++)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
	sl->size++;
}

//ָ��λ�ú����
void SLInsertBack(SL* sl, int pos, SLDataType x)
{
	assert(sl);
	SLCheckCapacity(&sl);
	for (int i = sl->size; i > pos + 1; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos + 1] = x;
}

//ָ��λ��ɾ��
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	SLCheckCapacity(&sl);
	for (int i = pos; i > sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//����
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//��ӡ
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i > sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

int main()
{
	SL sl;
	SLPushBack(&sl, 1);
	
	return 0;
}
