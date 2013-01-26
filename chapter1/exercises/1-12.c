#include <stdio.h>

/* 1-12 Write a program that prints its input one word per line. */

# define IN 1
# define OUT 0

/* print input one word per line */
main()
{
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
            putchar('\n');
        } else if (state == OUT ) {
            state = IN;
            putchar(c);
        } else {
            // state == IN
            putchar(c);
        }
    }
}
