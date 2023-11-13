#include <stdio.h>
#include <string.h>

int main()
{
    //variable for option inputs
    char option;
    char operation;

    //variable for tryagain option
    char tryAgain = 'Y';

    //variable for login attempts
    int attempt = 3;

    //variable for number inputs and for the result
    float num1;
    float num2;
    float result;

    //variable that will hold user credentials
    char username [50];
    char l_username [50];
    char password [50];
    char l_password [50];


    //program code starts here
    start:
        fflush(stdin);
        printf("================ CALCULATOR PRO MAX ================\n");
        printf("|           ><><><><><><><><><><><><><><\n");
        printf("| >> Press 1 to Login\n| >> Press 2 to Sign up\n");
        printf("|\n| Response: ");
        scanf("%c", &option);

        if(option == '1')
        {
            goto login;
        }

        if(option == '2')
        {
            goto signup;
        }
        
        else
        {
            printf("|\n| >> Invalid input!\n");
            goto start;
        }

    //code for signup function
    signup:
        fflush(stdin);
        printf("===================== SIGN UP ======================\n");
        printf("|           ><><><><><><><><><><><><><><\n");
        printf("| Enter Username: ");
        scanf("%s", &username);

        printf("| Enter Password: ");
        scanf("%s", &password);

        printf("|\n| >> Registration Complete!\n");

    //code for login function
    login:
        while(attempt > -1)
        {
            fflush(stdin);
            printf("====================== LOGIN =======================\n");
            printf("|           ><><><><><><><><><><><><><><\n");
            printf("| Enter Username: ");
            scanf("%s", &l_username);

            printf("| Enter Password: ");
            scanf("%s", &l_password);

            if(attempt > 0)
            {
                if(strcmp(username, l_username)==0)
                {
                    if(strcmp(password, l_password)==0)
                    {
                        printf("|\n| >> Login Successful!\n", username);
                        goto calculator;
                    }

                    else
                    {
                        printf("|\n| >> Wrong password!\n");
                        attempt--;
                        printf("| >> You have %i attempt/s left.\n", attempt);
                    }
                }

                else
                {
                    printf("|\n| >> Username does not exist!\n");
                    attempt--;
                    printf("| >> You have %i attempt/s left.\n", attempt);
                }
            }

            else
            {
                printf("|\n| >> Please try again later!\n");
                attempt = 3;
                goto start;
            }
        }

    //code for calculator function
    calculator:
        fflush(stdin);
        printf("================ CALCULATOR PRO MAX ================\n");
        printf("| WELCOME %s!\n", username);

        while(tryAgain == 'Y' || tryAgain == 'y')
        {
            fflush(stdin);
            printf("|           ><><><><><><><><><><><><><><\n");
            printf("| >> Press 1 for Addition\n| >> Press 2 for Subtraction\n| >> Press 3 for Multiplication\n| >> Press 4 for Division\n| >> Press 5 for Squared Value\n| >> Press x to Log out.\n");
            printf("|\n| Response: ");
            scanf("%c", &operation);

            if(operation == '1')
            {
                printf("===================== ADDITION =====================\n");
                printf("|           ><><><><><><><><><><><><><><\n");
                printf("| Enter the first number: ");
                scanf("%f", &num1);

                printf("| Enter the second number: ");
                scanf("%f", &num2);

                result = num1 + num2;

                printf("|\n| >> %.2f + %.2f = %.2f\n", num1, num2, result);
            }
            
            else if(operation == '2')
            {
                printf("==================== SUBTRACTION ===================\n");
                printf("|           ><><><><><><><><><><><><><><\n");
                printf("| Enter the first number: ");
                scanf("%f", &num1);

                printf("| Enter the second number: ");
                scanf("%f", &num2);

                result = num1 - num2;

                printf("|\n| >> %.2f - %.2f = %.2f\n", num1, num2, result);
            }

            else if(operation == '3')
            {
                printf("================== MULTIPLICATION ==================\n");
                printf("|           ><><><><><><><><><><><><><><\n");
                printf("| Enter the first number: ");
                scanf("%f", &num1);

                printf("| Enter the second number: ");
                scanf("%f", &num2);

                result = num1 * num2;

                printf("|\n| >> %.2f * %.2f = %.2f\n", num1, num2, result);
            }

            else if(operation == '4')
            {
                printf("===================== DIVISION =====================\n");
                printf("|           ><><><><><><><><><><><><><><\n");
                printf("| Enter the first number: ");
                scanf("%f", &num1);

                printf("| Enter the second number: ");
                scanf("%f", &num2);

                result = num1 / num2;

                printf("|\n| >> %.2f / %.2f = %.2f\n", num1, num2, result);
            }

            else if(operation == '5')
            {
                printf("================== SQUARED VALUE ==================\n");
                printf("|           ><><><><><><><><><><><><><><\n");
                printf("| Enter a number: ");
                scanf("%f", &num1);

                result = num1 * num1;

                printf("|\n| >> The squared value of %.2f is %.2f\n", num1, result);
            }

            else if(operation == 'x')
            {
                printf("|\n| >> Thanks for using my program! :)\n");
                printf("|===================================================");
                return 0;
            }

            else
            {
                printf("|\n| >> Invalid input!");
                goto calculator;
            }

            fflush(stdin);
            printf("|\n| >> Do you want to try again? Yes (press Y) or No (press any key)\n");
            printf("| Response:");
            scanf("%s", &tryAgain);
        }

        printf("|\n| >> Thanks for using my program! :)\n");
        printf("|===================================================");

    return 0;    
}

