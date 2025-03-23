#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
typedef struct ListNode
{
	int val;
	struct ListNode* next;
	
}ListNode;

struct ListNode* reverseList(struct ListNode* head)
{
	//�ж�ͷ����Ƿ�Ϊ��
	if (head)
	{
		return head;
	}
	//����3��ָ��
	ListNode* n1 = NULL;
	ListNode* n2 = head;
	ListNode* n3 = n2->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		//�ж�ָ��n3�Ƿ�Ϊ��
		if (n3)
		{
			n3 = n3->next;
		}
	}

	return n1;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* middleNode(struct ListNode* head)
{
	//�������ָ��
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
	    return list1;
	//����������
	ListNode* newhead = NULL;
	ListNode* newtail = NULL;
	//������������ָ�룬�ֱ����list1��list2
	ListNode* l1 = list1;
	ListNode* l2 = list2;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			//l1β�嵽��������
			if (newhead == NULL)
			{
				newhead = l1;
			}
			else
			{
				newtail->next = l1;
				newtail = newtail->next;
			}
			l1 = l1->next;
		}
		else
		{
			//l2β�嵽��������
			if (newhead == NULL)
			{
				newhead = l2;
			}
			else
			{
				newtail->next = l2;
				newtail = newtail->next;
			}
			l2 = l2->next;
		}
	}

	//Ҫôl1Ϊ�գ�Ҫôl2Ϊ��
	if (l1)
		newtail->next = l1;
	if (l2)
		newtail->next = l2;

	return newhead;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	//�����ǿ�����
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* newtail = (ListNode*)malloc(sizeof(ListNode));
	//������������ָ�룬�ֱ����list1��list2
	ListNode* l1 = list1;
	ListNode* l2 = list2;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			//l1β�嵽��������
			newtail->next = l1;
			newtail = newtail->next;
			l1 = l1->next;
		}
		else
		{
			newtail->next = l2;
			newtail = newtail->next;
			l2 = l2->next;
		}
	}

	//Ҫôl1Ϊ�գ�Ҫôl2Ϊ��
	if (l1)
		newtail->next = l1;
	if (l2)
		newtail->next = l2;

	ListNode* Lrethead = newhead->next;
	free(newhead);
	newhead = NULL;
	return Lrethead;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

bool chkPalindrome(ListNode* A)
{
	//��������
	int arr[900] = { 0 };
	int len = 0;

	//��������
	ListNode* pcur = A;
	while (pcur)
	{
		arr[len++] = pcur->val;
		pcur = pcur->next;
	}

	//�жϻ���
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		//����ȷ���false
		if (arr[left] != arr[right])
		{
			return false;
		}
		left++;
		right--;
	}

	//����ѭ��������true
	return true;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

bool chkPalindrome(ListNode* A)
{
	//���м���
	ListNode* slow = A;
	ListNode* fast = A;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//����ѭ���󣬴�ʱslowָ��ľ����м���
	//��ת�м���
	ListNode* n1 = NULL;
	ListNode* n2 = slow;
	ListNode* n3 = slow->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	//n1���Ƿ�ת������µ�ͷ���
	ListNode* right = n1;
	//����ԭ����
	ListNode* left = A;
	while (right)
	{
		if (left->val != right->val)
		{
			return false;
		}
		left = left->next;
		right = right->next;
	}
	
	return true;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	//��������ָ���������������ȡ����ĳ���
	ListNode* pA = headA;
	ListNode* pB = headB;
	//���������������洢��������ĳ���
	int sizeA = 0;
	int sizeB = 0;
    
	//��������������ȡ����
	while (pA)
	{
		sizeA++;
		pA = pA->next;
	}
	while (pB)
	{
		sizeB++;
		pB = pB->next;
	}
	
	//���㳤�Ȳ�,�þ���ֵ����
	int gap = abs(sizeA - sizeB);

	ListNode* shortList = headA;
	ListNode* longList = headB;
	//�����������Ƿ�A�������Ϊ������
	if (sizeA > sizeB)
	{
		longList = headA;
		shortList = headB;
	}

	//�ó���������gap��
	while (gap--)
	{
		longList = longList->next;
	}

	//��ʱlongList��shortList��ͬһ�����
	while (shortList)
	{
		//�����ѭ��������short��longList������Ҫ��
		//��Ϊ����������ͬʱ�ƶ���ͬʱΪNULL
		if (longList == shortList)
		{
			return longList;
		}
		shortList = shortList->next;
		longList = longList->next;
	}
	
	return NULL;
}