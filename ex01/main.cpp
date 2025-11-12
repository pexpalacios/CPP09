/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:09 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/12 13:35:21 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);

	try
	{
		int numbers = 0;
		int operators = 0;
		for (int i = 0; av[1][i]; i++)
		{
			if (std::isspace((av[1][i])))
				continue;
			if (isdigit(av[1][i]) && isdigit(av[1][i + 1]))
				throw(std::runtime_error("Numbers must be below 10"));
			if (av[1][i + 1] && (!std::isspace(av[1][i + 1])))
				throw(std::runtime_error("Numbers & operators must be separated"));

			if (isdigit(av[1][i]))
				numbers++;
			else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' || av[1][i] == '/')
				operators++;
		}

		if (operators != numbers - 1)
			throw(std::runtime_error("Error: not enough operators for the amount of numbers"));

		newStack st;
		for (int i = 0; av[1][i]; i++)
		{
			if (std::isspace((av[1][i])))
				continue;
			st.checkInput(av[1][i]);
		}
		std::cout << st.top() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}