#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
/***********************SORT*************************************************/
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;    
    int L[n1], R[n2];   
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j];   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { count++;
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { count++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { count++;
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;  
       
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}
/*************************************************************************/
/*********************INPUT*****************************/
int esearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return 1;
        }
    }
    return 0;
}

void create_inp_txt(int n,int row,int range){
int *arr,x;
FILE *fp;
fp=fopen("input.txt","w+");
if(fp==NULL){
    printf("\nError opening file");
    exit(0);
}
srand(time(NULL));
while(row--){
arr=(int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
       x=rand()%range;
       if(!esearch(arr,i+1,x)){
           arr[i]=x;
       }else{
           i--;
       }
      
    }
    for(int i=0;i<n;i++){
        fprintf(fp," %d",arr[i]);
    }
    fprintf(fp,"\n");
    }
fclose(fp);
}

/*
bool create_output_txt(int arr[],int n,int total){
FILE *fp;


}
*/

void read_file_sort(int n,int row){
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
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        fprintf(fp1," %d",arr[i]);
    }
    printf("\n");
    fprintf(fp1,"\n");
    }
}


int main(){
int n,r,range;
printf("Enter the Number of elements \nand Number of arrays\nand the range of integer : ");
scanf("%d%d%d",&n,&r,&range);


create_inp_txt(n,r,range);
read_file_sort(n,r);
printf("Avg No of Comparisn : %d \n", count/r );

}
