#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = m + n - 1;

	while (l1 >= 0 && l2 >= 0)
	{
		if (nums1[l1] > nums2[l2])
		{
			nums1[l3--] = nums1[l1--];
		}
		else
		{
			nums1[l3--] = nums2[l2--];
		}
	}

	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}

}
*/

//定义链表的结构
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;//存储的数据
	struct SListNode* next;//指向下一个结点
}SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		//找到下一个结点
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建新结点
SLTNode* SLTBuyNode(SLTDataType x)
{
	//根据x创建结点
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

//尾插
// 时间复杂度O(N)
//因为要修改链表的头结点，即要改变实参，
//所以要传地址，传一级指针的地址，用二级指针来接收
//结点                      *plist           **pphead
//指向结点的指针            plist            *pphead(一级指针）
//指向结点的指针的地址      &plist           pphead(二级指针）
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//避免传过来的结点为无效的结点，即为&plist == NULL，也就是pphead == NULL
	//所以要在这里断言判断pphead不为NULL、
	//pphead这里为空说明传过来的参数是错误的
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x) ;
	//链表为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}   
	else
	{
		//找尾结点
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			//找下一个结点
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

//头插
//时间复杂度为O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//避免传过来的结点为无效的结点，即为&plist == NULL，也就是pphead == NULL
	//所以要在这里断言判断pphead不为NULL、
	//pphead这里为空说明传过来的参数是错误的
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//1，2代码同时适用与链表为空和链表不为空这两种情况
	newnode->next = *pphead;//1代码
	*pphead = newnode;//2代码

}

//尾删
// 时间复杂度O(N)
//数据总会被删完，数据被删完后，头结点发生了改变。
//既然要改变头结点，那么这里就需要传址调用
void SLTPopBack(SLTNode** pphead)
{
	//链表不能为空，第一个结点不能为空。
	assert(pphead && *pphead);

	//只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找prev和ptail
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		//让ptail去找NULL
		while (ptail->next)
		{
			//让prev存储ptail当前所指向的位置
			prev = ptail;
			ptail = ptail->next;
		}
		//ptail找到NULL后，改变prev的next指针所指向的位置，
		//从而达到尾删的效果
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}	
}

//头删
//时间复杂度为O(1)
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	//只有一个结点和多个结点的情况都能满足
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

/*
//创建一个链表
void test01()
{
	//创建结点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	//赋具体数值
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	//将各个结点链接起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	SLTNode* plist = node1;
	SLTPrint(plist);
}
*/

/*
void test02()  
{
	//创建空链表
	SLTNode* plist = NULL;
	//往链表插入数据
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	//打印链表
	SLTPrint(plist);
}
*/

void test03()
{
	//创建空链表
	SLTNode* plist = NULL;
	//往链表插入数据
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	//打印链表
	SLTPrint(plist);
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
