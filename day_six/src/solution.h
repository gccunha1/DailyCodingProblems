#ifndef SOLUTION_H
#define SOLUTION_H

template <class T>
class EfficientDoubleLinkedList
{
private:
    struct Node
    {
        T val;
        Node *both;
    };
    Node *head;

    Node *GetNextNode(Node *current_node);
    Node *GetPreviousNode(Node *current_node);

public:
    EfficientDoubleLinkedList() : head{nullptr}
    {
    }
    ~EfficientDoubleLinkedList()
    {
        //Loop through list
        //free memory
    }
    void Add(T element);
    T Get(uint8_t index);
};

#endif
