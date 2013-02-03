#include <stdio.h>

/* 1-20 Write a program 'detab' that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every 'n' columns. Should 'n' be a variable or
 * symbolic parameter? */

#define SPACES 4
#define MAXLINE 500

int getline2(char line[], int maxline);
void detab(char line[], char detabed_line[]);

main()
{
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
        detab(line, newline);
        printf("%s", newline);
    }
    return 0;
}

void detab(char old[], char new[])
{
    int i, j, q;

    i = j = 0;
    while (old[i] != '\0') {
        // Read till end of line
        if (old[i] == '\t') {
            // Replace tab with SPACES*' '
            for (q = 0; q < SPACES; ++q) {
                new[i+q] = ' ';
            }
            // Update offset
            j += SPACES-1;
        } else {
            new[i+j] = old[i];
        }
        // Continue reading
        i++;
    }
    // Don't forget null character
    new[i+j] = '\0';
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
