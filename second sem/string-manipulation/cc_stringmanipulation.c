#include <stdio.h>
#include <string.h>
#include <conio.h>

char stringVal[100], ch;
int int_ch;

//function declaration
int letterCounter(); 
int digitCounter();
int spaceCounter();

void main()
{
    // ===== get string value and paste every character in a new line ===== //
    printf("Coding Challenge\n");
    printf("Enter string value: ");
    scanf("%[^\n]s", &stringVal);
    printf("\n");

    printf("\n");
    printf("Number of Letters: %d\n", letterCounter());
    printf("Number of Digits: %d\n", digitCounter());
    printf("Number of White Spaces: %d\n", spaceCounter());

    getch();
}

//function definition
int letterCounter()
{ 
    int a = 0;

    for(int i=0; i < strlen(stringVal); i++)
    {
        ch = stringVal[i];
        int_ch = (int)(ch);
        
        if((int_ch >= 65 && int_ch <= 90) || (int_ch >= 97 && int_ch <= 122))
        {
            a++;
        }
    }

    return a;
}

int digitCounter()
{
    int a = 0;

    for(int i=0; i < strlen(stringVal); i++)
    {
        ch = stringVal[i];
        int_ch = (int)(ch);
        
        if(int_ch >= 48 && int_ch <= 57)
        {
            a++;
        }
    }

    return a;
}

int spaceCounter()
{
    int a = 0;

    for(int i=0; i < strlen(stringVal); i++)
    {
        ch = stringVal[i];
        int_ch = (int)(ch);
        
        if(int_ch == 32)
        {
            a++;
        }
    }

    return a;
}
