#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>


int minKey(int key[],bool mstset[],int nv){
    int min=INT_MAX,minid,i;
    for(i=0;i<nv;i++){
        if(mstset[i]==false && key[i]<min){
            min=key[i];
            minid=i;
        }
    }
return minid;
}

int printMST(int parent[], int *graph[],int nv) 
{ int total=0;
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < nv; i++){ 
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
        total+=graph[i][parent[i]];
    }
    printf("\n Weight :%d",total);
}

void prims(int *graph[],int nv){
    int *key,*parent,i,v,u;
    bool *incld_mst;
    key=(int *)malloc(sizeof(int)*nv);
    parent=(int *)malloc(sizeof(int)*nv);
    incld_mst=(bool *)malloc(sizeof(bool)*nv);

    for ( i = 0; i < nv; i++)    
    key[i]=INT_MAX,incld_mst[i]=false;
    
    key[0]=0;
    parent[0]=-1;
    for(i=0;i<nv-1;i++){
        u=minKey(key,incld_mst,nv);
        incld_mst[u]=true;

        for (v = 0; v < nv; v++){
            if(graph[u][v]&&incld_mst[v]==false&& graph[u][v]<key[v])
                parent[v]=u,key[v]=graph[u][v];
        }
        
    }
    printMST(parent,graph,nv);
}

int main(){
int nv,i,j;
int **graph;
printf("Enter the Number of the vertices :");
scanf("%d",&nv);
graph=(int **)malloc(sizeof(int*)*nv);
for(i=0;i<nv;i++){
    graph[i]=(int *)malloc(sizeof(int)*nv);

}

for ( i = 0; i < nv; i++){
    for ( j = 0; j < nv; j++){
    scanf("%d",&graph[i][j]);
    }
    
}

prims(graph,nv);


}

/********************************
 * 
 * Enter the Number of the vertices :9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
0 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Edge    Weight
0 - 1   4 
1 - 2   8 
2 - 3   7 
3 - 4   9 
2 - 5   4 
5 - 6   2 
6 - 7   1 
2 - 8   2 

 Weight :37
 * **********************************/