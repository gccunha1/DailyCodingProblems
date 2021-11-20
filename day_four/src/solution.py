def solution(integer_array):
    carry = 0
    value_copy = 0
    for value in integer_array:
        value_copy = value
        while (
            value_copy > 0
            and value_copy <= len(integer_array)
            and value_copy != integer_array[value_copy - 1]
        ):
            carry = integer_array[value_copy - 1]
            integer_array[value_copy - 1] = value_copy
            value_copy = carry

    for index, value in enumerate(integer_array):
        if index != value - 1:
            return index + 1

    return len(integer_array) + 1


if __name__ == "__main__":
    print(solution([7, 9, 6, 4, 8, 1, 6, 2, 0, 54, 7, 5, -2]))
