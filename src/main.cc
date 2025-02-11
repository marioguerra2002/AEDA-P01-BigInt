#include "bigunsigned.h"

int main() {
  // vamos a probar el construtor y el operador de salida

  BigUnsigned num1(5); // creamos un objeto con 5 digitos
  std::cout << num1 << std::endl; // imprimimos el objeto
  BigUnsigned num2(10); // creamos un objeto con 10 digitos
  std::cout << num2 << std::endl; // imprimimos el objeto
  // BigUnsigned num2(10);
  // std::cout << num2 << std::endl;

  // if (num1 == num2) {
  //   std::cout << "Son iguales" << std::endl;
  // } else {
  //   std::cout << "No son iguales" << std::endl;
  // }
  // if (num1 < num2) {
  //   std::cout << "num1 es menor que num2" << std::endl;
  // } else {
  //   std::cout << "num1 no es menor que num2" << std::endl;
  // }
  
  // prueba de pre-incremento
  // std::cout << "num1: " << num1 << std::endl;
  // ++num1;
  // std::cout << "num1: " << num1 << std::endl;
  // // prueba de post-incremento
  // std::cout << "num1: " << num1 << std::endl;
  // num1++;
  // std::cout << "num1: " << num1 << std::endl;
  //prueba de pre-decremento
  // std::cout << "num1: " << num1 << std::endl;
  // --num1;
  // std::cout << "num1: " << num1 << std::endl;
  // prueba de post-decremento
  // std::cout << "num1: " << num1 << std::endl;
  // num1--;
  // std::cout << "num1: " << num1 << std::endl;
  // prueba de suma
  
  // if (num1 == num2) {
  //   std::cout << "Son iguales" << std::endl;
  // } else {
  //   std::cout << "No son iguales" << std::endl;
  // }
  // if (num1 < num2) {
  //   std::cout << "num1 es menor que num2" << std::endl;
  // } else {
  //   std::cout << "num1 no es menor que num2" << std::endl;
  // }

  BigUnsigned num3 = num1 + num2;
  std::cout << "num3: " << num3 << std::endl;

  // prueba de resta
  BigUnsigned num4 = num1 - num2;
  std::cout << "num4: " << num4 << std::endl;


}