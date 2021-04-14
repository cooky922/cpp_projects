#ifndef BATO_BATO_DISPLAY_HPP
#define BATO_BATO_DISPLAY_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <custom/console.hpp>

// INTERFACES
namespace bato_bato {
    void intro(std::string&);
    void rules();
}

// IMPLEMENTATIONS
void bato_bato::intro(std::string& name) {
    std::cout
    << "BATO-BATO-PICK!! VERSION BETA 1.0"
    << "\n\n"
    << "Before we play, I should know your name: ";

    std::getline(std::cin, name);

    console::clear_screen();

    std::cout
    << "Hello "
    << name
    << "!"
    << "\n\n";
}

void bato_bato::rules() {

    std::string response;
    std::string rules_list[4] = {
        "#1: You only have 3 choices: (1) Bato, (2) Papel, (3) Gunting <3\n\t",
        "#2: You need 5 points in order to win the game <3\n\t",
        "#3: You can type _ to terminate the game <3\n\t",
        "#4: Your opponent is the computer! So don't loss to your opponent <3\n\n"
    };

    std::cout << "SIMPLE RULES:" << '\n' << '\t';

    [rules_list](auto dur) {
        for (int i = 0; i < 4; i++) {
            console::sleep(dur);
            std::cout
            << "NUMBER "
            << i + 1
            << "...";

            console::sleep(dur);
            console::cursor::set_cursor_position(8, i + 3);
            std::cout << std::string(11, ' ');
            console::cursor::set_cursor_position(8, i + 3);

            std::cout << rules_list[i];
        }
    }(800);

    do {
        std::cout << "Are you ready? (yes/no): ";
        std::getline(std::cin, response);
        if (std::string(strlwr(const_cast<char*>(response.c_str()))) == "yes") {
            console::clear_screen();
            break;
        } else {
            console::cursor::set_cursor_position(0, 8);
            std::cout << std::string(80, ' ');
            console::cursor::set_cursor_position(0, 8);
        }
    } while (true);


//    if (std::string(strlwr(const_cast<char*>((response.c_str())))) == "yes") {
//        std::cout << "I'm glad <33 :> ..." << '\n';
//        console::clear_screen();
//        return;
//    } else /* if (std::string(strlwr(const_cast<char*>((response.c_str())))) == "no") */ {
//        console::clear_screen();
//        bato_bato::rules();
//    }
}

#endif // BATO_BATO_DISPLAY_HPP
