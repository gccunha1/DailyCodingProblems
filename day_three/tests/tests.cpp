#include "../src/solution.h"
#include <gtest/gtest.h>

void ExpectEqualNode(const Node *node1, const Node *node2)
{
    if (!node1 && !node2)
        return;

    ASSERT_TRUE(node1 != nullptr);
    ASSERT_TRUE(node2 != nullptr);
    ASSERT_EQ(node1->val, node2->val);
    std::cout << node1->val << " " << node2->val << std::endl;
    ExpectEqualNode(node1->left, node2->left);
    ExpectEqualNode(node1->right, node2->right);
}

void DeleteTree(Node *head)
{
    if (head == nullptr)
        return;

    if (head->left != nullptr)
    {
        DeleteTree(head->left);
        head->left = nullptr;
    }
    if (head->left != nullptr)
    {
        DeleteTree(head->right);
        head->right = nullptr;
    }
    delete head;
}

TEST(DayThree, ExampleTest)
{
    using namespace naive;
    Node *head = new Node("root", new Node("left", new Node("left.left")), new Node("right"));
    std::string head_serialized = serialize(head);
    Node *output_head = deserialize(head_serialized);
    ASSERT_TRUE(output_head != nullptr);
    ASSERT_TRUE(output_head->left->left->val == "left.left");
    ExpectEqualNode(head, output_head);
    DeleteTree(head);
    DeleteTree(output_head);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}