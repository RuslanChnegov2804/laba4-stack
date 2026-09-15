#include "tree.h"

#include <iostream>

Tree::Tree()
    : root_(nullptr), size_(0) {
}

Tree::~Tree() {
    clear();
}

Tree::Node* Tree::insert(Node* node, int value) {
    if (node == nullptr) {
        ++size_;
        return new Node{value, nullptr, nullptr};
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    }
    else if (value > node->value) {
        node->right = insert(node->right, value);
    }

    return node;
}

void Tree::insert(int value) {
    root_ = insert(root_, value);
}

bool Tree::search(Node* node, int value) const {
    if (node == nullptr) {
        return false;
    }

    if (value == node->value) {
        return true;
    }

    if (value < node->value) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

bool Tree::search(int value) const {
    return search(root_, value);
}

void Tree::printInOrder(Node* node, bool& first) const {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left, first);

    if (!first) {
        std::cout << " ";
    }

    std::cout << node->value;
    first = false;

    printInOrder(node->right, first);
}

void Tree::print() const {
    bool first = true;
    printInOrder(root_, first);
    std::cout << '\n';
}

void Tree::clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);

    delete node;
}

void Tree::clear() {
    clear(root_);
    root_ = nullptr;
    size_ = 0;
}

bool Tree::empty() const {
    return root_ == nullptr;
}

std::size_t Tree::size() const {
    return size_;
}
