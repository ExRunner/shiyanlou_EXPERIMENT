#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList *L)
{
	*L = (LinkList) malloc(sizeof(LNode));
	if (!L)
	{
		exit(OVERFLOW);
	}
	(*L)->next = NULL;
}

void DestoryList(LinkList *L)
{
	LinkList temp;
	while(*L)
	{
		temp = (*L)->next;
		free(*L);
		*L = temp;
	}
}

void ClearList(LinkList L)
{
	LinkList p = L->next;
	L->next = NULL;
	DestoryList(&p);
}

Status isEmpty(LinkList L)
{
	if(L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int GetLength(LinkList L)
{
	int i = 0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p = L->next;
	while(p && j<i)
	{
		j++;
		p = p->next;
	}
	if(!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status compare(Elemtype e1,Elemtype e2)
{
	if(e1 == e2)
		return 0;
	else if(e1 < e2)
		return -1;
	else
		return 1;
}

int FindElem(LinkList L, Elemtype e)
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if(!compare(p-data,e))
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}

Status PreElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList p, q = L->next;
	while(p->next)
	{
		q = p->next;
		if(q->data == cur_e)
		{
			*pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	LinkList p = L->next;
	while(p->next)
	{
		if(p->data == cur_e)
		{
			*next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status InsertElem(LinkList L, int i, ElemType E)
{
	int j = 0;
	LinkList s, p = L;
	while(p && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if(!p || j > i-1)
	{
		return ERROR;
	}
	s = (LinkList) malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status DeleteElem(LinkList L, int i, ElemType *e)
{
	int j = 0;
	LinkList p, q = L;
	while(p->next && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if(!p->next || j > i - 1)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void visit(ElemType e)
{
	printf("%d", e);
}

void TraverList(LinkList L, void (*visit)(ElemType))
{
	LinkList p = L->next;
	while(p)
	{
		visit(p->data);
		p = p->next;
	}
}

int main()
{
	LinkList L;
	InitList(&L);
	ElemType e;
	int i;

	return 0;
}


