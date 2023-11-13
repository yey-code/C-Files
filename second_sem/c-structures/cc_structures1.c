#include <stdio.h>
#include <conio.h>

struct MathOptn
{
    int n1;
    int n2;
    int sum;
    int difference;
    int product;
    int quotient;
};

void main()
{
    struct MathOptn math;

    printf("Enter the Value of n1: ");
    scanf("%d", &math.n1);

    printf("Enter the Value of n2: ");
    scanf("%d", &math.n2);

    math.sum = math.n1 + math.n2;
    math.difference = math.n1 - math.n2;
    math.product = math.n1 * math.n2;
    math.quotient =math.n1 / math.n2;

    printf("Value of n1: %d\n", math.n1);
    printf("Value of n2: %d\n ", math.n2);
    printf("Value of Sum: %d\n ", math.sum);
    printf("Value of Difference:%d\n ", math.difference);
    printf("Value of Product:%d\n ", math.product);
    printf("Value of Quotient:%d\n ", math.quotient);

    getch();
}