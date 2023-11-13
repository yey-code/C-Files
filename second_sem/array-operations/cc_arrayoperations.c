//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function declaration
void randomArray();
void arrayList();
void operations();
void again();

//function declaration (operations)
void searchGrade();
void sortGrade();
void computeAverage();
void countPass();
void countFail();
void exitProgram();

//array declaration
int grade[8];

//variable declaration
int sortOpe = 0, num = 0; //for sortGrade()
int searchInput = 0, gradeOccur = 0; //for searchGrade()
int average = 0; //for computeAverage()
int pass = 0, fail = 0; //for countPass() and countFail()

char ope = '\n'; //for operations()
char tryAgain; //for again()
char terminate; //for exitProgram()

//code starts here
int main()
{
    srand(time(0)); //random number generator every run
    randomArray();

    operations(); //UI starts here...
    return 0;
}

//===================== user-defined functions starts here... ===================== 

void randomArray() //insert random numbers to array
{
    for(int i = 0; i < 8; i++)
    {
        grade[i] = (rand() % (100 - 50 + 1)) + 50; //random number from 50 - 100
    }                        
}

void arrayList() //show array elements
{
    printf("|\n|============================================================================");
    printf("\n| LIST OF GRADES: \n| >> \t");
    for(int i = 0; i < 8; i++)
    {
        printf("%d\t", grade[i]);
    }
    printf("\n"); 
}

void operations() //show operations
{
    printf("========================= GRADE OPERATIONS PROGRAM ==========================\n");
    printf("|                       ><><><><><><><><><><><><><><\n");

    //function call, show list of grades
    arrayList();

    //starting point -> go-to statement (operations)
    chooseOpe:
    printf("|\n| Operations: \n");
    printf("| A. Search for Specific Grade\n| B. Sort Grades\n| C. Compute the Average Grade\n| D. Count Number of PASS Grades\n| E. Count Number of FAIL Grades\n| F. Exit\n");
    printf("|\n| > Enter the letter that corresponds to the operation: ");
    scanf("%s", &ope);

    switch (ope) //verify ope (user input) - what option did the user chose
    {
        case 'A':
        case 'a':
            searchGrade();
            break;
        
        case 'B':
        case 'b':
            sortGrade();
            break;

        case 'C':
        case 'c':
            computeAverage();
            break;

        case 'D':
        case 'd':
            countPass();
            break;

        case 'E':
        case 'e':
            countFail();
            break;

        case 'F':
        case 'f':
            exitProgram();
            break;

        default:
            printf("|\n| >> Invalid Input!! ~ Please enter a valid operation.\n");
            goto chooseOpe; //back to starting point (operations)
            break;
    }
}

void again() //try again/back to operations
{
    printf("\n|\n===========================================================================\n");
    
    //starting point -> go-to statement (again)
    start:
    printf("|\n| > Press Y to return to Operations, press N to try again: ");
    scanf("%s", &tryAgain);
    
    //verify tryAgain (user input)
    if (tryAgain == 'Y' || tryAgain == 'y')
    {
        operations();
    }

    else if (tryAgain == 'N' || tryAgain == 'n')
    {
        arrayList();
        switch (ope)
        {
            case 'A':
            case 'a':
                searchGrade();
                break;
            
            case 'B':
            case 'b':
                sortGrade();
                break;

            case 'C':
            case 'c':
                computeAverage();
                break;

            case 'D':
            case 'd':
                countPass();
                break;

            case 'E':
            case 'e':
                countFail();
                break;

            case 'F':
            case 'f':
                exitProgram();
                break;
        }
    }

    else
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a valid option.\n");
        goto start; //back to starting point (again)
    }
}

//===================== user-defined functions for operations ===================== 

void searchGrade() //search occurences of grade
{
    printf("|\n====================== [A.] Search for Specific Grade =======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");
    printf("|\n| > Enter a grade to search: ");
    while(scanf("%d", &searchInput) != 1) //verify user input if it is a number
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a valid integer.\n");
        printf("|\n| > Enter a grade to search: ");
        while(getchar() != '\n');
    }

    //iteration - check searchInput(user input) if it occurs in the array 
    for (int i = 0; i < 8; i++)
    {
        if(searchInput == grade[i])
        {
            gradeOccur++; //+1 to occurence(s)
        }
    }

    //if there's occurence
    if(gradeOccur > 0)
    {
        printf("|\n| >> Result: %d occurence(s)", gradeOccur);
        gradeOccur = 0;
    }

    //if there's no occurence
    else if(gradeOccur == 0)
    {
        printf("|\n| >> Result: Not found!");
    }

    //function call - try again/back to operations
    again();
}

