import unittest
import solution


class TestSolution(unittest.TestCase):
    def expected_output_test(self, input, expected_output):
        output = solution.solution(input)
        self.assertEqual(output, expected_output)

    def test_example_tests(self):
        self.expected_output_test([3, 4, -1, 1], 2)
        self.expected_output_test([1, 2, 0], 3)


if __name__ == "__main__":
    unittest.main()
