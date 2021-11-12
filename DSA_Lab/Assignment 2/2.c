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
	int arr[]={4,9,3,6,1,5,7,2},i;
	selection(arr,8);
	for(i=0;i<8;i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
}
