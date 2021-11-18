#include "solution.h"
#include <iostream>

namespace naive
{
    std::string serialize(const Node *node)
    {
        if (node == nullptr)
            return "";
        std::string val = node->val;
        std::string left = serialize(node->left);
        std::string right = serialize(node->right);
        return "Node(" + val + left + right + ")";
    }
    Node *deserialize(const std::string &bytes)
    {
        return nullptr;
    }
}