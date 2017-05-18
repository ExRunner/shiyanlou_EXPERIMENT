#include<stdio.h>
#include<stdlib.h>

void InsertSort(int *array, int n)
{
	int i, j, p;
	for(i = 1; i < n; i++)
	{
		if(array[i] < array[i - 1])
		{
			p = array[i];
			array[i] = array[i - 1];
		       for(j = i - 2; j >= 0 && p < array[j] ; j--)
		       {
			       array[j + 1] = array[j];
		       }
		       array[j + 1] = p;
		}
	}
}

int main()
{
	int i, n;
	int *array;
	printf("Enter Amount:");
	scanf("%d", &n);
	array = (int*) malloc(sizeof(int) * (n));
	printf("Enter Numbers:");
	for( i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	InsertSort(array, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

