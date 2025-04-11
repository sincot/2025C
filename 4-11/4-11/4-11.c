#include <stdio.h>

typedef struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
}Node;

//Ϊ�µĽ�㿪���ڴ�ռ�
Node* BuyNode(int x)
{
	//Ϊ�½���������С���ڴ�ռ�
	Node* newnode = (Node*)malloc(sizeof(Node));

	//��ʼ���½��
	newnode->val = x;
	newnode->next = newnode->random = NULL;

	//�����½��
	return newnode;
}

//�����µĽ��
//��ԭ�����ͷ���ĵ�ַ��Ϊ��������Ϊ��Ҫ����ԭ�����еĽ��
void AddNode(Node* head)
{
	//����һ��ָ��pcurȥ����ԭ����
	Node* pcur = head;

	//ѭ������ԭ����ֻҪpcurΪ�գ���ֹͣѭ��
	while (pcur)
	{
		//���ƽ�㣬Ϊ�µĽ�㿪���ڴ�ռ�
		//�½���б����valֵ��pcur��valһ��
		Node* newnode = BuyNode(pcur->val);

		//��newnode����ԭ������
		//����һ��ָ��next����pcur����һ�����ĵ�ַ
		Node* next = pcur->next;

		pcur->next = newnode;
		newnode->next = next;

		//pcur��������ȥ����
		pcur = next;
	}
}

//���ÿ�������randomָ���ָ��
//��ԭ�����ͷ���ĵ�ַ��Ϊ��������Ϊ�����Ľ����ԭ������
void SetRandom(Node* head)
{
	//����һ��ָ��pucrָ��ԭ�����ͷ���
	Node* pcur = head;

	//��pcur����ԭ����ȥ���ÿ�������randomָ���ָ��
	//ѭ��ִ�У�ֱ��pcurָ��NULL
	while (pcur)
	{
		//����һ��ָ��copyָ�򿽱����ĵ�һ�����,��pcur����һ�����
		//copyָ��ָ���ʼ����pucr����һ�����
		Node* copy = pcur->next;

		//���ÿ�������randomָ���ָ��
		//ֻҪpcur��randomָ��ָ��Ĳ���NULL
		//��ִ��copy->random = pcur->random->next
		if (pcur->random)
		{
			copy->random = pcur->random->next;
		}

		//������randomָ���pcur��Ҫ�������±���
		pcur = copy->next;
	}	
}

struct Node* copyRandomList(struct Node* head)
{
	//������Ϊ��
	if (head == NULL)
	{
		return head;
	}

	//��ԭ����Ļ����Ͽ�����㣬�����½�����ԭ������
	//���ú���AddNode
	AddNode(head);

	//���ÿ�������randomָ���ָ��
	//���ú���SetRandom
	SetRandom(head);

	//���������ԭ�����жϿ�
    //����ָ��pcurȥ����ԭ����
	Node* pcur = head;

	//����ָ��prev��ʼ��ָ��ԭ�����ͷ���
	//Ϊ�˻ָ�ԭ�����nextָ���ָ��
	Node* prev = head;

	//��������ָ��copyhead��copytail����ʼ��ָ���ƽ��ĵ�һ�����
	//copyheadʼ��ָ���������ͷ���
	//copytailȥ����������ȥ�����������н���nextָ���ָ��
	Node* copyhead = pcur->next;
	Node* copytail = pcur->next;

	while (copytail->next)
	{
		//��pcurָ��ָ��copytail����һ�����
		//ʹ��pcur�������±���ԭ����
		pcur = copytail->next;

		//�ָ�ԭ����nextָ���ָ��
		prev->next = pcur;
		prev = pcur;

		//������������nextָ���ָ��
		copytail->next = pcur->next;
		
		//copytail�������±���������
		copytail = copytail->next;
	}

	//���������ͷ��㷵��
	return copyhead;
}