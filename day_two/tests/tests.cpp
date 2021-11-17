#include "../src/solution.h"
#include <gtest/gtest.h>

void ExpectEquallVectors(std::vector<int> v1, std::vector<int> v2)
{
    ASSERT_EQ(v1.size(), v2.size());
    for (size_t i = 0; i < v1.size(); i++)
    {
        EXPECT_EQ(v1[i], v2[i]);
    }
}

TEST(DayTwo, GivenExampleVectorsExpectExampleOutputs)
{
    std::vector<int> input1 = {1, 2, 3, 4, 5};
    std::vector<int> input2 = {3, 2, 1};
    std::vector<int> expected_output1 = {120, 60, 40, 30, 24};
    std::vector<int> expected_output2 = {2, 3, 6};

    std::vector<int> output1 = day_two_solution(input1);
    std::vector<int> output2 = day_two_solution(input2);

    ExpectEquallVectors(expected_output1, output1);
    ExpectEquallVectors(expected_output2, output2);
}

TEST(DayTwo, GivenVectorFilledWithZerosExpectOutputsFilledWithZeros)
{
    std::vector<int> input = {0, 0, 0, 0, 0};
    std::vector<int> expected_output = {0, 0, 0, 0, 0};

    std::vector<int> output = day_two_solution(input);

    ExpectEquallVectors(expected_output, output);
}

TEST(DayTwo, GivenVectorWithOneZeroExpectOutputsFilledWithZerosExceptForOneEntry)
{
    std::vector<int> input = {2, 3, 4, 5, 0, 8, 7};
    std::vector<int> expected_output = {0, 0, 0, 0, 6720, 0, 0};

    std::vector<int> output = day_two_solution(input);

    ExpectEquallVectors(expected_output, output);
}

TEST(DayTwo, GivenVectorOfSizeOneExpectOutputEquallToOne)
{
    std::vector<int> input = {3};
    std::vector<int> expected_output = {1};

    std::vector<int> output = day_two_solution(input);

    ExpectEquallVectors(expected_output, output);
}

TEST(DayTwo, GivenVectorWithNegativeNumberExpectCorrectOutputs)
{
    std::vector<int> input = {1, 2, 3, -4, 5};
    std::vector<int> expected_output = {-120, -60, -40, 30, -24};

    std::vector<int> output = day_two_solution(input);

    ExpectEquallVectors(expected_output, output);
}

TEST(DayTwo_No_Division, GivenExampleVectorsExpectExampleOutputs)
{
    std::vector<int> input1 = {1, 2, 3, 4, 5};
    std::vector<int> input2 = {3, 2, 1};
    std::vector<int> expected_output1 = {120, 60, 40, 30, 24};
    std::vector<int> expected_output2 = {2, 3, 6};

    std::vector<int> output1_no_division = day_two_solution_no_division(input1);
    std::vector<int> output2_no_division = day_two_solution_no_division(input2);

    ExpectEquallVectors(expected_output1, output1_no_division);
    ExpectEquallVectors(expected_output2, output2_no_division);
}

TEST(DayTwo_No_Division, GivenVectorFilledWithZerosExpectOutputsFilledWithZeros)
{
    std::vector<int> input = {0, 0, 0, 0, 0};
    std::vector<int> expected_output = {0, 0, 0, 0, 0};

    std::vector<int> output_no_division = day_two_solution_no_division(input);

    ExpectEquallVectors(expected_output, output_no_division);
}

TEST(DayTwo_No_Division, GivenVectorOfSizeOneExpectOutputEquallToOne)
{
    std::vector<int> input = {3};
    std::vector<int> expected_output = {1};

    std::vector<int> output_no_division = day_two_solution_no_division(input);

    ExpectEquallVectors(expected_output, output_no_division);
}

TEST(DayTwo_No_Division, GivenVectorWithOneZeroExpectOutputsFilledWithZerosExceptForOneEntry)
{
    std::vector<int> input = {2, 3, 4, 5, 0, 8, 7};
    std::vector<int> expected_output = {0, 0, 0, 0, 6720, 0, 0};

    std::vector<int> output = day_two_solution_no_division(input);

    ExpectEquallVectors(expected_output, output);
}

TEST(DayTwo_No_Division, GivenVectorWithNegativeNumberExpectCorrectOutputs)
{
    std::vector<int> input = {1, 2, 3, -4, 5};
    std::vector<int> expected_output = {-120, -60, -40, 30, -24};

    std::vector<int> output = day_two_solution_no_division(input);

    ExpectEquallVectors(expected_output, output);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}