#include <iostream>

int main() {
  char c = '0';
  c--;
  if (c == '/') {
    c = '9';
  } else {
    std::cout << "No es igual" << std::endl;
  }
  std::cout << c << std::endl;
}