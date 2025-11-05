//Program for giving grade to a student based on their marks

#include <stdio.h>
    /* 
    90-100=>A
    80-90=>B
    70-80=>C
    60-70=>D
    50-60=>E
    <50=>F
    */
int main(){
    int marks;
    char grade;
    printf("Enter your marks out of 100: \n");
    scanf("%d",&marks);
    if(marks<=100 && marks>=90){
        grade = 'A';
    }
    else if(marks<=90 && marks>=80){
        grade = 'B';
    }
    else if(marks<=80 && marks>=70){
        grade = 'C';
    }
    else if(marks<=70 && marks>=60){
        grade = 'D';
    }
    else if(marks<=60 && marks>=50){
        grade = 'E';
    }
    else{
        grade = 'F';
    }

    printf("Your grade is: %c\n", grade);
    return 0;
}