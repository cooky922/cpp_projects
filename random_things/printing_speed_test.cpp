/**
  Created by: Desmond Gold
  Created: May 12, 2021
*/

#include <iostream>
#include <cstdint>
#include <sstream>
#include <cstdio>
#include <string>
#include <string_view>
#include <fmt/format.h>

// #1: Normal Cout
void drawbox_1(int width, int height, 
               char block = '*', bool new_line = true) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << block;
        }
        std::cout << '\n';
    }
    std::cout << (new_line ? '\n' : '\0');
}

// #2: Using `stringstream`
void drawbox_2(uint8_t width, uint8_t height, 
               char block = '*', bool new_line = true) {
    std::stringstream oss;
    for (uint8_t i = 0; i < height; ++i) {
        for (uint8_t j = 0; j < width; ++j) {
            oss << block;
        }
        oss << '\n';
    }
    oss << (new_line ? '\n' : '\0');
    std::cout << oss.str();
}

// #3: Off-synchronization from `std::stringstream`
void drawbox_3(uint8_t width, uint8_t height, 
               char block = '*', bool new_line = true) {
    std::ios_base::sync_with_stdio(false);
    std::stringstream oss;
    for (uint8_t i = 0; i < height; ++i) {
        for (uint8_t j = 0; j < width; ++j) {
            oss << block;
        }
        oss << '\n';
    }
    oss << (new_line ? '\n' : '\0');
    std::cout << oss.str();
    std::ios_base::sync_with_stdio(true);
}

// #4: Using `std::string` with `.push_back(char)`
void drawbox_4(uint8_t width, uint8_t height,
               char block = '*', bool new_line = true) { 
    std::string string_builder;
    string_builder.reserve(width * height);
    for (uint8_t i = 0; 
         i < (new_line ? height + 1 : height); 
         ++i
    ) {
        for (uint8_t j = 0; j < width; ++j) {
            string_builder.push_back(block);
        }
        string_builder.push_back('\n');
    }
    std::cout << string_builder;
}

// #5 : Normal Cout with String Constructor Multiplier
void drawbox_5(uint8_t width, uint8_t height,
               char block = '*', bool new_line = true) {
    for (int i = 0; i < height; i++) {
        std::cout 
        << std::string(block, width)
        << '\n';
    }
    std::cout << (new_line ? '\n' : '\0');
}

// #i: Using `fmt::format`
void drawbox_i(uint8_t width, uint8_t height,
               char block = '*', bool new_line = true) {
    // unfinished...
}

int main() {
  
  return 0;
}

