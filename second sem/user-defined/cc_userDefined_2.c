#include <stdio.h>

//function declaration
void showTable(int g[3][3]);
int comAverage(int g[][3], int row_index);
void displayRemarks(int average);

//variable declaration
int r, c, total;

//array declaration
int grade[3][3] = 
    {
        {90, 98, 76},
        {76, 88, 77},
        {87, 57, 65},
    };

int main()
{
    //display table of grades
    printf("Q1\tQ2\tQ3\tAverage\tRemarks\t\n");
    showTable(grade);
    
    return 0;
}

void showTable(int g[3][3])
{
    for(r = 0; r < 3;r++)
    {
        for(c = 0; c < 3; c++)
        {
            printf("%i\t", grade[r][c]);
        }
        printf("%d", comAverage(grade, r));
        displayRemarks(comAverage(grade, r));
    }
}

int comAverage(int g[][3], int row_index)
{
    total = 0;
    for(c = 0; c < 3; c++)
    {    
        total += grade[row_index][c];
    }
    return(total/3);
}

void displayRemarks(int average)
{
    if(average >= 75 && average <= 100)
        printf("\tPASSED!\n");
    else if(average >= 50 && average <= 74)
        printf("\tFAILED!\n");
}