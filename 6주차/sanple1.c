def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # 최솟값을 가진 인덱스 초기화
        min_index = i
        
        # 남은 정렬되지 않은 영역에서 최솟값 탐색
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
                
        # 찾은 최솟값과 현재 위치의 원소 교환 (Swap)
        arr[i], arr[min_index] = arr[min_index], arr[i]
        
    return arr

# --- 실행 예시 ---
if __name__ == "__main__":
    sample_data = [64, 25, 12, 22, 11]
    print("정렬 전:", sample_data)
    sorted_data = selection_sort(sample_data)
    print("선택 정렬 후:", sorted_data)