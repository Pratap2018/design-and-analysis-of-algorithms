#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int size,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l < size && arr[l]>arr[large])
        large=l;
    if(r < size && arr[r]>arr[large]) 
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

int main(){
int arr[] = {12, 11, 13, 5, 6, 7,100,0}; 
int n = sizeof(arr)/sizeof(arr[0]); 
  
heap_sort(arr, n); 
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}