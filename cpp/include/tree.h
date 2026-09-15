#pragma once

#include <cstddef>

class Tree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
    };

    Node* root_;
    std::size_t size_;

    Node* insert(Node* node, int value);
    bool search(Node* node, int value) const;
    void printInOrder(Node* node, bool& first) const;
    void clear(Node* node);

public:
    Tree();
    ~Tree();

    void insert(int value);
    bool search(int value) const;

    void print() const;
    void clear();

    bool empty() const;
    std::size_t size() const;
};
