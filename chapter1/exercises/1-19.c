#include <stdio.h>
#define MAXLINE 1000

/* 1-19 Write a function 'reverse(s)' that reverses the character
 * string 's'. Use it to write a program that reverses its input a line
 * at a time */

int getline2(char line[], int maxline);
void reverse(char s[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

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

void reverse(char s[])
{
    int i = 0, j = 0;
    int tmp;

    // Get the length of the list
    while (s[++i] != '\0');

    // Decrement i so we don't go out of bounds
    --i;

    // Don't swap the newline
    if (s[i] == '\n')
        --i;

    // Reverse iterate and swap till middle
    j = i;
    while (j > (i/2)) {
        tmp = s[j];
        s[j] = s[i-j];
        s[i-j] = tmp;
        --j;
    }
}
