#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
	if(!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
}

Status isEmpty(LinkQueue Q)
{
	if(Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}

Status GetLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p = Q.front;
	while(Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if(Q.front == Q.rear)
	{
		return ERROR;
	}
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
	if(!p)
	{
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

void visit(QElemType e)
{
	printf("%d", e);
}

Status TraverseQueue(LinkQueue Q, void (*visit)(QElemType))
{
	QueuePtr p = Q.front->next;
	while(p)
	{
		visit(p->data);
		p = p->next;
	}
	return OK;
}

int main()
{
	LinkQueue Q;
	if(InitQueue(&Q))
	{
		QElemType e;
		int i;
		
		printf("INIT_SUCCESS\n");

		if(isEmpty(Q))
		{
			printf("It's empty\n");
		}
		for(i = 0; i< 10; i++)
		{
			EnQueue(&Q, i);
		}
		GetHead(Q, &e);
		printf("HEAD = %d\n", e);
		printf("LENGTH = %d\n", GetLength(Q));
		DeQueue(&Q, &e);
		printf("DEL ELEMENT %d\n", e);
		TraverseQueue(Q, *visit);
		if(DestroyQueue(&Q))
		{
			printf("\nDESTROY_SUCCESS\n");
		}
	}
	return 0;
}
