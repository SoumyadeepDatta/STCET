#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
	int h,i,j,b[high-low+1],k;
	h=low;i=0;j=mid+1;
	while(h<=mid && j<=high)
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	
	while(h<=mid)
	{
		b[i]=a[h];
		h=h+1;
		i=i+1;
	}	
	while(j<=high)
	{
			b[i]=a[j];
			j=j+1;
			i=i+1;
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k-low];
	}
}
void mergeSort(int arr[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,h);
		merge(arr,l,m,h);
	}
}
int main()
{
	int array[]={4,9,3,6,1,5,7,2},i;
	mergeSort(array,0,7);
	for(i=0;i<8;i++)
	{
		printf("%d  ",array[i]);
	}
	return 0;
}
