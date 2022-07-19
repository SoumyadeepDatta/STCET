#include<stdio.h>
void swap(int *x,int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int partition(int a[],int start,int end)
{
    int i = start, j = end - 1, pivot = end;
    while (i<=j)
    {
        while (a[i]<a[pivot])
        {
            i++;
        }
        while (j>=start && a[j]>=a[pivot])
        {
            j--;
        }
        if(i<=j)
        {
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i],&a[pivot]);
    return i;
}
void quickSort(int a[],int l,int u)
{
	int k;
	if(u>l)
	{
		k=partition(a,l,u);
		quickSort(a,l,k-1);
		quickSort(a,k+1,u);
		
	}
}
int main()
{
	
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements:");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("\nSorted Array:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
