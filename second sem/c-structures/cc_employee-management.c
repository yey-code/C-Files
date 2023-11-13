#include <stdio.h>
#include <string.h> //for string manipulation
#include <conio.h> //for getch() function

#define MAX_LENGTH 50 // for empId[] and idSearch[]

//structure template
struct Employee
{
    char emp_id[50];
    char emp_name[50];
    char emp_status[50];
    double emp_basic;
    double emp_net;
};

//structure variable declaration
struct Employee emp[10];

//user - defined functions
void empManagementSystem();
void tryAgain();

//for program functionalities
void addEmployee();
void compPayroll();
void summPayroll();
void exitProgram();

int trID; //for empManagementSystem()
char tryOpe; //for tryAgain()

//for addEmployee()
char empStatus, empId[MAX_LENGTH + 1]; // +1 for null terminator
double mprem = 0;
int i = 5; //for struct Employee emp[]

char idSearch[MAX_LENGTH]; //for compPayroll()

int result = 0; //for addEmployee() and compPayroll()

//code starts here...
int main()
{
    //5 sets of initial data
    strcpy(emp[0].emp_id, "2023-01");
    strcpy(emp[0].emp_name, "DELA CRUZ, JUAN F.");
    strcpy(emp[0].emp_status, "CASUAL");
    emp[0].emp_basic = 15000;
    emp[0].emp_net = 16500;

    strcpy(emp[1].emp_id, "2023-02");
    strcpy(emp[1].emp_name, "CABRERA, LAURA G.");
    strcpy(emp[1].emp_status, "CONTRACTUAL");
    emp[1].emp_basic = 10000;
    emp[1].emp_net = 10500;

    strcpy(emp[2].emp_id, "2023-03");
    strcpy(emp[2].emp_name, "MEDINA, MILAGROSA B.");
    strcpy(emp[2].emp_status, "REGULAR");
    emp[2].emp_basic = 25000;
    emp[2].emp_net = 30000;

    strcpy(emp[3].emp_id, "2023-04");
    strcpy(emp[3].emp_name, "SANZ, LUIS I.");
    strcpy(emp[3].emp_status, "CASUAL");
    emp[3].emp_basic = 15000;
    emp[3].emp_net = 16500;

    strcpy(emp[4].emp_id, "2023-05");
    strcpy(emp[4].emp_name, "ROMERO, BENEDICT A.");
    strcpy(emp[4].emp_status, "CONTRACTUAL");
    emp[4].emp_basic = 10000;
    emp[4].emp_net = 10500;

    empManagementSystem(); //UI starts here...
}

//===================== user-defined functions starts here... =====================

//Main program
void empManagementSystem()
{
    printf("=============================== EMPLOYEE MANAGEMENT SYSTEM ================================\n");
    printf("|                              ><><><><><><><><><><><><><><                                \n");
    printf("|\n");
    printf("| >> [1] Add New Employee\n| >> [2] Compute Payroll\n| >> [3] Summarize Payroll\n| >> [4] Exit Program\n");

    //starting point -> go-to statement (empManagementSystem)
    start:
    printf("|\n| > Enter Transaction ID: ");
    while(scanf("%d", &trID) != 1) //verify user input if it is a number
    {
        printf("|\n| >> Invalid Input! Please enter a valid number.\n");
        printf("|\n| > Enter Transaction ID: ");
        while(getchar() != '\n');
    }

    switch (trID) //verify trID (user input) - transaction ID options
    {
        case 1:
            addEmployee(); //ID 1: add new employee function
            break;

        case 2:
            compPayroll(); //ID 2: compute payroll function
            break;

        case 3:
            summPayroll(); //ID 3: Summarize payroll function
            break;

        case 4:
            exitProgram(); //ID 4: Terminate the program
            break;
        
        default:
            printf("|\n| >> Invalid Input! Please enter a valid transaction ID.\n");
            goto start; //back to starting point (empManagementSystem)
            break;
    }
}
 
