#include <stdio.h>

/* 1-18 Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#define MAXLINE 1000   /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char from[], char to[]);
int rm_trail(char from[], char to[], int length);

main()
{
    int len, line_len;                  /* current line length */
    char line[MAXLINE];       /* current input line */
    char betterline[MAXLINE]; /* the new and improved line */

    while ((len = getline2(line, MAXLINE)) > 0 ) {
        copy(line, betterline);
        line_len = rm_trail(betterline, betterline, len);
        if (line_len != -1)
            printf("%s", betterline);
    }
    return 0;
}

/* getline: read a line into s, return length  */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* rm_trail: remove trailing whitespace and tabs from a string */
int rm_trail(char from[], char to[], int len)
{
    int i, j, DONE;

    j = 2;
    DONE = 0;
    // len-2; last two chars are \n\0
    /* Look backwards through a string counting the trailing 
     * whitespace. Once counted, copy the rest of the string. */
    for (i = len-2; i > 0; --i) {
        // count extra whitespace
        if (DONE == 0 && (from[i] == '\t' || from[i] == ' ')) {
            ++j; 
        } else {
            // copy rest of string
            DONE = 1;
            to[i] = from[i];
        }
    }

    // line is empty or full of spaces
    if (len == 1 || j == len) {
        return -1;
    }

    if (j > 2) {
        // Add \n\0 to end of string
        j = len + 1 - j;
        to[j++] = '\n';
        to[j] = '\0';
    }

    return j;
}
