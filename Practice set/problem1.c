#include <stdio.h>

int main()
{
    int area, length, width;
    printf("Enter the value for length: \n");
    scanf("%d", &length);   // use & before variable
    printf("Enter the value for width: \n");
    scanf("%d", &width);    // use & before variable
    area = length * width;
    printf("Area of rectangle = %d\n", area);
    return 0;   // good practice
}
