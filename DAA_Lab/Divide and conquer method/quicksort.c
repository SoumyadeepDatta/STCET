/*
Design and Analysis of Algorithm (PCC-CS494)

Lab assignment
Submission date: 20/4/21

1. Implement Quicksort Algorithm
*/

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
