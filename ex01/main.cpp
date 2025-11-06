/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:09 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/06 16:48:03 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	// check the numbers are single digit
	// numbers can't be negative? nor decimal
	// doesn't accept parentheses, only + - * /
	if (ac < 2)
		return (1);
	try
	{
		newStack st;
		for (int i = 0; av[1][i]; i++)
		{
			// if number over 10 -> error
			if (av[1][i] == ' ')
				i++;
			if (isdigit(av[1][i]) && isdigit(av[1][i + 1]))
				throw(std::runtime_error("Numbers must be below 10"));
			st.checkInput(av[1][i]);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}