import unittest
import solution
import random


class TestSolution(unittest.TestCase):
    def expected_output_test(self, input, expected_output):
        output = solution.solution(input)
        self.assertEqual(output, expected_output)

    def test_example_tests(self):
        self.expected_output_test([3, 4, -1, 1], 2)
        self.expected_output_test([1, 2, 0], 3)
        self.expected_output_test([5, 6, 7, 8, 4, 3, 1, 2], 9)

    def test_random_list(self):
        random_list = [random.randrange(1, 10000, 1) for i in range(1000000)]
        sorted_list = list(dict.fromkeys(sorted(random_list)))

        answer = 1
        for idx, value in enumerate(sorted_list):
            if idx + 1 != value:
                break
            answer += 1

        self.expected_output_test(random_list, answer)


if __name__ == "__main__":
    unittest.main()
