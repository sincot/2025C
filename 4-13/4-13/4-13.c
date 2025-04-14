#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//ʵ����ʽ�ṹ������

//������ʽ�ṹ������
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* leftchild;
	struct BinaryTreeNode* rightchild;
}BTNode;


//Ϊ��㿪���ڴ�ռ�
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	newnode->data = x;
	newnode->leftchild = newnode->rightchild = NULL;

	return newnode;
}

//����������
BTNode* CreateBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');

	nodeA->leftchild = nodeB;
	nodeA->rightchild = nodeC;
	nodeB->leftchild = nodeD;
	nodeC->leftchild = nodeE;
	nodeC->rightchild = nodeF;

	return nodeA;
}

//ǰ����� --- ������
void BTPreOrder(BTNode* root)
{
	//�������ΪNULL����ӡNULL�����ҷ���
	if (root == NULL)
	{
		printf("NULL\t");
		
		//���ں����ķ���ֵ����Ϊvoid������ʲô���Ͷ������أ�����д��return����
		return;
	}

	//��ӡ�����
	printf("%c\t", root->data);

	//�ݹ����������������
	BTPreOrder(root->leftchild);

	//�ݹ����������������
	BTPreOrder(root->rightchild);
}

//������� --- �����
void BTInOrder(BTNode* root)
{
	//�������ΪNUll����ӡNULL�����ҷ���
	if (root == NULL)
	{
		printf("NULL\t");
		return;
	}

	//�ݹ����������������
	BTInOrder(root->leftchild);

	//��ӡ������dataֵ
	printf("%c\t", root->data);

	//�ݹ����������������
	BTInOrder(root->rightchild);
}

//������� --- ���Ҹ�
void BTPostOrder(BTNode* root)
{
	//�������ΪNULL����ӡNULL�����ҷ���
	if (root == NULL)
	{
		printf("NULL\t");
		return;
	}

	//�ݹ����������������
	BTPostOrder(root->leftchild);

	//�ݹ����������������
	BTPostOrder(root->rightchild);

	//��ӡ������dataֵ
	printf("%c\t", root->data);
}

//��������Ľ��Ľṹ
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueListNode
{
	QDataType data;//����Ľ�����洢������
	struct QueueListNode* next; //ָ����һ������ָ��
}QueueNode;

//������еĽṹ
typedef struct Queue
{
	QueueNode* phead; //ָ��ͷ����ָ��
	QueueNode* ptail; //ָ��β����ָ��
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	//������ָ����Ϊ��
	pq->phead = pq->ptail = NULL;
}

//���
void QueuePush(Queue* pq, QDataType x)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	//Ϊ��Ҫ����Ľ�㿪���ڴ�ռ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;
	//������������Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//�����������ݲ�Ϊ��
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//�ж϶������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	return pq->phead == NULL;
}

//������
void QueuePop(Queue* pq)
{
	//�������Ƿ�Ϊ��
	assert(!QueueEmpty(pq));
	//��������ֻ��һ�����
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//����һ��ָ��next��ͷ������һ���洢����
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	//���еĵ�ַ����Ϊ��
	assert(pq);
	return pq->phead->data;
}


//�������
void BTLevelOrder(BTNode* root)
{
	//����һ�����нṹ
	Queue q;

	//��ʼ������ --- ���ú���QueueInit
	QueueInit(&q);

	//������������ --- ���ú���QueuePush
	QueuePush(&q, root);

	//�ж϶����е������Ƿ�Ϊ��QueueEmpty
	while (!QueueEmpty(&q))
	{
		//ȡ���еĶ�ͷ�е����� --- ���ú���QueueFront
		BTNode* top = QueueFront(&q);
		//����ͷ������ --- ���ú���QueuePop
		QueuePop(&q);

		//��ӡ֮ǰ��ͷ������
		printf("%c\t", top->data);

		//��ͷ�����ݳ���ȥ֮�󣬽�top�����Һ��ӽ�������
		//�������֮ǰ�������ж������Һ����Ƿ�Ϊ��
		//��Ϊ�գ�����Ҫ����У�����Ϊ�գ�����Ҫ�����
		//�������Һ��ӽ������˳���ܸı䣬ֻ���������㣬���ҽ��
		if (top->leftchild)
		{
			QueuePush(&q, top->leftchild);
		}
		if (top->rightchild)
		{
			QueuePush(&q, top->rightchild);
		}
	}
}
//���������ĸ���
int BinaryTreeSize(BTNode* root)
{
	//��������Ϊ�գ��ͷ���0
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->leftchild) 
		   + BinaryTreeSize(root->rightchild);
}

//������Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	//����㲻��Ϊ�գ��������Ϊ���ˣ��Ͳ���������������
	//�������Ϊ�գ�����0
	if (root == NULL)
	{
		return 0;
	}
    
	//�ж��Ƿ���Ҷ�ӽ��
	//���ý�����Һ��Ӿ�ΪNULLʱ������˵���ý��ΪҶ�ӽ��
	//��ΪҶ�ӽ�㣬�򷵻�1
	if (root->leftchild == NULL && root->rightchild == NULL)
	{
		return 1;
	}

	//�ݹ������������������������
	return BinaryTreeLeafSize(root->leftchild)
		+ BinaryTreeLeafSize(root->rightchild);
}

//��������K����ĸ���
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//����㲻��ΪNUll����Ϊ�գ��Ͳ���������������
	//�������ΪNULL���򷵻�0
	if (root == NULL)
	{
		return 0;
	}

	//��k����1ʱ�������Ѿ�������Ŀ�����
	//��ʱֱ�ӷ���1
	if (k == 1)
	{
		return 1;
	}

	//�ݹ������������������������
	//��ÿ�εݹ飬k��Ҫ��1���Դ˴ﵽĿ�����
	return BinaryTreeLevelKSize(root->leftchild, k - 1)
	     + BinaryTreeLevelKSize(root->rightchild, k - 1);
}

//�����������/�߶�
int BinaryTreeDeap(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDeap = BinaryTreeDeap(root->leftchild);
	int rightDeap = BinaryTreeDeap(root->rightchild);

	return 1 + (leftDeap > rightDeap ? leftDeap : rightDeap);
}

//�ڶ������в���ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//�������ΪNULL���򷵻�NULL
	if (root == NULL)
	{
		return NULL;
	}

	//�жϸ�����dataֵ�Ƿ����x�������ڣ��򷵻ظø����ĵ�ַ
	if (root->data == x)
	{
		return root;
	}

	//�ݹ�������������۲��Ƿ��ܹ��ҵ�ֵΪx�Ľ��
	//����һ��ָ�������յݹ�����ķ���ֵ
	BTNode* leftFind = BinaryTreeFind(root->leftchild, x);

	//��leftFind��Ϊ�գ����������������Ѿ��ҵ��ˣ��Ǿ�ֱ�ӷ��ظ�ָ��
	if (leftFind)
	{
		return leftFind;
	}

	//�������е��⣬˵������������û���ҵ��������ٵݹ����������
	//����һ��ָ�������յݹ�����ķ���ֵ
	BTNode* rightFind = BinaryTreeFind(root->rightchild, x);

	//��rightFind��Ϊ�գ����������������Ѿ��ҵ��ˣ��Ǿ�ֱ�ӷ��ظ�ָ��
	if (rightFind)
	{
		return rightFind;
	}

	//�������е��⣬˵������������û���ҵ���������������Ҳû���ҵ�
	//�Ǿ�˵���ڶ��������Ҳ���dataֵΪx�Ľ�㣬��Ȼ�Ҳ������ͷ���NULL
	return NULL;
}

//������������
void BinaryTreeDestory(BTNode** root)
{
	//��ȡ��������ķ���ȥ����������
	if (*root == NULL)
	{
		return;
	}

	//�ݹ�������ٸ�����������
	BinaryTreeDestory(&((*root)->leftchild));

	//�ݹ�������ٸ�����������
	BinaryTreeDestory(&((*root)->rightchild));

	//���ٸ����
	free(*root);

	//�ֶ��ÿ�
	*root = NULL;
}

int main()
{
	BTNode* root = CreateBinaryTree();
	//BTPreOrder(root);
	//BTInOrder(root);
	//BTPostOrder(root);
	//BTLevelOrder(root);
	//printf("%d ", BinaryTreeLeafSize(root));
	//printf("%d ", BinaryTreeLevelKSize(root, 3));
	//printf("%d ", BinaryTreeDeap(root));
	//BTNode* find = BinaryTreeFind(root, 'F');
	BinaryTreeDestory(&root);

	return 0;
}
