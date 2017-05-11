#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int TElemType;
typedef int Status;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree *T)
{
	TElemType e;
	scanf("%d", &e);
	if(e == 0)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree) malloc(sizeof(BiTNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = e;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return OK;
}

void visit(TElemType e)
{
	printf("%d ", e);
}

Status PreOrderTraverse(BiTree T,void (*visit)(TElemType))
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
}

Status InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if(T)
	{
		InOrderTraverse(T->lchild, visit);
		visit(T->data);
		InOrderTraverse(T->rchild, visit);
	}
}

Status PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if(T)
	{
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T->data);
	}
}

void MakeMaxHeap(BiTree *T)
{
	TElemType p;
	if(*T)
	{
		MakeMaxHeap(&(*T)->lchild);
		MakeMaxHeap(&(*T)->rchild);
		if((*T)->lchild && (*T)->lchild->data > (*T)->data)
		{
			p = (*T)->data;
			(*T)->data = (*T)->lchild->data;
			(*T)->lchild->data = p;
		}
		else if((*T)->rchild && (*T)->rchild->data > (*T)->data)
		{
			p = (*T)->data;
			(*T)->data = (*T)->rchild->data;
			(*T)->lchild->data = p;
		}
	}
}

void MakeMinHeap(BiTree *T)
{
	TElemType p;
	if(*T)
	{
		MakeMinHeap(&(*T)->lchild);
		MakeMinHeap(&(*T)->rchild);
		if((*T)->lchild && (*T)->lchild->data < (*T)->data)
		{
			p = (*T)->data;
			(*T)->data = (*T)->lchild->data;
			(*T)->lchild->data = p;
		}
		else if((*T)->rchild && (*T)->rchild->data < (*T)->data)
		{
			p = (*T)->data;
			(*T)->data = (*T)->rchild->data;
			(*T)->lchild->data = p;
		}
	}
}

int main()
{
	BiTree T;
	printf("Create_BINARY_TREE\n");
	CreateBiTree(&T);
	MakeMaxHeap(&T);
	printf("PRE_ORDER:");
	PreOrderTraverse(T, *visit);
	printf("\nIN_ORDER:");
	InOrderTraverse(T, *visit);
	printf("\nPOST_ORDER:");
	PostOrderTraverse(T, *visit);
	printf("\n");
	return 0;
}

