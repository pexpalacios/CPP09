/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:18:32 by penpalac          #+#    #+#             */
/*   Updated: 2025/11/05 18:31:43 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw(std::runtime_error("Error: file data.csv couldn't be opened"));

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma != std::string::npos)
		{
			std::string date = line.substr(0, comma);
			std::stringstream ss (line.substr(comma + 1));
			float value;
			ss >> value;
			_data[date] = value;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->_data = copy._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/////

float getValue(const std::string &line)
{
	size_t pipe = line.find('|');
	if (pipe == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);

	std::stringstream ssy(line.substr(pipe + 1));
	float value;
	ssy >> value;
	return (value);
}

void BitcoinExchange::handleFile(std::ifstream &file)
{
	// check and _data.insert(std::make_pair(key, value));
	// for getting line -> checks
	// file is given through terminal
	std::string line;
	while (std::getline(file, line))
	{
		try
		{
			if (line.empty() || line == "date | value")
				continue;

			std::string date = line.substr(0, 10);
			std::stringstream ssy(line.substr(0, 4));
			size_t year;
			ssy >> year;
			std::stringstream ssm(line.substr(5, 2));
			size_t month;
			ssm >> month;
			std::stringstream ssd(line.substr(8, 2));
			size_t day;
			ssd >> day;
			try
			{
				checkDate(year, month, day);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				continue;
			}

			float value = getValue(line);
			try
			{
				checkValue(value);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				continue;
			}

			// Find closest date in database
			std::map<std::string, float>::iterator it = _data.lower_bound(date);
			if (it == _data.begin() && date < it->first)
			{
				std::cerr << "Error: no exchange rate available for this date." << std::endl;
				continue;
			}
			if (it == _data.end() || date < it->first)
				--it;

			// Calculate and print result
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::checkDate(size_t year, size_t month, size_t day) const
{
	// Check if date is valid
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		throw (std::runtime_error("Error: Invalid date"));
	else if (month == 2 && day > 29)
		throw (std::runtime_error("Error: Invalid date"));
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		throw (std::runtime_error("Error: Invalid date. Month doesn't have a 31st"));
}

void BitcoinExchange::checkValue(float value) const
{
	if (value < 0 || value > 1000)
		throw (std::runtime_error("Error: Invalid value"));
}