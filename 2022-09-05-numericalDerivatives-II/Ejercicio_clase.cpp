#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

double f(double x);
double g(double x);
double forward_deriv(double x, double h);
double central_deriv(double x, double h);

int main(void) {
  std::ofstream fout;
  fout.precision(16);
  fout.setf(std::ios::scientific);
  fout.open("datos-h.txt");

  double h, x, dx, d, m, dexact;

  dx = 0.1;
  x = 1.2345;

  for (h = 1.0e-18; h <= 0.1; h *= 10) {
    d = forward_deriv(x, h);
    m = central_deriv(x, h);
    dexact = 2 * std::cos(2 * x);
    fout << h << "\t" << d << "\t" << m << "\t" << std::fabs(1 - d / dexact) << "\t" << std::fabs(1 - m / dexact) << std::endl;
  }

  fout.close();

  return 0;
}

double f(double x) {
  return std::sin(2 * x);
}

double g(double x) {
  return 2 * std::cos(2 * x);
}

double forward_deriv(double x, double h) {
  return (f(x + h) - f(x)) / h;
}
double central_deriv(double x, double h) {
  return (f(x + h / 2) - f(x - h / 2)) / h;
}
