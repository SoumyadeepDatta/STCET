#include<stdio.h>
void bubble(int a[],int n)
{
	int k,p,t,flag=0;
	for(k=1;k<=n-1;k++)
	{
		for(p=0;p<n-k;p++)
		{
			if(a[p]>a[p+1])
			{
				t=a[p];
				a[p]=a[p+1];
				a[p+1]=t;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
int main()
{
	int arr[]={4,9,3,6,1,5,7,2},i;
	bubble(arr,8);
	for(i=0;i<8;i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
}
