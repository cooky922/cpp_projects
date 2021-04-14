#ifndef BATO_BATO_START_HPP
#define BATO_BATO_START_HPP

#include <iostream>
#include <string>
#include <cstdlib>

// INTERFACES
namespace bato_bato {
    std::string possible_choices[] = {"bato", "gunting", "papel"};

    struct params {
        int& winner_arg;
        int& your_point_arg;
        int& opponent_point_arg;
        std::string& choice_arg;
        std::string& random_choice_arg;
        std::string& name_arg;
    };

    /**
    struct params_restart {
        int& your_point_arg;
        int& opponent_point_arg;
        std::string& name_arg;
    };
    */

    // . . .
    void start(params);
    void restart(params);
}

// IMPLEMENTATIONS
void bato_bato::start(bato_bato::params arg) {
    std::cout << "MY POINTS: " << arg.your_point_arg
    << '\t'   << "OPPONENT POINTS: " << arg.opponent_point_arg
    << '\n' << '\n';

    int coord_y = 2;

    while (true) {
        if (arg.your_point_arg >= 5 || arg.opponent_point_arg >= 5)
            break;

        std::cout << ">>> ";

        console::cursor::set_cursor_position(11, 0);
        std::cout << arg.your_point_arg;
        console::cursor::set_cursor_position(33, 0);
        std::cout << arg.opponent_point_arg;
        console::cursor::set_cursor_position(5, coord_y);

        std::getline(std::cin, arg.choice_arg);

        arg.random_choice_arg = bato_bato::possible_choices[rand() % 3];

        arg.winner_arg = bato_bato::pick(arg.choice_arg, arg.random_choice_arg);

        if (arg.winner_arg == 0) {
            std::cout
            << "TIE"
            << std::string(10, ' ')
            << "\t\t\t\t"
            << "Your Opponent's Choice: "
            << arg.random_choice_arg
            << '\n';

            coord_y += 2;
        }
        else if (arg.winner_arg == -1) {
            std::cout
            << "YOU GOT 1 POINT!"
            << std::string(10, ' ')
            << "\t\t"
            << "Your Opponent's Choice: "
            << arg.random_choice_arg
            << '\n';

            arg.your_point_arg++;
            coord_y += 2;

        } else if (arg.winner_arg == 1) {
            std::cout
            << "YOUR OPPONENT GOT 1 POINT!"
            << std::string(10, ' ')
            << '\t'
            << "Your Opponent's Choice: "
            << arg.random_choice_arg
            << '\n';

            arg.opponent_point_arg++;
            coord_y += 2;
        } else {
             if (arg.choice_arg.find('_') != std::string::npos)
                bato_bato::restart(arg);
             else
                coord_y++;
        }
    }

    console::cursor::set_cursor_position(11, 0);
    std::cout << arg.your_point_arg;
    console::cursor::set_cursor_position(33, 0);
    std::cout << arg.opponent_point_arg;
    console::cursor::set_cursor_position(0, coord_y + 1);

}

void bato_bato::restart(bato_bato::params arg) {
    std::string response;
    std::cout << '\n';

    if (arg.your_point_arg == 5 && arg.your_point_arg > arg.opponent_point_arg)
        std::cout
        << "YOU WIN! :) CONGRATULATIONS "
        << arg.name_arg
        << "! <33"
        << '\n' << '\n';
    else if (arg.opponent_point_arg == 5 && arg.opponent_point_arg > arg.your_point_arg)
        std::cout
        << "YOU LOSE! :( BETTER LUCK NEXT TIME! <33"
        << '\n';

    std::cout << "Do you want to try again? (yes/no): ";
    std::getline(std::cin, response);

    if (std::string(strlwr(const_cast<char*>(response.c_str()))) == "yes") {
        console::clear_screen();
        arg.your_point_arg = 0;
        arg.opponent_point_arg = 0;
        bato_bato::start(arg);
    } else {
        console::clear_screen();
        std::cout
        << "THANK YOU FOR PLAYING <333 SEE YOU AGAIN!!"
        << "\n\n"
        << "Created by Desmond Gold written in C++ 23..."
        << "\n\n";
        std::cin.get();
        exit(0);
    }
}

#endif // BATO_BATO_START_HPP
