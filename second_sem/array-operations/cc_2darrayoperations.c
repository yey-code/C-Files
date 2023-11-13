#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function declaration
void randomBingoNum();
void bingoTable();
void patternTable();
void again();

// ===== Pattern Functions ===== // 
void patt1();
void patt2();
void patt3();
void patt4();
void patt5();
void patt6();
void patt7();
void patt8();
void patt9();
void patt10();

//variable declarations
int bingo[5][5]; //bingo array
int usedBingoNum[5][5] = {{0}}; //array for unique random number (checking) 
int r, c, min, max, bingoNum, patternInput;
char tryAgain;

int main()
{
    srand(time(0)); //random number generator every execution
    randomBingoNum();

    bingoTable(); //UI starts here...
    return 0;
}

//===================== user-defined functions starts here... ===================== //

void randomBingoNum() //insert random numbers to the bingo card
{
    for (r = 0; r < 5; r++)
    {
       for (c = 0; c < 5; c++)
       {
            min = c * 15 + 1;
            max = (c + 1) * 15;

            do
            {
                bingoNum = (rand() % (max - min + 1)) + min; //generates random number that depends upon the column
            } 
            while(usedBingoNum[bingoNum][bingoNum]); //checks random number if unique
                
            usedBingoNum[bingoNum][bingoNum] = 1;
            bingo[r][c] = bingoNum; //insert random number in the bingo array
       }
    }
    
    bingo[2][2] = 0; //set the middle to 0
}

void bingoTable() //print the bingo card
{
    printf("=============================== BINGO SOSYAL APP ================================\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
       for (c = 0; c < 5; c++)
       {
            if(bingo[r][c] == 0)
            {
                printf("|\tFREE\t|"); //print FREE in the middle
            }
            else
            {
                printf("|\t%d\t|", bingo[r][c]); //print the unique random number of the bingo card
            }
       }
       printf("\n");
    }
    patternTable(); //prints the table of patterns then prompts the user to input a number
}

