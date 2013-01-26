#include <stdio.h>

/* 1-15 Rewrite the temperature converstion program of Section 1.2 to
 * use a function for conversion. */

double cels(double fahrenheit);

/* print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    
    printf(" Fahr  |  Cels\n");
    printf("---------------\n");

    while (fahr <= upper) {
        celsius = cels(fahr);
        printf(" %3.0f\t%.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/* Convert a temperature in Fahrenheit to Celsius */
double cels(double fahrenheit)
{
    return (5.0/9.0) * (fahrenheit-32.0);
}
