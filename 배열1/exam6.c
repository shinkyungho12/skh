#include <stdio.h>

int main(void)
{
    int a[100], n = 0, i;
    while (n < 100) {
        scanf("%d", &a[n]);
        if (a[n] == 0) break;
        n++;
    }
    for (i = n - 1; i >= 0; i--) printf("%d ", a[i]);
    return 0;
}