#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    int sizeA = 0;
    int sizeB = 0;
    ListNode* pcurA = headA;
    ListNode* pcurB = headB;

    while (pcurA)
    {
        sizeA++;
        pcurA = pcurA->next;
    }
    while (pcurB)
    {
        sizeB++;
        pcurB = pcurB->next;
    }
    //相差长度
    int gap = abs(sizeA - sizeB);

    //定义长链表和短链表
    ListNode* longlist = headA;
    ListNode* shortlist = headB;
    if (sizeA < sizeB)
    {
        longlist = headB;
        shortlist = headA;
    }
    //走差步
    while (gap--)
    {
        longlist = longlist->next;
    }

    //开始比较
    while (longlist)
    {
        if (longlist == shortlist)
        {
            return longlist;
        }
        longlist = longlist->next;
        shortlist = shortlist->next;
    }

    return NULL;
}


struct ListNode
{
  int val;
  struct ListNode* next;
 };

typedef struct ListNode ListNode;
bool hasCycle(struct ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}


struct ListNode
{
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head)
{
    //快慢指针
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode* pcur = head;
            while (pcur != slow)
            {
                pcur = pcur->next;
                slow = slow->next;
            }
            return pcur;
        }
    }

    return NULL;
} 

