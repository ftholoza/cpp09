/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:41:25 by ftholoza          #+#    #+#             */
/*   Updated: 2024/06/24 11:43:27 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    Date::set_year(int year)
{
    this->year = year;
}
void    Date::set_mounth(int mounth)
{
    this->mounth = mounth;
}

void    Date::set_day(int day)
{
    this->day = day;
}

int     Date::get_year()
{
    return (this->year);
}

int     Date::get_month()
{
    return (this->mounth);
}

int     Date::get_day()
{
    return (this->day);
}

bool    Date::check_day()
{
    if (this->mounth == 9 || this->mounth == 11 || this->mounth == 4 || this->mounth == 6)
    {
        if (this->day > 30)
        {
            std::cout << ErrorDay("this mounth have maximum 30 days");
            throw Error();
        }
    }
    if (this->mounth == 2)
    {
        if (this->year % 4 == 0)
        {
            if (this->day > 29)
            {
                std::cout << ErrorDay("this mounth on bisextil years have maximum 29 days");
                throw Error();
            }
        }
        else
        {
            if (this->day > 28)
            {
                std::cout << ErrorDay("this mounth out of bisextil years have maximum 28 years");
                throw Error();
            }
        }
    }
    return (true);
}

double  get_value(std::string line)
{
	double	res;
    if (is_str_digit(line.substr(11, line.size())) == false)
		std::cout << ErrorAmountFormat(line) << std::endl;
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
    
    if (line.c_str()[1] == '-')
    {
        std::cout << ErrorDateFormat("need 0 before");
        throw Error();
    }
    else if (is_str_digit(line) == false)
        return (false);
    mounth = std::atoi(line.c_str());
    if (mounth < 1 || mounth > 12)
        return (false);
    return (true);
}

bool    check_day(std::string line)
{
    int day;
    
    if (line.c_str()[1] == ' ')
    {
        std::cout << ErrorDateFormat("need 0 before");
        throw Error();
    }
    if (is_str_digit(line) == false)
        return (false);
    day = std::atoi(line.c_str());
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

std::string get_date(std::string line)
{
	Date date;
    if (line.size() < 12)
    {
		std::cout << ErrorDateFormat(line);
        throw Error();
    }
    if (check_year(line.substr(0, 4)) == false)
    {
        std::cout << ErrorYear(line);
        throw Error();
    }
    date.set_year(std::atoi(line.substr(0, 4).c_str()));
    if (line.c_str()[4] != '-')
    {
        std::cout << ErrorDateFormat(line);
        throw Error();
    }
    if (check_mounth(line.substr(5, 2)) == false)
    {
        std::cout << ErrorMounth(line);
        throw Error();
    }
    date.set_mounth(std::atoi(line.substr(5, 2).c_str()));
    if (line.c_str()[7] != '-')
    {
        std::cout << ErrorDateFormat(line);
        throw Error();
    }
    if (check_day(line.substr(8, 2)) == false)
    {
        std::cout << ErrorDay(line);
        throw Error();
    }
    date.set_day(std::atoi(line.substr(8, 2).c_str()));
    date.check_day();
    return (line.substr(0, 10));
}

std::string ErrorYear(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Invalid Year => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorMounth(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Invalid Mounth => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorDay(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Invalid Day => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorDateFormat(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Invalid Date Format => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorAmountFormat(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Invalid Amount Format => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorAmountValue(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Amount can't be |> 1000| or |<= 0| => ";
    string += str;
    string += "\33[0m";
    return (string);
}

std::string ErrorMissingInfo(std::string str)
{
    std::string string;
    string = "\033[1;31mError: Date or Amount is missing => ";
    string += str;
    string += "\33[0m";
    return (string);
}

const char *Error::what() const throw()
{
    return ("");
}
