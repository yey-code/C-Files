#include <stdio.h>

//function declaration
void allowanceDeduc();
void totalAllowance();
void totalDeduc();
void gSalary();
void nSalary();

//variable for allowances
float hra = 0, da = 0, ea = 0, ta = 0;

//variable for deductions
float ss = 0, levy = 0;

//variable for totals
float totalAllow = 0, totalDed = 0;

//variable for salaries
float salary = 0, gross = 0, net = 0;

//variable for try again
int tryAgain;


//code starts here
int main()
{
    //salary, allowances, and deductions 
    printf("====================== SALARY CALCULATOR =======================\n");
    printf("|               ><><><><><><><><><><><><><><\n");
    start:
    printf("|\n| >> Start program? [1] to continue or [0] to terminate the program\n");
    printf("| >> Response: ");

    //validate user input value in tryAgain
    while(scanf("%i", &tryAgain) != 1)
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a number.\n");
        printf("|\n| >> Start program? [1] to continue or [0] to terminate the program\n");
        printf("| >> Response: ");
        while(getchar() != '\n');
    }

    //if the user input is 1
    if(tryAgain == 1)
    {
        salaryInput:
        printf("|\n| > ENTER BASIC SALARY: ");

        //validate user input value in salary
        while(scanf("%f", &salary) != 1)
        {
            printf("|\n| >> Invalid Input!! ~ Please enter a number.\n");
            printf("\n| > ENTER BASIC SALARY: ");
            while(getchar() != '\n');
        }

        //validate the salary value
        if(salary > 0)
        {
            //function call for allowances and deductions
            allowanceDeduc();

            //add new line
            printf("|\n");



            //total allowance and total deduction
            printf("============================ TOTALS =============================\n");
            printf("|                ><><><><><><><><><><><><><><\n");

            //function call for total allowance and total deduction
            totalAllowance();
            totalDeduc();
            printf("|\n");

                
            //gross salary and net salary
            printf("====================== GROSS AND NET SALARY =======================\n");
            printf("|                 ><><><><><><><><><><><><><><\n");

            //function call for gross and net salary
            gSalary();
            nSalary();

            printf("\n|\n===================================================================\n");

            //back to start
            goto start;
        }

        //if the salary is below or equal to zero
        else if(salary <= 0)
        {
            printf("|\n| >> Please input a higher amount of number.\n");
            goto salaryInput;
        }
    }

    //if the user input is 0
    if(tryAgain == 0)
    {
        printf("|\n| >> Program Terminated, thanks for using!");
        printf("\n|\n===================================================================\n");
    }

    //if the user input is not 1 or 0
    else
    {
        printf("|\n| >> Invalid Input! ~ Please enter either [1] to continue or [0] to terminate the program");
        goto start;
    }
}

//computes each item in allowances and deduction: HRA, DA, EA, TA, SS, and Levy.
void allowanceDeduc()
{
    // formula: <allowance/deduction variable name> = salary * <percentage in basic salary>

    //computations
    hra = salary * 0.15;
    da = salary * 0.10;
    ea = salary * 0.05;
    ta = salary * 0.12;

    ss = salary * 0.07;
    levy = salary * 0.01;

    //show allowances and deductions
    printf("|\n| >> ALLOWANCES: | HRA\t\t\t| DA\t\t\t| EA\t\t\t| TA\n");
    printf("|    ----------  | P %.2f\t\t| P %.2f\t\t| P %.2f\t\t| P %.2f\n", hra, da, ea, ta);

    printf("|\n| >> DEDUCTIONS: | SS\t\t\t| LEVY\n");
    printf("|    ----------  | P %.2f\t\t| P %.2f\n", ss, levy);
}

//function that computes the total allowances
void totalAllowance()
{
    //sum up all allowances
    totalAllow = hra + da + ea + ta;
    printf("|\n| >> TOTAL ALLOWANCE: P %.2f\n", totalAllow);
}

//function that computes the total deductions
void totalDeduc()
{
    //sum up all deductions
    totalDed = ss + levy;
    printf("|\n| >> TOTAL DEDUCTION: P %.2f\n", totalDed);
}

//function that computes the gross salary
void gSalary()
{
    //Formula: Gross salary = Basic salary + allowances
    gross = salary + totalAllow;
    printf("|\n| >> GROSS SALARY: P %2.f\n", gross);
}

//function that computes the net salary
void nSalary()
{
    //Formula: Net salary = Gross salary - deductions
    net = gross - totalDed;
    printf("|\n| >> NET SALARY: P %2.f", net);
}