/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:41:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/06/07 15:54:21 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double  get_value(std::string line)
{
	double	res;
    if (is_str_digit(line.substr(11, line.size())) == false)
		throw ErrorInvalidAmountFormat(line);
	res = std::atof((line.substr(11, line.size())).c_str());
	return (res);
}

bool    is_str_digit(std::string str)
{
    const char *string;

    string = str.c_str();
    for (int i = 0; string[i] != 0; i++)
        if (std::isdigit(string[i]) == 0 && string[i] != '.')
            return (false);
    return (true);
}

bool    check_year(std::string  line)
{
    int year;
    
	//if (line == "2011")
    //	std::cout << line << std::endl;
    if (is_str_digit(line) == false)
        return (false);
    if (line.c_str()[0] == '0')
        return (false);
    year = std::atoi(line.c_str());
    if (year < 0)
        return (false);
    return (true);
}

bool    check_mounth(std::string line)
{
    int mounth;
    
	//std::cout << line;
    if (is_str_digit(line) == false)
        return (false);
    mounth = std::atoi(line.c_str());
    if (mounth < 1 || mounth > 12)
        return (false);
    return (true);
}

bool    check_day(std::string line)
{
    int day;
    
   // std::cout << line;
    if (is_str_digit(line) == false)
        return (false);
    day = std::atoi(line.c_str());
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

std::string get_date(std::string line)
{
	//std::cout << line << std::endl;
    if (line.size() < 12)
		throw ErrorInvalidDateFormat(line);
    if (check_year(line.substr(0, 4)) == false)
        throw ErrorInvalidYear(line);
    if (line.c_str()[4] != '-')
        throw ErrorInvalidDateFormat(line);
    if (check_mounth(line.substr(5, 2)) == false)
        throw ErrorInvalidMounth(line);
    if (line.c_str()[7] != '-')
		throw ErrorInvalidDateFormat(line);
    if (check_day(line.substr(8, 2)) == false)
        throw ErrorInvalidDay(line);
    return (line.substr(0, 10));
}

const char *ErrorInvalidYear::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorInvalidMounth::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorInvalidDay::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorInvalidDateFormat::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorInvalidAmountFormat::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorNegative1000::what() const throw()
{
    return (this->message.c_str());
}

const char *ErrorIncomplet::what() const throw()
{
    return (this->message.c_str());
}