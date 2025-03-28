#include "Slist.h"

SLTNode* SLTBuyNode(SLTDataType x)
{
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

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//�����ս��
	SLTNode* newnode = SLTBuyNode(x);
	//ͷ���Ϊ��
	//���´����õĽ�㸳ֵ��*pphead
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//ͷ��㲻ΪNULL
	else
	{
		//����pcurָ�룬��������
		SLTNode* pcur = *pphead;
		while (pcur->next)
		{
			//�������±���
			pcur = pcur->next;
		}
		//����ѭ����˵��pcur->nextΪ��
		//����ʱpcur��ָ��β���
		pcur->next = newnode;
	}
}

//�������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	//�������ĵ�ַ����Ϊ�գ����������Ϊ�գ���*pphead����Ϊ��
	assert(pphead);
	//�����ս��
	SLTNode* newnode = SLTBuyNode(x);
	//newnode��ͷ�������
	newnode->next = *pphead;
	//newnode��Ϊ�µ�ͷ���
	*pphead = newnode;
}

//�������βɾ
void SLTPopBack(SLTNode** pphead)
{
	//�������ĵ�ַ����Ϊ��
	//������Ϊ��
	assert(pphead && *pphead);
	
	//ֻ��һ�����
	//*pphead�����ŵ�ԭ���ǣ�->�����������ȼ�����*
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//��һ�����ϵĽ��
	else
	{
		//��������ָ��pcur,ptail
	    //pcur����β����ǰһ�����
	    //ptail����β���
		SLTNode* pcur = NULL;
		SLTNode* ptail = *pphead;

		//��patilȥ����������β���
		while (ptail->next)
		{
			//��ptail��ֵ��pcur
			pcur = ptail;
			ptail = ptail->next;
		}
		//��β��������ϵͳ������ڴ�ռ��ͷŵ�
		free(ptail);
		//�ֶ���ΪNULL
		ptail = NULL;
		pcur->next = NULL;
	}	
}

//�������ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//����ָ��next��ͷ������һ�����ĵ�ַ�洢����
	SLTNode* next = (*pphead)->next;
	//��ͷ��������ϵͳ����Ŀռ�黹������ϵͳ
	free(*pphead);
	//���µ�ͷ���ĵ�ַ��ֵ��*pphead
	*pphead = next;
}

//��ָ��λ��posǰ��������
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	//�����ս��
	SLTNode* newnode = SLTBuyNode(x);
	//posָ��Ľ��Ϊͷ���
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	//posָ��Ľ�㲻Ϊͷ���
	else
	{
		//����pcurָ��ȥ��������
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		//����ѭ����˵���ҵ���pos��ǰһ�����
		pcur->next = newnode;
		newnode->next = pos;
	}	
}

//��ָ��λ��pos���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	//�����ս��
	SLTNode* newnode = SLTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��ָ��λ��pos������
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	//posָ��Ľ��Ϊͷ���
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		//����ָ��pos���������ҵ�posλ��֮ǰ�Ľ��
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			//�������±���
			pcur = pcur->next;
		}
		//����ѭ����˵���ҵ���posλ��֮ǰ�Ľ��
		//pcur pos pos->next
		pcur = pos->next;
		//free��pos
		free(pos);
		//�ֶ���ΪNULL
		pos = NULL;
	}
}

//ɾ��ָ��λ��pos֮�������
void SLTEraseAfter(SLTNode* pos)
{
	//posָ�벻��Ϊ��,pos֮��Ľ�㲻��Ϊ��
	assert(pos && pos->next);
	//����delָ�룬������ʾҪɾ��������
	SLTNode* del = pos->next;
	//pos del del->next
	pos->next = del->next;
	free(del);
	del = NULL;
}

//�������������
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	//����pcurָ��ȥ��������
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//����ѭ����˵���Ҳ���x���ʷ���NULL
	return NULL;
}

//�������������
void SLTDestory(SLTNode** pphead)
{
	//������Ϊ�գ���������ָ�벻��Ϊ��
	asserrt(pphead && *pphead);
	//����ָ��pcur�����������������ٽ��
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		//����һ��ָ�������pcur������ĵ�ַ
		//Ϊ������pcur֮�����ҵ������Ľ��
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}