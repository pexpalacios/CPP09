/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:04:27 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/05 18:13:47 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: need a file" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc;
		std::ifstream infile(av[1]);
		if(!infile.is_open())
		{
			std::cerr << "Error: couldn't open input file" << std::endl;
			return (1);
		}
		btc.handleFile(infile);
		infile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}