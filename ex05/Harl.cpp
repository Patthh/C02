/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:16:50 by pracksaw          #+#    #+#             */
/*   Updated: 2025/04/30 12:51:24 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << CYA << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RES << std::endl;
}

void Harl::info(void)
{
	std::cout << GRE << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RES << std::endl;
}

void Harl::warning(void)
{
	std::cout << YEL << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << RES << std::endl;
}

void Harl::error(void)
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RES << std::endl;
}

void Harl::complain(std::string level)
{
	int	i;
	static const char* lvlStr[]={"DEBUG", "INFO", "WARNING", "ERROR"};
	static void (Harl::*complaintFn[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	i = 0;
	while (lvlStr[i] && level != lvlStr[i])
		i++;
	if (lvlStr[i]) {
		(this ->*complaintFn[i])();
	}
	else {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
