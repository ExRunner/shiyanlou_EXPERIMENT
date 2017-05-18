#include<stdio.h>
#include<stdlib.h>

int BubbleSort(int *array, int n)
{
	int i, j, p;
	for(i = n - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(array[j] > array[j + 1])
			{
				p = array[j];
				array[j] = array[j + 1];
				array[j + 1] = p;
			}
		}
	}
	return 0;
}

int main()
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
	BubbleSort(array, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
