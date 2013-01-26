#include <stdio.h>

/* 1-6 Verify that the expression 'getchar() != EOF' is 0 or 1 */

main()
{
    int c;

    // c get set to the evaluation of 'getchar() != EOF'
    //   look closely at those parentheses
    printf("c = %d\n", getchar() != EOF);
    while (c = (getchar() != EOF)) {
        ;
    }
    printf("c = %d\n", c);
}
