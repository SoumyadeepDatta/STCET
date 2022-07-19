#include <stdio.h>
#define M 20 //Maximum size 
int mat[M][M];
int visit[M];
int stack[M];
int dfs[M];
int cnt=0;
int top=-1;
int ind=1,n;
//Compiler version gcc  6.3.0
void push(int value)
{
  if(top<M)
  {stack[++top]=value;}
}
int pop()
{
  if(top>-1)
  {return stack[top--];}
}
int is_visited(int x)
{
  int i;
  for(i=1;i<=ind;i++)
  {
    if(visit[i]==x) 
    {
      return 1;
    }
  }
  return 0;
}
void visited(int x)
{
  visit[ind]=x;
  ind++;
}
int main()
{
  printf("For UNDIRECTED GRAPH\n");
  printf("No. of vertices :");
  int i,j,vtx,flag,idle;
  scanf("%d",&n);
  printf("Enter 1(if edge exists)\nelse enter 0:");        
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(i==j)
      {
        mat[i][j]=0;
      }
      else{
        if(i<j)
      {printf("\nV%d to V%d:",i,j);
      scanf("%d",&mat[i][j]);
      mat[j][i]=mat[i][j];}
      }
    }
  }
  printf("\n");
  push(1);
  visited(1);
  dfs[++cnt]=1;
  //printf("%d",1);
  while(top!=-1)
  {
    flag=0;
    for(i=1;i<=n;i++)
    {
      if(mat[stack[top]][i]==1)
      {
        if(is_visited(i)==0)
        {
          push(i);
          dfs[++cnt]=i;
          visited(i);
          flag=1;
          break;
        }
      }
    }
    if(flag==0)
    {
      idle=pop();
    }
  }
  printf("\nDFS\n");
  for(j=1;j<=cnt;j++)
  {
    printf("V%d\t\t",dfs[j]);
  }
  return 0;
}
