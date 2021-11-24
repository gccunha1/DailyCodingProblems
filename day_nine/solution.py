def get_largest_sum_of_non_adjacent_numbers(list, start):
    step_possibilities = list[start + 2 :]

    max_sum = 0
    print(step_possibilities)
    for idx, val in enumerate(step_possibilities):
        path_sum = get_largest_sum_of_non_adjacent_numbers(step_possibilities, idx)
        if path_sum >= max_sum:
            max_sum = path_sum

    if start >= 0:
        print(f"I'm {start} returning: {list[start] + max_sum}")
        return list[start] + max_sum
    return max_sum


if __name__ == "__main__":
    numbers_list = [5, 1, 1, 5]
    print(get_largest_sum_of_non_adjacent_numbers(numbers_list, -2))
