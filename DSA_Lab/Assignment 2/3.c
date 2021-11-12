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
	int arr[]={4,9,3,6,1,5,7,2},i;
	insertion(arr,8);
	for(i=0;i<8;i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
}
