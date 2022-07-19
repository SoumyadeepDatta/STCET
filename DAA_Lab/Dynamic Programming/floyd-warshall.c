//Soumyadeep Datta Roll 26
#include<stdio.h>
void shortest_path(int n ,int arr[n+1][n+1])
{
    int i,j,k,r,c;
    for ( k = 1; k <= n; k++)
    {
        for ( i = 1; i <= n; i++)
        {
            for ( j = 1; j <= n; j++)
            {
                if ((arr[i][k]+arr[k][j])<arr[i][j])
                {
                    if(arr[i][k] != 999 && arr[k][j] != 999)
                    {arr[i][j] = arr[i][k]+arr[k][j];}
                }
                
            }
        }
        printf("\n********A%d********\n",k);
        for ( r = 1; r <= n; r++)
        {
            for ( c = 1; c <= n; c++)
            {
                printf("%d\t",arr[r][c]);
            }
            printf("\n");
        }
    }
    
}
int main()
{
    int v,i,j;
    printf("No. of vertices:");
    scanf("%d",&v);
    int mat[v+1][v+1];
    printf("\nEnter value of edges:\n");
    for ( i = 1; i <= v; i++)
    {
        for ( j = 1; j <= v; j++)
        {
            printf("\nFor vertice %d to %d :",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n********A0********\n");
    for ( i = 1; i <= v; i++)
    {
        for ( j = 1; j <= v; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    shortest_path(v,mat);
    return 0;
}
