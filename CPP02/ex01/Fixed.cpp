#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    // Convertit l’entier en valeur fixe en décalant de 8 bits (multiplication par 256)
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    // Convertit le flottant en valeur fixe en multipliant par 256 et arrondissant
    this->_fixedPointValue = static_cast<int>( roundf(value * (1 << _fractionalBits)) );
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    // Conversion en nombre flottant en divisant par 2^fractionalBits
    return static_cast<float>(this->_fixedPointValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // Conversion en entier (partie entière) par décalage de bits
    return this->_fixedPointValue >> _fractionalBits;
}

// Surcharge de l’opérateur << pour afficher la valeur en virgule fixe sous forme décimale
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
