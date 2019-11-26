#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int Bellman_Ford(int cost_matrix[20][20] , int no_of_vertex, int E, int edge[10][10])
{
    int i,u,v,k,distance[20],parent[20],source_vertex,flag=1;
    for(i=0;i<no_of_vertex;i++)
        distance[i] = INFINITY, parent[i] = -1 ;
        printf("Enter source: ");
        scanf("%d",&source_vertex);
        distance[source_vertex-1]=0 ;
    for(i=0;i<no_of_vertex-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+cost_matrix[u][v] < distance[v])
                distance[v] = distance[u] +cost_matrix[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+cost_matrix[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<no_of_vertex;i++)
                printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);

        return flag;
}
int main()
{
    int no_of_vertex,edge[10][10],cost_matrix[20][20],i,j,k=0,n,number_of_edge;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&no_of_vertex);
    printf("Enter the number of egdes\n");
    scanf("%d",&number_of_edge);
  FILE *fp;
	fp=fopen("cost1.txt","r");//opening file cost.txt
     if(fp==NULL){
     	puts("Unable to fetch the cost matrix from file");
     	}
fscanf(fp,"%d",&n);//scanning the total number of nodes 
		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		fscanf(fp,"%d",&cost_matrix[i][j]);
		if(cost_matrix[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;	//scanning cost matrix from file 2d.txt
		}
		}
		printf("Cost matrix is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("|");
		for(j=0;j<n;j++)
		{
		printf(" %d ",cost_matrix[i][j]);// printing cost matrix		
		}
		
		printf("|\n");
	}

    if(Bellman_Ford(cost_matrix,no_of_vertex,number_of_edge,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}

