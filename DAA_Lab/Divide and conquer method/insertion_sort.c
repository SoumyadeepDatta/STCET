#include<stdio.h>
void insertion(int a[],int n)
{
	int k,t,i;
	for(k=1;k<n;k++)
	{
		for(i=k;i>0;i--)
		{
			if(a[i]<a[i-1])
			{
				t=a[i];
				a[i]=a[i-1];
				a[i-1]=t;
			}
		}
	}
}
int main()
{
	int i,n;
    printf("Enter range:");
    scanf("%d",&n);
    printf("Enter elements:");
    int arr[n];
    for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion(arr,n);
    printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
