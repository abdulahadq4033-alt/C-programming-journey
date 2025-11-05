//ASCII Table
//Program to find out if the character entered by the user is lowercase or uppercase
#include <stdio.h>

int main(){
    char ch;
    printf("The character is \n");
    scanf("%c",&ch);
    printf("The value of the character is %d\n", ch);
    //97-122 are lowercase characters
    if(ch >=97 && ch<=122){
        printf("This character is lowercase\n");
    }
    else{
        printf("This character is not lowercase\n");
    }
    return 0;
}