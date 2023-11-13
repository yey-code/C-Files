//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomGrade(int grade) //generate random grades
{
    grade = (rand() % (100 - 50 + 1)) + 50; //random number from 50 - 100

    return grade;    
}

void arrayList(int *gradeArray, int size) //show array elements
{
    printf("|\n|============================================================================");
    printf("\n| LIST OF GRADES: \n| >> \t");

    for(int i = 0; i < size; i++)
    {
        printf("%d\t", *gradeArray);
        gradeArray++;
    }
    printf("\n"); 
}

void searchGrade(int *gradeArray, int size) //search occurences of grade
{
    int searchInput = 0, gradeOccur = 0; //for searchGrade()

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
    for (int i = 0; i < size; i++)
    {
        if(searchInput == *gradeArray)
        {
            gradeOccur++; //+1 to occurence(s)
        }
        gradeArray++;
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
}

void sortGrade(int *gradeArray, int size) //sort grades in ascending/descending order
{
    int sortOpe = 0, num = 0; //for sortGrade()
    
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

            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if(*(gradeArray + j) < *(gradeArray + i))
                    {
                        //interchange values
                        num = *(gradeArray + i);
                        *(gradeArray + i) = *(gradeArray + j);
                        *(gradeArray + j) = num;
                    }
                }
            }
            for (int i = 0; i < size; i++)
            {
                printf("%d\t", *gradeArray); //print array in new order
                gradeArray++;
            }
            break;

        //descending order
        case 2:
            printf("|\n| Sort in Descending Order: \n| >> \t");

            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if(*(gradeArray + j) > *(gradeArray + i))
                    {
                        //interchange values
                        num = *(gradeArray + j);
                        *(gradeArray + j) = *(gradeArray + i);
                        *(gradeArray + i) = num;
                    }
                }
                
            }
            for (int i = 0; i < size; i++)
            {
                printf("%d\t", *gradeArray); //print array in new order
                gradeArray++;
            }
            break;    
        
        //if user input is not [1] or [2]
        default:
            printf("|\n| >> Invalid Input!! ~ Please enter a valid operation.\n");
            goto start; //back to starting point (sortGrade)
            break;
    }
}

