#include <stdio.h>

void arrayList(int num[]);
void posCount(int posNum);
void zCount(int zNum);
void negCount(int negNum);

int n[] = {9, 6, -2, 23, -78};
int pos = 0, neg = 0, zero = 0;

int main()
{
    arrayList(n);

    posCount(pos);
    zCount(zero);
    negCount(neg);
}

void arrayList(int num[])
{
    printf("\nList of array elements: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%i\t", n[i]);
    }
}

void posCount(int posNum)
{
    for(int i = 0; i < 5; i++)
    {
        if(n[i] > 0)
            pos++;
    }
    printf("\n\nPositive numbers: %i", pos);
}

void zCount(int zNum)
{
    for(int i = 0; i < 5; i++)
    {
        if(n[i] == 0)
            zero++;
    }
    printf("\nZeros: %i", zero);
}

void negCount(int negNum)
{
    for(int i = 0; i < 5; i++)
    {
        if(n[i] < 0)
            neg++;
    }
    printf("\nNegative numbers: %i", neg);
}

//Function declaration
/*int addNum(int a, int b); // with parameter & with return

int subtractNum(); //without parameter & with return

void multiplyNum(int a, int b); //with parameter & without return

void divideNum(); //without parameter & without return

int num1, num2, tryAgain;

int main()
{
    //Input
    start:
    printf("\nDo you want to try this? 1 or 0\n");
    scanf("%d", &tryAgain);

    switch (tryAgain)
    {
        case 1:
            while(tryAgain == 1)
            {
                printf("Enter Value 1: ");
                scanf("%i", &num1);

                printf("Enter Value 2: ");
                scanf("%i", &num2);

                //function call
                printf("Sum: %i\n", addNum(num1, num2)); // with parameter & with return

                printf("Difference: %i\n", subtractNum()); //without parameter & with return
                
                multiplyNum(num1, num2); //with parameter & without return

                divideNum(); //without parameter & without return

                goto start;
            }
            break;
        
        case 0:
            printf("END OF THE PROGRAM\n");
            break;
        
        default:
            printf("invalid input\n");
            goto start;
            break;
    }

    return 0;
}

//function definition
int addNum(int a, int b) //with parameter & with return
{
    return(a + b);
}

int subtractNum() //without parameter & with return
{
    return(num1 - num2);
}

void multiplyNum(int a, int b) //with parameter & without return
{
    printf("Product: %i\n", a * b);
}

void divideNum() //without parameter & without return
{
    printf("Quotient: %i\n", num1 / num2);
}*/