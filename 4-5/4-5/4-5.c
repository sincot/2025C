#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//������ʽ�ṹ�Ķ�����
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�������
BTNode* BTBuyNode(char x)
{
	//�����ϵͬ�����ڴ�
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;

	return newnode;
}

//����һ��������
void CreateBinaryTree()
{
	//�������
	BTNode* nodeA = BTBuyNode('A');
	BTNode* nodeB = BTBuyNode('B');
	BTNode* nodeC = BTBuyNode('C');
	BTNode* nodeD = BTBuyNode('D');
	BTNode* nodeE = BTBuyNode('E');
	BTNode* nodeF = BTBuyNode('F');

	//���ӽ�� --- ����������ͼ������˳������
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	//���ظ����ĵ�ַ
	return nodeA;
}

//�������Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	//��㲻��Ϊ�գ�Ϊ�վͷ���0
	if (root == NULL)
	{
		return 0;
	}
	//�жϽ���Ƿ�Ҷ�ӽ��
	//����жϣ�--- �ý������ҽ�㶼Ϊ��
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	//�ݹ� --- ��������Ҷ�ӽ��ĸ��� �� ������Ҷ�ӽ��ĸ���
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//���������K����ĸ���
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//�����Ϊ�գ�ֱ�ӷ���0
	if (root == NULL)
	{
		return 0;
	}
	//������Ŀ��㣬��kΪ1
	if (k == 1)
	{
		return 1;
	}
	//����������K����ĸ��� �� ��������K����ĸ���
	//ÿ�����µݹ飬k����1��ֱ��k == 1
	return BinaryTreeLevelKSize(root->left, k - 1)
		 + BinaryTreeLevelKSize(root->right, k - 1);
}

//������������/�߶�
int BinaryTreeDepth(BTNode* root)
{
	//���Ϊ�վͷ���0
	if (root == NULL)
	{
		return 0;
	}
	//�������������/�߶�
	//����һ���������������������/�߶�
	int leftDeapth = BinaryTreeDepth(root->left);
	////�������������/�߶�
	//����һ���������������������/�߶�
	int rightDeapth = BinaryTreeDepth(root->right);

	//�����������/�߶� = ����� + �������������/�߶ȵ����ֵ(����Ŀ��������
	return 1 + (leftDeapth > rightDeapth ? leftDeapth : rightDeapth);
}

//������������Ϊx�Ľ��,�����ظý��ĵ�ַ
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//���Ϊ�գ�����NULL
	if (root == NULL)
	{
		return NULL;
	}
	//�ҵ��ˣ�ֱ�ӷ��ص�ǰ���ĵ�ַ
	if (root->data == x)
	{
		return root;
	}
	//�ݹ����������
	BTNode* leftFind = BinaryTreeFind(root->left, x);

	//�ж��Ƿ������������ҵ���
	//�������������ҵ��ˣ��ͷ���leftFind
	if (leftFind)
	{
		return leftFind;
	}

	//��û�����������ҵ�����ȥ��������ȥ��
	//�ݹ����������
	BTNode* rightFind = BinaryTreeFind(root->right, x);

	//�ж��Ƿ������������ҵ���
	//�������������ҵ��ˣ��ͷ���rightFind
	if (rightFind)
	{
		return rightFind;
	}

	//��û�����������ҵ����Ǿ�˵���Ҳ����ˣ�ֱ�ӷ���NULL
	return NULL;
}

//������������
//���ٻ�ı������������Ҫ��ַ
void BinaryTreeDestory(BTNode** root)
{
	//���ٿ϶���Ҫ����������������ô�����أ�
	//Ϊ���ܹ��ҵ����������ҽ��
	//���Ը��������ٱ���������
	//����ǰ��Ķ��������������֪��
	//��ʵ�����������ı��������Ǻ�����������Ҹ���

	//�����Ϊ�գ������ͷ�
	if (*root == NULL)
	{
		return;
	}
	//�ȱ��������������Ľ��
	BinaryTreeDestory(&((*root)->left));
	//�ٱ��������������Ľ��
	BinaryTreeDestory(&((*root)->right));
	//������ٸ����
	free(*root);
	//�ֶ��ÿ�
	*root = NULL;
}

//***********************���е���ز���***********************
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//������еĽṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;
}Queue;

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

//���--��β
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//���в�Ϊ��
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//����--��ͷ
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->ptail->data;
}

//���е�����
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
}

