#include<stdio.h>
int arr[4][4];
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray()
{
    printf("\n");
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void sort()
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4-1; j++)
        {
            for (size_t t = 0; t < 4-j-1; t++)
            {
                if(arr[i][t]>arr[i][t+1])
                {
                    swap(&arr[i][t],&arr[i][t+1]);
                }
            }
            
        }
    }
}
void sortCol()
{
    for (size_t j = 0; j < 4; j++)
    {
        for (size_t i = 0; i < 4-1; i++)
        {
            for (size_t t = 0; t < 4-i-1; t++)
            {
                if(arr[t][j]>arr[t+1][j])
                {
                    swap(&arr[t][j],&arr[t+1][j]);
                }
            }
            
        }
    }
}
int main()
{
    
    printf("Enter elements in a 4X4 matrix");
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    printArray(arr);
    sort();
    printArray(arr);
    sortCol();
    printArray(arr);
    return 0;
}
