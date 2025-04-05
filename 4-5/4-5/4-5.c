#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

/*
//定义链式结构的二叉树
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//创建结点
BTNode* BTBuyNode(char x)
{
	//向操作系同申请内存
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

//创建一个二叉树
void CreateBinaryTree()
{
	//创建结点
	BTNode* nodeA = BTBuyNode('A');
	BTNode* nodeB = BTBuyNode('B');
	BTNode* nodeC = BTBuyNode('C');
	BTNode* nodeD = BTBuyNode('D');
	BTNode* nodeE = BTBuyNode('E');
	BTNode* nodeF = BTBuyNode('F');

	//链接结点 --- 按照所作的图的链接顺序链接
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	//返回根结点的地址
	return nodeA;
}

//求二叉树叶子结点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	//结点不能为空，为空就返回0
	if (root == NULL)
	{
		return 0;
	}
	//判断结点是否叶子结点
	//如何判断？--- 该结点的左右结点都为空
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	//递归 --- 求左子树叶子结点的个数 和 右子树叶子结点的个数
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//求二叉树第K层结点的个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//根结点为空，直接返回0
	if (root == NULL)
	{
		return 0;
	}
	//到达了目标层，即k为1
	if (k == 1)
	{
		return 1;
	}
	//求左子树第K层结点的个数 和 右子树第K层结点的个数
	//每次往下递归，k都减1，直到k == 1
	return BinaryTreeLevelKSize(root->left, k - 1)
		 + BinaryTreeLevelKSize(root->right, k - 1);
}

//求二叉树的深度/高度
int BinaryTreeDepth(BTNode* root)
{
	//结点为空就返回0
	if (root == NULL)
	{
		return 0;
	}
	//求左子树的深度/高度
	//定义一个变量接收左子树的深度/高度
	int leftDeapth = BinaryTreeDepth(root->left);
	////求左子树的深度/高度
	//定义一个变量接收左子树的深度/高度
	int rightDeapth = BinaryTreeDepth(root->right);

	//二叉树的深度/高度 = 根结点 + 左右子树中深度/高度的最大值(用三目操作符）
	return 1 + (leftDeapth > rightDeapth ? leftDeapth : rightDeapth);
}

//二叉树查找置为x的结点,并返回该结点的地址
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//结点为空，返回NULL
	if (root == NULL)
	{
		return NULL;
	}
	//找到了，直接返回当前结点的地址
	if (root->data == x)
	{
		return root;
	}
	//递归遍历左子树
	BTNode* leftFind = BinaryTreeFind(root->left, x);

	//判断是否在左子树中找到了
	//若在左子树中找到了，就返回leftFind
	if (leftFind)
	{
		return leftFind;
	}

	//若没在左子树中找到，就去右子树中去找
	//递归遍历右子树
	BTNode* rightFind = BinaryTreeFind(root->right, x);

	//判断是否在右子树中找到了
	//若在右子树中找到了，就返回rightFind
	if (rightFind)
	{
		return rightFind;
	}

	//若没在右子树中找到，那就说明找不到了，直接返回NULL
	return NULL;
}

//二叉树的销毁
//销毁会改变二叉树，所以要传址
void BinaryTreeDestory(BTNode** root)
{
	//销毁肯定得要遍历二叉树，那怎么遍历呢？
	//为了能够找到根结点的左右结点
	//所以根结点的销毁必须放在最后
	//根据前面的二叉树的排序可以知道
	//能实现最后遍历到的遍历方法是后序遍历（左右根）

	//若结点为空，则不用释放
	if (*root == NULL)
	{
		return;
	}
	//先遍历销毁左子树的结点
	BinaryTreeDestory(&((*root)->left));
	//再遍历销毁右子树的结点
	BinaryTreeDestory(&((*root)->right));
	//最后销毁根结点
	free(*root);
	//手动置空
	*root = NULL;
}

//***********************队列的相关操作***********************
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;
}Queue;

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

//入队--队尾
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
	//队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//队列不为空
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//出队--队头
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

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->ptail->data;
}

//队列的销毁
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

//层序遍历 --- 借用数据结构--队列来实现
void BTLeverOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//定义一个队列
	Queue q;
	//初始化队列
	QueueInit(&q);
	//将根结点入队列，调用函数QueuePush
	QueuePush(&q, root);
	//循环遍历二叉树
	while (!QueueEmpty(&q))
	{
		//取队头 --- 调用函数QueueFront
		//队列中的数据是二叉树的结点，所以取出来的数据的类型是BTNode*
		BTNode* top = QueueFront(&q);
		//出队头 --- 调用函数QueuePop
		QueuePop(&q);
		//打印当前队列中队头存储的结点的数据
		printf("%c ", top->data);
		//将当前队头的存储的结点的非空左右孩子入队列
		//若它的左孩子非空，则将左孩子入队列
		if (top->left)
		{
			//入队列
			QueuePush(&q, top->left);
		}
		//若它的右孩子非空，则将右孩子入队列
		if (top->right)
		{
			//入队列
			QueuePush(&q, top->right);
		}
	}
	//销毁队列——调用函数QueueDestory
	QueueDestory(&q);
}

//判断二叉树是否为完全二叉树 --- 借助数据结构——队列
bool BinaryTreeCompplete(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//定义一个队列
	Queue q;
	//初始化队列
	QueueInit(&q);
	//将根结点入队列，调用函数QueuePush
	QueuePush(&q, root);

	//第一个循环
	while (!QueueEmpty(&q))
	{
		//取队头结点——调用函数QueueFront
		BTNode* top = QueueFront(&q);
		//出队头结点——调用函数QueuePop
		QueuePop(&q);
		//判断取的队头结点是否为空，为空就结束循环
		if (top == NULL)
		{
			break;
		}
		//不为空，就将取出队头的结点的左右结点入队列
		QueuePush(&q, top->left);
		QueuePush(&q, top->right);
	}

	//队列不一定为空
	//第二个循环
	while (!QueueEmpty(&q))
	{
		//取队头的结点
		BTNode* top = QueueFront(&q);
		//出队头的结点
		QueuePop(&q);
		//若取到的队头的结点结点非空
		//那么就返回false，表明该二叉树不是完全二叉树
		if (top != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}

	QueueDestory(&q);
	//循环结束后，说明一直都没有取到非空结点
	//直接返回true，表明该二叉树是完全二叉树
	return true;
}
*/


