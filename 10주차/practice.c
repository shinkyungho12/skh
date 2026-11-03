#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() 
{
    int arr[] = {2, 5, 8, 12, 16, 22, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1) 
    {
        printf("원소 %d는 인덱스 %d에 존재합니다. \n", target, result);
    } else {
        printf("원소를 찾지 못했습니다.\n");
    }

    return 0;
}