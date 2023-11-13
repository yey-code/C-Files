#include <stdio.h>

//function declaration
void operations(int a, int b);

//variables to be used
int num1, num2, ope, result, tryAgain;

int main()
{
    //input
    start:
    printf("\nDo you want to try the program? [1] or [0]\n");
    scanf("%i", &tryAgain);

    //looping condition
    switch (tryAgain)
    {
        //if user input 1
        case 1:
            printf("\n>> Enter integer value 1: ");
            scanf("%i", &num1);

            printf(">> Enter integer value 2: ");
            scanf("%i", &num2);

            printf("\nOperations: \n [1]: Addition\n [2]: Subtraction\n [3]: Multiplication\n [4]: Division\n");
            printf("\n>> Enter operation: ");
            scanf("%i", &ope);

            //process
            operations(num1, num2);

            goto start;
            break;
        
        //if user input 0
        case 0:
            printf("\n>> Goodbye! ^^");
            break;

        default:
            printf("\n>> Invalid input (1)!\n");
            goto start;
            break;    
    }

    return 0;
}

void operations(int a, int b)
{
    //output
    switch (ope)
    {
        //user input 1
        case 1:
            result = a + b;
            printf("\n>> Sum of %i and %i is %i\n", num1, num2, result);
            break;

        //user input 2
        case 2:
            result = a - b;
            printf("\n>> Difference of %i and %i is %i\n", num1, num2, result);
            break;

        //user input 3
        case 3:
            result = a * b;
            printf("\n>> Product of %i and %i is %i\n", num1, num2, result);
            break;

        //user input 4
        case 4:
            result = a / b;
            printf("\n>> Quotient of %i and %i is %i\n", num1, num2, result);
            break;
        
        //if 4<ope
        default:
            printf("\n>> Invalid input (2)!\n");
            break;
    }
}