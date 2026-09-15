#include <stdio.h>

int main(void)
{
    int number;

    scanf("%d", &number);

    printf("%s", (number % 2 == 0) ? "even" : "odd");

    return 0;
}
