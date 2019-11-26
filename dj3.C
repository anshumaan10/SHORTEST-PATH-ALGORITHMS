#include<stdio.h>
#include<stdlib.h>

int main(){
int cost_matrix[10][10],no_of_nodes,i,j,distance_matrix[10],path_matrix[10][10],node_to_visit,number_of_paths,r,c,min,ind=1,starting_node;
	FILE *fp;
	fp=fopen("cost.txt","r");//opening file cost.txt
     if(fp==NULL){
     	puts("Unable to fetch the cost matrix from file");
     	}
fscanf(fp,"%d",&no_of_nodes);//scanning the total number of nodes 
		for(i=1;i<=no_of_nodes;i++)
	{
		for(j=1;j<=no_of_nodes;j++)
		{
		fscanf(fp,"%d",&cost_matrix[i][j]);	//scanning cost matrix from file 2d.txt
		}
		}
		printf("Cost matrix is:\n\n");
	for(i=1;i<=no_of_nodes;i++)
	{
		printf("|");
		for(j=1;j<=no_of_nodes;j++)
		{
		printf(" %d ",cost_matrix[i][j]);// printing cost matrix		
		}
		
		printf("|\n");
	}
	
Q:printf("\nEnter Starting node:");
	scanf("%d",&starting_node);
	if(starting_node<=0 || starting_node>no_of_nodes){
	puts("\nInvalid starting node:");
	goto Q;
	}	
	A:printf("\n\nEnter node to visit: ");
	scanf("%d",&node_to_visit);
	if(node_to_visit<= 0 || node_to_visit>no_of_nodes){
		puts("\nInvalid destination node:");
		goto A;
	}
	
	B:printf("\nEnter the total no of paths for the selected node: ");
scanf("%d",&number_of_paths);
	if(number_of_paths<=0 || number_of_paths>no_of_nodes){
		puts("\nInvalid no of paths:");
	goto B;
	}
	
	printf("\nEnter the Path matrix:\n");
	for(i=1;i<=number_of_paths;i++)
	{                                                
		for(j=1;j<=no_of_nodes;j++)
		{
		
			
			printf("\npath[%d][%d]:",i,j);
			scanf("%d",&path_matrix[i][j]);    //scanning path matrix
		
		}
	}
	printf("\nThe path matrix is\n\n");
	for(i=1;i<=number_of_paths;i++)
	{
		printf("|");
		for(j=1;j<=no_of_nodes;j++)                              //if there is only 1 path which is also minimum so best case time complexity is O(1) and if n paths
		                                               // then the worst case complexity is O(n^2)
		{
			printf(" %d ",path_matrix[i][j]);                            
		}
		printf("|\n");
	}
	for(i=1;i<=number_of_paths;i++) 
	{
		distance_matrix[i]=0;
		r=starting_node;
		for(j=1;j<no_of_nodes;j++)
		{
			if(r!=node_to_visit)
			{
				c=path_matrix[i][j+1];
				distance_matrix[i] =  distance_matrix[i]+cost_matrix[r][c];
			}
			r=c;
		}
	}
	
	min=distance_matrix[1];
	for(i=1;i<=number_of_paths;i++)//calculating the minimum distance to reach the node from array dis[]
	{
		if(distance_matrix[i]<=min)
		{
			min=distance_matrix[i];
			ind=i;
		}
	}
	printf("\nThe minimum distance to reach the node is %d\n",min);
	printf("The path of minimum distance is\n");
	for(i=1;i<=no_of_nodes;i++)
	{
		if(path_matrix[ind][i]!=0)
			printf("--->%d", path_matrix[ind][i]);
	}
    return 0;
}

