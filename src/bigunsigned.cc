#include "bigunsigned.h"

BigUnsigned::BigUnsigned(unsigned n) {
  // Pedimos el número al usuario
  std::string input;
  std::cout << "Ingrese el número: ";
  std::cin >> input;
  // en caso de que no se haya ingresado un numero
  if (input.size() == 0) {
    input = "0";
  }

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

BigUnsigned& BigUnsigned::operator--() {
  // decrementamos el ultimo digito
  // en caso de que sea necesario acarreo (que el ultimo digito sea 0)
  // decrementamos el siguiente digito
  std::vector<unsigned char> aux = digits;
  aux[digits.size() - 1]--;
  for (int i = digits.size() - 1; i > 0; i--) {
    if (aux[i] == 255) {
      aux[i] = 9;
      aux[i - 1]--;
    }
  }
  // en caso de que el primer digito necesite también acarreo
  if (aux[0] == 0) {
    aux.erase(aux.begin());
  }
  digits = aux;
  return *this;
}

// // post-decremento
BigUnsigned BigUnsigned::operator--(int) {
  BigUnsigned temp = *this; // guardamos el valor actual
  --(*this); // decrementamos el valor
  return temp; // devolvemos el valor guardado del principio
}

// // operadores aritmeticos

// friend operator+

BigUnsigned operator+(const BigUnsigned& num1, const BigUnsigned& num2) {
  // // creamos un vector auxiliar para guardar el resultado
  // std::vector<unsigned char> aux;
  // std::cout << "num1: " << num1 << std::endl;
  // std::cout << "num2: " << num2 << std::endl;
  // // primero ver cual es el vector mas grande (el numero mas grande)
  // // redimensionamos el vector al tamaño correcto
  // // if (num1.digits.size() > num2.digits.size()) {
  // //   aux.resize(num1.digits.size());
  // // } else {
  // //   aux.resize(num2.digits.size());
  // // } 
  // // en caso de que un numero sea 0, devolvemos el otro numero
  // if (num1.getDigits()[0] == '0') {
  //   std::cout << "num1 es 0" << std::endl;
  //   return num2;
  // } else if (num2.getDigits()[0] == '0') {
  //   std::cout << "num2 es 0" << std::endl;
  //   return num1;
  // }
  // BigUnsigned result;
  // return result;
  BigUnsigned result;
  std::vector<unsigned char> aux;

  // Tamaño del número más grande
  size_t max_size = std::max(num1.digits.size(), num2.digits.size()); // Tamaño del número más grande
  aux.resize(max_size + 1, 0); // Se deja espacio para el acarreo

  int carry = 0; // Acarreo inicial
  int i = num1.digits.size() - 1, j = num2.digits.size() - 1, k = max_size; 
  // Sumamos los dígitos de ambos números y el acarreo
  // el acarreo es la division de la suma entre 10 

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += num1.digits[i--];
    if (j >= 0) sum += num2.digits[j--];

    carry = sum / 10;
    aux[k--] = sum % 10;
  }

  // Si el primer dígito es 0, lo eliminamos
  if (aux[0] == 0) {
    aux.erase(aux.begin());
  }

  result.digits = aux;
  return result;
}

  


BigUnsigned& BigUnsigned::operator-(const BigUnsigned& other) const {
  // // creamos un vector auxiliar para guardar el resultado
  // std::vector<unsigned char> aux;
  // // redimensionamos el vector al tamaño correcto
  // aux.resize(digits.size());
  // // inicializamos el vector en 0
  // for (unsigned i = 0; i < aux.size(); i++) {
  //   aux[i] = 0;
  // }
  // // restamos los digitos
  // for (int i = digits.size() - 1; i >= 0; i--) {
  //   aux[i] += digits[i] - num.digits[i];
  //   if (aux[i] < 0) {
  //     aux[i] += 10;
  //     aux[i - 1]--;
  //   }
  // }
  // // en caso de que el primer digito sea 0
  // if (aux[0] == 0) {
  //   aux.erase(aux.begin());
  // }
  // BigUnsigned result;
  // result.digits = aux;
  // return result;
  // Verificar que el número actual (*this) sea mayor o igual que el otro
  if (*this < other) {
    throw std::underflow_error("Resultado negativo no permitido en BigUnsigned");
    // no se permiten resultados negativos
  }

  // Crear un objeto para almacenar el resultado
  BigUnsigned* result = new BigUnsigned(*this); // Copiamos *this

  int borrow = 0;  // Variable para manejar los "préstamos"
  int i = result->digits.size() - 1; // Última posición de *this
  int j = other.digits.size() - 1;   // Última posición de other

  while (i >= 0) {
    int diff = result->digits[i] - borrow;

    if (j >= 0) {
        diff -= other.digits[j];
        j--;
    }

    if (diff < 0) {
      diff += 10;   // Se toma un préstamo de la siguiente posición
      borrow = 1;   // Indicar que en la siguiente iteración hay préstamo
    } else {
      borrow = 0;   // No hay préstamo si la resta es positiva
    }

    result->digits[i] = diff;
    i--;
  }

  // Eliminar ceros a la izquierda
  while (result->digits.size() > 1 && result->digits[0] == 0) {
    result->digits.erase(result->digits.begin());
  }

  return *result;
}




