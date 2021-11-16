#include "../src/solution.cpp"
#include <gtest/gtest.h>

TEST(DayOne, NoSolution)
{
    //create vector of ints
    std::vector<int> input = {1, 1, 1};
    int sum = 30;
    EXPECT_FALSE(check_if_sum_of_two_numbers_in_vector(input, sum));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
