// compute_fibonacci.cpp

/*
  Author: Desmond Gold
  Created: May 2, 2021
  Last Edited: May 12, 2021
*/

// computes fibonacci sequence in many ways:

#include <concepts>
#include <cmath>
#include <numbers>
#include <iostream>

// No. 1: Using Binet's Formula
template <std::integral T>
constexpr T fib1(T n) {
  auto phi = std::numbers::phi_v<long double>;
  return std::round((std::pow(phi, n) - std::pow(-phi, -n)) / std::sqrt(5.0l));
}

// No. 2: Using Recursion
template <std::integral T>
constexpr T fib2(T n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fib2(n - 1) + fib2(n - 2);
}

// No. 3: Using a regular for-loop
template <std::integral T>
constexpr T fib3(T n) {
    T a = 1, b = 0, result = 0;
    for (T i = 0; i < n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

// No. 4: Using an array
template <std::integral T>
constexpr T fib4(T n) {
    T f[n + 2];
    f[0] = 0;
    f[1] = 1;

    for (T i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main(int argc, char** argv) {
  for (int i = 0; i <= 20; i++) {
    std::cout
    << "fib(" << i << ") = "
    << fib1(i) << '\n';
  } 
  std::cout << '\n';
  
  return 0;
}
