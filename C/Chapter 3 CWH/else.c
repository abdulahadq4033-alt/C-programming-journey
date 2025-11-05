#include <stdio.h>

int main(){
    int age;
    printf("Enter your age\n");
    scanf("%d",&age);
    if(age>60){
        printf("You can drive and you are a senior citizen\n");
    }
    else if(age>40){
        printf("You can drive and you are middle aged");
    }
    else if(age>18){
        printf("You can drive\n");
    }
    else{ //optional. You can remove this else statement and nothing happens
        printf("You cannot drive\n");
    }
    return 0;
}