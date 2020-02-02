#include<stdio.h>
#include<time.h>

void Toh(int n,char src,char dst,char aux ){
    if(n==1){
        printf("Disk no %d is moved from %c to %c \n",n,src,dst);
        return;
    }
    Toh(n-1,src,aux,dst);
    printf("Disk no %d is moved from %c to %c \n",n,src,dst);
    Toh(n-1,aux,dst,src);


}

int main(){
int n;
clock_t start,end;
start=clock();
printf("Enter the Number of disks : ");
scanf("%d",&n);
Toh(n,'A','C','B');
end=clock();
printf("The time is taken %f ",(float)(end-start)/CLOCKS_PER_SEC);
    
}