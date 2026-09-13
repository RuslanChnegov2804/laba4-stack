#pragma once

#include <cstddef>

class Stack {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* top_;
    std::size_t size_;

    void printFromBottom(Node* node, bool& first) const;
    
public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    int top() const;

    bool empty() const;
    std::size_t size() const;

    void clear();
    void print() const;
};
