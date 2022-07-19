//Soumyadeep Datta Roll 26
#include <stdio.h>
#include <stdlib.h>

main()
{
	
    int n,i,j,k=1,v=1,dist[30][30],u,s,a[30][30],cost[30][30];
    printf("Enter  no. of Vertices : ");
    scanf("%d",&n);
    printf("\n");
    
	for(i=1;i<=n;i++)
	{
    	for(j=1;j<=n;j++)
		{
    		printf("Enter the cost from %d to %d : ",i,j);
    		scanf("%d",&cost[i][j]);
		}
	}
	printf("\n\n");
    // printf("Value of K : %d\n\n",(n-1));
    for(i=1;i<=n-1;i++){
   		for(j=1;j<=n;j++){
   		dist[i][j]=999;
	   }
   }
   
   for(i=1;i<=n;i++){
        if(dist[1][i]>cost[v][i]){
        dist[1][i]=cost[v][i];}
    }
    
    for(i=2;i<=n-1;i++){
        for(j=1;j<=n;j++)
        {
          dist[i][j]=dist[1][j];  
        }
    }
    
    for(k=2;k<=n-1;k++){
        for(u=2;u<=n;u++){
        	if(u!=v)
            for(i=2;i<=n;i++){
            	if(cost[i][u]<999 && i!=u)
            	{
                if(dist[k][u]>dist[k-1][i]+cost[i][u]){
                    dist[k][u]=dist[k-1][i]+cost[i][u];
                 
                }
           }
            
        }   

        }
        
    
    }
    printf("\nOutput\n\n");
    printf("\t");
   for(i=1;i<=n-1;i++)
   {
   		printf("\n");
   		for(j=1;j<=n;j++)
		   {		
   				printf("\t%d",dist[i][j]);
			}
	
   }	
   
   
    
}