//������� --- �������ݽṹ--������ʵ��
void BTLeverOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//����һ������
	Queue q;
	//��ʼ������
	QueueInit(&q);
	//�����������У����ú���QueuePush
	QueuePush(&q, root);
	//ѭ������������
	while (!QueueEmpty(&q))
	{
		//ȡ��ͷ --- ���ú���QueueFront
		//�����е������Ƕ������Ľ�㣬����ȡ���������ݵ�������BTNode*
		BTNode* top = QueueFront(&q);
		//����ͷ --- ���ú���QueuePop
		QueuePop(&q);
		//��ӡ��ǰ�����ж�ͷ�洢�Ľ�������
		printf("%c ", top->data);
		//����ǰ��ͷ�Ĵ洢�Ľ��ķǿ����Һ��������
		//���������ӷǿգ������������
		if (top->left)
		{
			//�����
			QueuePush(&q, top->left);
		}
		//�������Һ��ӷǿգ����Һ��������
		if (top->right)
		{
			//�����
			QueuePush(&q, top->right);
		}
	}
	//���ٶ��С������ú���QueueDestory
	QueueDestory(&q);
}

//�ж϶������Ƿ�Ϊ��ȫ������ --- �������ݽṹ��������
bool BinaryTreeCompplete(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//����һ������
	Queue q;
	//��ʼ������
	QueueInit(&q);
	//�����������У����ú���QueuePush
	QueuePush(&q, root);

	//��һ��ѭ��
	while (!QueueEmpty(&q))
	{
		//ȡ��ͷ��㡪�����ú���QueueFront
		BTNode* top = QueueFront(&q);
		//����ͷ��㡪�����ú���QueuePop
		QueuePop(&q);
		//�ж�ȡ�Ķ�ͷ����Ƿ�Ϊ�գ�Ϊ�վͽ���ѭ��
		if (top == NULL)
		{
			break;
		}
		//��Ϊ�գ��ͽ�ȡ����ͷ�Ľ������ҽ�������
		QueuePush(&q, top->left);
		QueuePush(&q, top->right);
	}

	//���в�һ��Ϊ��
	//�ڶ���ѭ��
	while (!QueueEmpty(&q))
	{
		//ȡ��ͷ�Ľ��
		BTNode* top = QueueFront(&q);
		//����ͷ�Ľ��
		QueuePop(&q);
		//��ȡ���Ķ�ͷ�Ľ����ǿ�
		//��ô�ͷ���false�������ö�����������ȫ������
		if (top != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}

	QueueDestory(&q);
	//ѭ��������˵��һֱ��û��ȡ���ǿս��
	//ֱ�ӷ���true�������ö���������ȫ������
	return true;
}
*/


/*
//��ֵ������
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isUnivalTree(struct TreeNode* root)
{
	//���Ϊ�գ�ֱ�ӷ���true
	if (root == NULL)
	{
		return true;
	}
	//����ǰ����val���������ӵ�val��Ƚ�
	//�����ֱ�ӷ���false
	if (root->left != NULL && root->val != root->left->val)
	{
		return false;
	}
	//����ǰ����val���������ӵ�val��Ƚ�
	//�����ֱ�ӷ���false
	if (root->right != NULL && root->val != root->right->val)
	{
		return false;
	}

	//��ǰ����val���������Һ��ӵ�val�����
	//�ݹ����������
	//�ȵݹ��жϸ������������Ƿ�Ϊ��ֵ������
	//�ٵݹ��жϸ������������Ƿ�Ϊ��ֵ������
	//��������Ϊ��ֵ��������������ҲΪ��ֵ������
	//��ô�ö�����Ϊ��ֵ������
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}
*/

/*
//��ͬ���� --- �ṹ��ͬ����ͬ��λ�õĽ���ֵ��ͬ
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//��p,q��Ϊ�գ���˵����ǰ�Ľ���ֵ����ȵ�
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,qֻ������һ��Ϊ��
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q����Ϊ��
    //�Ƚ�p,q��ֵ�Ƿ���ȣ������ֱ�ӷ���false
	if (p->val != q->val)
	{
		return false;
	}
	//�ṹ��ͬ��ֵҲ��ͬ
	//�ݹ�p,q���������Ľṹ��ֵ�Ƿ����
	//�ݹ�p,q���������Ľṹ��ֵ�Ƿ����

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
*/

/*
//�Գƶ�����
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//��p,q��Ϊ�գ���˵����ǰ�Ľ���ֵ����ȵ�
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,qֻ������һ��Ϊ��
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q����Ϊ��
	//�Ƚ�p,q��ֵ�Ƿ���ȣ������ֱ�ӷ���false
	if (p->val != q->val)
	{
		return false;
	}
	//�ݹ�p���������Ľṹ��ֵ��q���������Ľṹ��ֵ�Ƿ����
	//�ݹ�p���������Ľṹ��ֵ��q���������Ľṹ��ֵ�Ƿ����
	return isSameTree(p->left, q->right) && isSameTree(p->left, q->right);
}

bool isSymmetric(struct TreeNode* root)
{
	return isSameTree(root->left, root->right);
}
*/

/*
//��һ����������
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//�ж��������Ƿ�����ͬ����
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//��p,q��Ϊ�գ���˵����ǰ�Ľ���ֵ����ȵ�
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,qֻ������һ��Ϊ��
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q����Ϊ��
	//�Ƚ�p,q��ֵ�Ƿ���ȣ������ֱ�ӷ���false
	if (p->val != q->val)
	{
		return false;
	}
	//�ṹ��ͬ��ֵҲ��ͬ
	//�ݹ�p,q���������Ľṹ��ֵ�Ƿ����
	//�ݹ�p,q���������Ľṹ��ֵ�Ƿ����
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	//�ж��������Ƿ�����ͬ����
	//���root��subRoot����ͬ�������Ǿ�ֱ�ӷ���true
	if (isSameTree(root, subRoot))
	{
		return true;
	}

	//����root����������subRoot�Ƚ�
	//����root����������subRoot�Ƚ�
	//������һ��������true���Ǿ�˵��subRoot��root������
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
*/

/*
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//����������ÿһ��ֵ�洢��������

/*
//����������ĸ���
int BinaryTreeSize(TreeNode* root)
{
	//��㲻��Ϊ��,��Ϊ�գ���ô���ĸ���Ϊ0
	if (root == NULL)
	{
		return 0;
	}
	//���������ĸ��� = ����� + ���������ĸ��� + ���������ĸ���
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//ǰ�����
void BTPreOrder(TreeNode* root, int* arr, int* pi)
{
	//��㲻��Ϊ��
	if (root == NULL)
	{
		return;
	}
	//��������ֵ������������
	arr[(*pi)++] = root->val;
	//�ݹ����������
	BTPreOrder(root->left, arr, pi);
	BTPreOrder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	//Ҫ����������ÿһ��ֵ���洢��������
	//��ô�͵ö���һ�����飬������Ĵ�СΪ����أ�
	//����Ĵ�С���Ƕ��������ĸ���
	//��������Ҫ��ö��������ĸ���

	//����������ĸ���
	//ΪʲôҪ��*returnSize�����ն��������ĸ���
	//����Ȼ�����������˵���ò���Ҫ�洢����
	*returnSize = BinaryTreeSize(root);
	//Ϊ��������һ��*returnSize��int��С�Ŀռ�
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
	//ǰ�����
	//����i��������
	int i = 0;
	BTPreOrder(root, arr, &i);

	//��������
	return arr;
}
*/

//�������������ʽ�ṹ
typedef struct TreeNode
{
	char data;  //�洢���������ַ���
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//�������
TreeNode* BTBuyNode(char ch)
{
	//Ϊ��㶯̬�ڴ濪�ٿռ�
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	//�ж��Ƿ񿪱ٳɹ�
	if (newnode == NULL)
	{
		perror("malloc");
		exxit(1);
	}
	//�洢����
	newnode->data = ch;
	newnode->left = newnode->right = NULL;

	return newnode;
}

//���������� --- ���ض������ĸ����
TreeNode* BTCreateTree(char* arr, int* pi)
{
	//�ж��±�Ϊpi��ֵ�Ƿ�Ϊ'#'
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	//���������
	TreeNode* root = BTBuyNode(arr[*pi]);
	//pi++
	(*pi)++;
	//�ݹ鴴����������������������
	root->left = BTCreateNode(arr, pi);
	root->right = BTCreateTree(arr, pi);

	//����ָ�������ָ��
	return root;
}

//������� --- �����
void BTInOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTInOrder(root->left);
	printf("%c ", root->data);
	BTInOrder(root->right);
}

int main()
{
	//����һ���������洢������ַ���
	//��Ŀ�ṩ���ַ����ĳ��Ȳ�����100
	//��������Ĵ�СΪ100
	char arr[100] = { 0 };
	//��ȡ�û�������ַ���
	scanf("%s", arr);

	//����ǰ��������������ַ���������������
	//����һ������i����Ϊ������±�
	int i = 0;
	TreeNode* root = BTCreateTree(arr, &i);
	//���������������
	BTInOrder(root);

	return 0;
}