#include<stdio.h>
#include<stdlib.h>

#define OK 1;
#define ERROR 0;
#define TRUE 1;
#define FALSE 0;
#define EXIST 1;

typedef struct HashT
{
	int *data;
	int count;
	int size;
}HashT,*HashTable;

int InitHash(HashTable *H, int n)
{
	*H = (HashTable) malloc(sizeof(HashT));
	if(!H)
		return FALSE;
	(*H)->data = (int*) malloc (sizeof(int) * n);
	(*H)->size = n;
	(*H)->count = 0;
	if(!(*H)->data)
	{
		return FALSE;
	}
	return TRUE;
}

int Hash(int key, int prime, int c)
{
	if(c == 0)
		return (key % prime);
	else if(c % 2 == 1)
		return ((key + ((c+1)/2)*((c+1)/2)) % prime);
	else
		return ((key - ((c+1)/2)*((c+1)/2)) % prime);
}

int GetMaxPrime(int n)
{
	int i;
	while(1)
	{
		n--;
		if(n == 2 || n == 1)
			return FALSE;
		for(i = 2; i < n; i++)
		{
			if(n % i == 0)
				break;
		if(i == n-1)
			return n;
		}
	}
}

int SearchHash(HashTable H, int key, int prime, int *p)
{
	int c = 0;
	*p = Hash(key, prime, 0);
	while(H->data[*p] != NULL && H->data[*p] != key)
		*p = Hash(*p, prime, ++c);
	if(H->data[*p] == key)
		return TRUE;
	else
		return FALSE;
}

int main(void)
{
	int prime,n;
	printf("Enter N:");
	scanf("%d", &n);
	prime = GetMaxPrime(n);
	printf("Max Prime is %d\n", prime);
	return 0;
}

