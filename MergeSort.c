#include<stdio.h>
#include<stdlib.h>

void Merge(int *source, int *target, int i, int m, int n)
{
	int j, k;
	for(j = m + 1, k = 1; i <= m && j <= n; k++)
	{
		if(source[i] <= source[j])
		{
			target


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
	//ShellSort(array, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
