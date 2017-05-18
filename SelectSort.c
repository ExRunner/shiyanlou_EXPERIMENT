#include<stdio.h>
#include<stdlib.h>

void SelectSort(int *array, int n)
{
	int i, j, k, p;
	for(i = 0; i < n; i++)
	{
		k = i;
		for(j = i; j < n; j++)
		{
			if(array[j] < array[k])
			{
				k = j;
			}
		}
		if(k != i)
		{
			p = array[i];
			array[i] = array[k];
			array[k] = p;
		}
	}
}

int main(void)
{
	int i, n;
	int *array;
	printf("Enter Amount:");
	scanf("%d", &n);
	array = (int*) malloc(sizeof(int) * n);
	printf("Enter Numbers:");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	SelectSort(array, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
