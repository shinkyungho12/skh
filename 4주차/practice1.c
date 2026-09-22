#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int answer;
   int num;
   int count=0;

   srand(time(NULL));

   answer = rand() % 100;
   
   while (1)
   {
      printf("숫자 입력: ");
      scanf("%d", &num);
      count++;

      if (num > answer)
      {
          printf("더 작은 수 입니다\n");
      }
      else if (num < answer)
      {
         printf("더 큰 수 입니다\n");
      }
      else  
      {
         printf("정답입니다");
         printf("%d번 반복만에 맞혔습니다.\n" , count);
         break;
      }
   }
   
   return 0;

}
