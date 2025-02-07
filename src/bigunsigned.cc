#include "bigunsigned.h"

BigUnsigned::BigUnsigned(unsigned n) {
  // Pedimos el número al usuario
  std::string input;
  std::cout << "Ingrese el número: ";
  std::cin >> input;

  // Redimensionamos el vector al tamaño correcto
  digits.resize(input.size());

  // Convertimos cada carácter en un número (restando '0')
  for (unsigned i = 0; i < input.size(); i++) {
    if (input[i] < '0' || input[i] > '9') {
      throw std::invalid_argument("Entrada no válida. Se esperaban solo dígitos.");
    }
    digits[i] = input[i] - '0';  // Conversión ASCII a valor numérico
  }
}


BigUnsigned::BigUnsigned(const unsigned char* num) {
  // comprobar primero que el *char.size sea menor o igual al tamaño del vector
  // si no es asi, se debe redimensionar el vector
  if (digits.size() < strlen((char*)num)) {
    digits.resize(strlen((char*)num));
  }
  // recorremos el arreglo de char y lo guardamos en el vector caracter por caracter
  for (unsigned i = 0; num[i] != '\0'; i++) {
    digits.push_back(num[i]); // guardamos el caracter en el vector
  }
}

BigUnsigned::BigUnsigned(const BigUnsigned& num) {
  // copiamos el vector de digitos
  digits = num.digits;
}

// operador de salida

std::ostream& operator<<(std::ostream& os, const BigUnsigned& num) {
  // recorremos el vector y lo imprimimos
  char aux;
  for (unsigned i = 0; i < num.digits.size(); i++) {
    aux = num.digits[i] + '0'; // convertimos el numero a caracter
    os << aux; // imprimimos el caracter
  }
  return os;
}

// operador de entrada

std::istream& operator>>(std::istream& is, BigUnsigned& num) {
  // pedimos el numero al usuario
  std::string input;
  is >> input;
  // redimensionamos el vector al tamaño correcto
  num.digits.resize(input.size());
  // convertimos cada caracter en un numero (restando '0')
  for (unsigned i = 0; i < input.size(); i++) {
    if (input[i] < '0' || input[i] > '9') {
      throw std::invalid_argument("Entrada no válida. Se esperaban solo dígitos.");
    }
    num.digits[i] = input[i] - '0';  // Conversión ASCII a valor numérico
  }
  return is;
}

bool BigUnsigned::operator==(const BigUnsigned& num) const {
  // comparamos el tamaño de los vectores
  if (digits.size() != num.digits.size()) {
    return false;
  }
  // comparamos cada digito
  for (unsigned i = 0; i < digits.size(); i++) {
    if (digits[i] != num.digits[i]) {
      return false;
    }
  }
  return true;
}

bool operator<(const BigUnsigned& num1, const BigUnsigned& num2) {
  // comparamos el tamaño de los vectores
  if (num1.digits.size() < num2.digits.size()) {
    return true;
  } else if (num1.digits.size() > num2.digits.size()) {
    return false;
  }
  // comparamos cada digito
  bool flag = false;
  for (unsigned i = 0; i < num1.digits.size(); i++) {
    if (num1.digits[i] < num2.digits[i]) {
      flag = true;
    } else if (num1.digits[i] > num2.digits[i]) {
      flag = false;
    }
  }
  return flag;
}

BigUnsigned& BigUnsigned::operator=(const BigUnsigned& num) {
  // copiamos el vector de digitos
  digits = num.digits;
  return *this;
}

BigUnsigned& BigUnsigned::operator++() {
  digits[digits.size() - 1]++; // incrementamos el ultimo digito
  // acarreo en caso de que sea necesario
  for (int i = digits.size() - 1; i > 0; i--) {
    if (digits[i] == 10) {
      digits[i] = 0;
      digits[i - 1]++;
    }
  }
  // en caso de que el primer digito necesite también acarreo
  if (digits[0] == 10) {
    digits[0] = 0;
    digits.insert(digits.begin(), 1);
  }

  return *this;

}

// post-incremento

BigUnsigned BigUnsigned::operator++(int) {
  BigUnsigned temp = *this; // guardamos el valor actual
  ++(*this); // incrementamos el valor
  return temp; // devolvemos el valor guardado del principio
}

// pre-decremento

// BigUnsigned& BigUnsigned::operator--() {
//   // decrementamos el ultimo digito
//   digits[digits.size() - 1]--;
//   // acarreo en caso de que sea necesario
//   for (int i = digits.size() - 1; i > 0; i--) {
//     if (digits[i] == -1) {
//       digits[i] = 9;
//       digits[i - 1]--;
//     }
//   }
//   // en caso de que el primer digito necesite también acarreo
//   if (digits[0] == 0) {
//     digits.erase(digits.begin());
//   }

//   return *this;
// }


