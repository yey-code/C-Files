#include <stdio.h>
#include <string.h> //strcpy function => string manipulation
#include <conio.h> //getch();

struct Books
{
    char id[5];
    char title[50];
    char author[30];
} book[5];

void main()
{
    strcpy(book[0].id, "1001");
    strcpy(book[0].title, "Introduction to Computer");
    strcpy(book[0].author, "Juan Dela Cruz");

    strcpy(book[1].id, "1002");
    strcpy(book[1].title, "Introduction to C Programming");
    strcpy(book[1].author, "John Cruz");

    strcpy(book[2].id, "1003");
    strcpy(book[2].title, "Introduction to C# Programming");
    strcpy(book[2].author, "Mary Santos");

    strcpy(book[3].id, "1004");
    strcpy(book[3].title, "Introduction to PHP Programming");
    strcpy(book[3].author, "Ely Salvador");

    strcpy(book[4].id, "1005");
    strcpy(book[4].title, "Introduction to Java Programming");
    strcpy(book[4].author, "Maria David");

    for(int i = 0; i < 5; i++)
    {
        printf("Book ID: ");
        puts(book[i].id);

        printf("Book Title: ");
        puts(book[i].title);
    
        printf("Book Author: ");
        puts(book[i].author);

        printf("\n");
    }
    
    getch();
}