/*
//单值二叉树
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isUnivalTree(struct TreeNode* root)
{
	//结点为空，直接返回true
	if (root == NULL)
	{
		return true;
	}
	//将当前结点的val与它的左孩子的val相比较
	//不相等直接返回false
	if (root->left != NULL && root->val != root->left->val)
	{
		return false;
	}
	//将当前结点的val与它的左孩子的val相比较
	//不相等直接返回false
	if (root->right != NULL && root->val != root->right->val)
	{
		return false;
	}

	//当前结点的val与它的左右孩子的val都相等
	//递归遍历二叉树
	//先递归判断根结点的左子树是否为单值二叉树
	//再递归判断根结点的右子树是否为单值二叉树
	//若左子树为单值二叉树，右子树也为单值二叉树
	//那么该二叉树为单值二叉树
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}
*/

/*
//相同的树 --- 结构相同，相同的位置的结点的值相同
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//若p,q都为空，则说明当前的结点的值是相等的
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,q只有其中一个为空
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q都不为空
    //比较p,q的值是否相等，不相等直接返回false
	if (p->val != q->val)
	{
		return false;
	}
	//结构相同，值也相同
	//递归p,q的左子树的结构和值是否相等
	//递归p,q的右子树的结构和值是否相等

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
*/

/*
//对称二叉树
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//若p,q都为空，则说明当前的结点的值是相等的
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,q只有其中一个为空
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q都不为空
	//比较p,q的值是否相等，不相等直接返回false
	if (p->val != q->val)
	{
		return false;
	}
	//递归p的左子树的结构和值与q的右子树的结构和值是否相等
	//递归p的右子树的结构和值与q的左子树的结构和值是否相等
	return isSameTree(p->left, q->right) && isSameTree(p->left, q->right);
}

bool isSymmetric(struct TreeNode* root)
{
	return isSameTree(root->left, root->right);
}
*/

