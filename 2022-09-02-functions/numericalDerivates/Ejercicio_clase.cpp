/* García Martínez Juan Diego
Martínez Correales Adriana Yaneth
Sánchez Poveda Juan Felipe
Guzmán López Nicolás
Ruiz Tovar Carlos Julio */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

double f(double x);
double g(double x);
double forward_deriv(double x, double h);

int main(void) {
  std::ofstream fout;
  fout.precision(16); fout.setf(std::ios::scientific);
  fout.open("datos.txt");

  double h, x, dx, d, dh, dexact;

  x = 1.2345;
  dx = 0.1;
  dh = 10;
  for (h = 1.0e-18; h <= 1.0e-1; h *= dh) {
    d = forward_deriv(x, h);
    dexact = 2 * std::cos(2 * x);
    fout << h << "\t" << d << "\t\t" << std::fabs(1 - d / dexact) << std::endl;
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