void patternTable() //prints the table of patterns then prompts the user to input a number
{
    // === PATTERN 1 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #1: Top Row                                                        |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 0)
            {
                printf("|\t*\t|"); //prints asterisk on the 1st row
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 2 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #2: Bottom Row                                                     |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 4)
            {
                printf("|\t*\t|"); //prints asterisk on the 5th row
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 3 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #3: Middle Row                                                     |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c != 2)
            {
                printf("|\t*\t|"); //prints asterisk on the 3rd row
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 4 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #4: Left Column                                                    |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 0)
            {
                printf("|\t*\t|"); //prints asterisk on the 1st column
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 5 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #5: Right Column                                                   |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 4)
            {
                printf("|\t*\t|"); //prints asterisk on the 5th column 
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 6 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #6: Middle Column                                                  |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 2 && r != 2)
            {
                printf("|\t*\t|"); //prints asterisk on the 3rd column
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 7 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #7: From Left to Right Diagonal                                    |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r == c)
            {
                printf("|\t*\t|"); //prints asterisk from left [0][0] to right [4][4]
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 8 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #8: From Right to Left Diagonal                                    |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r+c == 4)
            {
                printf("|\t*\t|"); //prints asterisk from right [0][4] to right [4][0]
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 9 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #9: Square Top-Left Rows                                           |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r < 2 && c < 2)
            {
                printf("|\t*\t|"); //prints asterisk on the rows and columns that has 0 and 1 location
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    // === PATTERN 10 === //
    printf("=================================================================================\n");
    printf("| >> Pattern #10: Square Bottom-Right Rows                                      |\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r > 2 && c > 2)
            {
                printf("|\t*\t|"); //prints asterisk on the rows and columns that has locations greater than 2
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining areas
            }
        }
        printf("\n");
    }

    //prompts the user to input their desired pattern number
    printf("=================================================================================\n");
    //starting point -> go-to statement (patternTable)
    start:
    fflush(stdin); //flushes output buffer of the stream
    printf("|                                                                               |\n");
    printf("| > Enter Pattern Number, [1 - 10]: ");
    while(scanf("%d", &patternInput) != 1) //verify user input if it is a number
    {
        printf("|                                                                               |\n");
        printf("| >> Invalid Input! ~ Please input a valid number.                              |\n");
        printf("|                                                                               |\n");
        printf("| > Enter Pattern Number, [1 - 10]: ");
        while(getchar() != '\n');
    }

    switch (patternInput) //verify patternInput on what option did the user chose
    {
        //prints pattern results
        case 1:
            patt1(); 
            break;

        case 2:
            patt2();
            break;

        case 3:
            patt3();
            break;

        case 4:
            patt4();
            break;

        case 5:
            patt5();
            break;

        case 6:
            patt6();
            break;

        case 7:
            patt7();
            break;

        case 8:
            patt8();
            break;

        case 9:
            patt9();
            break;

        case 10:
            patt10();
            break;
        
        //if the user chose a different option
        default:
            printf("|                                                                               |\n");
            printf("| >> Invalid Input! ~ Please input a valid option.                              |\n");
            goto start;
            break;
    }
}

void again() //try again/terminate the program
{
    printf("=================================================================================\n");
    //starting point -> go-to statement (again)
    start:
    fflush(stdin); //flushes output buffer of the stream
    printf("|                                                                               |\n");
    printf("| > Press [Y] to try again, press [N] to exit: ");
    scanf("%s", &tryAgain);

    if(tryAgain == 'Y' || tryAgain == 'y')
    {
        patternTable(); //prints the table of patterns then prompts the user to input a number
    }

    //terminates the program
    else if(tryAgain == 'N' || tryAgain == 'n')
    {
        printf("|                                                                               |\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("| >> Thanks for using the program!                                              |\n");
    }
    
    //back to starting point if the user chose different option
    else
    {
        printf("|                                                                               |\n");
        printf("| >> Invalid Input! ~ Please input a valid number.                              |\n");
        goto start;
    }
}


//===================== function of patterns starts here... ===================== //

void patt1() //prints pattern 1 result(based on the bingo table) - TOP ROW
{
    printf("| >> Pattern #1: Top Row                                                        |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 0)
            {
                printf("|\t%d\t|", bingo[r][c]); //print top row numbers
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt2() //prints pattern 2 result(based on the bingo table) - BOTTOM ROW
{
    printf("| >> Pattern #2: Bottom Row                                                     |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 4)
            {
                printf("|\t%d\t|", bingo[r][c]); //print bottom row numbers
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt3() //prints pattern 3 result(based on the bingo table) - MIDDLE ROW
{
    printf("| >> Pattern #3: Middle Row                                                     |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c != 2)
            {
                printf("|\t%d\t|", bingo[r][c]); //print middle row numbers
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt4() //prints pattern 4 result(based on the bingo table) - LEFT COLUMN
{
    printf("| >> Pattern #4: Left Column                                                    |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 0)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers in the left column
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt5() //prints pattern 5 result(based on the bingo table) - RIGHT COLUMN
{
    printf("| >> Pattern #5: Right Column                                                   |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 4)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers in the right column
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt6() //prints pattern 6 result(based on the bingo table) - MIDDLE COLUMN
{
    printf("| >> Pattern #6: Middle Column                                                  |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(c == 2 && r != 2)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers in the middle column 
            }

            else if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt7() //prints pattern 7 result(based on the bingo table) - FROM LEFT TO RIGHT DIAGONAL 
{
    printf("| >> Pattern #7: From Left to Right Diagonal                                    |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r == c)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers from left [0][0] to right [4][4]
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt8() //prints pattern 8 result(based on the bingo table) - FROM RIGHT TO LEFT DIAGONAL
{
    printf("| >> Pattern #8: From Right to Left Diagonal                                    |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r+c == 4)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers from right [0][4] to right [4][0]
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt9() //prints pattern 9 result(based on the bingo table) - SQUARE TOP-LEFT ROWS
{
    printf("| >> Pattern #9: Square Top-Left Rows                                           |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r < 2 && c < 2)
            {
                printf("|\t%d\t|", bingo[r][c]);  //print numbers on the rows and columns that has 0 and 1 location
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    }

    again(); //try again/terminate the program
}

void patt10() //prints pattern 10 result(based on the bingo table) - SQUARE BOTTOM-RIGHT ROWS
{
    printf("| >> Pattern #10: Square Bottom-Right Rows                                      |\n");
    printf("|_______________________________________________________________________________|\n");
    printf("|\tB\t||\tI\t||\tN\t||\tG\t||\tO\t|\n");
    printf("|---------------||--------------||--------------||--------------||--------------|\n");
    for (r = 0; r < 5; r++)
    {
        for(c = 0; c < 5; c++)
        {
            if(r == 2 && c == 2)
            {
                printf("|\tFREE\t|"); //prints FREE in the middle
            }

            else if(r > 2 && c > 2)
            {
                printf("|\t%d\t|", bingo[r][c]); //print numbers on the rows and columns that has locations greater than 2
            }

            else
            {
                printf("|\t \t|"); //prints white space in the remaining spaces
            }
        }
        printf("\n");
    } 

    again(); //try again/terminate the program
}