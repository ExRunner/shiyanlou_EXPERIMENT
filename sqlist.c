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
	else
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
		if(!compare(L.elem[i],e))
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

Status NextElem(const SqList L,ElemType cur_e,ElemType *next_e)
{
	int i;
	for(i = 0;i < L.length;i++)
	{
		if(cur_e == L.elem[i])
		{
			if(i != 0)
				*next_e = L.elem[i+1];
			else
				return ERROR;
		}
	}
	if(i >= L.length)
		return ERROR;
}

Status InsertElem(SqList *L, int i, ElemType e)
{
	ElemType *new;
	if(i < 1 || i > L->length + 1)
		return ERROR;
	if(L->length >= L->size)
	{
		new = (ElemType*) realloc(L->elem,(L->size + INC_SIZE) * sizeof(ElemType));
		if(!new)
			return ERROR;
		L->elem = new;
		L->size += INC_SIZE;
	}
	ElemType *p = &L->elem[i-1];
	ElemType *q = &L->elem[L->length - 1];
	for(;q >= p;q--)
		*(q + 1) = *q;
	*p = e;
	++L->length;
	return OK;
}

Status DeleteElem(SqList *L, int i, ElemType *e)
{
	if(i < 1 || i > L->length)
		return ERROR;
	ElemType *p = &L->elem[i - 1];
	*e = *p;
	for(; p < &L->elem[L->length];p++)
		*(p) = *(p + 1);
	--L->length;
	return OK;
}

Status visit(const SqList L, int i)
{
	printf("%d", L.elem[i]);
}

Status TraverseList(const SqList L)
{
	int i;
	for(i = 0;i < L.length; i++)
		visit(L,i);
	return OK;
}

Status DestoryList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;
}

int main()
{
	SqList L;
	if(InitList(&L))
	{
		ElemType e;
		printf("INIT_SECCESS\n");
		int i;
		for(i = 0; i < 10; i++)
			InsertElem(&L, i + 1, i);
		printf("LENGTH = %d\n", getLength(L));
		if(GetElem(L, 1, &e))
			printf("FIRST = %d\n", e);
		else
			printf("FIRST ERROR\n");
		printf("Find 5 in %d\n", FineElem(L, 5));
		PreElem(L, 6, &e);
		printf("%d\n",e);
		NextElem(L, 6, &e);
		printf("%d\n",e);
		DeleteElem(&L, 1, &e);
		printf("DEL = %d\n", e);
		TraverseList(L);
		return 0;
	}
}
