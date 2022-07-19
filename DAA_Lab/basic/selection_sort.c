#include<stdio.h>
void selection(int a[],int n)
{
	int t,min,k,i,pos,flag;
	for(k=0;k<n;k++)
	{
		min=a[k];
		flag=0;
		for(i=k+1;i<n;i++)
		{
			if(a[i]<min)
			{
				min=a[i];
				pos=i;
				flag=1;
			}			
		}
		if(flag==1)
		{
			t=a[pos];
			a[pos]=a[k];
			a[k]=t;
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
	selection(arr,n);
    printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
