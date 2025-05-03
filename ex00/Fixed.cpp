/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:38 by pracksaw          #+#    #+#             */
/*   Updated: 2025/05/03 19:45:37 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor: initializes raw value to 0
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;;
}

// Copy constructor: copies raw value from another instance
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator: avoids self-assignment, copies raw value
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawValue = other._rawValue;
    return *this;
}

// Destructor (empty, no dynamic memory to free)
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Returns the raw fixed-point value
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;
}

// Sets the raw fixed-point value
void Fixed::setRawBits(int const raw) {
    _rawValue = raw;
}

/*
Orthodox Canonical Form Compliance:

Default constructor: Initializes _rawValue to 0.

Copy constructor: Copies _rawValue from another instance.

Copy assignment operator: Safely copies _rawValue (avoids self-assignment).

Destructor: Empty, as there’s no dynamic memory.

Fixed-Point Representation:

_rawValue stores the fixed-point number as an integer.

_fractionalBits is a static constant (8 bits for the fractional part).

Accessors:

getRawBits(): Retrieves the raw integer value.

setRawBits(): Modifies the raw integer value.
*/