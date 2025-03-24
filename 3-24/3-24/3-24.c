#include <stdbool.h>
#include <stdio.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	
}ListNode;

bool hasCycle(struct ListNode* head)
{
	//快慢指针
	ListNode* slow = head;
	ListNode* fast = head;
    //开始移动
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			//相遇
			return true;
		}
	}

	//跳出循环说明，fast为空，或者fast->next为空
	//表明了链表中存在尾结点，自然不可能为环形链表
	return false;
}

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode* pcur = head;
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;

    while (pcur)
    {
        if (pcur->val != val)
        {
            if (newhead == NULL)
            {
                newhead = newtail = pcur;
            }
            else
            {
                newtail->next = pcur;
                newtail = newtail->next;
            }
        }
        pcur = pcur->next;
    }
    if (newtail)
    {
        newtail->next = NULL;
    }
    return newhead;
}



struct ListNode
{
    int val;
    struct ListNode* next;
};
typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode* l1 = NULL;
    ListNode* l2 = head;
    ListNode* l3 = head->next;

    while (l2)
    {
        l2->next = l1;
        l1 = l2;
        l2 = l3;
        if (l3)
        {
            l3 = l3->next;
        }
    }

    return l1;
}


struct ListNode
{
    int val;
    struct ListNode* next; 
};

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;
    ListNode* l1 = list1;
    ListNode* l2 = list2;

    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            if (newhead == NULL)
            {
                newhead = newtail = l2;
            }
            else
            {
                newtail->next = l2;
                newtail = newtail->next;
            }
            l2 = l2->next;
        }
        else
        {
            if (newhead == NULL)
            {
                newhead = newtail = l1;
            }
            else
            {
                newtail->next = l1;
                newtail = newtail->next;
            }
            l1 = l1->next;
        }
    }

    if (l1)
    {
        newtail->next = l1;
    }
    if (l2)
    {
        newtail->next = l2;
    }

    return newhead;
}