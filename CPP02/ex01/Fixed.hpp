#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>  // pour roundf

class Fixed {
public:
    Fixed();                           // Constructeur par défaut
    Fixed(const Fixed &other);         // Constructeur de copie
    Fixed(const int value);            // Constructeur depuis un entier
    Fixed(const float value);          // Constructeur depuis un flottant
    Fixed& operator=(const Fixed &other);   // Opérateur d’affectation
    ~Fixed();                          // Destructeur

    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;         // Conversion en float
    int   toInt(void) const;           // Conversion en int

private:
    int                  _fixedPointValue;
    static const int     _fractionalBits = 8;
};

// Surcharge de l’opérateur d’insertion sortie (déclaration hors classe)
std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif
