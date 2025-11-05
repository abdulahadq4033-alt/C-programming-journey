#include <stdio.h>

int main(){
    int age;
    printf("Give me your age: \n");
    scanf("%d",&age);
    if(age>17){
        printf("You are an adult\n");
    }else{
        printf("You are a child");
    }
}