void sortGrade() //sort grades in ascending/descending order
{
    printf("|\n============================= [B.] Sort Grades ==============================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");
    printf("|\n| >> Sorting Operations:\n");
    printf("| [1] Ascending\n| [2] Descending\n");

    //starting point -> go-to statement (sortGrade)
    start:
    printf("|\n| > Enter operation: ");
    while(scanf("%d", &sortOpe) != 1) //verify user input if it is a number
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a valid operation.\n");
        printf("|\n| > Enter operation: ");
        while(getchar() != '\n');
    }

    switch (sortOpe) //verify sortOpe(user input) - what option did the user chose
    {
        //ascending order
        case 1: 
            printf("|\n| Sort in Ascending Order: \n| >> \t");

            for (int i = 0; i < 8; i++)
            {
                for (int j = i + 1; j < 8; j++)
                {
                    if(grade[i] > grade [j])
                    {
                        //interchange values
                        num = grade[i];
                        grade[i] = grade[j];
                        grade[j] = num;
                    }
                }
                
            }
            for (int i = 0; i < 8; i++)
            {
                printf("%d\t", grade[i]); //print array in new order
            }
            break;

        //descending order
        case 2:
            printf("|\n| Sort in Descending Order: \n| >> \t");

            for (int i = 7; i >= 0; i--)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if(grade[i] > grade [j])
                    {
                        //interchange values
                        num = grade[i];
                        grade[i] = grade[j];
                        grade[j] = num;
                    }
                }
                
            }
            for (int i = 0; i < 8; i++)
            {
                printf("%d\t", grade[i]); //print array in new order
            }
            break;    
        
        //if user input is not [1] or [2]
        default:
            printf("|\n| >> Invalid Input!! ~ Please enter a valid operation.\n");
            goto start; //back to starting point (sortGrade)
            break;
    }

    //function call - try again/back to operations
    again();
}

void computeAverage() //compute average grade
{
    printf("|\n====================== [C.] Compute the Average Grade =======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //computation of average grade
    average = (grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] + grade[6] + grade[7])/8;

    printf("|\n| >> Average grade: %d%%", average);
    average = 0; //reset average grade to 0

    //function call - try again/back to operations
    again();
}

void countPass() //show number of PASSING grades (75-100)
{
    printf("|\n===================== [D.] Count Number of PASS Grades ======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //iteration - check how many elements satisfy the condition
    for(int i = 0; i < 8; i++)
    {
        if(grade[i] >= 75 & grade[i] <= 100)
        {
            pass++; //+1 to pass (passing grades)
        }
    }

    //print results
    printf("|\n| >> Count: %d", pass);
    pass = 0; //reset pass grade counter

    //function call - try again/back to operations
    again();
}

void countFail() //show number of FAILING grades (50-74)
{
    printf("|\n===================== [E.] Count Number of FAIL Grades ======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //iteration - check how many elements satisfy the condition
    for(int i = 0; i < 8; i++)
    {
        if(grade[i] >= 50 & grade[i] <= 74)
        {
            fail++; //+1 to fail (failing grades)
        }
    }

    //print results
    printf("|\n| >> Count: %d", fail);
    fail = 0; //reset fail grade counter

    //function call - try again/back to operations
    again();
}

void exitProgram() //terminates the program
{
    printf("|\n===========================================================================\n");
    printf("|\n| >> Thank you! Press E to exit...");

    //starting point -> go-to statement (exitProgram)
    start:
    fflush(stdin); //flush output buffer of the stream
    printf("\n| >> ");
    scanf("%c", &terminate);

    switch (terminate) //verify terminate(user input) if the user inputted E or e
    {
        case 'E':
        case 'e':
            printf("|\n| >> Program Terminated.");
            exit(0); //terminated program without error/interruptions
            break;
        
        default:
        printf("|\n| >> Program still running.");
            goto start; //back to starting point (exitProgram)
            break;
    }
}