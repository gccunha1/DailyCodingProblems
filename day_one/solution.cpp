#include <vector>
#include <algorithm>
#include <iostream>

// Considering very large values and negatives are possible O(nlogn)
bool check_if_sum_of_two_numbers_in_vector(std::vector<int> &vec, int sum)
{
    //naive approach
    /* for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == sum)
            {
                return true;
            }
        }
    }
    return false; */

    //sort the vector
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if (std::binary_search(vec.begin(), vec.end(), sum - vec[i]))
        {
            return true;
        }
    }
    return false;
}
// Considering only positive values O(n)
bool check_if_sum_of_two_numbers_in_vector_positives(std::vector<int> &vec, int sum)
{
    std::vector<int> occurence_vector(sum + 1, 0);

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > sum)
            continue;
        if (occurence_vector[sum - vec[i]])
            return true;
        occurence_vector[vec[i]] = 1;
    }
    return false;
}

//main function
int main()
{
    //create vector with random integers
    std::vector<int> vec(100000000);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = rand() % 1000000000000;
    }

    int sum = 102341;
    std::cout << check_if_sum_of_two_numbers_in_vector(vec, sum) << std::endl;
    //std::cout << check_if_sum_of_two_numbers_in_vector_positives(vec, sum) << std::endl;
    return 0;
}