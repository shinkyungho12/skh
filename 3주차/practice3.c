#include <stdio.h>

int main(void)
{
    int a, b, temp;

    scanf("%d", &a);
    scanf("%d", &b);

    temp = b;

    while (temp > 0)
    {
        printf("%d\n", a * (temp % 10));
        temp /= 10;
    }

    return 0;
}
