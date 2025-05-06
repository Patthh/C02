/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:38 by pracksaw          #+#    #+#             */
/*   Updated: 2025/05/06 13:05:59 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue) {
	// std::cout << "Copy constructor called" << std::endl;
}

// Int constructor: converts int to fixed-point
Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits) {
	// std::cout << "Int constructor called" << std::endl;
}

// Float constructor: converts float to fixed-point (rounded)
Fixed::Fixed(const float value) : _rawValue(roundf(value * (1 << _fractionalBits))) {
	// std::cout << "Float constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawValue = other._rawValue;
	return *this;
}

// Destructor
Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

// Returns raw fixed-point value
int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}

// Sets raw fixed-point value
void Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

// Converts fixed-point to float
float Fixed::toFloat() const {
	return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

// Converts fixed-point to int (truncates fractional part)
int Fixed::toInt() const {
	return _rawValue >> _fractionalBits;
}

// Overload << operator to output the float representation
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
	return _rawValue > other._rawValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return _rawValue < other._rawValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _rawValue >= other._rawValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _rawValue <= other._rawValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return _rawValue == other._rawValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _rawValue != other._rawValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_rawValue + other._rawValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_rawValue - other._rawValue);
	return result;
}

// We need to be careful with overflow, so we use a larger type for multiplication
// Then shift back by _fractionalBits to get the correct fixed-point value
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((static_cast<long long>(_rawValue) * static_cast<long long>(other._rawValue)) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	// Division by zero will crash as specified in the requirements
	Fixed result;
	// We shift the dividend left by _fractionalBits to maintain precision
	result.setRawBits((static_cast<long long>(_rawValue) << _fractionalBits) / other._rawValue);
	return result;
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
	// Pre-increment: increment and return the reference
	++_rawValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	// Post-increment: return the current value, then increment
	Fixed temp(*this);
	++_rawValue;
	return temp;
}

Fixed& Fixed::operator--() {
	// Pre-decrement: decrement and return the reference
	--_rawValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	// Post-decrement: return the current value, then decrement
	Fixed temp(*this);
	--_rawValue;
	return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
