/*
Design and Analysis of Algorithm (PCC-CS494)

Lab assignment
Submission date: 13/4/21

1. Implement Binary Search
2. Implement Merge Sort
*/

#include<stdio.h>
int merge(int a[], int u, int l, int m)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = u - m;
    int L[n1] , R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[m + 1 + j];
    }
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
        
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int u)
{
    int m;
    if (l < u)
    {
        m = (u+l) / 2;
        mergesort( a, l, m);
        mergesort( a, m+1, u);
        merge(a, u, l, m);
    }
}

int BinarySearch(int a[], int l, int u, int v)
{
    int mid;
    
    
    if (l < u)
    {
        mid = (l + u) / 2;
        if (a[mid] == v)
        {
            return mid;
        }
        else
        {
            if (a[mid] > v)
            {
                return BinarySearch(a, l, mid, v);
            }
            else
            {
                return BinarySearch(a, mid + 1, u, v);
            }
            
        }
        
    }
    else if (l == u && a[l] == v)
    {
        return l;
    }
    else
    {
        return -1;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int t, n, v;
    printf( "Enter array size :" );
    scanf( "%d" , &n);
    int a[n];
    printf( "\nEnter elements :" );
    for ( t = 0; t < n; t++)
    {
        scanf( "%d" , &a[t]);
    }
    mergesort(a, 0, n-1);
    printf( "\nAfter merge sort :" );
    for ( t = 0; t < n; t++)
    {
        printf( "%d\t" , a[t]);
    }
    printf( "\nNo. you want to search :" );
    scanf( "%d" , &v);
    if ( BinarySearch(a, 0, n-1, v)==-1 )
    {
        printf( "\nElement not found " );
    }
    else
    {
        printf( "\nElement found at : %d position" , BinarySearch(a, 0, n-1, v) + 1);
    }
    
    return 0;
}
