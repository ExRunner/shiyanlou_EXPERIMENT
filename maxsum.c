#include<stdio.h>

using namespace std;

int main()
{
    int a[20];
    int maxsum=0,n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
	int sum=0;
	for(int j=i;j<n;j++)
	{
	sum=sum+a[j];
	if(sum>maxsum){
	    maxsum=sum;
		printf("%d\n",maxsum);
	}
	}
    }
    printf("%d",maxsum);
}
