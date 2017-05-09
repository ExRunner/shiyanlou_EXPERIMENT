#include<stdio.h>
#include<stdlib.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INC_SIZE 5

typedef int SElemtype;
typedef int Status;

typedef struct 
{
	SElemtype *base;
	SElemtype *top;
	int size;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base = (SElemtype*) malloc (INIT_SIZE * sizeof(SElemtype));
	if (!S->base)
	{
		exit(OVERFLOW);
	}
	S->top = S->base;
	S->size = INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->size = 0;
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

Status isEmpty(SqStack S)
{
	if (S.top == S.base)
		return TURE;
	else
		return FALSE;
}

int GetLength(SqStack S)
{
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemtype *e)
{
	if(S.top > S.base)
	{
		*e = *(--S.top);
		return OK;
	}
	else
	{
		return ERROR;
	}
}


Status Push(SqStack *S, SElemtype e)
{
	if((S->top - S->base) / sizeof(SElemtype) >= S->size)
	{
		S->base = (SElemtype*) realloc(S->base, (S->size + INC_SIZE) * sizeof(SElemtype));
		if(!S->base)
			exit(OVERFLOW);
		S->top = S->base + S->size;
		S->size += INC_SIZE;
	}
	*S->top = e;
	S->top++;
	return OK;
}

Status Pop(SqStack *S, SElemtype *e)
{
	if(S->top = S->base)
	{
		return ERROR;
	}
	S->top--;
	*e = *S->top;
	return OK;
}

void visit(SElemtype e)
{
	printf("%d", e);
}

Status TraverseStack(SqStack S, void (*visit)(SElemtype))
{
	while(S.top > S.base)
	{
		visit(*S.base);
		S.base++;
	}
	return OK;
}

int main()
{
	SqStack S;
	if(InitStack(&S))
	{
		SElemtype e;
		int i;
		printf("INIT_SUCCESS\n");

		if(isEmpty(S))
		{
			printf("It's empty\n");
		}
		for(i = 0;i < 10;i++)
		{
			Push(&S, i);
		}

		GetTop(S, &e);
		printf("first element = %d\n", e);
		printf("LENGTH = %d\n", GetLength(S));
		Pop(&S, &e);
		printf("POP %d\n", e);
		TraverseStack(S, *visit);

		if(DestroyStack(&S))
			printf("\ndestroy_success\n");
		printf("%lu", sizeof(SElemtype));
	}
}