//try again/back to main program
void tryAgain()
{
    //starting point -> go-to statement (tryAgain)
    start:
    fflush(stdin);
    printf("|\n| > Try Again [Y] / [N]: ");
    scanf("%c", &tryOpe);

    //verify tryOpe (user input)
    if(tryOpe == 89 || tryOpe == 121) // Y or y
    {
        //if Y - print again the current function 
        switch (trID)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                compPayroll();
                break;

            case 3:
                summPayroll();
                break;
        }
    }

    else if(tryOpe == 78 || tryOpe == 110) // N or n
    {
        //back to main program
        empManagementSystem();
    }

    else
    {
        //if the user input other character
        printf("|\n| >> Invalid Input! Please enter a valid option.\n");
        goto start; //back to starting point (tryAgain)
    }
}

//==================== user-defined functions for transactions ====================

//adds new employee in the database
void addEmployee()
{
    printf("|\n================================== [1] Add New Employee ===================================\n");
    printf("|                              ><><><><><><><><><><><><><><                                \n");

    //if i exceeds the maximum sets of data (10 sets of data maximum)
    if(i == 10)
    {
        printf("|\n| >> DATABASE IS FULL! CANNOT ADD NEW EMPLOYEE!");
    }

    //can add 9 new employees (initial data + 9 = 10 sets of data)
    if(i < 10)
    {
        //starting point -> go-to statement (id)
        id:
        fflush(stdin); //flush output buffer of the stream
        printf("|\n| > Enter Employee ID: ");
        fgets(empId, MAX_LENGTH + 1, stdin);

        if(strlen(empId) == MAX_LENGTH && empId[MAX_LENGTH - 1] != '\n')
        {
            printf("|\n| >> Employee ID too long!\n");
            goto id;
        }
        
        empId[strcspn(empId, "\n")] = '\0'; //replaces the newline character with null character

        //check the uniqueness of user input empID
        for(int i = 0; i < 10; i++)
        {
            result = strcmp(empId, emp[i].emp_id); //compares empID to every employee ID in the database

            //if the empID has a similar employee ID in the database
            if(result == 0)
            {
                printf("|\n| >> Employee ID already exists in database! Please input a unique Employee ID.\n");
                goto id; //back to starting point (id)
            }
        }
        strcpy(emp[i].emp_id, empId); //stores user input in the current set of emp_id
        
        name:
        fflush(stdin); //flush output buffer of the stream
        printf("|\n| > Enter Employee Name: ");
        fgets(emp[i].emp_name, MAX_LENGTH + 1, stdin);

        if(strlen(emp[i].emp_name) == MAX_LENGTH && emp[i].emp_name[MAX_LENGTH - 1] != '\n')
        {
            printf("|\n| >> Employee Name too long!\n");
            goto name;
        }

        emp[i].emp_name[strcspn(emp[i].emp_name, "\n")] = '\0'; //replaces the newline character with null character

        //starting point -> go-to statement (status)
        status:
        fflush(stdin); //flush output buffer of the stream
        printf("|\n| > Enter Employment Status - [A] Contractual | [B] Casual | [C] Regular: ");
        scanf("%c", &empStatus);

        //verify user input(empStatus) - options: A B C
        switch (empStatus)
        {
            //CONTRACTUAL EMPLOYMENT STATUS
            case 65: // A
            case 97: // a
                emp[i].emp_basic = 10000; //10k basic salary
                
                strcpy(emp[i].emp_status, "CONTRACTUAL");
                break;
            
            //CASUAL EMPLOYMENT STATUS
            case 66: // B
            case 98: // b
                emp[i].emp_basic = 15000; //15k basic salary
                
                strcpy(emp[i].emp_status, "CASUAL");
                break;

            //REGULAR EMPLOYMENT STATUS
            case 67: // C
            case 99: // c
                emp[i].emp_basic = 25000; //25k basic salary
                
                strcpy(emp[i].emp_status, "REGULAR");
                break;
            
            default: //if the user input other employment status
                printf("|\n| >> Invalid Input! Please enter a valid Employment Status.\n");
                goto status; //back to starting point (status)
                break;
        }

        printf("|\n| ============ > New employee record is successfully saved into the database < ========== |\n");
        printf("|\n");

        //prints the id, name, status, and salary based on user input
        printf("| >> Employee ID:\t");
        puts(emp[i].emp_id);


        printf("| >> Employee Name:\t");
        strupr(emp[i].emp_name); //converts the string to uppercase
        puts(emp[i].emp_name);

        printf("| >> Employment Status:\t");
        puts(emp[i].emp_status);

        printf("| >> Basic Salary:\t%.2f", emp[i].emp_basic);

        //increment i -> for emp[i] and count of set of data
        i++;
    }
    
    printf("\n|\n===========================================================================================\n");
    printf("|\n");
    printf("| >> Press [Y] to return to Add New Employee ||| Press [N] to return to Main Menu\n");

    tryAgain(); //function call - try again/back to main program
}

