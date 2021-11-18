#include "../src/solution.h"
#include <gtest/gtest.h>

void ExpectEqualNode(const std::shared_ptr<Node> node1, const std::shared_ptr<Node> node2)
{
    if (node1 && !node2)
        return;
    ASSERT_TRUE(node1 && node2);
    ASSERT_EQ(node1->val, node2->val);
    ASSERT_EQ(node1->left, node2->left);
    ASSERT_EQ(node1->right, node2->right);
}

TEST(DayThree, ExampleTest)
{
    std::shared_ptr<Node> head = std::make_shared<Node>(
        "root",
        std::make_shared<Node>("left", std::make_shared<Node>("left.left")),
        std::make_shared<Node>("right"));

    std::shared_ptr<Node> output_head = deserialize(serialize(head));

    ASSERT_TRUE(output_head != nullptr);
    ASSERT_TRUE(output_head->left->left->val == "left.left");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}