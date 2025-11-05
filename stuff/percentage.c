#include <stdio.h>
int main()
{
    float a, b, c, pera, perb, perc;
   int total= 40;
    printf("The total marks for one subject is %d\n", total);
    printf("Give me the marks you recieved for Maths, Physics and Biology: \n");
    scanf("%f %f %f",&a,&b,&c);
    printf("The percentage for the marks you recieved are: \n");
    pera= (a*100)/total;
    printf("Percentage for Maths is: %f\n", pera);
    perb= (b*100)/total;
    printf("Percentage for Physics is: %f\n", perb);
    perc= (c*100)/total;
    printf("Percentage for Biology is: %f\n", perc);
}