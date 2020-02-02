#include<stdio.h>
#include<time.h>
int count;
long long power(long long x,long long n){
    long long temp;
    if(n==0){
        count++;
        return 1;
    }
    temp=power(x,n/2);
    count++;
    if(n%2==0){
        
        return temp*temp;
    }
    else
    {   
        return x*temp*temp;
    }
    


}

int main(){
long long x,n,k;
printf("Enter the numver and the power : ");
scanf("%lld %lld",&x,&n);
clock_t start,end;
start=clock();
k=power(x,n);
end=clock();
printf("The result %lld  time taken %f sec \n",k,(float)(end-start)/CLOCKS_PER_SEC);
printf("The complexity is %d \n",count);

}