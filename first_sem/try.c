#include <stdio.h>

int main() 
{
    char fname[20], lname[20];

    printf("Enter your first name: ");
    scanf("%s", fname);

    printf("Enter your last name: ");
    scanf("%s", lname);

    printf("So your name is %s %s", fname, lname);
    
    /*int num;
    int sum = 0;

    for (int i = 0; i < 3; i++) 
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        sum = sum + num;
    }

    printf("the sum is %d\n", sum);*/
    



    return 0;


}