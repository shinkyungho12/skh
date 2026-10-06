#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) // 행
    {
        for (int j = 0; j < i + 1; j++) // 열
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
