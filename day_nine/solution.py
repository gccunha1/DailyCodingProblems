import random


numbers_list = [2, 4, 6, 2, 5]
numbers_list = [random.randrange(-5, 30, 1) for i in range(100)]
print(numbers_list)


def get_largest_sum_of_non_adjacent_numbers(start):
    # @TODO Better solution bc this one is bad
    max_sum = 0
    for idx, val in enumerate(numbers_list[start + 2 :]):
        if val <= 0:
            continue
        path_sum = get_largest_sum_of_non_adjacent_numbers(idx + start + 2)
        if path_sum >= max_sum:
            max_sum = path_sum

    if start >= 0:
        print(f"I'm {start} returning: {numbers_list[start] + max_sum}")
        return numbers_list[start] + max_sum
    return max_sum


if __name__ == "__main__":

    print(get_largest_sum_of_non_adjacent_numbers(-2))
