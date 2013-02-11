#include <stdio.h>

/* 1-21 Write a program 'entab' that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use
 * the same tab stops as for detab. When either a tab or a single blank
 * would suffice to reach a tab stop, which should be given preference.
 */

#define SPACES 4
#define MAXLINE 500

int getline2(char line[], int maxline);
void entab(char line[], char t_line[]);

main()
{
    int len;
    char line[MAXLINE];
    char t_line[MAXLINE];

    while((len = getline2(line, MAXLINE)) > 0) {
        entab(line, t_line);
        //printf("--%s", line);
        printf("%s", t_line);
    }
}

void entab(char line[], char t_line[])
{
    int i, j, r;
    
    i = 0;
    j = 0;
    r = 0;
    while (line[i] != '\0') {
        if (line[i] == ' ') {
            // Count the number of spaces
            ++j;
        } else {
            if (j == 4) {
                t_line[r++] = '\t';
                // reset space counter
                j = 0;
            } 

            if (0 < j < 4) {
                while (j > 0) {
                    t_line[r++] = ' ';
                    --j;
                }
                j = 0;
            }

            t_line[r] = line[i];
            ++r;
        }
        ++i;
    }
    t_line[r] = '\0';
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
