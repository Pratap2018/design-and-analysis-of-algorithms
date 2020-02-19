#include<stdio.h>
#include<stdlib.h>
FILE *fp;
int count=0;

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

/***********************************************************************/
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1,j=0;
    for(j=low;j<=high-1;j++){
        if(++count && arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }


}

/***********************************************************************************/
long long fact (long long n){
   long long i,k=1;
   for(i=1;i<=n;i++){
       k*=i;
   }
   return k;
}


/***********************************************************************************/
void read_file_sort(int n,long long row){
FILE *fp,*fp1;
int *arr;
arr=(int *)malloc(sizeof(int)*n);
fp=fopen("input.txt","r");
fp1=fopen("output.txt","w+");
if(fp1==NULL || fp==NULL){
    printf("\nError opening file");
    exit(0);
}
while(row--){
    
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        fprintf(fp1," %d",arr[i]);
    }
    printf("\n");
    fprintf(fp1,"\n");
    }
}
/***************************************************************************************/
int main(){
int n;
long long row;
fp=fopen("input.txt","w+");
printf("Enter the size  : ");
scanf("%d",&n);
start_permute(n);
fclose(fp);
row=fact(n);
read_file_sort(n,row);
printf(" avarage no of comparisn  %lld",count/row);
}
