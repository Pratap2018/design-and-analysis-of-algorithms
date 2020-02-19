#include<stdio.h>
#include<stdlib.h>
FILE *fp;

/****************************** permutation part *********************************/

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}


void permute(int arr[],int l,int r,int n){
    int i=0; 
    if(l==r){
        for ( i = 0; i < n; i++)
            {
                printf(" %d",arr[i]);
                fprintf(fp," %d",arr[i]);
            }
            printf("\n");
                 fprintf(fp," \n");
        }
        else
        {
            for ( i = l; i <=r; i++)
            {
                swap(&arr[l],&arr[i]);
                permute(arr,l+1,r,n);
                swap(&arr[l],&arr[i]);
            }
            
        }
        
    }

void start_permute(int n){
int *arr,i=0;
arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		arr[i]=i+1;
	}
permute(arr,0,n-1,n);
}

/***************************************************************/

int main(){
int n;
fp=fopen("input.txt","w+");
printf("Enter the size  : ");
scanf("%d",&n);
start_permute(n);
fclose(fp);

}
