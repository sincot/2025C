#include <stdio.h>

typedef struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
}Node;

//为新的结点开辟内存空间
Node* BuyNode(int x)
{
	//为新结点申请结点大小的内存空间
	Node* newnode = (Node*)malloc(sizeof(Node));

	//初始化新结点
	newnode->val = x;
	newnode->next = newnode->random = NULL;

	//返回新结点
	return newnode;
}

//增加新的结点
//将原链表的头结点的地址作为参数，因为需要拷贝原链表中的结点
void AddNode(Node* head)
{
	//定义一个指针pcur去遍历原链表
	Node* pcur = head;

	//循环遍历原链表，只要pcur为空，就停止循环
	while (pcur)
	{
		//复制结点，为新的结点开辟内存空间
		//新结点中保存的val值与pcur的val一样
		Node* newnode = BuyNode(pcur->val);

		//将newnode插入原链表中
		//定义一个指针next保存pcur的下一个结点的地址
		Node* next = pcur->next;

		pcur->next = newnode;
		newnode->next = next;

		//pcur继续往下去遍历
		pcur = next;
	}
}

//设置拷贝结点的random指针的指向
//将原链表的头结点的地址作为参数，因为拷贝的结点在原链表中
void SetRandom(Node* head)
{
	//定义一个指针pucr指向原链表的头结点
	Node* pcur = head;

	//让pcur遍历原链表，去设置拷贝结点的random指针的指向
	//循环执行，直到pcur指向NULL
	while (pcur)
	{
		//定义一个指针copy指向拷贝结点的第一个结点,即pcur的下一个结点
		//copy指针指向的始终是pucr的下一个结点
		Node* copy = pcur->next;

		//设置拷贝结点的random指针的指向
		//只要pcur的random指针指向的不是NULL
		//就执行copy->random = pcur->random->next
		if (pcur->random)
		{
			copy->random = pcur->random->next;
		}

		//设置完random指针后，pcur需要继续往下遍历
		pcur = copy->next;
	}	
}

struct Node* copyRandomList(struct Node* head)
{
	//链表不能为空
	if (head == NULL)
	{
		return head;
	}

	//在原链表的基础上拷贝结点，并将新结点插入原链表中
	//调用函数AddNode
	AddNode(head);

	//设置拷贝结点的random指针的指向
	//调用函数SetRandom
	SetRandom(head);

	//将新链表从原链表中断开
    //定义指针pcur去遍历原链表
	Node* pcur = head;

	//定义指针prev开始是指向原链表的头结点
	//为了恢复原链表的next指针的指向
	Node* prev = head;

	//定义两个指针copyhead与copytail，开始都指向复制结点的第一个结点
	//copyhead始终指向新链表的头结点
	//copytail去遍历新链表，去处理新链表中结点的next指针的指向
	Node* copyhead = pcur->next;
	Node* copytail = pcur->next;

	while (copytail->next)
	{
		//让pcur指针指向copytail的下一个结点
		//使得pcur继续向下遍历原链表
		pcur = copytail->next;

		//恢复原链表next指针的指向
		prev->next = pcur;
		prev = pcur;

		//处理新链表中next指针的指向
		copytail->next = pcur->next;
		
		//copytail继续往下遍历新链表
		copytail = copytail->next;
	}

	//将新链表的头结点返回
	return copyhead;
}