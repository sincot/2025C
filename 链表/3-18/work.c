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

//��������Ľṹ
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;//�洢������
	struct SListNode* next;//ָ����һ�����
}SLTNode;

//����Ĵ�ӡ
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d -> ", pcur->data);
		//�ҵ���һ�����
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//�����½��
SLTNode* SLTBuyNode(SLTDataType x)
{
	//����x�������
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

//β��
// ʱ�临�Ӷ�O(N)
//��ΪҪ�޸������ͷ��㣬��Ҫ�ı�ʵ�Σ�
//����Ҫ����ַ����һ��ָ��ĵ�ַ���ö���ָ��������
//���                      *plist           **pphead
//ָ�����ָ��            plist            *pphead(һ��ָ�룩
//ָ�����ָ��ĵ�ַ      &plist           pphead(����ָ�룩
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//���⴫�����Ľ��Ϊ��Ч�Ľ�㣬��Ϊ&plist == NULL��Ҳ����pphead == NULL
	//����Ҫ����������ж�pphead��ΪNULL��
	//pphead����Ϊ��˵���������Ĳ����Ǵ����
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x) ;
	//����Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}   
	else
	{
		//��β���
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			//����һ�����
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

//ͷ��
//ʱ�临�Ӷ�ΪO(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//���⴫�����Ľ��Ϊ��Ч�Ľ�㣬��Ϊ&plist == NULL��Ҳ����pphead == NULL
	//����Ҫ����������ж�pphead��ΪNULL��
	//pphead����Ϊ��˵���������Ĳ����Ǵ����
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//1��2����ͬʱ����������Ϊ�պ�����Ϊ�����������
	newnode->next = *pphead;//1����
	*pphead = newnode;//2����

}

//βɾ
// ʱ�临�Ӷ�O(N)
//�����ܻᱻɾ�꣬���ݱ�ɾ���ͷ��㷢���˸ı䡣
//��ȻҪ�ı�ͷ��㣬��ô�������Ҫ��ַ����
void SLTPopBack(SLTNode** pphead)
{
	//������Ϊ�գ���һ����㲻��Ϊ�ա�
	assert(pphead && *pphead);

	//ֻ��һ�����
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��prev��ptail
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		//��ptailȥ��NULL
		while (ptail->next)
		{
			//��prev�洢ptail��ǰ��ָ���λ��
			prev = ptail;
			ptail = ptail->next;
		}
		//ptail�ҵ�NULL�󣬸ı�prev��nextָ����ָ���λ�ã�
		//�Ӷ��ﵽβɾ��Ч��
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}	
}

//ͷɾ
//ʱ�临�Ӷ�ΪO(1)
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	//ֻ��һ�����Ͷ�����������������
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

/*
//����һ������
void test01()
{
	//�������
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	//��������ֵ
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	//�����������������
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
	//����������
	SLTNode* plist = NULL;
	//�������������
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	//��ӡ����
	SLTPrint(plist);
}
*/

void test03()
{
	//����������
	SLTNode* plist = NULL;
	//�������������
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	//��ӡ����
	SLTPrint(plist);
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
