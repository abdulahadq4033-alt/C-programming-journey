#include <stdio.h>

int main(){
    if(1){
        printf("This if is executed\n");
    }
    if(2324){
        printf("This if is also executed\n");
    }
    if(2.3){
        printf("This if is also executed");
    }
    if(0){      //if you write if(0) the statement will not be executed
        printf("I am not executed because I am zero");
    }
    return 0;
}