#include <iostream>

int main(int arg, char **argv) {

  double * data;
  data = new double [20]; // ask for memory

  std::cout << "data[0] = " << data[0] << std::endl;
  std::cout << "&data[0] = " << &data[0] << std::endl;
  std::cout << "&data[1] = " << &data[1] << std::endl;
  std::cout << "data = " << data << std::endl; // this is the same as &data[0]
  std::cout << "data[20] = " << data[20] << std::endl; // ERROR copilot
  std::cout << "data[-1] = " << data[-1] << std::endl; // ERROR

  delete [] data; // free memory

  return 0;
}

// data[5] -> data + 5 * sizeof(double)
// data[20] -> data + 20 * sizeof(double)
// data[-1] -> data - 1 * sizeof(double)