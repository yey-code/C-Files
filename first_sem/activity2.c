#include <stdio.h>

int main()
{
    //declare all possible options
    char optN = 'N';
    char optD = 'D';
    char optA = 'A';
    char optC = 'C';
    char yes = 'Y';
    char no = 'N';

    //declare userInputs
    char userInput;
    char tryAgain;

    //data to be shown
    char name[] = "Arvin Teodoro De Vera";
    char dob[]= "June 05, 2004";
    char address[] = "#1235 Purok 4 Tibagan, Cay Pombo, Sta. Maria, Bulacan";
    char contact[] = "(+63) 950-3766-373";

    //code starts here
    printf("\n");
    printf("================  WELCOME TO MY PERSONAL SPACE  ================\n");

    do
    {
        start:
        printf("|                 ><><><><><><><><><><><><><><\n");
        printf("|\n| >> What do you want to know about me?\n");
        printf("| Name (press N), Date of Birth (press D), Address (press A), Contact (press C)\n");
        printf("| Response:");
        scanf("%s", &userInput);

        if(userInput == optN)
        {
            printf("|\n| >> My Name is %s. :D\n", name);
            printf("|---------------------------------------------------");
        }

        else if(userInput == optD)
        {
            printf("|\n| >> My Date of Birth is on %s. :D\n", dob);
            printf("|---------------------------------------------------");
        }

        else if(userInput == optA)
        {
            printf("|\n| >> My Address is %s. :D\n", address);
            printf("|---------------------------------------------------");
        }

        else if(userInput == optC)
        {
            printf("|\n| >> My Contact is %s. :D\n", contact);
            printf("|---------------------------------------------------");
        }

        else
        {
            printf("|\n| >> Invalid input, please try again. :(\n");
            printf("|\n");
            goto start;
        }

        printf("\n| >> Do you want to know more about me? Yes (press Y) or No (press any key)\n");
        printf("| Response:");
        scanf("%s", &tryAgain);
    } 
    
    while (tryAgain == 'Y' || tryAgain == 'y');
    printf("|\n|                 ><><><><><><><><><><><><><><\n");
    printf("|\n| >> Thanks for using my program! :D\n");
    printf("|\n|================================================================");

    return 0;
}