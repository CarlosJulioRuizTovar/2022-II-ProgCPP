#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>

int main() {
  const int N = 1000;
  std::valarray<double> v;
  v.resize(N);
  double DELTAX = (2 * M_PI - 0.0) / N;
  std::iota(std::begin(v), std::end(v), 0);
  v *= DELTAX;
  std::valarray<double> v2 = std::sin(v);
  std::valarray<double> v3 = v[std::abs(v2) <= 0.5];
  
  for (auto n : v3) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
}