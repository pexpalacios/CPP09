/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:04:51 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/12 12:33:45 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITEX_HPP
#define BITEX_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>
#include <utility>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	void handleFile(std::ifstream &file);
	void checkDate(size_t year, size_t month, size_t day) const;
	void checkFormat(const std::string line);
};

#endif