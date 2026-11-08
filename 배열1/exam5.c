#include <stdio.h>

int main(void)
{
    int a[100], n = 0, i;
    while (n < 100) {
        scanf("%d", &a[n]);
        if (a[n] == 0) break;
        n++;
    }
    for (i = 1; i < n; i += 2) printf("%d ", a[i]);
    return 0;
}