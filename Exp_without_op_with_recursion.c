#include<stdio.h>
long long exp(long base,long pow){
    //long double md=2;
    if (pow < 0) return exp(1 / base, -pow);
    else if (pow == 0) return 1;
    else if (pow == 1) return  base ;
    else if (pow%2 == 0) return exp(base * base,  pow / 2);
    else if (pow%2 == 1) return base * exp(base * base, (pow - 1) / 2);
}

void main(){
    
    long base,pow;
    long long res;
    printf("Enter base:");
    scanf("%ld",&base);
    printf("Enter power:");
    scanf("%ld",&pow);
    res=exp(base,pow);
    printf("Result =  %llu",res);
}

