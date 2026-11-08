#include <stdio.h>

int main(void)
{
    char a[26];
    int i;
    for (i = 0; i < 26; i++) a[i] = 'A' + i;
    for (i = 25; i >= 0; i--) printf("%c ", a[i]);
    return 0;
}