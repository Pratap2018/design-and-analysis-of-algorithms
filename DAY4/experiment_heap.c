#include<stdio.h>
#include<stdlib.h>
/*******************************************************/
struct node
{
    char data;
    struct node*  left;
    struct node* right;
    int freq;
};
struct heap{
    int size,capcity;
    struct node ** arr;
};
/*******************************************************/
struct node* newNode(char data,int frequency){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=frequency;
    return temp;
}
/*******************************************************/
/***************************************************************/
struct heap* create_heap(int capacity){
    struct heap* Heap=(struct heap*)malloc(sizeof(struct heap)*capacity);
    Heap->size=0;
    Heap->capcity=capacity;
    Heap->arr=(struct node**)malloc(Heap->capcity*sizeof(struct node*));
    return Heap;
}
/***************************************************************/
/***************************************************************/
void swapnode(struct node **a,struct node **b ){
    struct node* temp=*a;
    *a=*b;
    *b=temp;
}
/***************************************************************/
void heapify(struct heap* Heap,int idx){
    int small =idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<Heap->size && Heap->arr[left]->freq <Heap->arr[small]->freq)
        small=left;
    if(right<Heap->size && Heap->arr[right]->freq < Heap->arr[small]->freq)
        small=right;
    if (small!=idx)
    {
        swapnode(&Heap->arr[idx],&Heap->arr[small]);
        heapify(Heap,small);
    }
    
}

int isSizeone(struct heap* Heap){
    return (Heap->size==1);
}

struct node* extractmin(struct heap* Heap){
    struct node* temp=Heap->arr[0];
    Heap->arr[0]=Heap->arr[Heap->size-1];
    --Heap->size;
    heapify(Heap,0);
    return temp;
}

void insert_heap(struct heap* Heap,struct node* node){
    ++Heap->size;
    int i=Heap->size-1;
    while (i && node->freq < Heap->arr[(i-1)/2]->freq){
        Heap->arr[i]=Heap->arr[(i-1)/2];
        i=(i-1)/2;        
    }
    Heap->arr[i]=node;
}

void buildheap(struct heap* Heap){
    int n =Heap->size-1;
    int i;
    for(i=(n-1)/2;i<n;i++){
        heapify(Heap,i);
    }
}

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]);   
    printf("\n"); 
} 

int isleaf(struct node* root){
    return !(root->left) && !(root->right);
}

struct heap* create_build_heap(char data[],int freq[],int size){
    int i=0;
    struct heap* Heap=create_heap(size);
    for(i=0;i<size;i++){
        Heap->arr[i]=newNode(data[i],freq[i]);
    }
    Heap->size=size;
    buildheap(Heap);
    return Heap;
}

struct node* build_huff_tree(char data[],int freq[],int size){
    struct node *left,*top,*right;
    struct heap *Heap=create_build_heap(data,freq,size);
    while(!isSizeone(Heap)){
        left=extractmin(Heap);
        right=extractmin(Heap);
        top=newNode('#',left->freq+right->freq);
        top->left=left;
        top->right=right;
        insert_heap(Heap,top);
    }
return extractmin(Heap);
}
void printcode(struct node* root,int arr[],int top){
    if (root->left) {  
        arr[top] = 0; 
        printcode(root->left, arr, top + 1); 
    } 
    if (root->right) {   
        arr[top] = 1; 
        printcode(root->right, arr, top + 1); 
    }
    if(isleaf(root)){
        printf("%c : ",root->data);
        printArr(arr,top);
    }
}

void Huffman(char data[],int freq[],int size){
    struct node* root=build_huff_tree(data,freq,size);
    int arr[100],top=0;
    printcode(root,arr,top);
}


int main(){
char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
int freq[] = { 21,61,51,14,15,10 }; 
Huffman(arr,freq,6);
    
}