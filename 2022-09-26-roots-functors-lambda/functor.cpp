#include <iostream>
#include <cmath> 

struct Functor_f {
  double M = 68.1, G = 9.81, VT = 40.0, T = 10.0;
  double operator() (double x) {
    return M * G * (1 - std::exp(- x * T / M)) / x - VT;
  }
};

int main() {
  Functor_f F;
  std::cout << F(1.23) << "\n";
  F.VT = 30.0;
  std::cout << F(1.23) << "\n";
  return 0;
}
