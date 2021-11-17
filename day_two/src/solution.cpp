#include "solution.h"
#include <iostream>

std::vector<int> day_two_solution(std::vector<int> input)
{
    std::vector<int> output(input.size(), 0);
    int cumulative_multiplication = 1;

    for (size_t i = 0; i < input.size(); i++)
    {
        output[i] = cumulative_multiplication;
        cumulative_multiplication *= input[i];
    }
    cumulative_multiplication = 1;
    for (size_t i = 0; i < input.size(); i++)
    {
        output[output.size() - i - 1] *= cumulative_multiplication;
        cumulative_multiplication *= input[output.size() - i - 1];
    }
    return output;
}
