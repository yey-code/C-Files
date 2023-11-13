#include <stdio.h> //include the standard input/output library functions
void main() //declare a void type main function
{
    int ctr, x=8, y=5, z=2; //declare initial variables
    x += (y+z); //x = x + (y+z) -> x = 8 + (5+2) x=15
    x -= y; //x = x - y -> x = 15 - 5 x=10
    y *= (x+y); //y = y*(x+y) -> y = 5*(10+5) y=75

    //ctr = 75   75 >=0    ctr = 75-12 
    for(ctr = y; ctr >= 0; ctr -= 12)
    {
        z += x; //z = z + x -> z = 2+10 z=12
        if(z > ctr) // 12 > ctr
        z += 15; //z = z+15 -> z = 70 +15 -> z=85
        else // 12 < ctr
        z *= 5; //z = z * 5 -> z = 12 * 5 z=60
        printf("%d\n",z);
    }

    printf("The Last Value of X is %d\n",x);
    printf("The Last Value of y IS %d\n",y);
}   