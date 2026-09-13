#include <gtest/gtest.h>
#include <stdexcept>

#include "stack.h"

TEST(StackTest, NewStackIsEmpty) {
    Stack stack;

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PushAddsElements) {
    Stack stack;

    stack.push(10);
    stack.push(20);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), 20);
}

TEST(StackTest, PopRemovesTopElement) {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.pop(), 30);
    EXPECT_EQ(stack.top(), 20);
    EXPECT_EQ(stack.size(), 2);
}

TEST(StackTest, ClearRemovesAllElements) {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.clear();

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PopFromEmptyStackThrowsException) {
    Stack stack;

    EXPECT_THROW(stack.pop(), std::underflow_error);
}

TEST(StackTest, TopFromEmptyStackThrowsException) {
    Stack stack;

    EXPECT_THROW(stack.top(), std::underflow_error);
}
TEST(StackTest, PrintShowsElementsInCorrectOrder) {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    testing::internal::CaptureStdout();

    stack.print();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30\n");
}
