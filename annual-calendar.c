/**
 * Displays a calendar for a given year
 * @Input: year: Year to generate calendar 
 *         for
 * @OnError: If no year is entered, either 
 *           the current year is used or the
 *           year this code was written if 
 *           there's a calculation error
 */
#include <stdio.h>
#include <time.h>
#define DEFAULT 2018

/*
 * Remember the rhyme
 * 30 days past September,
 * April, June, and November,
 * February has 28 alone
 * All the rest have 31
 * Except in Leap Year, that's the time
 * When February's Days are 29
 * NOTE: –Added 'dummy' value at index 0 in 
 *       order to directly index by months
 *       –Leap year is addressed later in the 
 *       code
 */
int monthMaxDays[]= {0,31,28,31,
                     30,31,30,31,
                     31,30,31,30,
                     31};

char *months[]= {" ", "Jan", "Feb", "Mar",
                 "Apr", "May", "Jun",  "Jul",
                 "Aug", "Sept", "Oct", "Nov",
                 "Dec" };

/*
 * Utility function returning a valid year if 
 * the user does not provide one. Uses the 
 * system time to return the current year
 * if possible
 * @return The current year, or the year 
 * this code was written if not possible
 */ 
unsigned int currentYear(void)
{
    char yr[5];
    time_t curr;
    struct tm* time_info;
    time(&curr);
    time_info = localtime(&curr);
    int year = 0;
    strftime(yr, 5, "%Y", time_info);
    return sscanf(yr, "%d", &year)==1 ? year : DEFAULT;
}

/*
 * Reads in a year from the user if possible
 * @return User int representing calendar 
 *         year or one from currentYear() if  *          not valid
 */
unsigned int readYear(void)
{
    int year;
    printf("Year? (Ex: 2018): ");
    return (scanf("%d", &year) == 1) && year >-1 ?  year : currentYear();
}

/*
 * Determine the day of the week of the 
 * calendar year
 * @param year: int representing the year to 
 *              check
 * @return The starting day of the week for 
 *         the calendar year
 */
int getStart(int year)
{
    int startDay;
    int delta1, delta2, delta3;
    delta1 = (year - 1.)/ 4.0;
    delta2 = (year - 1.)/ 100.;
    delta3 = (year - 1.)/ 400.;
    startDay = (year + delta1 - delta2 + delta3) % 7;     
    return startDay;
}

/*
 * Utility function to determine if year is
 * a leap year and adjust Feb's days if so
 * @param year: int representing the year to 
 *              check
 */
void leapYear(int year)
{
    monthMaxDays[2] = ((!(year % 4) && (year % 100)) || !(year % 400)) ? 29 : 28;
} 

/*
 * Print out the calendar
 * @param year: int representing the calendar 
 *              year
 * @param startDay: int representing the  
 *                  calendar start day of 1/1
 */
void printCalendar(int year, int startDay) {
    int month, day;
    for(month=1; month<=12; month++)     
    {
        printf("\n\n%s %d\n", months[month], year);         
        printf("Sun Mon Tue Wed Thu Fri Sat\n" );  
        // Position the first date
        for(day=1; day<=((startDay)*4); day++)
        {
            printf("%c", ' ');
        }
        // Print all days in month         
        for(day=1; day<=monthMaxDays[month]; day++)
        {
            printf("%3d",day );
            // Is day before Sat?
            if((day + startDay) % 7 > 0)                 
                printf(" ");
            //Begin new week
            else
                printf("\n" );
        }
        // Position following month             
        startDay = (startDay + monthMaxDays[month]) % 7;
    }
} 

/*
 * Driver
 * Read the year, get the starting day of the 
 * week, adjust for leap year if necessary, 
 * then prints the calendar
 */
int main(void)
{
    unsigned int year;
    int startDay;
    year = readYear();
    printf("%d", year);
    startDay = getStart(year);     
    leapYear(year);
    printCalendar(year, startDay);     
    printf("\n");
}


/**
 * @uthor: Ace
 * Bugs: Formatting issues–FIXED.
 * Version:
 * 04202018.1730 - Separated logic of driver 
 *                 into separate functions
 * 04202018.1900 - Added error checks to
 *                 readYear(), currentYear()
 * 04212018.1402 - Addressed formatting 
 *                 issues. Many thanks to 
 *                 @Baptiste E. Prunier 
 * 04212018.1555 - Disallow negative years
 */
