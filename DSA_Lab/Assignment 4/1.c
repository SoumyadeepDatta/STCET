#include<stdio.h>

int partition(int a[],int lower,int upper)
{
	int p=lower,t,s,q=upper+1,i=a[lower];
	while(q>=p)
	{
		while(a[++p]<i);
		while(a[--q]>i);
		if(q>p)
		{
			t=a[p];
			a[p]=a[q];
			a[q]=t;
		}
	}
	s=a[lower];
	a[lower]=a[q];
	a[q]=s;
	return q;
}
void quickSort(int arr[],int l,int u)
{
	int k;
	if(u>l)
	{
		k=partition(arr,l,u);
		quickSort(arr,l,k-1);
		quickSort(arr,k+1,u);
		
	}
}
int main()
{
	int array[]={4,9,3,6,1,5,7,2},i;
	quickSort(array,0,7);
	for(i=0;i<8;i++)
	{
		printf("%d  ",array[i]);
	}
	return 0;
}
