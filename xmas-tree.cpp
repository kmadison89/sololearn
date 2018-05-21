#include <stdio.h>
#include <stdlib.h> //rand & srand
#include <time.h> //srand seed

#define ROW 25
#define COL 20

/**
 * So after a bad 1st attempt, (I kind of did 
 * it on the fly, sorry) I decided to sit down 
 * and hash this out the old school way. I 
 * treat the console as a 2D plane, (x,y 
 * representing rows and columns).
 * @uthor: @ce
 * Bugs: Calculations may seem a bit off in 
 * some displays, but I did the best of my 
 * ability to compensate.
 * Version:
 * 0.0.0.0: Initial
 * 0.0.0.1: Modified the display
 * 0.0.0.2: 'Randomized' snow and decorations
 * 0.0.0.3: Minor cleanup
 * 0.0.0.4: New decorations added
 */

//Helper function to calculate absolute value. Otherwise would need to use math library
int absVal(int n)
{
    return n > 0 ? n : 0 - n;
}

int main(void)
{
    srand(time(NULL));
    //Iterate every point of the row and draw if the point is a part of the overall X-mas tree.
    int absX;
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < ROW; x++)
        {
            absX = x - ROW / 2;
            //Condition checks coordinate to the top middle and bottom sections of the tree, as well as the base (the stem or trunk if you prefer).
            if((y <= COL/4 && absVal(absX) <= y) || (COL/5 <= y && y <= (3*COL)/5 && absVal(absX) <= y -  COL/5) || (COL/2 <= y && y <= COL && absVal(absX) <= y - COL/2) || (COL/2 <= y && absVal(absX) < ROW/10))
                if(y < ROW - 4)
                    printf("%c", rand()%100 > 15 ? '*' : rand()%100 > 50 ? '@' : rand()%100 > 50 ? '$' : '&');
                else 
                    printf("%c", '*');
            else
                printf("%c", rand()%100 > 67 ? '.' : ' ');
        }
        printf("\n");
    }
    printf("\n\nHAPPY HOLIDAYS FROM MY FAMILY TO YOURS! ~~ACE~~");
    return 0;
}
