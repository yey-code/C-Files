#include <stdio.h>

int main()
{
    //fullname and course
    char name[] = "De Vera, Arvin T.";
    char course[] = "BSIT";

    //userInput
    int number;
    char tryAgain = 'Y';

    printf("\n");
    printf("================  MY INFO  ================\n");
    printf("|       ><><><><><><><><><><><><><><\n");
    printf("|\n| >> My name is: %s\n", name);
    printf("| >> My course is: %s\n", course);
    printf("|\n");
    printf("============  INTEGER CHECKER  ============\n");
    printf("|       ><><><><><><><><><><><><><><\n");

    while (tryAgain == 'Y' || tryAgain == 'y')
    {
        fflush(stdin);
        printf("|\n| Enter a number: ");
        
        if(scanf("%d", &number) == 1)
        {
            if(number < 0)
            {
                printf("|\n| >> The number %d is a negative integer.\n", number);
            }

            else if(number > 0)
            {
                printf("|\n| >> The number %d is a positive integer.\n", number);
            }

            else
            {
                printf("|\n| >> The number is a zero, it is neither negative nor positive.\n", number);
            }
        }

        else
        {
            printf("|\n| >> Invalid character.\n");
        }

        fflush(stdin);
        printf("|\n| >> Do you want to try again? Yes (press Y) or No (press any key)\n");
        printf("| Response:");
        scanf("%s", &tryAgain);
    }

    printf("|\n|                 ><><><><><><><><><><><><><><\n");
    printf("|\n| >> Thanks for using my program! :D\n");
    printf("|\n|================================================================");
    

    return 0;
}