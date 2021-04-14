#ifndef BATO_BATO_PICK_HPP
#define BATO_BATO_PICK_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
#include <deque>
#include <cstdlib>

// INTRODUCTION
/*
    Number 1 = BATO
    Number 2 = GUNTING
    Number 3 = PAPEL

    ------------------

    BATO    beats GUNTING   > +1 POINT
    GUNTING beats PAPEL     > +1 POINT
    PAPEL   beats BATO      > +1 POINT

    ------------------

    THE SAME CHOICES WILL BE TIE

    ------------------

    0   if TIE
    -1  if YOU BEAT THE OPPONENT
    1   if THE OPPONENT BEATS YOU

*/

// INTERFACES
namespace bato_bato {
    int parse(const std::string&);
    int pick(const std::string&, const std::string&);
}

// IMPLEMENTATIONS
int bato_bato::parse(const std::string& choice) {
    int result;
    std::string temporary = choice;
    std::transform(
        temporary.begin(), temporary.end(), temporary.begin(),
        [](auto c){
            return std::tolower(c);
        }
    );

    if (
        temporary == "bato"
    )   result = 1;

    else if (
        temporary == "gunting"
    )   result = 2;

    else if (
        temporary == "papel"
    )   result = 3;

    else
        result = 0;

    return result;
}

int bato_bato::pick(const std::string& choice_1,
                   const std::string& choice_2) {

    int* result_1 = new int(bato_bato::parse(choice_1));
    int* result_2 = new int(bato_bato::parse(choice_2));
    int winner;

    if (*result_1 == *result_2)
        winner = 0;

    else if (
        (*result_1 == 1 && *result_2 == 2) ||
        (*result_1 == 2 && *result_2 == 3) ||
        (*result_1 == 3 && *result_2 == 1)
    )
        winner = -1;

    else if (
        (*result_2 == 1 && *result_1 == 2) ||
        (*result_2 == 2 && *result_1 == 3) ||
        (*result_2 == 3 && *result_1 == 1)
    )
        winner = 1;

    else if (
        (*result_1 == 0 || *result_2 == 0)
    )
        winner = -2;

    delete result_1;
    delete result_2;
    return winner;
}

#endif // BATO_BATO_PICK_HPP
