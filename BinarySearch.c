#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *array, int key, int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == array[mid])
		{
			return mid;
		}
		else if (key < array[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return 0;
}

int BinarySearchRecursion(int *array, int key, int low, int high)
{
	int mid = (low + high) / 2;
	if(low <= high)
	{
		if(key == array[mid])
		{
			return mid;
		}
		else if(key < array[mid])
		{
			return BinarySearchRecursion(array, key, low, mid-1);
		}
		else
		{
			return BinarySearchRecursion(array, key, mid+1, high);
		}
	}
	return 0;
}

int main()
{
	int n, i, key, position;
	int *array;
	printf("Enter Amount:");
	scanf("%d", &n);
	array = (int*) malloc(sizeof(int) * n);
	printf("Enter Numbers:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("Enter Key");
	scanf("%d", &key);
	if (position = BinarySearchRecursion(array, key, 0, n - 1)) 
	{
		printf("%d in %d\n", key, position);
	}
	else
	{
		printf("no %d\n", key);    
	}
}
