#include <stdio.h>

int main(){
    /*Simple interest = [p*r*t]
    p=principal amount
    r= annual interest rate
    t=time*/
    int p,r,t,i;
    scanf("%f, %f, %f",&p,&r,&t);
    i=(p*r*t)/100;
    printf("Simple interest is %f",i);
    return 0;
}