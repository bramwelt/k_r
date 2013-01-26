#include <stdio.h>

/* 1-14 Write a program to print a histogram of the frequencies of
 * different characters in its input. */

/* Print a histogram of the frequency of characters from stdin */
main()
{
    int i, j, c;
    int chars[256];

    // initialize array to 0
    for (i = 0; i < 256; ++i)
        chars[i] = 0;

    // get a count of chars
    while((c = getchar()) != EOF) {
        ++chars[c];
    }

    // print horizontal histogram
    for (i = 0; i < 256; ++i) {
        // only print chars that were found
        if ( chars[i] != 0 ) {
            // \n char will make things funky
            if ( i == 10 ) {
                printf("'nl':\t");
            } else {
                printf("'%c':\t", i);
            }
            // print # for each occurance
            for (j = 0; j < chars[i]; ++j) {
                printf("#");
                if (j == (chars[i]-1)) {
                    printf("\n");
                }
            }
        }
    }
}
