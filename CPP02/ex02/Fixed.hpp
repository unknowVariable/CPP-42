#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    // Constructeurs / Destructeur
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int value);
    Fixed(const float value);
    Fixed& operator=(const Fixed &other);
    ~Fixed();

    // Accesseurs
    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

    // Opérateurs de comparaison
    bool  operator>(const Fixed &other) const;
    bool  operator<(const Fixed &other) const;
    bool  operator>=(const Fixed &other) const;
    bool  operator<=(const Fixed &other) const;
    bool  operator==(const Fixed &other) const;
    bool  operator!=(const Fixed &other) const;

    // Opérateurs arithmétiques
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Opérateurs d'incrémentation/décrémentation
    Fixed& operator++();    // pré-incrémentation
    Fixed  operator++(int); // post-incrémentation
    Fixed& operator--();    // pré-décrémentation
    Fixed  operator--(int); // post-décrémentation

    // Fonctions statiques min et max
    static Fixed&       min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed&       max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;
};

// Surcharge de l'opérateur de sortie <<
std::ostream& operator<<(std::ostream &out, const Fixed &value);

#endif
