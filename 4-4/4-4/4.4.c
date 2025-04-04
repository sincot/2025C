//链式结构的二叉树
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//定义链式结构的二叉树
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data; //存储的数据
	struct BinaryTreeNode* left; //指向左孩子结点的指针
	struct BinaryTreeNode* right;//指向右孩子结点的指针
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

//前序遍历 --- 根左右
void BTPreOrder(BTNode* root)
{
	//结点为空,打印NULL
	if (root == NULL)
	{
		printf("NULL ");
		//不返回任何类型的值
		return;
	}
	//打印结点中所存储的数据
	printf("%c ", root->data);
	//递归遍历左结点
	BTPreOrder(root->left);
	//递归遍历右结点
	BTPreOrder(root->right);
}

//中序遍历 --- 左根右
void BTInOrder(BTNode* root)
{
	//结点为空，打印NULL
	if (root == NULL)
	{
		printf("NULL ");
		//不返回任何类型的值
		return;
	}
	//递归遍历左结点
	BTInOrder(root->left);
	//打印结点中的数据
	printf("%c ", root->data);
	//递归遍历右结点
	BTInOrder(root->right);
}

//后序遍历 --- 左右根
void BTPostOrder(BTNode* root)
{
	//结点为空，打印NULL
	if (root == NULL)
	{
		printf("NULL ");
		//不返回任何类型的值
		return;
	}
	//递归遍历左结点
	BTPostOrder(root->left);
	//递归遍历右结点
	BTPostOrder(root->right);
	//打印结点中的数据
	printf("%c ", root->data);
}

//求二叉树结点的个数
/*
//不用递归实现 --- 定义一个变量作为参数来统计结点的个数
int size = 0;//全局变量，在每次调用后，要手动将size置为0
int BinaryTreeSize(BTNode* root, int* psize)
{
	//结点为空返回0
	if (root == NULL)
	{
		return 0;
	}
	//结点非空,size就加1
	(*psize)++;
	//形参的改变要影响实参，所以要传址调用
	BinaryTreeSize(root->left, &size);
	BinaryTreeSize(root->right, &size);

	return size;
}
*/

//求二叉树结点的个数
//用递归实现
int BinaryTreeSize(BTNode* root)
{
	////结点为空返回0
	if (root == NULL)
	{
		return 0;
	}
	//结点非空
	//二叉树结点的个数 = 1 + 左子树结点的个数 + 右子树结点的个数
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}


int main()
{

	return 0;
}
