#include "SeqList.h"

//�ṹ��ĳ�ʼ��
void SLInit(SL* sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = sl->capacity = 0;
}

//��ӡ˳����е�����
void SLPrint(SL* sl)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->arr[i]);
	}
}

void SLCheckCapacity(SL* sl)
{
	//�ж��Ƿ���Ҫ����
	if (sl->size == sl->capacity)
	{
		//�ж��Ƿ����ڴ棬��capacity�Ƿ�Ϊ0
		int newcapacity = (sl->capacity == 0 ? 4 : 2 * sl->capacity);
		//��reallocǿ������ת��Ϊ��ָ����ͬ�����ͣ�����tmpָ�����
		//realloc�����������ֱ�ΪҪ���ݿռ����ʼ��ַ����Ҫ�������ֽ��ڴ�ռ�
		//ǧ��Ҫֱ����sl->arrȥ���ն�̬�ڴ�ɹ����ٺ󷵻����ĵ�ַ
		//���⶯̬�ڴ濪��ʧ�ܺ󣬷���NULL����ָ��ԭ���ռ��ָ�븳ΪNULL
		SLDataType* tmp = (SLDataType*)realloc(sl->arr, newcapacity * sizeof(SLDataType));
		//�ж��Ƿ�ɹ����뿪���ڴ�ռ�
		//���û�оͰѴ�����Ϣ��ӡ������Ȼ��ֱ���˳���������
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
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[0] = x;
	sl->size++;
}

//βɾ
void SLPopBack(SL* sl)
{
	//����slָ���Ƿ�ΪNULL��
	//ɾ��������Ҫ����һ���������������û������
	//����Ҫ�ж��Ƿ���Ч�����Ƿ�Ϊ0��Ҳ����sl->size�Ƿ�Ϊ0
	assert(sl && sl->size);
	sl->size--;
}

//ͷɾ
void SLPopFront(SL* sl)
{

	//����slָ���Ƿ�ΪNULL��
	//ɾ��������Ҫ����һ���������������û������
	//����Ҫ�ж��Ƿ���Ч�����Ƿ�Ϊ0��Ҳ����sl->size�Ƿ�Ϊ0
	assert(sl && sl->size);
	for (int i = 0; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//ָ��λ��posǰ��������
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

//ָ��λ��pos���������
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

//ָ��λ��pos��ɾ������
void SLDelete(SL* sl, int pos)
{
	assert(sl && sl->size);
	for (int i = pos; i < sl->size - 1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
}

//��������
int SLFind(SL* sl, SLDataType x)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//����
void SLDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->size = sl->capacity = 0;
}


