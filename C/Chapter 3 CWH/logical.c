#include <stdio.h>

int main(){
    int a,b;
    a=1,b=1;
    printf("The value of a and b is %d\n",a&&b);  //if a is 0 and b is 1 the value will be zero but if both are zero then the value is zero and if b=0 and a=1 then the value is zero
    printf("The value of a or b is %d\n",a||b);//if either a or b is 1 then the value is 1
    printf("The value of not(a) is %d", !a);//if a=1 then value will be 0. If a=0 then the value will be 1
    return 0;
}