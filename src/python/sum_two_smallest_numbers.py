def sum_two_smallest_numbers(numbers: list[int]) -> int:
    return sum(sorted(numbers)[:2])
