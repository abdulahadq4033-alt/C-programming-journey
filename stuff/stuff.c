#include <stdio.h>

int main() {
    float a, b, c;
    char name[25];

    printf("Enter values for a, b and c: \n");
    scanf("%f %f %f", &a, &b, &c);

    printf("Also say what your name is: \n");
    scanf("%24s", name);

    printf("Hello %s, you entered a=%.2f, b=%.2f, c=%.2f\n", name, a, b, c);

    return 0; 
}
