def sum_two_smallest_numbers(numbers: list[int]) -> int:
    return sum(sorted(numbers)[:2])


print(sum_two_smallest_numbers([6, 7, 8, 9, 10, 21, 1, 3]))
