//����

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//����ṹ��
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//�����ս��
SLTNode* SLTBuyNode(SLTDataType x)
{
	//�����ս��
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

//��ӡ����
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//�����β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//������Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//������Ϊ��
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

//�����ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//�����βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//�ҵ�β����ǰһ�����
	SLTNode* prev = NULL;
	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		prev = ptail;
		ptail = ptail->next;
	}
	prev->next = NULL;
	free(ptail);
	ptail = NULL;
}

//�����ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����Ĳ���
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
	//����ѭ���ߵ������˵��������Ϊ�գ�û���ҵ�x
	//��ô�ͷ���NULL
	return NULL;
}

//��ָ��λ��pos֮ǰ��������
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);
	//pos����ͷ���
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		//�ҵ�pos֮ǰ��λ��
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//�ҵ���pos֮ǰ��λ��
		prev->next = newnode;
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
void SLTDelete(SLTNode** pphead, SLTNode* pos)
{
	//ָ��λ�õĵ�ַ�ɲ���Ϊ��
	assert(pphead && *pphead && pos);
	//�ҵ�poss֮ǰ�Ľ��
	SLTNode* prev = *pphead;
	//pos����ͷ���
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//�ҵ�pos֮ǰ�Ľ��
		prev->next = pos->next;
		//�ͷŵ�pos���ڴ�ռ䣬���ֶ��ÿ�
		free(pos);
		pos = NULL;
	}
}

//ɾ��ָ��λ��pos֮�������
void SLTDeleteBack(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//��������
void SLTDistory(SLTNode** pphead)
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

//��������
void test1()
{
	//�������
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//��ʼ��
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	//����
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	SLTNode* plist = node1;
	SLTDistory(&plist);
	
	SLTNode* pfind = SLTFind(plist, 2);
	SLTInsetFront(&plist, pfind, 5);
	SLTPrint(plist);
	SLTPrint(plist);
	if (pfind)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	
}


void test2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPopBack(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
}



void test3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTNode* pfind = plist;
	SLTInsertBack(pfind, 2);
	SLTDeleteBack(&plist, pfind);
	SLTPrint(plist);
}


int main()
{
	test1();
	//test2();
	//test3();

	return 0;
}
*/

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	
}ListNode;

struct ListNode* removeElements(struct ListNode* head, int val)
{
	//����������
	ListNode* newHead = NULL;//Ҫ���ص���ͷ���
	ListNode* newtail = NULL;

	ListNode* pcur = head;//��ȥ��������
	while (pcur)
	{
		//�������в�Ϊvalֵ�Ľ��β�����µ�������
		if (pcur->val != val)
		{
			//β��
			//����Ϊ��
			if (newHead == NULL)
			{
				newHead = newtail = pcur;
			}
			else
			{
				//����ǿ�
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if (newtail != NULL)
	{
		newtail->next = NULL;
	}

	return newHead;
}