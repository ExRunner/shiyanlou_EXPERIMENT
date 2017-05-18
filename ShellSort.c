#include<stdio.h>
#include<stdlib.h>

int ShellSort(int *array, int n)
{
	int k = n / 2;
	while(k > 0)
	{
		int i, j, p;
		for(i = k; i < n; i++)
		{
			if(array[i] < array[i - k])
			{
				p = array[i];
				for(j = i - k; j >= 0 && p < array[j]; j -= k)
				{
					array[j + k] = array[j];
				}
				array[j + k] = p;
			}
		}
		k = k / 2;
	}
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
	ShellSort(array, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

