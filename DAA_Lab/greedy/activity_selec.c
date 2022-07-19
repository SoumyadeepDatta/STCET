#include<stdio.h>
struct activity
{
    int index;
    int started;
    int finished;
};
void swap(int *x,int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int partition(struct activity array[50],int start,int end)
{
    // struct activity temp;
    int i = start, j = end - 1, pivot = end;
    while (i<=j)
    {
        while (array[i].finished<array[pivot].finished)
        {
            i++;
        }
        while (j>=start && array[j].finished>=array[pivot].finished)
        {
            j--;
        }
        if(i<=j)
        {
            swap(&array[i].index,&array[j].index);
            swap(&array[i].started,&array[j].started);
            swap(&array[i].finished,&array[j].finished);
            // temp = array[i];
            // array[i] = array[j];
            // array[j] = temp;
            // swap(&a[i],&a[j]);
        }
    }
    swap(&array[i].index,&array[pivot].index);
    swap(&array[i].started,&array[pivot].started);
    swap(&array[i].finished,&array[pivot].finished);
    // temp = array[i];
    // array[i] = array[pivot];
    // array[pivot] = temp;
    // swap(&a[i],&a[pivot]);
    return i;
}
void quickSort(struct activity array[50],int l,int u)
{
	int k;
	if(u>l)
	{
		k=partition(array,l,u);
		quickSort(array,l,k-1);
		quickSort(array,k+1,u);
		
	}
}
void activity_selection(int n)
{
    struct activity array[n];
    int i = 0;
    while (i<n)
    {
        array[i].index = i+1;
        printf("\nFor activity %d:",i+1);
        printf("\nStart time:");
        scanf("%d",&array[i].started);
        printf("Finish time:");
        scanf("%d",&array[i].finished);
        i++;
    }
    quickSort(array,0,n-1);
    
    // int sol={array[0].index};
    printf("\n%d",array[0].index);
    i = 0;
    int m;
    for(m=1;m<n;m++)
    {
        if(array[m].started>=array[i].finished)
        {
            printf("\t%d",array[m].index);
            i=m;
        }
    }
}
int main()
{
    int n;
    printf("No. of activities:");
    scanf("%d",&n);
    activity_selection(n);
    return 0;
}
