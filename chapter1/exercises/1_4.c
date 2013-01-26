#include <stdio.h>

/* 1-4 Write a program to print the corresponding Celsius to Fahrenheit
 * table. */

/* print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300 */

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    
    printf("Cels  |  Fahr\n");
    printf("---------------\n");

    while (celsius <= upper) {
        fahr = ((9.0 * celsius) / 5.0) + 32.0;
        printf(" %3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
