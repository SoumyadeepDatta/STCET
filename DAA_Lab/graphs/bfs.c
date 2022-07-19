#include<stdio.h>
#include<stdlib.h>
#define M 50

int queue[M] , visit[M] ;
int visit_index = 0;
int front = -1 , rear = -1;
void visited(int v)
{
    visit[visit_index] = v;
    visit_index++;
}
int is_visited(int vtx)
{
    int i;
    for (i=0;i<visit_index;i++)
    {
        if(visit[i]==vtx)
        {
            return 1;
        }
    }
    return -1;
}
void insert(int num)
{
    
    
    if (rear + 1 == M)
    {
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0 ;
        }
        queue[++rear] = num;
    }
}
int delete()
{
    int x;
    if (!(front == -1 || front > rear))
    {
        x = queue [front];
        
        
        front++;
        
        return x;
    }
    
}
void bfs(int n)
{
    int matrix[n+1][n+1];
    
    // printf("\nOK\n");
    int i ,j , ele, col;
    for (i = 1; i <=n ; i++)
    {
        
        for ( j = 1; j <= n; j++)
        {
            printf("\nFor vertex %d-%d :",i,j);
            scanf("%d",&matrix[i][j]);
        }
        
    }
    insert(1);
    visited(1);
    printf("\n");
    while(front <= rear)
    {
        ele = delete();
        printf("%d\t",ele);
        for (col = 1; col <= n; col++)
        {
            if (matrix[ele][col] == 1)
            {
                if (is_visited(col) == -1)
                {
                    insert(col);
                    visited(col);
                }
                
            }
            
        }
        
    }
        
    
}

int main()
{
    int n;
    printf("No. of vertex :");
    scanf("%d",&n);
    bfs(n);
    return 0;
}