/*
//另一棵树的子树
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//判断两个树是否是相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//若p,q都为空，则说明当前的结点的值是相等的
	if (p == NULL && q == NULL)
	{
		return true;
	}
	//p,q只有其中一个为空
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//p,q都不为空
	//比较p,q的值是否相等，不相等直接返回false
	if (p->val != q->val)
	{
		return false;
	}
	//结构相同，值也相同
	//递归p,q的左子树的结构和值是否相等
	//递归p,q的右子树的结构和值是否相等
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	//判断两个树是否是相同的树
	//如果root和subRoot是相同的树，那就直接返回true
	if (isSameTree(root, subRoot))
	{
		return true;
	}

	//先拿root的左子树与subRoot比较
	//再拿root的右子树与subRoot比较
	//若其中一个返回了true，那就说明subRoot是root的子树
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
//将遍历到的每一个值存储在数组中

/*
//求二叉树结点的个数
int BinaryTreeSize(TreeNode* root)
{
	//结点不能为空,若为空，那么结点的个数为0
	if (root == NULL)
	{
		return 0;
	}
	//二叉树结点的个数 = 根结点 + 左子树结点的个数 + 右子树结点的个数
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//前序遍历
void BTPreOrder(TreeNode* root, int* arr, int* pi)
{
	//结点不能为空
	if (root == NULL)
	{
		return;
	}
	//将根结点的值保存在数组中
	arr[(*pi)++] = root->val;
	//递归遍历左子树
	BTPreOrder(root->left, arr, pi);
	BTPreOrder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	//要将遍历到的每一个值都存储在数组中
	//那么就得定义一个数组，而数组的大小为多大呢？
	//数组的大小就是二叉树结点的个数
	//所以首先要求得二叉树结点的个数

	//求二叉树结点的个数
	//为什么要用*returnSize来接收二叉树结点的个数
	//它既然给了你参数，说明该参数要存储数据
	*returnSize = BinaryTreeSize(root);
	//为数组申请一个*returnSize个int大小的空间
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
	//前序遍历
	//变量i用来计数
	int i = 0;
	BTPreOrder(root, arr, &i);

	//返回数组
	return arr;
}
*/

//定义二叉树的链式结构
typedef struct TreeNode
{
	char data;  //存储的数据是字符型
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//创建结点
TreeNode* BTBuyNode(char ch)
{
	//为结点动态内存开辟空间
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	//判断是否开辟成功
	if (newnode == NULL)
	{
		perror("malloc");
		exxit(1);
	}
	//存储数据
	newnode->data = ch;
	newnode->left = newnode->right = NULL;

	return newnode;
}

//创建二叉树 --- 返回二叉树的根结点
TreeNode* BTCreateTree(char* arr, int* pi)
{
	//判断下标为pi的值是否为'#'
	if (arr[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	//创建根结点
	TreeNode* root = BTBuyNode(arr[*pi]);
	//pi++
	(*pi)++;
	//递归创建根结点的左子树与右子树
	root->left = BTCreateNode(arr, pi);
	root->right = BTCreateTree(arr, pi);

	//返回指向根结点的指针
	return root;
}

//中序遍历 --- 左根右
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
	//定义一个数组来存储输入的字符串
	//题目提供了字符串的长度不超过100
	//所以数组的大小为100
	char arr[100] = { 0 };
	//读取用户输入的字符串
	scanf("%s", arr);

	//根据前序遍历方法遍历字符串来创建二叉树
	//定义一个变量i来作为数组的下标
	int i = 0;
	TreeNode* root = BTCreateTree(arr, &i);
	//二叉树的中序遍历
	BTInOrder(root);

	return 0;
}