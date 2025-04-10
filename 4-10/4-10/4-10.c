//�������ĸ���
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int val;
     struct Node *next;
     struct Node *random;
}Node;


//Ϊ�½�㿪���ڴ�ռ�
Node* BuyNode(int x)
{
    //Ϊ�µĽ�㿪�ٽ���С���ڴ�ռ�
    Node* newnode = (Node*)malloc(sizeof(Node));

    //��ʼ���µĽ��
    //��x��ֵ���½���val
    newnode->val = x;

    //���½�������ָ�붼ָ���
    newnode->next = newnode->random = NULL;

    //�����ӵ��½��ĵ�ַ����
    return newnode;
}

//�����µĽ��
//��ԭ����ĵ�ַ��Ϊ����
void AddNode(Node* head)
{
    //����һ��ָ��������ԭ�������㿽��
    Node* pcur = head;

    //ֻҪpcur��Ϊ�գ��ͼ�������
    while (pcur)
    {
        //�����µĽ��
        Node* newnode = BuyNode(pcur->val);

        //����һ��ָ��������pcur��һ�����ĵ�ַ
        Node* next = pcur->next;

        //��newnode������ԭ����
        newnode->next = next;
        pcur->next = newnode;

        //�����Ҳ�����Ϻ�pcur��ʼ��������Ľ��
        pcur = next;
    }
}

//�������ָ��random
void SetRandom(Node* head)
{
    //����һ��ָ����ָ��ԭ�����ͷ���
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

//֪��ԭ�����ͷ�����ظ��������ͷ
struct Node* copyRandomList(struct Node* head)
{
    //��ԭ����Ļ����Ͽ�����㲢������ԭ������
    AddNode(head);
    //����randomָ���ָ��
    SetRandom(head);
    //�Ͽ�������
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