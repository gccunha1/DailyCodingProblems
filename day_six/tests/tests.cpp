#include "../src/solution.h"
#include <gtest/gtest.h>

TEST(DaySix, AddElementToList_ExpectElementInIndexZero)
{
    EfficientDoubleLinkedList<int> list;
    list.Add(4);
    ASSERT_EQ(4, list.Get(0));
}

TEST(DaySix, AddMultipleElementsToList_ExpectCorrectOrder)
{
    EfficientDoubleLinkedList<int> list;
    list.Add(4);
    list.Add(0);
    list.Add(7);
    ASSERT_EQ(4, list.Get(0));
    ASSERT_EQ(0, list.Get(1));
    ASSERT_EQ(7, list.Get(2));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}