#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 50

int main()
{
    // ===== scanf with scanset ===== //
    /*char name[20];

    printf("Enter your complete name: ");
    scanf("%[^\n]s", &name);

    printf("Greetings:\nHello %s, Welcome to String Manipulation in C!", name);

    getch();*/


    
    // with defined size
    /*char str1[50] = "I love PUPSMB!";
    printf("\nwith defined size: \n%s\n\n", str1);

    // undefined size
    char str2[] = "I love PUPSMB!";
    printf("with undefined size: \n%s\n\n", str2);

    //in char val, with size
    char str3[50] = {'I', ' ', 'l', 'o', 'v', 'e', ' ', 'P', 'U', 'P', 'S', 'M', 'B', '!', '\0'};
    printf("in character value with defined size: \n%s\n\n", str3);

    //in char val, without size
    char str4[] = {'I', ' ', 'l', 'o', 'v', 'e', ' ', 'P', 'U', 'P', 'S', 'M', 'B', '!', '\0'};
    printf("in character value with undefined size: \n%s\n\n", str4);



    // ===== fgets ===== //
    char str[MAX];
    printf("Enter string value: ");
    fgets(str, MAX, stdin);
    printf("\nString is: \n");
    puts(str);

    // ===== concatinate ===== //
    char str1[50]= "Hello";
    char str2[50]= "World";
    char str3[50];

    strcat(str1, " ");
    strcat(str1, str2);
    puts(str1);

    // ===== compare ===== //
    char str1[50] = "h";
    char str2[50] = "H";

    int result = strcmp(str1, str2);
    printf("%d", result);

    //returns 1 if x<y
    //returns 0 if x=y
    //returns -1 if x>y*/

    char str1[50] = "hello";
    char str2[50] = "H";

    printf("%s", strchr(str2, 'h'));
    printf("%s", strstr(str1, "hello"));

    getche();
}