//computes the payroll of employee based on employee ID
void compPayroll()
{
    printf("|\n================================== [2] Compute  Payroll ===================================\n");
    printf("|                              ><><><><><><><><><><><><><><                                \n");
    fflush(stdin); //flush output buffer of the stream
    printf("| > Enter Employee ID: ");
    scanf("%[^\n]s", &idSearch);

    //search for the specific employee ID
    for(int i = 0; i < 10; i++)
    {
        result = strcmp(idSearch, emp[i].emp_id); //compares idSearch to every employee id in database
        
        //if the user input matches employee id in database
        if(result == 0)
        {
            //prints the name, status, basic salary, and net salary
            printf("|\n| >> Employee Name:\t");
            puts(emp[i].emp_name);

            printf("| >> Employee Status:\t");
            puts(emp[i].emp_status);

            printf("| >> Basic Salary:\t%.2f\n", emp[i].emp_basic);

            //contractual >> ID: A / 10k bs / 5% mp
            //casual >> ID: B / 15k bs / 10% mp
            //regular >> ID: C / 25k bs / 20% mp

            //Net salary = basic salary + monthly premium

            if(emp[i].emp_basic == 10000.00) //CONTRACTUAL EMPLOYMENT STATUS NET SALARY
            {
                mprem = emp[i].emp_basic * 0.05; //5% monthly premium

                emp[i].emp_net = emp[i].emp_basic + mprem; //net salary
            }

            else if(emp[i].emp_basic == 15000.00) //CASUAL EMPLOYMENT STATUS NET SALARY
            {
                mprem = emp[i].emp_basic * 0.10; //10% monthly premium

                emp[i].emp_net = emp[i].emp_basic + mprem; //net salary
            }

            else if(emp[i].emp_basic == 25000.00) //REGULAR EMPLOYMENT STATUS NET SALARY
            {
                mprem = emp[i].emp_basic * 0.20; //20% monthly premium

                emp[i].emp_net = emp[i].emp_basic + mprem; //net salary
            }

            printf("| >> Net Salary:\t%.2f\n", emp[i].emp_net);

            goto end; //proceeds to end -> go-to statement
        }
    }

    //if the user input did not match the employee id's in the database
    if(result != 0)
    {
        printf("|\n| >> No record found!\n");
    }

    //starting point -> go-to statement (end)
    end:
    printf("|\n===========================================================================================\n");
    printf("|\n");
    printf("| >> Press [Y] to return to Compute Payroll ||| Press [N] to return to Main Menu\n");

    tryAgain(); //function call - try again/back to main program
}

//prints all payrolls in the database
void summPayroll()
{
    printf("|\n================================= [3] Summarize  Payroll ==================================\n");
    printf("|                               ><><><><><><><><><><><><><><                                \n");

    //maximum of 10 sets of payroll
    for(int i = 0; i < 10; i++)
    {
        //prints payroll if the salary is not 0
        if(emp[i].emp_basic != 0)
        {
            printf("|\n======================================= RECORD  # %d =======================================\n", i + 1);

            printf("| >> Employee ID:\t");
            puts(emp[i].emp_id);

            printf("| >> Employee Name:\t");
            puts(emp[i].emp_name);

            printf("| >> Employee Status:\t");
            puts(emp[i].emp_status);

            printf("| >> Basic Salary:\t%.2f\n", emp[i].emp_basic);

            printf("| >> Net Salary:\t%.2f\n", emp[i].emp_net);
        }
    }
    printf("|\n===========================================================================================\n");
    printf("|\n");
    printf("| >> Press [Y] to return to Summarize Payroll ||| Press [N] to return to Main Menu\n");

    tryAgain(); //function call - try again/back to main program
}

//terminates the program
void exitProgram()
{
    printf("|\n================================== [4] Exit Program ===================================\n");
    printf("|                            ><><><><><><><><><><><><><><                                \n");

    printf("|\n| >> Press any key to terminate the execution of the program...\n");
    
    getch(); //terminates the program by key press
}