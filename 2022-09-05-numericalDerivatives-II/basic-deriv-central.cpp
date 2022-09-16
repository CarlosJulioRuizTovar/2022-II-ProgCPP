#include <cstdio> // to use std::printf
#include <cmath> // to use std::sin

double f(double x);
double fderivforward(double x, double h);
double fderivcentral(double x, double h);

int main(void) {
  double x = M_PI / 3;
  double h = 0.1;
  std::printf("%25.16e\n", std::cos(x));
  std::printf("%25.16e\n", fderivforward(x, h));
  std::printf("%25.16e\n", fderivcentral(x, h));

  return 0;
}

double f(double x) {
  double result = std::sin(x);
  return result;
}

double fderivforward(double x, double h) {
  double result = (f(x + h) - f(x)) / h;
  return result;
}

double fderivcentral(double x, double h) {
  double result = (f(x + h / 2) - f(x - h / 2)) / h;
  return result;
}
