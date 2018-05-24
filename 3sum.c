/**
 * 3SUM Solution
 * NOTE: THIS IMPLEMENTATION ONLY REQUIRES
 * THE NUMBER OF SET ELEMENTS AS INPUT 🙂 THE 
 * PROGRAM WILL GENERATE THE SET FOR YOU AND 
 * SHOW SOLUTIONS IF ANY.
 *
 * In computational complexity theory, the 
 * 3SUM problem asks if a given set of n real 
 * numbers contains 3 elements that sum to 0
 *
 * A naïve solution works in O(N²) time, and 
 * research efforts have been exploring the 
 * lower complexity bound for some time now.
 *
 * Input for this problem is a set of
 * integers.
 Example:
 -6, -1, 0, 1, 2, -1
 * 
 * Your program should display triplets of 
 * numbers that sum to 0 on separate lines.
 * If the set contains no values that sum to 
 * zero, indicate so with a simple "No 
 * triplets found" message.
The example input 
 * from above should generate the following 
 * output:
 * -1, 0, 1
 * -1, -1, 2
 */
 
#include <stdio.h> //scanf, printf 
#include <stdlib.h> //NULL, rand, srand
#include <time.h> //time structure for random seed
#define DEFAULT 10

int numcmp(const void *, const void *);
int main()
{
    srand(time(NULL));
    int a,b,c,start,end,i=0,n,sets=0;
    printf("Enter number of elements in the set: ");
    if(scanf("%d",&n) < 1)
        n = DEFAULT;
    printf("\n");
    
    n = n < 3 ? DEFAULT : n;
    int *set = malloc(n*sizeof(int));
    if(!set)
    {
        perror("Fatal error: No memory to use.");
        return 1;
    }
    //fill and show the array contents
    printf("Set elements are: [");
    for(;i<n;i++)
    {
        set[i] = (rand() % (2*n + 1)) - n;
        printf(i != n-1 ? "%d," : "%d]" , set[i]);
    }
    printf("\n\n");
    
    //first sort the elements. Using a quicksort O(N²) time (worst case), which does not change the overall complexity of the code from O(N²)
    qsort (set, n, sizeof(int), numcmp);
    for(i=0; i<n-2; i++)
    {
        a = set[i];
        start = i+1;
        end = n-1;
        // Binary search for all triplet combinations summing to zero.
        while (start < end)
        {
            b = set[start];
            c = set[end]; 
            if (a+b+c == 0)
            {
                printf("[%d, %d, %d]\n", a, b, c);
                sets++; 
                if (b == set[start + 1])
                    start++; 
                else
                    end--;
             }else if (a+b+c > 0)
                 end--; 
             else 
                 start++;
        }//end while
    }//end for
    if(!sets)
        printf("No triplets found.");
    free(set);
    return 0;
}

/*
 * Compares 2 integers a & b and returns 
 * a value indicating which is larger or if 
 * they are the same.
 * @param a,b 2 integers to compare
 * @return positive int if a>b, 0 if a==b, 
 * negative int if a<b
 */
int numcmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
/**
 * @uthor: Ace
 * Version: 20180329 - Released
 *          20180330 - fixed comparison 
 * function bug. Mainly a result of me typing 
 * too fast. (Thanks @gordie).
 *          20180402 - Added default case in 
 * case user enters value less than 3. Added 
 * handler in case integer cannot be read.
 * Bugs: None known
 */
