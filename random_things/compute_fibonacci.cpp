// compute_fibonacci.cpp

/*
  Author: Desmond Gold
  Created: May 2, 2021
*/

// computes fibonacci sequence in many ways:

#include <concepts>
#include <cmath>
#include <numbers>
#include <iostream>

template <std::integral T>
constexpr T fib(T n) {
  auto phi = std::numbers::phi_v<long double>;
  return std::round((std::pow(phi, n) - std::pow(-phi, -n)) / std::sqrt(5.0l));
}

int main(int argc, char** argv) {
  for (int i = 0; i <= 20; i++) {
    std::cout
    << "fib(" << i << ") = "
    << fib(i) << '\n';
  } 
  std::cout << '\n';
  
  return 0;
}
