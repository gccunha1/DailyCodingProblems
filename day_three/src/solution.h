#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <memory>

struct Node
{
    const std::string &val;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(const std::string &str, std::shared_ptr<Node> lft = nullptr, std::shared_ptr<Node> rite = nullptr) : val{str}, left{lft}, right{rite}
    {
    }
};

std::string serialize(const std::shared_ptr<Node> node);
std::shared_ptr<Node> deserialize(const std::string &bytes);

#endif
