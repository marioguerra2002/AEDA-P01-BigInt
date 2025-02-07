#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>


class BigUnsigned {
  public:
    /// constructores
    BigUnsigned(unsigned n = 0);
    // constructor que recibe un entero, que simboliza el numero de digitos
    BigUnsigned(const unsigned char*); 
    // constructor que recibe un arreglo de char el cual simboliza el numero
    BigUnsigned(const BigUnsigned&);
    // constructor de copia

    BigUnsigned& operator=(const BigUnsigned&); // operador de asignacion

    friend std::ostream& operator<<(std::ostream&, const BigUnsigned&);
    // operador de salida
    friend std::istream& operator>>(std::istream&, BigUnsigned&);
    // operador de entrada
    bool operator==(const BigUnsigned&) const;
    // operador de igualdad
    friend bool operator<(const BigUnsigned&, const BigUnsigned&); 
    // es friend  porque no es un metodo de la clase

    /// operadores incremento-decremento

    BigUnsigned& operator++(); // pre-incremento
    BigUnsigned operator++(int); // post-incremento
    // la diferencia entre pre y post incremento 
    // es que el pre incremento devuelve una referencia al objeto incrementado y el
    // post incremento devuelve una copia del objeto antes de incrementarlo
    BigUnsigned& operator--(); // pre-decremento
    BigUnsigned operator--(int); // post-decremento

    /// operadores aritmeticos

    friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
    // es friend porque no es un metodo de la clase
    BigUnsigned& operator-(const BigUnsigned&) const;
    BigUnsigned& operator*(const BigUnsigned&) const;
    friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
    BigUnsigned& operator%(const BigUnsigned&) const;

  private:
    std::vector<unsigned char> digits;
};