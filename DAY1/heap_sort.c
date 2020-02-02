#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
int count=0;
/*********************************************/
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int size,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l < size && arr[l]>arr[large] && count++)
        large=l;
    if(r < size && arr[r]>arr[large] && count++) 
        large=r;

        if(large!=i){
            swap(&arr[i],&arr[large]);
            
            heapify(arr,size,large);
        }
}

void heap_sort(int arr[],int n){
    for(int i=n/2 -1 ;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }

}

 
/*********************************************/

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
    heap_sort(arr,n);
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
printf("Total No of Comparisn : %d \n", count/r );


}
