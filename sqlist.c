#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INC_SIZE 5

typedef int Status;
typedef int ElemType;


typedef struct
{
	ElemType *elem;
	int length;
	int size;
}SqList;

Status InitList(SqList *L)
{
	L->elem=(ElemType *)malloc(INIT_SIZE *sizeof(ElemType));
	if (!L->elem)
	{
		return ERROR;
	}
	L->length=0;
	L->size=INIT_SIZE;
	return OK;
}

Status ClearList(SqList *L)
{
	L->length=0;
	return OK;
}

Status isEmpty(const SqList L)
{
	if(L.length==0)
		return TRUE;
	elsw
		return FALSE;
}

Status getLength(const SqList L)
{
	return L.length;
}

Status GetElem(const SqList L,int i,ElemType *e)
{
	if(i<1||i>L.length)
		return ERROR;
	*e=L.elem[i-1];
	return OK;
}

Status compare (ElemType e1,ElemType e2)
{
	if(e1==e2)
		return 0;
	else if(e1<e2)
		return -1;
	else
		return 1;
}

Status FineElem(const SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(!compare(L.elem[i]),e)
		{
			return i+1;
		}
	}
	if(i>L.length)
	{
		return ERROR;
	}
}

Status PreElem(const SqList L,ElemType cur_e,ElemType *pre_e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(cur_e==L.elem[i])
		{
			if(i!=0)
				*pre_e=L.elem[i-1];
			else
				return ERROR;
		}
	}
	if(i>=L.length)
		return ERROR;
}


