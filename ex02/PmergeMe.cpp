/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:05:19 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/11 15:48:46 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void validateArg(char **av)
{
	for (size_t i = 1; av[i]; i++)
	{
		if (!av[i] || av[i] == '\0')
			throw(std::runtime_error("Error: argument is empty"));
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				throw(std::runtime_error("Error: argument contains non-digit(s)"));
		}
	}
}

void fillList(std::list<int> *lst, char **av)
{
	for (size_t i = 1; av[i]; i++)
	{
		std::stringstream ss(av[i]);
		unsigned int ui;
		ss >> ui;
		if (ui < 0 || ui > INT_MAX)
			throw(std::runtime_error("Number out of bounds"));
		lst->push_back(static_cast<int>(ui));
	}
}

void sortList(std::list<int> &lst)
{
	if (lst.size() < 2)
		return;

	std::list<int> bigger, lower;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::list<int>::iterator next = it;
		++next;
		if (next != lst.end())
		{
			if (*it < *next)
			{
				bigger.push_back(*next);
				lower.push_back(*it);
			}
			else
			{
				bigger.push_back(*it);
				lower.push_back(*next);
			}
			++it;
		}
		else
		{
			lower.push_back(*it);
			break;
		}
	}
	sortList(bigger);

	std::list<int>::iterator it;
	for (it = lower.begin(); it != lower.end(); ++it)
	{
		int n = *it;
		std::list<int>::iterator pos = std::lower_bound(bigger.begin(), bigger.end(), n);
		bigger.insert(pos, n);
	}
	lst = bigger;
}

void fillVector(std::vector<int> *vec, char **av)
{
	for (size_t i = 1; av[i]; i++)
	{
		std::stringstream ss(av[i]);
		unsigned int ui;
		ss >> ui;
		if (ui < 0 || ui > INT_MAX)
			throw(std::runtime_error("Number out of bounds"));
		vec->push_back(static_cast<int>(ui));
	}
}

void sortVector(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;

	std::vector<int> bigger, lower;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::vector<int>::iterator next = it;
		++next;
		if (next != vec.end())
		{
			if (*it < *next)
			{
				bigger.push_back(*next);
				lower.push_back(*it);
			}
			else
			{
				bigger.push_back(*it);
				lower.push_back(*next);
			}
			++it;
		}
		else
		{
			lower.push_back(*it);
			break;
		}
	}
	sortVector(bigger);

	std::vector<int>::iterator it;
	for (it = lower.begin(); it != lower.end(); ++it)
	{
		int n = *it;
		std::vector<int>::iterator pos = std::lower_bound(bigger.begin(), bigger.end(), n);
		bigger.insert(pos, n);
	}
	vec = bigger;
}