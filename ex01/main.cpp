/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:09 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/11 16:26:46 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	try
	{
		newStack st;
		int input, sign;
		for (int i = 0; av[1][i]; i++)
		{
			if (std::isspace(static_cast<unsigned char>(av[1][i])))
                continue;
			if (isdigit(av[1][i]) && isdigit(av[1][i + 1]))
				throw(std::runtime_error("Numbers must be below 10"));

			if (isdigit(av[1][i]) && (av[1][i - 1] == '-'))
				sign = -1;
			else if (isdigit(av[1][i]) && av[1][i - 1] == '+'))
				sign = 1;

			st.checkInput(input * sign);
		}
		std::cout << st.top() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}