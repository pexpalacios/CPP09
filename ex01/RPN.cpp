/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:00:38 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/12 13:19:12 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void newStack::checkInput(char input)
{

	if (isdigit(input))
	{
		std::stack<int>::push(input - '0');
	}
	else if (input == '+' || input == '-' || input == '*' || input == '/')
	{
		if (std::stack<int>::size() < 2)
			return;

		int b = std::stack<int>::top();
		std::stack<int>::pop();
		int a = std::stack<int>::top();
		std::stack<int>::pop();

		if (input == '+')
			std::stack<int>::push(a + b);
		else if (input == '-')
			std::stack<int>::push(a - b);
		else if (input == '*')
			std::stack<int>::push(a * b);
		else
		{
			if (b == 0)
				throw(std::runtime_error("Error: can't divide by zero"));
			std::stack<int>::push(a / b);
		}
	}
	else
		throw(std::runtime_error("Error: invalid input"));
}