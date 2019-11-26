#include<stdio.h>
int i, j, k,no_of_vertex;
void floydWarshall (int distance[10][10],int n)
{
 for (k = 1; k <= no_of_vertex; k++)
  for (i = 1; i <= no_of_vertex; i++)
   for (j =1; j <=no_of_vertex; j++){
   
    if (distance[i][k] + distance[k][j] < distance[i][j]){
	
     distance[i][j] = distance[i][k] + distance[k][j];
}
}
}
int main()
{
  int i,j,cost_matrix[10][10],starting_node,node_to_visit;
 A: printf("enter no of vertices :");
  scanf("%d",&no_of_vertex);
  if(no_of_vertex<=0){
  	printf("Invalid Vertex:\n");
  	goto A;
  }
  int n=no_of_vertex;
  FILE *fp;
	fp=fopen("cost2.txt","r");//opening file cost.txt
     if(fp==NULL){
     	puts("Unable to fetch the cost matrix from file");
     	}
//scanning the total number of nodes 
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		fscanf(fp,"%d",&cost_matrix[i][j]);	//scanning cost matrix from file 2d.txt
		}
		}
		printf("Cost matrix is:\n\n");
	for(i=1;i<=n;i++)
	{
		printf("|");
		for(j=1;j<=n;j++)
		{
		printf(" %d ",cost_matrix[i][j]);// printing cost matrix		
		}
		
		printf("|\n");
	}
 floydWarshall(cost_matrix,n);
 printf (" \n\n shortest distances between every pair of vertices \n");
 for (int i = 1; i <= no_of_vertex; i++)
 {
 	printf("|");
  for (int j = 1; j <=no_of_vertex; j++)

   printf ("  %d  ", cost_matrix[i][j]);
  printf("|\n");
  
 }
 W:printf("\nEnter Starting node:");
	scanf("%d",&starting_node);
	if(starting_node<=0 || starting_node>no_of_vertex){
	puts("\nInvalid starting node:");
	goto W;
	}	
 
 
 	Q:printf("\n\nEnter node to visit: ");
	scanf("%d",&node_to_visit);
	if(node_to_visit<= 0 || node_to_visit>no_of_vertex){
		puts("\nInvalid destination node:");
		goto Q;
	}
	
printf("\nShortest distance between node%d and node%d is: %d",starting_node,node_to_visit,cost_matrix[starting_node][node_to_visit]);
 return 0;
}
