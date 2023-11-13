#include <stdio.h>
#include <conio.h>

void displayElements(int *num, int s) 
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("%d\t", *num);
        num++;
    }
}

int countAllEven(int *num, int s)
{
    int i;
    int countEven = 0;

    for (i = 0; i < s; i++)
    {
        int result = *num % 2;

        if(result == 0)
        {
            countEven++;
        }
        
        num++;
    }

    return countEven;
}

void listAllEven(int *num, int s)
{
    int i;

    for (i = 0; i < s; i++)
    {
        int result = *num % 2;

        if(result == 0)
        {
            printf("%d\t", *num);
        }

        num++;
    }
}

int countAllOdd(int *num, int s)
{
    int i;
    int countOdd = 0;

    for (i = 0; i < s; i++)
    {
        int result = *num % 2;

        if(result != 0)
        {
            countOdd++;
        }
        
        num++;
    }

    return countOdd;
}

void listAllOdd(int *num, int s)
{
    int i;

    for (i = 0; i < s; i++)
    {
        int result = *num % 2;

        if(result != 0)
        {
            printf("%d\t", *num);
            num++;
        }
        
        num++;
    }
}

void main()
{
    int n[10];
    int i, size;
    size = sizeof(n) / sizeof(n[0]);

    for (i = 0; i < size; i++)
    {
        printf("Enter a number %d: ", (i+1));
        scanf("%d", &n[i]);
    }

    displayElements(n, size);
    printf("\n");
    printf("\n");

    printf("Number of Even Numbers: %d", countAllEven(n, size));
    printf("\n");
    printf("\n");

    listAllEven(n, size);
    printf("\n");
    printf("\n");
    
    printf("Number of Odd Numbers: %d", countAllOdd(n, size));
    printf("\n");
    printf("\n");

    listAllOdd(n, size);
    printf("\n");
    printf("\n");

    getch();
    
}