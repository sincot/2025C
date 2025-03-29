#include "List.h"

//Ϊ�ս�㿪���ڴ�ռ�
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	newnode->data = x;
	//Ϊ�˹���ѭ���ṹ��Ҫprev��nextָ��ָ���Լ�
	newnode->prev = newnode->next = newnode;

	return newnode;
}

//˫�����β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	//ͷ��㲻��Ϊ��
	assert(phead);
    //�����ս��
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->prev
	//��һ�����Ƚ�newnode��phead����
	newnode->next = phead;
	//�ڶ�������newnode��β��㣨phead->prev����������
	newnode->prev = phead->prev;
	//����������β��㣨phead->prev����newnode��������
	phead->prev->next = newnode;
	//���Ĳ�����phead��newnode��������
	phead->prev = newnode;
}

//˫�����ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	//ͷ��㲻��Ϊ��
	assert(phead);
	//�����ս��
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	//��һ�����Ƚ�newnode��phead->next����
	newnode->next = phead->next;
	//�ڶ�������newnode��phead����
	newnode->prev = phead;
	//����������phead->next��newnode��������
	phead->next->prev = newnode;
	//���Ĳ�����phead��newnode��������
	phead->next = newnode;
}

//�ж�˫�����Ƿ�Ϊ��
/*
bool LTEmpty(LTNode* phead)
{
	//������Ϊ��
	assert(phead);
	if (phead->next == phead)
	{
		return true;
	}

	return false;
}
*/

bool LTEmpty(LTNode* phead)
{
	//������Ϊ��
	assert(phead);

	return phead->next == phead;
}

//˫�����βɾ
void LTPopBack(LTNode* phead)
{
	//˫������Ϊ��
	//��Ϊ�գ�����true��ȡ��֮��Ϊfalse��ִ��assert
	//����Ϊ�գ�����false��ȡ��֮��Ϊtrue����ִ��assert
	assert(!LTEmpty(phead));
	//Ϊ�˷����ʾβ����ǰһ�����
	//��β�����ָ��del��ʾ
	LTNode* del = phead->prev;
	//phead del del->prev
	phead->prev = del->prev;
	del->prev->next = phead;
	//��ɾ���Ľ����ڴ�ռ�free��
	free(del);
	//�ֶ���Ϊ��
	del = NULL;
}

//˫�����ͷɾ
void LTPopFront(LTNode* phead)
{
	//˫������Ϊ��
	//��Ϊ�գ�����true��ȡ��֮��Ϊfalse��ִ��assert
	//����Ϊ�գ�����false��ȡ��֮��Ϊtrue����ִ��assert
	assert(!LTEmpty(phead));
	//Ϊ�˷����ʾͷ�������¸����
	//��ͷ������һ������ָ����ָ��del��ʾ
	LTNode* del = phead->next;
	//phead del del->next
	phead->next = del;
	del->next->prev = phead;
	//��ɾ���Ľ����ڴ�ռ�free��
	free(del);
	//�ֶ���Ϊ��
	del = NULL;
}

//˫���������ݵĲ���
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	//ͷ��㲻��Ϊ��
	assert(phead);
	//����һ��pcurָ��ȥ��������
	//��pcur����pheadʱ������ѭ��
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	//������ѭ����˵����������
	//��Ȼ�Ҳ���x,����NULL
	return NULL;
}

//��ָ��λ��posǰ��������
void LTInsertAfter(LTNode* pos, LTDataType x)
{
	//ָ��pos���ĵ�ַ����Ϊ��
	assert(pos);
	//�����ս��
	LTNode* newnode = LTBuyNode(x);
	//pos->prev newnode pos
	//��һ������newnode��pos��������
	newnode->next = pos;
	//�ڶ�������newnode��pos->prev��������
	newnode->prev = pos->prev;
	//����������pos->prev��newnode��������
	pos->prev->next = newnode;
	//���Ĳ�����pos��newnode��������
	pos->prev = newnode;
}

//��ָ��λ��pos���������
void LTInsertBefore(LTNode* pos, LTDataType x)
{
	//pos��ָ��Ľ��ĵ�ַ����Ϊ��
	assert(pos);
	//�����ս��
	LTNode* newnode = LTBuyNode(x);
	//pos newnode pos->next
	//��һ������newnode��pos->next����
	newnode->next = pos->next;
	//�ڶ�������newnode��pos����
	newnode->prev = pos;
	//����������pos->next��newnode��������
	pos->next->prev = newnode;
	//���Ĳ�����pos��newnode��������
	pos->next = newnode;
}

//ɾ��ָ��λ��pos��������
void LTErase(LTNode* pos)
{
	//posָ����ָ��Ľ��ĵ�ַ����Ϊ��
	assert(pos);
	//pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	//��pos�����ڴ�ռ�free��
	free(pos);
	pos = NULL;
}

//����˫��������ݣ���ַ���ã�
/*
void LTDestory(LTNode** pphead)
{
	//�������ĵ�ַ����Ϊ��
	assert(pphead);
	//����һ��ָ��pcur������������
	//��ͷ������һ����㿪ʼ
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		//����һ��ָ��next�����ڴ洢pcur����һ�����
		//����pcur�����±���
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//����ѭ����˵��pcur�Ѿ�ִ����ͷ���
	//��ͷ�����ڴ�ռ�Ҳ�ͷŵ����������������������ݲ���
	free(*pphead);
	//�ֶ��ÿ�
	*pphead = NULL;
}
*/
