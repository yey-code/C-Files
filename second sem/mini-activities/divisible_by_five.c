/*
Program Title: Coding Challenge # 2.2
Program Description: From the sequence of number from 100 down to 1, extract and display all numbers divisible by 5.
Date Created : April 03, 2023
Date Completed: April 03, 2023

Group  : De Vera, Arvin T.
         Dela Cruz, Lawrence Anderson
         Dela Cruz, Eugene
         
Course,Year & Sec.: BSIT 1-2
*/

#include <stdio.h> //include the standard input/output library functions
int main() //declare a main function
{
    printf("\nNUMBERS DIVISBLE BY 5\n");
    printf("\nThe numbers divisible by 5 from 100 down to 1 are: ");
    //declare a for loop statement
    for (int i = 100; i >= 1; i--)
    {
        //test i if it will return a remainder if divided by 5
        if(i%5==0)
        {
            //print numbers that are divisible by 5
            printf(" %i ", i);
        }
    }

    //end statement
    return 0;
}