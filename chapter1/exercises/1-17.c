#include <stdio.h>

/* 1-17 Write a program to print all lines that are longer than 80
 * characters */

#define MAXLINE 1000   /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char from[], char to[]);

/* print all lines longer than 80 chars */
main()
{
    int len;             /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0 )
        if ( len > 80 ) {
            printf("%s", line);
        }
    return 0;
}

/* getline: read a line into s, return length  */
int getline2(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
