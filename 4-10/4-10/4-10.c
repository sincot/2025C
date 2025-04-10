//随机链表的复制
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int val;
     struct Node *next;
     struct Node *random;
}Node;


//为新结点开辟内存空间
Node* BuyNode(int x)
{
    //为新的结点开辟结点大小的内存空间
    Node* newnode = (Node*)malloc(sizeof(Node));

    //初始化新的结点
    //将x赋值给新结点的val
    newnode->val = x;

    //将新结点的两个指针都指向空
    newnode->next = newnode->random = NULL;

    //将增加的新结点的地址返回
    return newnode;
}

//增加新的结点
//将原链表的地址作为参数
void AddNode(Node* head)
{
    //定义一个指针来遍历原链表，方便拷贝
    Node* pcur = head;

    //只要pcur不为空，就继续拷贝
    while (pcur)
    {
        //创建新的结点
        Node* newnode = BuyNode(pcur->val);

        //增加一个指针来保存pcur下一个结点的地址
        Node* next = pcur->next;

        //将newnode结点插入原链表
        newnode->next = next;
        pcur->next = newnode;

        //拷贝且插入完毕后，pcur开始拷贝后面的结点
        pcur = next;
    }
}

//设置随机指针random
void SetRandom(Node* head)
{
    //定义一个指针来指向原链表的头结点
    Node* pcur = head;

    while (pcur)
    {
        Node* copy = pcur->next;

        if (pcur->random)
        {
            copy->random = pcur->next->random;
        }

        pcur = pcur->next;
    }
}

//知道原链表的头，返回复制链表的头
struct Node* copyRandomList(struct Node* head)
{
    //在原链表的基础上拷贝结点并插入在原链表在
    AddNode(head);
    //设置random指针的指向
    SetRandom(head);
    //断开新链表
    Node* pcur = head;
    Node* copyhead = pcur->next;
    Node* copytail = pcur->next;

    while (copytail->next)
    {
        pcur = copytail->next;
        copytail->next = pcur->next;
        copytail = copytail->next;
    }

    return copyhead;
}