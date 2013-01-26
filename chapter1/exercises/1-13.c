#include <stdio.h>

/* 1-13 Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging. */

#define IN 1
#define OUT 2

int max(int a, int b);

/* Print a histogram of the lengths of words from stdin. Draw
 * horizontally, and vertically */
main()
{
    int i, j;
    int c, state;
    int sum, m;

    int words[26];
    
    for ( i = 0; i < 26; ++i)
        words[i] = 0;
    i = 0;
    sum = 0;
    m = 0;
    state = OUT;

    while((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
            if ( i != 0 ) {
                ++words[i];
                i = 0;
            }
        } else if(( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            if (state == OUT) {
                state = IN;
            } 
            ++i;
        }

    }

    // horizontal histogram
    for (i = 0; i < 26; ++i) {
        // column
        printf("%d:\t", i);
        for (j = 0; j < words[i]; ++j) {
            // row
            printf("#");
        }
        // new row
        printf("\n");
    }

    // Find max and sum of array
    for (i = 0; i < 26; ++i) {
        m = max(words[i], m);      
        sum += words[i];
    }

    // Maximum
    //printf("Max: %d", m);

    // vertical histogram
    for (i = m; i >= 0; --i) {
        // row
        for (j = 0; j < 26; ++j) {
            // columns
            if (words[j] >= i) {
                // word lenght is equal to or greater than current
                // column, print #
                if (i == 0) {
                    // Print numbers on bottom of histogram
                    printf("%d\t", j);
                } else {
                    // print # for number >= column
                    printf("#\t");
                }
            } else {
                // print 'nothing' for alignment
                printf("\t");
            }
        }
        // new row
        printf("\n");
    }

    // Total
    //printf("\ntotal = %d\n", sum);
}

int max(int a, int b) {
    if( a > b)
        return a;
    return b;
}
