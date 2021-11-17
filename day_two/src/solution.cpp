#include "solution.h"
#include <iostream>

std::vector<int> day_two_solution(std::vector<int> input)
{
    std::vector<int> output(input.size(), 0);
    int total_multiplication = 1;
    int zero_counter = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != 0)
            total_multiplication *= input[i];
        else
        {
            zero_counter++;
        }
    }
    if (zero_counter > 1)
        return output;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != 0)
            output[i] = total_multiplication * (1 - zero_counter) / input[i];
        else
            output[i] = total_multiplication;
    }
    return output;
}

std::vector<int> day_two_solution_no_division(std::vector<int> input)
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
