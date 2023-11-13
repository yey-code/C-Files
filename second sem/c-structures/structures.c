#include <stdio.h>
#include <conio.h>

/*struct Points  // => solution 1
{
    int x;
    int y;
} p;*/       

struct Points // => solution 2
{
    int x; // member variable 1
    int y; // member variable 2
};

struct Points p; //variable 

/*struct Points //solution 3
{
    int x;
    int y;
};*/

void main()
{
    // struct Points p; => solution 3

    //assign store value = solution 1
    p.x = 10;
    p.y = 5;

    // solution 2 = struct Points p = {11, 5};
    // solution 3 = struct Points p = {.y = 10, .x =5};
    
    int s = p.x + p.y;

    printf("point x = %d\n", p.x);
    printf("point y = %d\n", p.y);
    printf("%d", s);
    getch();
}