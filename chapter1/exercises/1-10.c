#include <stdio.h>

/* 1-10 Write a program to copy its input to its output, replacing each
 * tab by '\t', each backspace by '\b', and each backslash by '\\'. This
 * makes tabs and backspaces visible in an unambiguous way. */

/* cp stdin to stdout,
 * replace \t with \b and
 * \ with \\.
 */
main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\\') {
            printf("\\\\");
        // Terminal is generally cocked and cannot grab backspace
        } else if (c == '\b') {
            printf("\\b");
        } else {
            putchar(c);
        }
    }
}
