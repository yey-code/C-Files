#include <stdio.h>
#include <conio.h>

struct MathOptn  // => solution 1
{
    int n1;
    int n2;
    int sum;
    int difference;
    int product;
    int quotient;
} math;

void main()
{
    printf("Enter the first number: ");
    scanf("%d", &math.n1);
    printf("\n");
    printf("Enter the second number: ");
    scanf("%d", &math.n2);

    //operations
    math.sum = math.n1 + math.n2;
    math.difference = math. n1 - math.n2;
    math.product = math.n1 * math.n2;
    math.quotient = math.n1 / math.n2;

    printf("\n==============================\n\n");
    printf("Value of n1: %d\n\n", math.n1);
    printf("Value of n2: %d\n\n", math.n2);
    printf("Value of sum: %d\n\n", math.sum);
    printf("Value of difference: %d\n\n", math.difference);
    printf("Value of product: %d\n\n", math.product);
    printf("Value of quotient: %d\n\n", math.quotient);

    getch();
}