int computeAverage(int ave, int *gradeArray, int size) //compute average grade
{
    int sum = 0;

    printf("|\n====================== [C.] Compute the Average Grade =======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //computation of average grade
    for (int i = 0; i < size; i++)
    {
        sum+=*(gradeArray + i);
    }

    ave = sum/8;

    return ave;
}

int countPass(int count, int *gradeArray, int size) //show number of PASSING grades (75-100) 
{
    printf("|\n===================== [D.] Count Number of PASS Grades ======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //iteration - check how many elements satisfy the condition
    for(int i = 0; i < size; i++)
    {
        if(*(gradeArray + i) >= 75 & *(gradeArray + i) <= 100)
        {
            count++; //+1 to pass (passing grades)
        }
    }

    return count;
}

int countFail(int count, int *gradeArray, int size) //show number of FAILING grades (50-74)
{
    printf("|\n===================== [E.] Count Number of FAIL Grades ======================\n");
    printf("|                          ><><><><><><><><><><><><><><\n");

    //iteration - check how many elements satisfy the condition
    for(int i = 0; i < 8; i++)
    {
        if(*(gradeArray + i) >= 50 & *(gradeArray + i) <= 74)
        {
            count++; //+1 to fail (failing grades)
        }
    }

    return count;
}

void exitProgram() //terminates the program
{
    char terminate;

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

//code starts here
void main()
{
    //array declaration
    int grade[8];

    //variable declaration
    int size = sizeof(grade) / sizeof(grade[0]); //for the array grade[]
    int randomNum = 0; //for random grades
    int average = 0; //for computeAverage()
    int pass = 0, fail = 0; //for countPass() and countFail()

    char ope = '\n'; //for operations()
    char tryAgain; //for try again

    // === code starts here... === //

    srand(time(0)); //random number generator every code execution
    
    for(int i = 0; i < size; i++)
    {
        grade[i] = randomGrade(randomNum); //insert random numbers to array
    }

    printf("========================= GRADE OPERATIONS PROGRAM ==========================\n");
    printf("|                       ><><><><><><><><><><><><><><\n");

    arrayList(grade, size);//print random grades

    //starting point -> go-to statement (operations)
    chooseOpe:
    fflush(stdin);
    printf("|\n| Operations: \n");
    printf("| A. Search for Specific Grade\n| B. Sort Grades\n| C. Compute the Average Grade\n| D. Count Number of PASS Grades\n| E. Count Number of FAIL Grades\n| F. Exit\n");
    printf("|\n| > Enter the letter that corresponds to the operation: ");
    scanf("%c", &ope);

    //===================== functions for operations =====================
    
    //verify ope (user input) - what option did the user chose

    if(ope == 'A' || ope == 'a')
    {
        searchGrade(grade, size); //search occurences of grade

        //goto statement (end) - try again/back to operations
        goto end;
    }

    if(ope == 'B' || ope == 'b')
    {
        sortGrade(grade, size); //sort grades in ascending/descending order

        //goto statement (end) - try again/back to operations
        goto end;
    }

    if(ope == 'C' || ope == 'c')
    {
        printf("|\n| >> Average grade: %d%%", computeAverage(average, grade, size));
        average = 0; //reset average grade to 0

        //goto statement (end) - try again/back to operations
        goto end;
    }

    if(ope == 'D' || ope == 'd')
    {
        //print results
        printf("|\n| >> Count: %d", countPass(pass, grade, size));
        pass = 0; //reset pass grade counter

        //goto statement (end) - try again/back to operations
        goto end;
    }

    if(ope == 'E' || ope == 'e')
    {
        //print results
        printf("|\n| >> Count: %d", countFail(fail, grade, size));
        fail = 0; //reset fail grade counter

        //goto statement (end) - try again/back to operations
        goto end;
    }

    if(ope == 'F' || ope == 'f')
    {
        exitProgram(); //terminates the program
    }

    else
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a valid operation.\n");
        goto chooseOpe; //back to starting point (operations)
    }

    end:
    printf("\n|\n===========================================================================\n");
    
    //starting point -> go-to statement (again)
    start:
    fflush(stdin);
    printf("|\n| > Press Y to return to Operations, press N to try again: ");
    scanf("%c", &tryAgain);
    
    //verify tryAgain (user input)
    if (tryAgain == 'Y' || tryAgain == 'y')
    {
        goto chooseOpe; //back to starting point (operations)
    }

    else if (tryAgain == 'N' || tryAgain == 'n')
    {
        arrayList(grade, size);//print random grades

        switch (ope)
        {
            case 'A':
            case 'a':
                searchGrade(grade, size); //search occurences of grade

                //goto statement (end) - try again/back to operations
                goto end;
                break;
            
            case 'B':
            case 'b':
                sortGrade(grade, size); //sort grades in ascending/descending order

                //goto statement (end) - try again/back to operations
                goto end;
                break;

            case 'C':
            case 'c':
                printf("|\n| >> Average grade: %d%%", computeAverage(average, grade, size));
                average = 0; //reset average grade to 0

                //goto statement (end) - try again/back to operations
                goto end;
                break;

            case 'D':
            case 'd':
                //print results
                printf("|\n| >> Count: %d", countPass(pass, grade, size));
                pass = 0; //reset pass grade counter

                //goto statement (end) - try again/back to operations
                goto end;
                break;

            case 'E':
            case 'e':
                //print results
                printf("|\n| >> Count: %d", countFail(fail, grade, size));
                fail = 0; //reset fail grade counter

                //goto statement (end) - try again/back to operations
                goto end;
                break;

            case 'F':
            case 'f':
                exitProgram(); //terminates the program
                break;
        }
    }

    else
    {
        printf("|\n| >> Invalid Input!! ~ Please enter a valid option.\n");
        goto start; //back to starting point (again)
    }
}