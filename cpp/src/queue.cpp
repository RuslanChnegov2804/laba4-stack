#include "queue.h"

#include <iostream>
#include <stdexcept>

Queue::Queue()
    : front_(nullptr), rear_(nullptr), size_(0) {
}

Queue::~Queue() {
    clear();
}

void Queue::push(int value) {
    Node* newNode = new Node{value, nullptr};

    if (rear_ == nullptr) {
        front_ = newNode;
        rear_ = newNode;
    } else {
        rear_->next = newNode;
        rear_ = newNode;
    }

    ++size_;
}

int Queue::pop() {
    if (empty()) {
        throw std::underflow_error("Queue is empty");
    }

    Node* oldFront = front_;
    int value = oldFront->value;

    front_ = front_->next;

    if (front_ == nullptr) {
        rear_ = nullptr;
    }

    delete oldFront;
    --size_;

    return value;
}

int Queue::front() const {
    if (empty()) {
        throw std::underflow_error("Queue is empty");
    }

    return front_->value;
}

bool Queue::empty() const {
    return front_ == nullptr;
}

std::size_t Queue::size() const {
    return size_;
}

void Queue::clear() {
    while (front_ != nullptr) {
        Node* oldFront = front_;
        front_ = front_->next;
        delete oldFront;
    }

    rear_ = nullptr;
    size_ = 0;
}

void Queue::print() const {
    Node* current = front_;

    bool first = true;

    while (current != nullptr) {
        if (!first) {
            std::cout << " ";
        }

        std::cout << current->value;

        first = false;
        current = current->next;
    }

    std::cout << '\n';
}
