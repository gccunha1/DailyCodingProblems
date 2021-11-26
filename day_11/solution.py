def read_words_from_file():
    file = open("one_million_words.txt", "r")
    words_list = file.read().splitlines()
    return words_list


def binary_search(search_query, sorted_words_list, start_index, end_index):
    word_index = start_index + (end_index - start_index) // 2 - 1

    if end_index - start_index <= 1:
        if sorted_words_list[start_index].startswith(search_query):
            return start_index
        return end_index

    if search_query < sorted_words_list[word_index]:
        return binary_search(search_query, sorted_words_list, start_index, word_index)
    else:
        return binary_search(search_query, sorted_words_list, word_index + 1, end_index)


def get_autocomplete_words(search_query, sorted_words_list, first_word_index):
    autocomplete_words = []
    for word in sorted_words_list[first_word_index : len(sorted_words_list)]:
        if not word.startswith(search_query):
            break
        autocomplete_words.append(word)
    return autocomplete_words


if __name__ == "__main__":
    words_list = read_words_from_file()
    words_list.sort()

    while True:
        print("Search ->", end=" ")
        search_query = input()
        if search_query == "qqq":
            break
        first_word_index = binary_search(
            search_query, words_list, 0, len(words_list) - 1
        )
        print(get_autocomplete_words(search_query, words_list, first_word_index))
