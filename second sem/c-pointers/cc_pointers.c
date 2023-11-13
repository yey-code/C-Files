#include <stdio.h>
#include <conio.h>

int getHighest(int *g1, int *g2, int *g3)
{
    int h = *g1;

    if(h < *g2)
    {
        h = *g2;
    }

    if(h < *g3)
    {
        h = *g3;
    }
    
    return h;
}

int getLowest(int *g1, int *g2, int *g3)
{
    int l = *g3;

    if(l > *g1)
    {
        l = *g1;
    }

    if(l > *g2)
    {
        l = *g2;
    }

    return l;
}

int computeAverage(int *g1, int *g2, int *g3)
{
    int ave = (*g1 + *g2 + *g3) / 3;

    return ave; 
}

int remarks(int average)
{
    if(average >= 75 && average <= 100)
        printf("Remarks: PASSED!\n");
    else if(average >= 50 && average <= 74)
        printf("Remarks: FAILED!\n");
}

void main()
{
    int i, quizGrade1, quizGrade2, quizGrade3;

    printf("Enter quiz grade 1: ");
    scanf("%d", &quizGrade1);

    printf("Enter quiz grade 2: ");
    scanf("%d", &quizGrade2);

    printf("Enter quiz grade 3: ");
    scanf("%d", &quizGrade3);

    printf("\nHighest is: %d%%\n", getHighest(&quizGrade1, &quizGrade2, &quizGrade3));

    printf("Lowest is : %d%%\n", getLowest(&quizGrade1, &quizGrade2, &quizGrade3));

    printf("\nAverage grade: %d%%\n", computeAverage(&quizGrade1, &quizGrade2, &quizGrade3));

    remarks(computeAverage(&quizGrade1, &quizGrade2, &quizGrade3));

    getch();
}