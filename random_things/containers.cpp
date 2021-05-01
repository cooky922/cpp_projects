/**
    > STL Containers
    > STL Container Adapters

    > STL Algebraic Data Types
*/

/**
    LIST OF CONTAINERS:

    Sequence:
    > array
    > vector
    > deque
    > forward_list
    > list

    Associative:
    > set
    > map
    > multiset
    > multimap
    > unordered_set
    > unordered_map
    > unordered_multiset
    > unordered_multimap

    Container Adaptors:
    > stack
    > queue
    > priority_queue

    Non-owning View
    > span
*/
#define WAIT [[maybe_unused]]
#include <iostream>

#include "Containers.hpp"

template <typename Cont>
    requires Container<Cont> || Container_Adaptor<Cont>
std::ostream& operator<<(std::ostream& os, Cont cont) {
    for (const auto& elem : cont)
        os << elem << ' ';
    return os;
}

int main() {

    // Array
    WAIT std::array<int, 5> array_1 = {10, 3, 5, 0, 2};
    WAIT std::array array_2 = {"one", "two", "three",};
    // -> std::array<const char*, 3>
    std::cout << array_1 << '\n';

    return 0;
}
