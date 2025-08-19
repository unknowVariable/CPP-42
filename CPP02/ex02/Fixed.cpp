#include "Fixed.hpp"

// Constructeurs / Destructeur / Affectation

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
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

// Accesseurs

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

// Conversions

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// Opérateurs de comparaison

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

// Opérateurs arithmétiques

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    // Multiplication en 64 bits pour éviter les débordements puis normalisation
    long long prod = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result._fixedPointValue = static_cast<int>( prod >> _fractionalBits );
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    // Division en étendant en 64 bits pour conserver la précision
    long long divd = static_cast<long long>(this->_fixedPointValue) << _fractionalBits;
    result._fixedPointValue = static_cast<int>( divd / other._fixedPointValue );
    return result;
}

// Opérateurs d'incrémentation/décrémentation

Fixed& Fixed::operator++() {       // pré-incrémentation
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {     // post-incrémentation
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() {       // pré-décrémentation
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {     // post-décrémentation
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// Fonctions statiques min / max

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a._fixedPointValue < b._fixedPointValue ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a._fixedPointValue < b._fixedPointValue ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a._fixedPointValue > b._fixedPointValue ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a._fixedPointValue > b._fixedPointValue ? a : b);
}

// Surcharge opérateur << (sortie)
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
