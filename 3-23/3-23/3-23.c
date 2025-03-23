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
	//判断头结点是否为空
	if (head)
	{
		return head;
	}
	//创建3个指针
	ListNode* n1 = NULL;
	ListNode* n2 = head;
	ListNode* n3 = n2->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		//判断指针n3是否为空
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
	//定义快慢指针
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
	//创建空链表
	ListNode* newhead = NULL;
	ListNode* newtail = NULL;
	//定义两个遍历指针，分别遍历list1和list2
	ListNode* l1 = list1;
	ListNode* l2 = list2;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			//l1尾插到新链表中
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
			//l2尾插到新链表中
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

	//要么l1为空，要么l2为空
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
	//创建非空链表
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* newtail = (ListNode*)malloc(sizeof(ListNode));
	//定义两个遍历指针，分别遍历list1和list2
	ListNode* l1 = list1;
	ListNode* l2 = list2;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			//l1尾插到新链表中
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

	//要么l1为空，要么l2为空
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
	//创建数组
	int arr[900] = { 0 };
	int len = 0;

	//遍历链表
	ListNode* pcur = A;
	while (pcur)
	{
		arr[len++] = pcur->val;
		pcur = pcur->next;
	}

	//判断回文
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		//不相等返回false
		if (arr[left] != arr[right])
		{
			return false;
		}
		left++;
		right--;
	}

	//跳出循环，返回true
	return true;
}


typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

bool chkPalindrome(ListNode* A)
{
	//找中间结点
	ListNode* slow = A;
	ListNode* fast = A;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//跳出循环后，此时slow指向的就是中间结点
	//反转中间结点
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
	//n1就是反转链表的新的头结点
	ListNode* right = n1;
	//遍历原链表
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
	//创建两个指针遍历两个链表，求取链表的长度
	ListNode* pA = headA;
	ListNode* pB = headB;
	//创建两个变量来存储两个链表的长度
	int sizeA = 0;
	int sizeB = 0;
    
	//遍历两个链表，求取长度
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
	
	//计算长度差,用绝对值函数
	int gap = abs(sizeA - sizeB);

	ListNode* shortList = headA;
	ListNode* longList = headB;
	//调整，看看是否A链表真的为长链表
	if (sizeA > sizeB)
	{
		longList = headA;
		shortList = headB;
	}

	//让长链表现在gap步
	while (gap--)
	{
		longList = longList->next;
	}

	//此时longList和shortList在同一个起点
	while (shortList)
	{
		//里面的循环条件是short和longList并不重要，
		//因为它们两个会同时移动，同时为NULL
		if (longList == shortList)
		{
			return longList;
		}
		shortList = shortList->next;
		longList = longList->next;
	}
	
	return NULL;
}