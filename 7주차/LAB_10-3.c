#include <stdio.h>

#define MAX_STUDENTS 50

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int numStudents;
    int grades[MAX_STUDENTS];
    int *gradesPointer = grades;

    printf("학생 수를 입력하세요. (최대 %d명) : ", MAX_STUDENTS);

    if (scanf("%d", &numStudents) != 1 ||
        numStudents < 1 || numStudents > MAX_STUDENTS)
    {
        printf("학생 수를 1명 이상 %d명 이하로 입력하세요.\n",
               MAX_STUDENTS);
        return 1;
    }

    for (int i = 0; i < numStudents; i++)
    {
        printf("%d번 학생의 최종 성적을 입력하세요 : ", i + 1);

        if (scanf("%d", gradesPointer + i) != 1)
        {
            printf("올바른 성적을 입력하세요.\n");
            return 1;
        }
    }

    bubbleSort(gradesPointer, numStudents);

    printf("\n정렬된 성적 : ");

    for (int i = 0; i < numStudents; i++)
    {
        printf("%d ", *(gradesPointer + i));
    }

    printf("\n\n최고 성적 : %d\n",
           *(gradesPointer + numStudents - 1));

    printf("최하 성적 : %d\n", *gradesPointer);

    return 0;
}