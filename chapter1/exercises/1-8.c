#include <stdio.h>

/* 1-8 Write a program to count blanks, tabs, and newlines. */
main()
{
    int c, nl, nt, ns;

    nl = nt = ns = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        } else if (c == '\t') {
            ++nt;
        } else if (c == ' ') {
            ++ns;
        }
    }
    printf("%d %d %d\n", ns, nt, nl);
}
