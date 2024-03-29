def insertion_sort(arr: list[int]) -> list[int]:
    for i in range(len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    return arr


print(insertion_sort([10, 3, 6, 2, 1, 5]))
