#include "stack.h"

#include <iostream>
#include <stdexcept>

Stack::Stack() : top_(nullptr), size_(0) {
}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node{value, top_};
    top_ = newNode;
    ++size_;
}

int Stack::pop() {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }

    Node* oldTop = top_;
    int value = oldTop->value;

    top_ = oldTop->next;
    delete oldTop;

    --size_;

    return value;
}

int Stack::top() const {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }

    return top_->value;
}

bool Stack::empty() const {
    return top_ == nullptr;
}

std::size_t Stack::size() const {
    return size_;
}

void Stack::clear() {
    while (top_ != nullptr) {
        Node* oldTop = top_;
        top_ = top_->next;
        delete oldTop;
    }

    size_ = 0;
}

void Stack::printFromBottom(Node* node, bool& first) const {
    if (node == nullptr) {
        return;
    }

    printFromBottom(node->next, first);

    if (!first) {
        std::cout << " ";
    }

    std::cout << node->value;
    first = false;
}

void Stack::print() const {
    bool first = true;
    printFromBottom(top_, first);
    std::cout << '\n';
}
