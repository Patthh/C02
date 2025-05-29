/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:45:30 by pracksaw          #+#    #+#             */
/*   Updated: 2025/05/21 08:11:58 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return (0);
// }

int main(void) {
	std::cout << "===== CONSTRUCTORS =====" << std::endl;
	Fixed a;                 // Default constructor
	Fixed b(123);            // Int constructor
	Fixed c(456.789f);       // Float constructor
	Fixed d(b);              // Copy constructor
	Fixed e;
	e = c;                   // Assignment operator

	std::cout << "\n===== BASIC VALUES =====" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	std::cout << "\n===== COMPARISON OPERATORS =====" << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "c != e: " << (c != e) << std::endl;

	std::cout << "\n===== ARITHMETIC OPERATORS =====" << std::endl;
	Fixed f = b + c;
	std::cout << "b + c = " << f << std::endl;
	Fixed g = c - b;
	std::cout << "c - b = " << g << std::endl;
	Fixed h = b * c;
	std::cout << "b * c = " << h << std::endl;
	Fixed i = c / b;
	std::cout << "c / b = " << i << std::endl;

	std::cout << "\n===== INCREMENT/DECREMENT OPERATORS =====" << std::endl;
	Fixed j;
	std::cout << "j: " << j << std::endl;
	std::cout << "++j: " << ++j << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "j++: " << j++ << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "--j: " << --j << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "j--: " << j-- << std::endl;
	std::cout << "j: " << j << std::endl;

	std::cout << "\n===== MIN/MAX FUNCTIONS =====" << std::endl;
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
	const Fixed const_b(b);
	const Fixed const_c(c);
	std::cout << "min(const_b, const_c): " << Fixed::min(const_b, const_c) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	std::cout << "max(const_b, const_c): " << Fixed::max(const_b, const_c) << std::endl;

	std::cout << "\n===== REQUIRED TEST =====" << std::endl;
	Fixed x;
	Fixed const y(Fixed(5.05f) * Fixed(2));
	
	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << Fixed::max(x, y) << std::endl;

	return 0;
}
