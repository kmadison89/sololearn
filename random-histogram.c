#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * A histogram of random numbers in the 
 * range 0-9 based on a number of trials. 
 * @uthor: Ace
 * Bugs: None known
 * Notes: For more trials, increase the LIMIT value. To test more numbers, increase MAXRAND
 * Best view is on PC, but mobile is accomodated for.
 * @Version:
 * 20180131 - Initial release
 * 20180201 - Fixed issue with driver that would cause memory access violations if MAXRAND changed.
 */

#define LIMIT 500 //max number of trials
#define MAXRAND 10 //maximum random value

/*
 * Generate the random numbers and histogram them.
 * @param table - The array we intend to populate
 */
void generateTable(int *table)
{
    int j, point;
    for (j=0; j<LIMIT; j++)
    {
        point = rand() % MAXRAND;
        table[point]++ ;
    }//end for
}

/*
 * Find the maximum value in the histogram. 
 * This is the number of times that the most frequently occuring number appeared during generation.
 * @param table - The table of values that holds our data
 * @return - The number of times the most frequently occuring value appeared 
 */
int findMax(int *table)
{
    int i;
    int max = table[0];
    for (i=1; i<MAXRAND; i++)
        max = table[i] > max ? table[i] : max;
    return max;
}

/*
 * Plot the histogram
 * @param max - The maximum number of occurences
 * @param table - The data to display
 */
void plotHistogram(int max, int *table)
{
    const int barWidth = 50; //the number of symbols that span the page
    int i, symbol;
    printf("Based on %d randomly generated values...\n", LIMIT);
    for (i=0; i<MAXRAND; i++)
    {
        printf("%3d (%d times): ", i, table[i]);
        //The number of stars to print for a particular histogram value is computed by the expression: (table[i]*barWidth)/max
        for (symbol=0; 
        symbol< (table[i]*barWidth)/max; 
        symbol++)
            printf("*");
        printf("\n");
    }
} 

int main(void)
{
    int *table = malloc(MAXRAND*sizeof(int));
    if(!table)
    {
        perror("malloc failed!");
        exit(1);
    }
    int i;
    for(i=0; i<MAXRAND; i++)
    {
        table[i] = 0;
    }
    int max;
    srand(time(NULL));
    generateTable(table);
    max = findMax(table);
    plotHistogram(max, table);
    free(table);
    return 0;
}
