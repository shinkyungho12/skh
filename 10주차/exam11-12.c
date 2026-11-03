#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[20] = "Back";
    char str2[20] = "Space";
    char str3[20];

    char ch = 'p';
    int n = 3;

    int len = strlen(str1);
    printf("str1의 길이: %d\n", len);
    //길이 계산 str1의 길이를 반환한다 

    
    strcpy(str3, str1);
    printf("str1을 str3에 복사: %s\n", str3);
    //str3에를 str1에 복사한다(널 문자도 함께 복사된다)



    strncpy(str3, str2, n);
    str3[n] = '\0';
    printf("str2의 첫 %d 문자를  str3에 복사: %s\n", n, str3);
    // str2의 첫 n개 문자를 str3에 복사한다

    printf("str1과 str2 비교: %d\n", strcmp(str1, str2));
    //str1과 str2를 비교한다

    printf("str1과 str2의 첫 %d 문자 비교: %d\n", str1, str2,n);
    //이거는 최대 n개 문자까지만 비교한다.

    strcat(str1, str2);
    printf("str2를 str1에 연결: %s\n", str1);
    //str2를 str1의 끝에 연결한다

    strncat(str3, str1, n);
    printf("str1의 첫  %d 문자를 str3에 연결: %s\n", n, str3);
    //str1의 n개 문자를 str3의 끝에 연결한다

    char*ptr_ch = strchr(str1, ch);
    printf("str1에서 '%c'의 첫 번째 출현: %s\n", ch, ptr_ch);
    //str1에서 구분자 ch에 따라 문자열을 토큰으로 분리한다

    char*ptr_str = strstr(str1, str2);
    printf("str1에서 str2의 첫 번째 출현: %s\n", ptr_str ? ptr_str : "찾을 수 없음");
    //str1애서 str2의 첫 번째 출현을 찾는다

    return 0;

}