#include "solution.h"
#include <iostream>

namespace naive
{
    const std::string open_node_tag = "<node>";
    const std::string close_node_tag = "</node>";
    std::string serialize(const Node *node)
    {
        if (node == nullptr)
            return open_node_tag + close_node_tag;
        std::string val = node->val;
        std::string left = serialize(node->left);
        std::string right = serialize(node->right);
        return open_node_tag + val + left + right + close_node_tag;
    }
    Node *deserialize(std::string &bytes)
    {
        size_t node_start = bytes.find(open_node_tag);
        size_t next_node_end = bytes.find(close_node_tag);

        if (next_node_end == node_start + open_node_tag.length())
        {
            bytes.erase(0, open_node_tag.length() + close_node_tag.length());
            return nullptr;
        }

        if (node_start == std::string::npos)
        {
            return nullptr;
        }

        bytes.erase(node_start, open_node_tag.length());

        size_t left_node_start = bytes.find(open_node_tag);
        if (left_node_start == std::string::npos)
        {
            return nullptr;
        }

        Node *node = new Node(bytes.substr(0, left_node_start));
        bytes.erase(0, left_node_start);
        node->left = deserialize(bytes);

        node->right = deserialize(bytes);
        size_t my_end = bytes.find(close_node_tag);

        bytes.erase(0, my_end + close_node_tag.length());

        return node;
    }
}