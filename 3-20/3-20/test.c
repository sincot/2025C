#include "SLTlist.h"

//��������
/*
void test01()
{
	//�������
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	//��data��ֵ
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	//�����֮����������
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//����ͷ���
	SLTNode* plist = node1;
	SLTPrint(plist);
}
*/

void test02()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPopBack(&plist);
	SLTPrint(plist);
}

int main()
{
	//test01();
	test02();
	return 0;
}