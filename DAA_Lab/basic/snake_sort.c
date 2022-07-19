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
    for (size_t i = 0; i < 4; i++)//0 to 3; 0->even ; 1->odd ....
    {
        if (i%2==0)
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
        else
        {
            for (size_t j = 0; j < 4-1; j++)
        {
            for (size_t t = 0; t < 4-j-1; t++)
            {
                if(arr[i][t]<arr[i][t+1])
                {
                    swap(&arr[i][t],&arr[i][t+1]);
                }
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
void phase()
{
    for (size_t i = 1; i <= 4+1; i++)
    {
        printf("\nPhase %d\n",i);
        if (i%2==0)
        {
            sortCol();
        }
        else
        {
            sort();
        }
        printArray();
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
    printf("\nInitial state\n");
    printArray();
    phase();
    return 0;
}
