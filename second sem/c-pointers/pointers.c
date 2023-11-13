#include <stdio.h>
#include <conio.h>

void displayResult(int *num)
{
    if(*num >= 0)
    {
        printf("Result: %d is a positive value!", *num);
    }

    else
    {
        printf("Result: %d is a negative value!", *num);
    }
}

struct myStructure
{
    int i;
    char b;
    char c[30];
}struct1;

void main()
{
    /*int num[10];
    int i, *ip;

    int size = (sizeof(num) / sizeof(num[0]));
    printf("\nNumber of elements in num array: %d\n", size);

    printf("Values of num array: \n");
    for (i = 0; i < size; i++)
    {
        num[i] = i + 1;
        printf("num[%d]: %d\n", i, num[i]);
    }

    ip = num;

    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("ip value %d: %d\n", (i + 1), *ip);
        ip++;
    }*/

    int n;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    displayResult(&n);
    
    getch();
}