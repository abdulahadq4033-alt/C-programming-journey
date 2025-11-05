#include <stdio.h>

int main(){
    float c, f;
    printf("Give me the Celcius value: \n");
    scanf("%f", &c);
    f = ((9.0/5.0))*c + 32;
    printf("The value in Fahrenheit is %f\n",f);
    return 0;
}