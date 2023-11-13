#include <stdio.h>
#include <math.h> 

int remNum(int a, int b);
float addNum(float a, float b);
float subNum(float a, float b);
float proNum(float a, float b);
float quoNum(float a, float b);

int main()
{
    char ope;
    int rem;
    float fnum, snum, result;

    printf("Enter the first number: ");
    scanf("%f", &fnum);

    printf("Enter the second number: ");
    scanf("%f", &snum);

    printf("Enter the operation: ");
    scanf("%s", &ope);

    switch(ope)
    {
        case '+':
            result = addNum(fnum, snum);
            printf("The sum is: %.2f\n", result);

            if(result > 0)
                printf("positive number");
            else if(result < 0)
                printf("negative number");
            else if(result == 0)
                printf("zero number");
                
            break;

        case '-':
            result = subNum(fnum, snum);
            printf("The difference is: %.2f\n", result);
            
            if(result > 0)
                printf("positive number");
            else if(result < 0)
                printf("negative number");
            else if(result == 0)
                printf("zero number");
            
            break;   

        case '*':
            result = proNum(fnum, snum);
            printf("The product is: %.2f\n", result);
            
            if(result > 0)
                printf("positive number");
            else if(result < 0)
                printf("negative number");
            else if(result == 0)
                printf("zero number");
            
            break;

        case '/':
            result = quoNum(fnum, snum);

            fnum = (int)fnum;
            snum = (int)snum;
            rem = remNum(fnum, snum);
            printf("The quotient is: %li r. %d\n", lrint(result), rem);
            
            if(result > 0)
                printf("positive number");
            else if(result < 0)
                printf("negative number");
            else if(result == 0)
                printf("zero number");
            
            break;

        default:
            printf("invalid input\n");
            break;
    }

    return 0;
}

float addNum(float a, float b)
{
    float sum;
    sum = a + b;
    return sum;
}

float subNum(float a, float b)
{
    float min;
    min = a - b;
    return min;
}

float proNum(float a, float b)
{
    float mul;
    mul = a * b;
    return mul;
}

float quoNum(float a, float b)
{
    float div;
    div = a / b;
    return div;
}

int remNum(int a, int b)
{
    int rem;
    rem = a % b;
    return rem;
}