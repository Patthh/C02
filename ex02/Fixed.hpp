/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:36 by pracksaw          #+#    #+#             */
/*   Updated: 2025/05/06 13:05:39 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef FIXED_HPP
 #define FIXED_HPP
#include <cmath> // For roundf
#include <iostream>

class Fixed {
private:
	int                 _rawValue;          // Stores fixed-point value
	static const int    _fractionalBits = 8; // Always 8 bits for fractional part

public:
	Fixed();                               // Default constructor
	Fixed(const Fixed &other);             // Copy constructor
	Fixed(const int value);                // Int constructor
	Fixed(const float value);              // Float constructor
	Fixed& operator=(const Fixed &other);  // Copy assignment operator
	~Fixed();                              // Destructor

	int     getRawBits() const;            // Returns raw fixed-point value
	void    setRawBits(int const raw);     // Sets raw fixed-point value

	float   toFloat() const;               // Converts to float
	int     toInt() const;                 // Converts to int

	// Comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Increment/decrement operators
	Fixed& operator++();      // Pre-increment
	Fixed operator++(int);    // Post-increment
	Fixed& operator--();      // Pre-decrement
	Fixed operator--(int);    // Post-decrement

	// Static member functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

// Overload << to output the fixed-point number as a float
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif