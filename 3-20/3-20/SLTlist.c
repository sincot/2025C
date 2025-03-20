#include "SLTlist.h"

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

//����x�������
SLTNode* SLTBuyNode(SLTDataType x)
{
	//����x�������
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//�ж�newnode�Ƿ񴴽��ɹ�
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}

//�����β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//������ΪNULL������ɿ�ָ���쳣
	//�жϲ����Ƿ�Ϊ��Ч��㣬����pphead����Ϊ��
	//���*ppheadΪ�գ�˵����ָ��ĵ�һ�����ĵ�ַΪ��
	//���ppheadΪ�գ�˵������Ĵ����Ǵ���ġ�
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//����Ϊ��,��pheadΪ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//����Ϊ��
	else
	{
		//��β���
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//�ҵ���β���
		ptail->next = newnode;
	}
	
}

//�����ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//������ΪNULL������ɿ�ָ���쳣
	//�жϲ����Ƿ�Ϊ��Ч��㣬����pphead����Ϊ��
	//���*ppheadΪ�գ�˵����ָ��ĵ�һ�����ĵ�ַΪ��
	//���ppheadΪ�գ�˵������Ĵ����Ǵ���ġ�
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//�����βɾ
void SLTPopBack(SLTNode** pphead)
{
	//*ppheadΪ�գ�˵����һ�����Ϊ��
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
		//��β���
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//�����ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//�ҵ�ͷ������һ�����
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}






