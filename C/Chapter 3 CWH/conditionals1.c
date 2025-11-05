#include <stdio.h>

int main(){
    int age;
    printf("Give me your age: \n");
    scanf("%d",&age);
    if(age>10){
        printf("We are inside if\n");
        printf("Your age is greater than 10\n");
    }
    if(age%5==0){   //Is the remainder 0 if the age is divided by 5
        printf("You are a child\n");
    }

    
    return 0;
}