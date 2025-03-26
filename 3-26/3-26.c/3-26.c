//˫������
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//����˫������Ľṹ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//�洢������
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;


//�������
LTNode* LTBuyNode(LTDataType x)
{
	//�����½ڵ�
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	newnode->data = x;
	newnode->prev = newnode;
	newnode->next = newnode;

	return newnode;
}

//��ʼ�����
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//˫������Ĵ�ӡ
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//˫�������β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->prev
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//˫�������ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//˫�������βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	LTNode* del = phead->prev;
	//phead del del->prev
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}

//˫�������ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	LTNode* del = phead->next;
	//phead del del->next
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

//��ָ��λ��posǰ��������
void LTInsertFront(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	//pos->prev newnode pos
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

//��ָ��λ��pos֮���������
void LTInsertBack(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//���������е�����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

//˫����������ݵ�����
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* pnext = pcur->next;
		free(pcur);
		pcur = pnext;
	}
	free(phead);
	phead = NULL;
}

int main()
{
	LTNode* plist = LTInit(-1);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	//LTInsertFront(plist->next->next->next->next, 100);
	//LTInsertBack(plist->next, 100);
	LTDestory(plist);
	free(plist);
	plist = NULL;
	
	LTNode* pfind = LTFind(plist, 100);
	if (pfind)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("δ�ҵ�\n");
	}
	
	//LTPrint(plist);
	//LTPushFront(plist, 100);
	//LTPopFront(plist);
	//LTPrint(plist);

	return 0;
}
*/


//������
/*
typedef int SLTDataType;
//���嵥����ṹ��
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//�������
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


//������ĳ�ʼ��
void SLTInit(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	*pphead = SLTBuyNode(x);
}


//������Ĵ�ӡ
void SLTPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//������Ĳ���
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

//�������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

//�������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//�������βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//ֻ��һ�����
	if ((*pphead)->next == NULL)
	{
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

//�������ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//��ָ��λ��posǰ��������
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);
	SLTNode* newnode = SLTBuyNode(x);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
		newnode->next = pos;
	}
}

//��ָ��λ��pos֮���������
void SLTInsertBack(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��ָ��λ��pos������
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == (*pphead))
	{
		//ͷɾ
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//���������
void SLTDestory(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

int main()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushFront(&plist, 100);
	//SLTPopBack(&plist);
	//SLTPopFront(&plist);
	//SLTNode* pfind = SLTFind(plist, 4);
	//SLTInsertBack(pfind, 200);
	//SLTErase(&plist, pfind);
	SLTDestory(&plist);

	if (pfind)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("δ�ҵ�\n");
	}

	SLTPrint(plist);
	return 0;
}
*/

/*
//˳���
//˳���ṹ��Ķ���
typedef int SLDataType;
typedef struct SeqList
{
	int size;//��Ч���ݸ���
	int capacity;//�ڴ�ռ��С
	SLDataType* arr;
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//��ӡ����
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//���ݺ���
void SLCheckCapacity(SL* ps)
{
	//size��capacity�����˵����Ҫ����
	if (ps->size == ps->capacity)
	{
		//�ж�capacity���Ƿ���Ԫ��
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//���ٿռ�
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//˳����β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//˳����ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//��������
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

int main()
{
	SL* sl;
	return 0;
}
*/