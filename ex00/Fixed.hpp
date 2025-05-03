/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:08:36 by pracksaw          #+#    #+#             */
/*   Updated: 2025/05/03 19:42:19 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawValue;          // Stores fixed-point value
    static const int    _fractionalBits = 8; // Always 8 bits for fractional part

public:
    Fixed();                               // Default constructor
    Fixed(const Fixed &other);             // Copy constructor
    Fixed& operator=(const Fixed &other);  // Copy assignment operator
    ~Fixed();                              // Destructor

    int     getRawBits() const;            // Returns raw fixed-point value
    void    setRawBits(int const raw);     // Sets raw fixed-point value
};

#endif
