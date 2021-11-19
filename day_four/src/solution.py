def solution(integer_array):
    maximum = max(integer_array)
    occurences_list = [0] * maximum
    for value in integer_array:
        if value >= 0:
            occurences_list[value - 1] = 1

    try:
        return occurences_list.index(0) + 1
    except ValueError:
        return maximum + 1


if __name__ == "__main__":
    solution([7, 9, 6, 4, 8, 1, 6, 2, 0, 54, 7, 5, -2])
