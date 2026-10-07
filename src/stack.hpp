#pragma once
#include <iostream>
#include <string>

constexpr int STK_MAX = 1000;

class Stack {
    int _top;
    char buf[STK_MAX];
public:
    Stack() {
        _top = -1;
    }
    bool isEmpty() {
        return _top == -1;
    }
    bool isFull() {
        return _top == STK_MAX - 1;
    }
    void push(char c) {
        if (!isFull()) {
            buf[++_top] = c;
        }
    }
    char top() {
        if (isEmpty()) return '@';
        return buf[_top];
    }
    char pop() {
        if (isEmpty()) return '@';
        return buf[_top--];
    }
};

inline void push_all(Stack& stk, std::string line) {
    for (int i = 0; i < line.length(); i++) {
        stk.push(line[i]);
    }
}

inline void pop_all(Stack& stk) {
    while (!stk.isEmpty()) {
        std::cout << stk.pop();
    }
    std::cout << std::endl;
}
