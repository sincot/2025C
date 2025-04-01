// 带头+双向+循环链表增删查改实现
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

//为结点开辟内存空间
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

// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x)
{
	ListNode* pHead = ListBuyNode(x);
	return pHead;
}

// 双向链表销毁
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

// 双向链表打印
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

// 双向链表尾插
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

//判断双向链表中是否只有一个结点
bool ListEmpty(ListNode* pHead)
{
	return pHead->next == pHead;
}
// 双向链表尾删
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

// 双向链表头插
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

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(!ListEmpty(pHead));
	ListNode* del = pHead->next;
	//pHead del del->next
	pHead->next = del->next;
	del->next->prev = pHead;
}

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
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
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
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
	//创建两个带头的空链表
	ListNode* lessHead, * lessTail;
	lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
	ListNode* greaterHead, * greaterTail;
	greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));

	//定义指针pcur遍历原链表
	ListNode* pcur = pHead;
	//循环遍历,pcur为空时，跳出循环
	while (pcur)
	{
		if (pcur->val < x)
		{
			//由于是带头的链表，所以不存在链表为空的情况
			//直接尾插到小链表中
			lessTail->next = pcur;
			lessTail = lessTail->next;
		}
		else
		{
			//由于是带头的链表，所以不存在链表为空的情况
			//直接尾插到大链表中
			greaterTail->next = pcur;
			greaterTail = greaterTail->next;
		}
		pcur = pcur->next;
	}

	//大小链表链接
	lessTail->next = greaterHead->next;
	//大链表的尾结点置为NULL(避免死循环)
	greaterTail->next = NULL;
	//销毁开辟的内存空间
	//由于销毁内存空间后，要返回的值会找不到
	//所以定义一个指针将要返回的值存储起来
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

//为新的结点开辟内存空间
Node* BuyNode(int x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		exit(1);
	}
	//处理新的结点
	newnode->val = x;
	newnode->next = newnode->random = NULL;
}

//增加结点
void AddNode(Node* head)
{
	//定义一个指针pcur用于遍历原链表
	Node* pcur = head;
	while (pcur)
	{
		//创建一个与pcur指向的结点的一模一样的结点
		Node* newnode = BuyNode(pcur->val);
		//定义一个指针next先将pcur指向的结点的下一个结点的地址保存起来
		//因为下一个拷贝的结点就是它
		Node* next = pcur->next;
		//将newnode插入到pcur指针所指向的结点的后面
		//pcur newnode pcur->next
		//将这三个指针链接起来
		newnode->next = pcur->next;
		pcur->next = newnode;
		//pcur继续往后走
		pcur = next;
	}
	//跳出循环后，说明链表中的每个结点都拷贝了一份
	//并且插入到了原链表中
}

//处理random指针
void SetRandom(Node* head)
{
	//定义一个指针指向原链表的头
	Node* pcur = head;
	//让pcur去遍历原链表
	while (pcur)
	{
		//定义一个指针指向拷贝链表头,
		//拷贝链表的头结点就是pcur的next指针指向的结点
		Node* copy = pcur->next;
		//套用公式：copy->random = pcur->random->next
		//前提是pcur->random不为空，若为空则copy->random也赋值为NULL
		if (pcur->random)
		{
			copy->random = pcur->random->next;
			//移动pcur
			pcur = copy->next;
		}
	}
}

struct Node* copyRandomList(struct Node* head)
{
	//判断head是否为空，若为空直接将head返回
	if (head == NULL)
	{
		return head;
	}
	//在原链表的基础上拷贝结点并插入在原链表中
	AddNode(head);
	//设置random
	SetRandom(head);
	//将原链表与拷贝的链表断开
	//定义指针pcur，去遍历原链表
	Node* pcur = head;
	//定义两个指针指向拷贝链表
	Node* copyHead, *copyTail;
	//让它们两个指针指向拷贝链表的头结点
	//也就是pcur指针指向的结点的下一个结点
	copyHead = copyTail = pcur->next;
	//只要copy结点的下一个结点不为空
	//那么pcur就可以往后走，继续遍历原链表
	//因为此时copy结点还是与原链表相链接的
	//通过copy就可找到原链表的结点
	while (copyTail->next)
	{
		//让pcur指向拷贝结点的下一个结点
		//再通过pcur的next指针找到要与copyTail链接的结点
		pcur = copyTail->next;
		copyTail->next = pcur->next;
		//拷贝结点的copyTail指针指向与copyTail链接的结点
		copyTail = pcur->next;
	}
	//跳出循环后，说明原链表与拷贝链表已经断开了
	//但是原链表的结点的next指针让然指向这拷贝链表的结点
	//但是这个并不影响结果
	
	//返回拷贝后链表的新的头结点
	return copyHead;
}
*/

//顺序结构定义
//堆的结构
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;//底层是数组
	int size;       //有效数据个数
	int capacity;   //空间大小
}HP;

//初始化堆
void HeapInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//堆的销毁
void HeapDestory(HP* php)
{
	assert(php);
	if (php->arr)
	{
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}
