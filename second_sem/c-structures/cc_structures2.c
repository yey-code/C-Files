#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Books
{
    char title[50];
    char author[50];
    int book_id[50];
};

struct Books book;

void main()
{
    int ope;

    printf("Book Record\n");
    printf("Operation:\n[1] Store\n[2] Modify\n[3] Delete\n[4] Display\n");
    printf("Enter operation to perform: ");
    scanf("%d", &ope);

    switch (ope)
    {
    case 1:
        printf("Enter Book ID Number: ");
        scanf("%d", &book.book_id);

        fflush(stdin);
        printf("Enter Book Title: ");
        scanf("%[^\n]s", &book.title);

        fflush(stdin);        
        printf("Enter Book Author: ");
        scanf("%[^\n]s", &book.author);

        printf("\n\nPress any key to continue...\n\n");

        getch();

        printf("Book ID Number: %d\n", book.book_id);
        printf("Book Title: %s\n", book.title);
        printf("Book Author: %s", book.author);
        break;
    
    default:
        break;
    }
    
    getch();
}