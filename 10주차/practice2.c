#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int result = binarySearch(arr, size, key);

    if (result != -1)
    {
        printf("찾는 값의 위치: %d\n", result);
    } else {
        printf("값을 찾을 수 없습니다. \n");
    }
    return 0;
}