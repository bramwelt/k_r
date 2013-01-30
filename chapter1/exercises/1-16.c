#include <stdio.h>

/* 1-16 Rewrite the main routine of the longest-line program so it will
 * correctly print the length of arbitrary long input lines, and as much
 * as possible of the text. */

/* Change signature of copy to from -> to, not to -> from */

#define MAXLINE 1000   /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char from[], char to[]);

/* print the longest input line */
main()
{
    int len;             /* current line length */
    int max;             /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0 )
        if (len > max) {
            max = len;
            if ( len > 100 ) {
                printf("%d %s", len, line);
            }
            copy(line, longest);

        }
    if (max > 0)  /* there was a line */
        printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
