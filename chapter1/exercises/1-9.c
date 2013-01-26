#include <stdio.h>

/* 1-9 Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank. */

#define YES 1
#define NO 0

/* copy stdin to stdout, replace each 1+ spaces by 1 space */
main()
{
    int c, IN_WORD;

    IN_WORD = YES;
    while((c = getchar()) != EOF) {
        if (c == ' ') {
            // space -> word transition
            // put single space
            if (IN_WORD == NO) {
                putchar(c);
            }
            // ignore all other spaces
            IN_WORD = YES;
        }  else {
            IN_WORD = NO;
            putchar(c);
        }
    }
}
