def solution(integer_array):
    occurrences = [0] * len(integer_array)
    for value in integer_array:
        if value > 0 and value <= len(occurrences):
            occurrences[value - 1] = 1

    try:
        return occurrences.index(0) + 1
    except ValueError:
        return len(integer_array) + 1


if __name__ == "__main__":
    print(solution([7, 9, 6, 4, 8, 1, 6, 2, 0, 54, 7, 5, -2]))
