#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//实现链式结构二叉树

//定义链式结构二叉树
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* leftchild;
	struct BinaryTreeNode* rightchild;
}BTNode;


//为结点开辟内存空间
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

//创建二叉树
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

//前序遍历 --- 根左右
void BTPreOrder(BTNode* root)
{
	//当根结点为NULL，打印NULL，并且返回
	if (root == NULL)
	{
		printf("NULL\t");
		
		//由于函数的返回值类型为void，所以什么类型都不返回，仅仅写个return即可
		return;
	}

	//打印根结点
	printf("%c\t", root->data);

	//递归遍历根结点的左子树
	BTPreOrder(root->leftchild);

	//递归遍历根结点的右子树
	BTPreOrder(root->rightchild);
}

//中序遍历 --- 左根右
void BTInOrder(BTNode* root)
{
	//当根结点为NUll，打印NULL，并且返回
	if (root == NULL)
	{
		printf("NULL\t");
		return;
	}

	//递归遍历根结点的左子树
	BTInOrder(root->leftchild);

	//打印根结点的data值
	printf("%c\t", root->data);

	//递归遍历根结点的右子树
	BTInOrder(root->rightchild);
}

//后序遍历 --- 左右根
void BTPostOrder(BTNode* root)
{
	//当根结点为NULL，打印NULL，并且返回
	if (root == NULL)
	{
		printf("NULL\t");
		return;
	}

	//递归遍历根结点的左子树
	BTPostOrder(root->leftchild);

	//递归遍历根结点的右子树
	BTPostOrder(root->rightchild);

	//打印根结点的data值
	printf("%c\t", root->data);
}

//定义链表的结点的结构
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueListNode
{
	QDataType data;//链表的结点所存储的数据
	struct QueueListNode* next; //指向下一个结点的指针
}QueueNode;

//定义队列的结构
typedef struct Queue
{
	QueueNode* phead; //指向头结点的指针
	QueueNode* ptail; //指向尾结点的指针
}Queue;

//队列的初始化
void QueueInit(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	//将两个指针置为空
	pq->phead = pq->ptail = NULL;
}

//入队
void QueuePush(Queue* pq, QDataType x)
{
	//队列的地址不能为空
	assert(pq);
	//为将要插入的结点开辟内存空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;
	//若队列中数据为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	//若队列中数据不为空
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

//判断队列中是否为空
bool QueueEmpty(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	return pq->phead == NULL;
}

//出队列
void QueuePop(Queue* pq)
{
	//队列中是否为空
	assert(!QueueEmpty(pq));
	//若队列中只有一个结点
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//定义一个指针next将头结点的下一结点存储起来
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	//队列的地址不能为空
	assert(pq);
	return pq->phead->data;
}


//层序遍历
void BTLevelOrder(BTNode* root)
{
	//定义一个队列结构
	Queue q;

	//初始化队列 --- 调用函数QueueInit
	QueueInit(&q);

	//将根结点入队列 --- 调用函数QueuePush
	QueuePush(&q, root);

	//判断队列中的数据是否为空QueueEmpty
	while (!QueueEmpty(&q))
	{
		//取队列的队头中的数据 --- 调用函数QueueFront
		BTNode* top = QueueFront(&q);
		//出队头的数据 --- 调用函数QueuePop
		QueuePop(&q);

		//打印之前队头的数据
		printf("%c\t", top->data);

		//队头的数据出出去之后，将top的左右孩子结点入队列
		//在入队列之前，首先判断其左右孩子是否为空
		//若为空，则不需要入队列；若不为空，则需要入队列
		//结点的左右孩子结点的入队顺序不能改变，只能是先左结点，再右结点
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
//二叉树结点的个数
int BinaryTreeSize(BTNode* root)
{
	//如果根结点为空，就返回0
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->leftchild) 
		   + BinaryTreeSize(root->rightchild);
}

//二叉树叶子结点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	//根结点不能为空，若根结点为空了，就不存在左右子树了
	//若根结点为空，返回0
	if (root == NULL)
	{
		return 0;
	}
    
	//判断是否是叶子结点
	//当该结点左右孩子均为NULL时，即可说明该结点为叶子结点
	//若为叶子结点，则返回1
	if (root->leftchild == NULL && root->rightchild == NULL)
	{
		return 1;
	}

	//递归遍历根结点的左子树和右子树
	return BinaryTreeLeafSize(root->leftchild)
		+ BinaryTreeLeafSize(root->rightchild);
}

//二叉树第K层结点的个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//根结点不能为NUll，若为空，就不存在左右子树了
	//若根结点为NULL，则返回0
	if (root == NULL)
	{
		return 0;
	}

	//若k减到1时，表明已经到达了目标层数
	//这时直接返回1
	if (k == 1)
	{
		return 1;
	}

	//递归遍历根结点的左子树和右子树
	//且每次递归，k都要减1，以此达到目标层数
	return BinaryTreeLevelKSize(root->leftchild, k - 1)
	     + BinaryTreeLevelKSize(root->rightchild, k - 1);
}

//二叉树的深度/高度
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

//在二叉树中查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//根结点若为NULL，则返回NULL
	if (root == NULL)
	{
		return NULL;
	}

	//判断根结点的data值是否等于x，若等于，则返回该根结点的地址
	if (root->data == x)
	{
		return root;
	}

	//递归遍历左子树，观察是否能够找到值为x的结点
	//定义一个指针来接收递归结束的返回值
	BTNode* leftFind = BinaryTreeFind(root->leftchild, x);

	//若leftFind不为空，表明在左子树中已经找到了，那就直接返回该指针
	if (leftFind)
	{
		return leftFind;
	}

	//代码运行到这，说明在左子树中没有找到，接着再递归遍历右子树
	//定义一个指针来接收递归结束的返回值
	BTNode* rightFind = BinaryTreeFind(root->rightchild, x);

	//若rightFind不为空，表明在右子树中已经找到了，那就直接返回该指针
	if (rightFind)
	{
		return rightFind;
	}

	//代码运行到这，说明在左子树中没有找到，且在右子树中也没有找到
	//那就说明在二叉树中找不到data值为x的结点，既然找不到，就返回NULL
	return NULL;
}

//二叉树的销毁
void BinaryTreeDestory(BTNode** root)
{
	//采取后序遍历的方法去遍历二叉树
	if (*root == NULL)
	{
		return;
	}

	//递归遍历销毁根结点的左子树
	BinaryTreeDestory(&((*root)->leftchild));

	//递归遍历销毁根结点的右子树
	BinaryTreeDestory(&((*root)->rightchild));

	//销毁根结点
	free(*root);

	//手动置空
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
