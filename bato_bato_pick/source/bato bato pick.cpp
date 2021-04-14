#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <locale>
#include <cstdlib>

#include "bato bato pick.hpp"
#include "bato bato display.hpp"
#include "bato bato start.hpp"

int main() {

    // . . . DATA
    int winner, your_point{0}, opponent_point{0};
    std::string choice{}, name, random_choice;

    // . . . MAIN DRIVING
    bato_bato::intro(name);
    bato_bato::rules();

    bato_bato::start({
        .winner_arg = winner,
        .your_point_arg = your_point,
        .opponent_point_arg = opponent_point,
        .choice_arg = choice,
        .random_choice_arg = random_choice,
        .name_arg = name
    });

    bato_bato::restart({
        .winner_arg = winner,
        .your_point_arg = your_point,
        .opponent_point_arg = opponent_point,
        .choice_arg = choice,
        .random_choice_arg = random_choice,
        .name_arg = name
    });

    return 0;
}
