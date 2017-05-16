#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 20

typedef int Status;
typedef int QElemType;
typedef char VexType;

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode, *EdgeLink;

typedef struct VexNode
{
	VexType  data;
	EdgeNode *firstEdge;
}VexNode, AdjList[MAX_NUM];

typedef struct
{
	AdjList adjList;
	int vexNum, edgeNum;
}ALGraph;

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

Status isEmpty(LinkQueue Q)
{
	if(Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
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

Status CreateGraph(ALGraph *G)
{
	int i,j,k;
	EdgeLink e;
	printf("vex and edge\n");
	scanf("%d", &G->vexNum);
	scanf("%d", &G->edgeNum);
	getchar();
	printf("");
	for(i = 0; i < G->vexNum; i++)
	{
		scanf("%c", &G->adjList[i].data);
		if(G->adjList[i].data == '\n')
		{
			i--;
			continue;
		}
		G->adjList[i].firstEdge = NULL;
	}
	print("")
}

