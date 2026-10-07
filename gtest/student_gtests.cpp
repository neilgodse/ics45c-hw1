// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE:

TEST(StackTests, EmptyReturnsAt) {
    Stack s;
    EXPECT_EQ(s.top(), '@');
    EXPECT_EQ(s.pop(), '@');
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTests, OneChar) {
    Stack s;
    s.push('a');
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.top(), 'a');
    EXPECT_EQ(s.top(), 'a');
    EXPECT_EQ(s.pop(), 'a');
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.pop(), '@');
}

TEST(StackTests, LIFOOrder) {
    Stack s;
    s.push('a'); s.push('b'); s.push('c');
    EXPECT_EQ(s.pop(), 'c');
    EXPECT_EQ(s.pop(), 'b');
    EXPECT_EQ(s.pop(), 'a');
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTests, FullAtCapacity) {
    Stack s;
    for (int i = 0; i < STK_MAX - 1; ++i) s.push('x');
    EXPECT_FALSE(s.isFull());
    s.push('y');
    EXPECT_TRUE(s.isFull());
    s.push('z');
    EXPECT_EQ(s.top(), 'y');
    int n = 0;
    while (!s.isEmpty()) { s.pop(); ++n; }
    EXPECT_EQ(n, STK_MAX);
}

TEST(StackTests, FullOrderPreserved) {
    Stack s;
    for (int i = 0; i < STK_MAX; ++i) s.push(static_cast<char>('a' + i % 26));
    for (int i = STK_MAX - 1; i >= 0; --i)
        EXPECT_EQ(s.pop(), static_cast<char>('a' + i % 26));
}

TEST(StackTests, PushAllPopAll) {
    Stack s;
    testing::internal::CaptureStdout();
    push_all(s, "hello");
    pop_all(s);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "olleh\n");
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTests, PopAllEmpty) {
    Stack s;
    testing::internal::CaptureStdout();
    pop_all(s);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "\n");
}
