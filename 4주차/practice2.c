#include <stdio.h>

void PrintNum(int n)
{
    if (n == 0) {
        return;
    }

    PrintNum(n - 1);
    printf("%d\n", n);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    PrintNum(n);
    return 0;
}
