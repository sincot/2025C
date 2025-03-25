#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
/*
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* detectCycle(struct ListNode* head)
{
	//��������ָ��
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
		{
			//��������
			//�������ͷ��㵽�뻷��һ�����ľ������
			ListNode* pcur = head;
			//��ͷ��㿪ʼ����
			while (pcur != slow)
			{
				pcur = pcur->next;
				slow = slow->next;
			}
			//������ѭ��˵��pcur��slow���
			//��ʱ��������ָ���λ�þ����뻷��һ�����
			return pcur;
		}
	}

	return NULL;
}
*/


//����˫������Ľṹ
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;


//Ϊ�ս�㿪���ڴ�ռ�
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	newnode->data = x;
	//Ϊ�˹���ѭ���ṹ��������prevָ���nextָ�붼ָ�����Լ�
	newnode->prev = newnode->next = newnode;

	return newnode;
}

/*
//˫������ĳ�ʼ��
void LTInit(LTNode** pphead)
{
	//ͷ���ĵ�ַ����Ϊ��
	assert(pphead);
	//����Ч��ֵ
	*pphead = LTBuyNode(-1);
}
*/

//˫������ĳ�ʼ��
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTBuyNode(x);
	return phead;
}

//˫������Ĵ�ӡ
void LTPrint(LTNode* phead)
{
	//����ָ��ȥ����˫������
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->data);
		//����ƶ�
		pcur = pcur->next;
	}
}

//ֻ��ͷ���һ����������£��ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	//��phead->next == phead˵��������ֻʣ����һ�����
	//���Ϊ�գ�����true
	return phead->next == phead;
}

//����˫�������е�����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	//����һ��ָ��pcurȥ��������
	LTNode* pcur = phead->next;
	while (pcur)
	{
		//�ҵ���
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//û�ҵ�
	return NULL;
}

//˫�������β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(1);
	//����phead phead->prev newnode
	//�ȴӺ�ߵ�newnode�ı�
	newnode->prev = phead->prev;
	newnode->next = phead;
    //�ٸı�phead �� phead->prev
	//��β�����newnode��������
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//˫�������ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(2);
	//����phead phead->prev newnode
	newnode->prev = phead;
	newnode->next = phead->next;

	phead->next->prev = newnode;
	phead->next = newnode;
}

//˫�������βɾ
void LTPopBack(LTNode* phead)
{
	//�ж������Ƿ�Ϊ��
	//��Ϊ�գ��������ص���true���߼���֮��Ϊfalse��ִ�ж��Բ���
	//����Ϊ�գ��������ص���false���߼���֮��Ϊtrue����ִ�ж��Բ���
	assert(!LTEmpty(phead));

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
	assert(!LTEmpty(phead));
	//phead del del->next
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

//��ָ��λ��pos֮ǰ��������
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

//ɾ��posλ�õĽ��
void LTErase(LTNode* pos)
{
	assert(pos);
	//pos->prev pos pos->next
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//�������������
//����1����ַ����
/*
void LTDestory(LTNode** pphead)
{
	assert(pphead && *pphead);
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(*pphead);
	*pphead = NULL;
}
*/

//����2����ֵ����
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}

void test01()
{
	LTNode* plist = LTInit(-1);
	LTDestory(plist);
	plist = NULL;
}

int main()
{
	test01();
	return 0;
}
