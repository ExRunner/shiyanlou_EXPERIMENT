#include<stdio.h>
#include<stdlib.h>

int Partition(int *array, int low, int high)
{
	int dvipoint = array[low];
	while(low < high)
	{
		while(low < high && array[high] >= dvipoint)
		{
			high--;
		}
		array[low] = array[high];
		while(low < high && array[low] <= dvipoint)
		{
			low++;
		}
		array[high] = array[low];
	}
	array[low] = dvipoint;
	return low;
}

void QuickSort(int *array, int low, int high)
{
	if(low < high)
	{
		int dviposition = Partition(array, low, high);
		QuickSort(array, low, dviposition - 1);
		QuickSort(array, dviposition + 1, high);
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
	QuickSort(array, 0, n-1);
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
