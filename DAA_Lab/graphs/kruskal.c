//Soumyadeep Datta Roll 26
#include<stdio.h>
#include<limits.h>
#include<conio.h>
#include<stdlib.h>
#define M 20
int graph[M][M];
int parent[M];
int min_cost=0;

int find(int x)
{
    while(parent[x])
    {
        x=parent[x];
    }
    return x;
}

int not_cycle(int x1,int x2)
{
    if(x1 != x2)
    {
        parent[x2]=x1;
        return 1;
    }
    return 0;
}

void kruskal(int n,int g[M][M])
{
    int t=1,i,j;
    int u,v;
    int a,b;
    int min;
    
    
    while(t<n)
    {
        min=INT_MAX;
        for(i = 1; i <= n; i++)
        {
            for( j = 1; j <= n; j++)
            {
                if(graph[i][j]<min)
                {
                    min=graph[i][j];
                    u=i;
                    a=i;
                    v=j;
                    b=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(not_cycle(u,v))
        {
            printf("\n%d. Edge (%d,%d) = %d",t++,a,b,min);
            min_cost = min_cost + min;        
        }
        graph[a][b]=INT_MAX;
        graph[b][a]=INT_MAX;
        
    }
    printf("\n\n***************************************************\n");
    printf("\nMinimum Cost :%d\n",min_cost);
    printf("\n\n***************************************************\n");
}

int main()
{
    int n,i,j;
    printf("\n****************Kruskal's Algorithm******************\n");
    printf("\nEnter no. of vertices (Undirected Graph):");
    scanf("%d",&n);
    printf("\n\nNOTE : Enter 0 if edge doesn't exist");
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            if (i==j)
            {
                graph[i][j]=INT_MAX;
            }
            else if (i>j)
            {
                graph[i][j]=graph[j][i];
            }
            else
            {
                printf("\nFor edge %d to %d :",i,j);
                scanf("%d",&graph[i][j]);
                if(graph[i][j]==0)
                {
                    graph[i][j]=INT_MAX;
                }
            }
            
        }
        
    }
    printf("\n*********************Your graph********************\n");
    printf("\n");
    printf("  \t");
    for(i = 1; i <= n; i++)
    {
        printf("V%d\t",i);
    }
    printf("\n\n");
    for (i = 1; i <= n; i++)
    {
        printf("V%d\t",i);
        for ( j = 1; j <= n; j++)
        {
            
            if(graph[i][j]==INT_MAX)
                printf("-\t");
            else
                printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n***************************************************\n");
    kruskal(n,graph);
    return 0;
}
