/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:51:22 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/14 14:24:12 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::list<int> lst;
	std::vector<int> vec;

	clock_t start, end;
	double lstTime, vecTime;

	if (ac < 2)
	{
		std::cerr << "Error: Not enough arguments" << std::endl;
		return (1);
	}

	try
	{
		validateArg(av);
		std::cout << "Before [list]: ";
		start = clock();
		fillList(&lst, av);
		printContainer(lst);
		std::cout << "After [list]: ";
		sortList(lst);
		end = clock();
		printContainer(lst);
		lstTime = double(end - start) * 1000000 / CLOCKS_PER_SEC;

		std::cout << "Before [vector]: ";
		start = clock();
		fillVector(&vec, av);
		printContainer(vec);
		std::cout << "After [vector]: ";
		sortVector(vec);
		end = clock();
		printContainer(vec);
		vecTime = double(end - start) * 1000000 / CLOCKS_PER_SEC;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	std::cout << "Time to process a range of " << lst.size()
			  << " elements with std::list : " << lstTime << "us" << std::endl;
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << vecTime << "us" << std::endl;

	return (0);
}