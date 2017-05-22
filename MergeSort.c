#include<stdio.h>
#include<stdlib.h>

void Merge(int *source, int *target, int i, int m, int n)
{
	int j, k;
	for(j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if(source[i] <= source[j])
		{
			target[k] = source[i++];
		}
		else
		{
			target[k] = source[j++];
		}
	}

	while(i <= m)
	{
		target[k++] = source[i++];
	}
	while(j <= n)
	{
		target[k++] = source[j++];
	}
}


void MergeSort(int *source, int *target, int s, int t)
{
	int m, *temp;
	if(s == t)
	{
		target[s] = source[t];
	}
	else
	{
		temp = (int*) malloc(sizeof(int) * (t - s + 1));
		m = (s + t) / 2;
		MergeSort(source, temp, s, m);
		MergeSort(source, temp, m + 1, t);
		Merge(temp, target, s, m, t);
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
	MergeSort(array, array, 0, n - 1);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
