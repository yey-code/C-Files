#include <stdio.h>
int main() 
{
    /*printf("Hello, World \n");
    printf("Hello, PUP \nHello, BSIT");

    return 0*/

    int a, b, sum;/*%d = decimal*/

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b); /*scanf for getting user input*/

    sum = a + b;

    printf("%d + %d = %d", a, b ,sum);
    
    return 0;
}