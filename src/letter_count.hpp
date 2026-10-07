#pragma once
#include <iostream>
#include <string>
#include <cctype>

constexpr int N_CHARS = ('Z' - 'A' + 1);

inline int char_to_index(char ch) {
    return toupper(static_cast<unsigned char>(ch)) - 'A';
}

inline char index_to_char(int i) {
    return 'A' + i;
}

inline void count(std::string s, int counts[]) {
    for (int i = 0; i < s.length(); i++) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (isalpha(c)) {
            counts[char_to_index(c)]++;
        }
    }
}

inline void print_counts(int counts[], int len = N_CHARS) {
    for (int i = 0; i < len; i++) {
        std::cout << index_to_char(i) << " " << counts[i] << std::endl;
    }
}
