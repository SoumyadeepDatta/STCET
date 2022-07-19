#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 50
int board[M];
int cnt=0;
//Compiler version gcc  6.3.0
int place(int k,int i)
{
  int j;
  for (j=1;j<=k-1;j++)
  {
    if(board[j]==i || (abs(board[j]-i)==abs(j-k)))
    return 0;     
  }
  return 1;
}
void print(int n)
{
  int i,j;
  
  cnt++;
  fflush(stdin);
  printf("\nSolution %d:\n",cnt);
  for(i=1;i<=n;i++)
  {
    printf("\n\n");
    for(j=1;j<=n;j++)
    {
      if(board[i]==j)
      printf("Q\t\t\t");
      else
      printf("X\t\t\t");
    }
  }
  
  //printf("\n");
}
void nqueen(int k,int n)
{
  int i,l;
  for(i=1;i<=n;i++)
  {
    if(place(k,i)==1)
    {
      board[k]=i;
      if(k==n)
      {
        if(cnt>=10)
        {
          break;
        }
        printf("\n");
        fflush(stdin);
        print(n);
        /*printf("\n");
        for(l=1;l<=n;l++)
        {
          printf("%d\t",board[l]);
        }*/
      }
      else
      {
        nqueen(k+1,n);
      }
    }
  }
}
int main()
{
  printf("Enter no. of queens :");
  int n;
  scanf("%d",&n);
  //board[n+1][n+1];
  fflush(stdin);
  nqueen(1,n);
  fflush(stdin);
  return 0;
}
