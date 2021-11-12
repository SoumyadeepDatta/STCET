#include<stdio.h>
int binarySearch(int a[],int x,int left,int right)
{
	int mid;
	while(right>=left)
	{
		mid=(right+left)/2;
		if(x==a[mid])
		{
			return mid;
		}
		else
		{
			if(x<a[mid])
			return binarySearch(a,x,left,mid-1);
			if(x>a[mid])
			return binarySearch(a,x,mid+1,right);
		}
	}
	return -1;
}
int main()
{
	int arr[]={5,6,7,9,14,17,21};
	if(binarySearch(arr,9,0,6)==-1)
	printf("Item not found");
	else
	printf("\nItem found at %d th position",binarySearch(arr,9,0,6)+1);
	return 0;
}
