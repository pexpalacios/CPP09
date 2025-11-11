/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:57:52 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/11 15:34:22 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <cctype>
#include <sstream>
#include <climits>
#include <iostream>

template <typename T>
void printContainer(const T &container)
{
	if (container.empty())
	{
		std::cout << "Conatiner is empty" << std::endl;
		return ;
	}
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void validateArg(char **av);
void fillList(std::list<int> *lst, char **av);
void sortList(std::list<int> &lst);
void fillVector(std::vector<int> *vec, char **av);
void sortVector(std::vector<int> &vec);

#endif