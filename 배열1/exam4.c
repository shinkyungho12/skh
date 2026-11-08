#include <stdio.h>

int main(void)
{
    int a[10], i;
    for (i = 0; i < 10; i++) a[i] = i + 1;
    for (i = 0; i < 10; i++) printf("%d ", a[i]);
    return 0;
}