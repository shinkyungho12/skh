#include <stdio.h>

int main(void)
{
    int month;

    printf("1~12 사이의 정수를 입력하세요: ");
    scanf("%d", &month);

    switch (month)
    {
        case 2:
            printf("28일\n");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("31일\n");
            break;

       

        default:
            printf("잘못된 입력입니다.\n");
    }

    return 0;
}
