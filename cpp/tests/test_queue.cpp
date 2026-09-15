#include "queue.h"

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(QueueTest, NewQueueIsEmpty) {
    Queue queue;

    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, PushAddsElements) {
    Queue queue;

    queue.push(10);
    queue.push(20);

    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(queue.front(), 10);
}

TEST(QueueTest, PopRemovesFirstElement) {
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    EXPECT_EQ(queue.pop(), 10);
    EXPECT_EQ(queue.front(), 20);
    EXPECT_EQ(queue.size(), 2);
}

TEST(QueueTest, ClearRemovesAllElements) {
    Queue queue;

    queue.push(10);
    queue.push(20);

    queue.clear();

    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, PopFromEmptyQueueThrowsException) {
    Queue queue;

    EXPECT_THROW(queue.pop(), std::underflow_error);
}

TEST(QueueTest, FrontFromEmptyQueueThrowsException) {
    Queue queue;

    EXPECT_THROW(queue.front(), std::underflow_error);
}

TEST(QueueTest, PrintShowsElementsInCorrectOrder) {
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::ostringstream output;
    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    queue.print();

    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(output.str(), "10 20 30\n");
}
