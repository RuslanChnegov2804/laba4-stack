#include "tree.h"

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(TreeTest, NewTreeIsEmpty) {
    Tree tree;

    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST(TreeTest, InsertAddsElements) {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    EXPECT_FALSE(tree.empty());
    EXPECT_EQ(tree.size(), 3);
}

TEST(TreeTest, SearchFindsExistingElement) {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(20));
}

TEST(TreeTest, SearchReturnsFalseForMissingElement) {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    EXPECT_FALSE(tree.search(100));
}

TEST(TreeTest, ClearRemovesAllElements) {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    tree.clear();

    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST(TreeTest, DuplicateValueDoesNotIncreaseSize) {
    Tree tree;

    tree.insert(10);
    tree.insert(10);

    EXPECT_EQ(tree.size(), 1);
}

TEST(TreeTest, PrintShowsElementsInSortedOrder) {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(7);

    std::ostringstream output;
    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    tree.print();

    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(output.str(), "5 7 10 20\n");
}
