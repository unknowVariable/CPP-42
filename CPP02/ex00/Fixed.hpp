#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();                         // Constructeur par défaut
    Fixed(const Fixed &other);       // Constructeur de copie
    Fixed& operator=(const Fixed &other); // Opérateur d’affectation
    ~Fixed();                        // Destructeur

    int  getRawBits(void) const;     // Accesseur de la valeur brute
    void setRawBits(int const raw);  // Mutateur de la valeur brute

private:
    int               _fixedPointValue;               // Valeur du nombre en virgule fixe (partie entière)
    static const int  _fractionalBits = 8;            // Nombre de bits fractionnaires (constant, ici 8)
};

#endif