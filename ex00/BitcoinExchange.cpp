/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:34:20 by ftholoza          #+#    #+#             */
/*   Updated: 2024/06/11 08:01:25 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double	get_amount(std::string line)
{
	std::string	to_process;
	double		amount;
	
	to_process = line.substr(10, line.size());
	if (to_process.size() < 4)
	{
		std::cout << ErrorAmountFormat(line);
		throw Error();
	}
	if ((line.c_str())[10] != ' ')
	{
		std::cout << ErrorAmountFormat(line);
		throw Error();
	}
	if ((line.c_str())[11] != '|')
	{
		std::cout << ErrorAmountFormat(line);
		throw Error();
	}
	if ((line.c_str())[12] != ' ')
	{
		std::cout << ErrorAmountFormat(line);
		throw Error();
	}
	if (is_str_digit(line.substr(13, line.size())) == false)
	{
		std::cout << ErrorAmountFormat(line);
		throw Error();
	}
	amount = std::atof((line.substr(13, line.size())).c_str());
	if (amount < 0 || amount > 1000)
	{
		std::cout << ErrorAmountValue(line);
		throw Error();
	}
	return (amount);
}

void	compare_data(std::string line, std::map<std::string, double> &data)
{
	std::string	date;
	double		amount;
	bool		check = false;
	
	try
	{
		if (line.size() < 13)
			throw std::runtime_error(ErrorMissingInfo(line));
		date = get_date(line);
		amount = get_amount(line);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::map<std::string, double>::iterator it = data.begin();
	while (it != data.end())
	{
		if (date.compare("2009-01-02") < 0)
		{
			check = true;
			std::cout << date << " => " << amount << " = " << (amount * 0) << std::endl;
			break;
		}
		if (it->first.compare(date) == 0)
		{
			check = true;
			std::cout << date << " => " << amount << " = " << (amount * it->second) << std::endl;
			break;
		}
		if (it->first.compare(date) > 0)
		{
			check = true;
			std::cout << date << " => " << amount << " = " << (amount * (--it)->second) << std::endl;
			break;
		}
		it++;
	}
	if (check == false)
		std::cout << date << " => " << amount << " = " << amount * ((--data.end())->second) << std::endl;
	return ;
}

bool	read_infile(char *str, std::map<std::string, double> &data)
{
	std::string		line;
	std::ifstream   infile(str);
	if (infile.bad() || infile.eof() || infile.is_open() == false)
    {
        std::cerr << "data.csv opening failed" << std::endl;
        return (false);
    }
	while (std::getline(infile, line))
	{
		if (line != "" && line != "date | value" && line != std::string("$> head " + std::string(str)))
			compare_data(line, data);
	}
	return (true);
}