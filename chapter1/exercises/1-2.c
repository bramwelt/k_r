#include <stdio.h>

main()
{
    printf("Hello, world!");
    // alert/bell
    //printf("\a");

    // backspace
    printf("\b");

    // stop output - non-standard
    //printf("\c");

    // escape character
    printf("\ef");

    // form feed
    //printf("\f");

    // newline
    printf("\n");

    // carridge return
    //printf("\r");

    // tab
    printf("\t");

    // universal character names - only valid in C++, C99
    //printf("\u307a");

    // vertical tab
    printf("\v");

    /* Hex digits printf("\x"); */
    // Seems to set return value...
    //printf("\xf");
}
