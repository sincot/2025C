// ��ͷ+˫��+ѭ��������ɾ���ʵ��
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//Ϊ��㿪���ڴ�ռ�
ListNode* ListBuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->prev = newnode->next = newnode;

	return newnode;
}

// �������������ͷ���.
ListNode* ListCreate(LTDataType x)
{
	ListNode* pHead = ListBuyNode(x);
	return pHead;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* pcur = pHead->next;
	while (pcur != pHead)
	{
		ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(pHead);
	pHead = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* pcur = pHead->next;
	while (pcur != pHead)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = ListBuyNode(x);
	//pHead newnode pHead->prev
	newnode->next = pHead;
	newnode->prev = pHead->prev;
	pHead->prev->next = newnode;
	pHead->prev = newnode;
}

//�ж�˫���������Ƿ�ֻ��һ�����
bool ListEmpty(ListNode* pHead)
{
	return pHead->next == pHead;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(!ListEmpty(pHead));
	ListNode* del = pHead->prev;
	//pHead del del->prev
	pHead->prev = del->prev;
	del->prev->next = pHead;
	free(del);
	del = NULL;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = ListBuyNode(x);
	//pHead newnode pHead->next
	newnode->next = pHead->next;
	newnode->prev = pHead;
	pHead->next->prev = newnode;
	pHead->next = newnode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(!ListEmpty(pHead));
	ListNode* del = pHead->next;
	//pHead del del->next
	pHead->next = del->next;
	del->next->prev = pHead;
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* pcur = pHead->next;
	while (pcur != pHead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = ListBuyNode(x);
	//pos->prev newndoe pos
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	//pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

int main()
{
	ListNode* phead = ListBuyNode(-1);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListDestory(phead);
	phead = NULL;
	ListNode* pfind = ListFind(phead, 1);
	ListInsert(pfind, 100);
	ListPrint(phead);
	ListErase(pfind);
	ListPrint(phead);
	ListNode* pfind = ListFind(phead, 100);
	if (pfind)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("δ�ҵ�\n");
	}



	ListPushFront(phead, 100);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);

	return 0;
}
*/

/*
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* partition(ListNode* pHead, int x)
{
	//����������ͷ�Ŀ�����
	ListNode* lessHead, * lessTail;
	lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
	ListNode* greaterHead, * greaterTail;
	greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));

	//����ָ��pcur����ԭ����
	ListNode* pcur = pHead;
	//ѭ������,pcurΪ��ʱ������ѭ��
	while (pcur)
	{
		if (pcur->val < x)
		{
			//�����Ǵ�ͷ���������Բ���������Ϊ�յ����
			//ֱ��β�嵽С������
			lessTail->next = pcur;
			lessTail = lessTail->next;
		}
		else
		{
			//�����Ǵ�ͷ���������Բ���������Ϊ�յ����
			//ֱ��β�嵽��������
			greaterTail->next = pcur;
			greaterTail = greaterTail->next;
		}
		pcur = pcur->next;
	}

	//��С��������
	lessTail->next = greaterHead->next;
	//�������β�����ΪNULL(������ѭ��)
	greaterTail->next = NULL;
	//���ٿ��ٵ��ڴ�ռ�
	//���������ڴ�ռ��Ҫ���ص�ֵ���Ҳ���
	//���Զ���һ��ָ�뽫Ҫ���ص�ֵ�洢����
	ListNode* ret = lessTail->next;
	free(lessHead);
	free(greaterHead);

	return ret;
}
*/

/*
typedef struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
}Node;

//Ϊ�µĽ�㿪���ڴ�ռ�
Node* BuyNode(int x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		exit(1);
	}
	//�����µĽ��
	newnode->val = x;
	newnode->next = newnode->random = NULL;
}

//���ӽ��
void AddNode(Node* head)
{
	//����һ��ָ��pcur���ڱ���ԭ����
	Node* pcur = head;
	while (pcur)
	{
		//����һ����pcurָ��Ľ���һģһ���Ľ��
		Node* newnode = BuyNode(pcur->val);
		//����һ��ָ��next�Ƚ�pcurָ��Ľ�����һ�����ĵ�ַ��������
		//��Ϊ��һ�������Ľ�������
		Node* next = pcur->next;
		//��newnode���뵽pcurָ����ָ��Ľ��ĺ���
		//pcur newnode pcur->next
		//��������ָ����������
		newnode->next = pcur->next;
		pcur->next = newnode;
		//pcur����������
		pcur = next;
	}
	//����ѭ����˵�������е�ÿ����㶼������һ��
	//���Ҳ��뵽��ԭ������
}

//����randomָ��
void SetRandom(Node* head)
{
	//����һ��ָ��ָ��ԭ�����ͷ
	Node* pcur = head;
	//��pcurȥ����ԭ����
	while (pcur)
	{
		//����һ��ָ��ָ�򿽱�����ͷ,
		//���������ͷ������pcur��nextָ��ָ��Ľ��
		Node* copy = pcur->next;
		//���ù�ʽ��copy->random = pcur->random->next
		//ǰ����pcur->random��Ϊ�գ���Ϊ����copy->randomҲ��ֵΪNULL
		if (pcur->random)
		{
			copy->random = pcur->random->next;
			//�ƶ�pcur
			pcur = copy->next;
		}
	}
}

struct Node* copyRandomList(struct Node* head)
{
	//�ж�head�Ƿ�Ϊ�գ���Ϊ��ֱ�ӽ�head����
	if (head == NULL)
	{
		return head;
	}
	//��ԭ����Ļ����Ͽ�����㲢������ԭ������
	AddNode(head);
	//����random
	SetRandom(head);
	//��ԭ�����뿽��������Ͽ�
	//����ָ��pcur��ȥ����ԭ����
	Node* pcur = head;
	//��������ָ��ָ�򿽱�����
	Node* copyHead, *copyTail;
	//����������ָ��ָ�򿽱������ͷ���
	//Ҳ����pcurָ��ָ��Ľ�����һ�����
	copyHead = copyTail = pcur->next;
	//ֻҪcopy������һ����㲻Ϊ��
	//��ôpcur�Ϳ��������ߣ���������ԭ����
	//��Ϊ��ʱcopy��㻹����ԭ���������ӵ�
	//ͨ��copy�Ϳ��ҵ�ԭ����Ľ��
	while (copyTail->next)
	{
		//��pcurָ�򿽱�������һ�����
		//��ͨ��pcur��nextָ���ҵ�Ҫ��copyTail���ӵĽ��
		pcur = copyTail->next;
		copyTail->next = pcur->next;
		//��������copyTailָ��ָ����copyTail���ӵĽ��
		copyTail = pcur->next;
	}
	//����ѭ����˵��ԭ�����뿽�������Ѿ��Ͽ���
	//����ԭ����Ľ���nextָ����Ȼָ���⿽������Ľ��
	//�����������Ӱ����
	
	//���ؿ�����������µ�ͷ���
	return copyHead;
}
*/

//˳��ṹ����
//�ѵĽṹ
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;//�ײ�������
	int size;       //��Ч���ݸ���
	int capacity;   //�ռ��С
}HP;

//��ʼ����
void HeapInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//�ѵ�����
void HeapDestory(HP* php)
{
	assert(php);
	if (php->arr)
	{
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}
