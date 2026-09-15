#pragma once

#include <cstddef>

class Queue {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* front_;
    Node* rear_;
    std::size_t size_;

public:
    Queue();
    ~Queue();

    void push(int value);
    int pop();
    int front() const;

    bool empty() const;
    std::size_t size() const;

    void clear();
    void print() const;
};
