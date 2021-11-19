#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <memory>

//create tree node shared_ptr
struct Node
{
    std::string val;
    Node *left;
    Node *right;
    Node(std::string val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {}
};

namespace naive
{
    std::string serialize(const Node *node);
    Node *deserialize(std::string &bytes);
}
#endif
