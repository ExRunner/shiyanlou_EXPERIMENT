#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct BTNode
{
	int data;
	struct BTNode *lchild,*rchild;
}BTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree P, BiTree *p)
{
	if(!T)
	{
		*p = P;
		return FALSE;
	}
	else if(key == T->data)
	{
		*p = T;
		return OK;
	}
	else if(key < T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
	}
}

int InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if(!SearchBST(T, key, NULL,&p))
	{
		s = (BiTree) malloc(sizeof(BTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p)
		{
			*T = s;
		}
		else if(key < p->data)
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int Delete(BiTree *T)
{
	BiTree p,s;
	if((*T)->rchild == NULL)
	{
		p = *T;
		*T = (*T)->lchild;
		free(p);
	}
	else if((*T)->lchild == NULL)
	{
		p = *T;
		*T = (*T)->rchild;
		free(p);
	}
	else
	{
		p = *T;
		s = (*T)->lchild;
		while(s->rchild)
		{
			p = s;
			s = s->rchild;
		}
		s->data = (*T)->data;
		if(p != *T)
			p->rchild = s->lchild;
		else
			p->lchild = s->lchild;
		free(s);
	}
	return OK;
}

int DeleteBST(BiTree *T, int key)
{
	if(!T)
	{
		return FALSE;
	}
	else
	{
		if(key == (*T)->data)
			return Delete(T);
		else if(key < (*T->data))
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}
