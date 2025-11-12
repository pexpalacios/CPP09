/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:00:38 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/12 15:50:59 by penpalac         ###   ########.fr       */
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
		{
			if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
				throw(std::overflow_error("Error: integer overflow on addition"));
			std::stack<int>::push(a + b);
		}
		else if (input == '-')
		{
			if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
				throw(std::overflow_error("Error: integer overflow on addition"));
			std::stack<int>::push(a - b);
		}
		else if (input == '*')
		{
			if (a > 0 && b > 0 && a > INT_MAX / b)
				throw(std::overflow_error("Error: integer overflow on multiplication"));
			if (a > 0 && b < 0 && b < INT_MIN / a)
				throw(std::overflow_error("Error: integer overflow on multiplication"));
			if (a < 0 && b > 0 && a < INT_MIN / b)
				throw(std::overflow_error("Error: integer overflow on multiplication"));
			if (a < 0 && b < 0 && a < INT_MAX / b)
				throw(std::overflow_error("Error: integer overflow on multiplication"));
			std::stack<int>::push(a * b);
		}
		else
		{
			if (b == 0)
				throw(std::runtime_error("Error: can't divide by zero"));
			if (a == INT_MIN && b == -1)
				throw(std::overflow_error("Error: integer overflow on division"));
			std::stack<int>::push(a / b);
		}
	}
	else
		throw(std::runtime_error("Error: invalid input"));
}