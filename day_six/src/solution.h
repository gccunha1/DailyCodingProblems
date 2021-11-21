#ifndef SOLUTION_H
#define SOLUTION_H

#include <ostream>
#include <iostream>
#include <cstdint>

template <class T>
class EfficientDoubleLinkedList
{
private:
    struct Node
    {
        T val;
        Node *both;
        Node(T new_val) : val{new_val}, both{nullptr} {}
    };

    Node *head;
    Node *tail;
    int size;

    Node *NodeXOR(Node *node1, Node *node2)
    {
        return reinterpret_cast<Node *>(reinterpret_cast<std::uintptr_t>(node1) ^ reinterpret_cast<std::uintptr_t>(node2));
    }

    Node *GetNextNode(Node *current_node, Node *previous_node = nullptr)
    {
        if (current_node == nullptr)
            throw std::invalid_argument("Received nullptr as current_node");
        return NodeXOR(current_node->both, previous_node);
    }

public:
    EfficientDoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0}
    {
    }
    ~EfficientDoubleLinkedList()
    {
        FreeMemory();
    }
    void Add(T element)
    {
        try
        {
            Node *new_node = new Node(element);
            size++;
            if (tail == nullptr)
            {
                head = new_node;
                tail = new_node;
                return;
            }
            tail->both = NodeXOR(tail->both, new_node);
            new_node->both = NodeXOR(new_node->both, tail);
            tail = new_node;
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << e.what() << '\n';
            FreeMemory();
            exit(1);
        }
    }
    T Get(int index)
    {
        if (index < 0 || index >= size)
            throw std::invalid_argument("Index out of bounds");

        Node *current_node = nullptr, *previous_node = nullptr, *buffer_pointer = nullptr;
        int start_index;

        if (index < size / 2)
        {
            current_node = head;
            start_index = 0;
        }
        else
        {
            current_node = tail;
            start_index = size - 1;
        }

        for (int i = 0; i < abs(index - start_index) && current_node != nullptr; i++)
        {
            buffer_pointer = current_node;
            current_node = GetNextNode(current_node, previous_node);
            previous_node = buffer_pointer;
        }
        return current_node->val;
    }
    void FreeMemory()
    {
        Node *current_node = head, *previous_node = nullptr, *buffer_pointer = nullptr;

        //Loop through list
        while (current_node != nullptr)
        {
            //free memory
            buffer_pointer = current_node;
            current_node = GetNextNode(current_node, previous_node);
            previous_node = buffer_pointer;
            delete previous_node;
        }
    }
};

#endif
