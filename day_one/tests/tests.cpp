#include "../src/solution.cpp"
#include <gtest/gtest.h>

TEST(DayOne, NoSolution)
{
    //create vector of ints
    std::vector<int> input = {1, 1, 1};
    int sum = 30;
    EXPECT_FALSE(check_if_sum_of_two_numbers_in_vector(input, sum));
    EXPECT_FALSE(check_if_sum_of_two_numbers_in_vector_positives(input, sum));
}

TEST(DayOne, GivenVectorWithSolutionExpectSolutionFound)
{
    //create vector of ints
    std::vector<int> input = {1, 1, 37};
    int sum = 2;
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector(input, sum));
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector_positives(input, sum));
}

TEST(DayOne, GivenVectorWithSolutionAddingZeroExpectSolutionFound)
{
    //create vector of ints
    std::vector<int> input = {1, 1, 37, 0};
    int sum = 37;
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector(input, sum));
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector_positives(input, sum));
}

TEST(DayOne, SolutionSumZero)
{
    //create vector of ints
    std::vector<int> input = {1, 2, -2};
    int sum = 0;
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector(input, sum));
}

TEST(DayOne, SolutionSumNegative)
{
    //create vector of ints
    std::vector<int> input = {1, 2, -2};
    int sum = -1;
    EXPECT_TRUE(check_if_sum_of_two_numbers_in_vector(input, sum));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
