/*
Program Title: Coding Challenge #2.1
Program Description: From the sequence of number from 10 down to 1, extract and display all even numbers.
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
    printf("\nEVEN NUMBERS\n");
    printf("\nThe even numbers from 10 down to 1 are: ");
    //declare a for loop statement
    for(int i = 10; i >= 1; i--)
    {
        //test i if it will return a remainder if divided by 2
        if(i%2==0)
        {
            //print even numbers
            printf("%i ", i);
        }
    }

    //end statement
    return 0;
}