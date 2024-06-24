/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:34:42 by ftholoza          #+#    #+#             */
/*   Updated: 2024/06/24 09:46:33 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#   define BITCOINEXCHANGE_HPP


#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <cstdlib>

bool	read_infile(const char *str, std::map<std::string, double> &data);
bool    is_str_digit(std::string str);
bool    check_year(std::string  line);
bool    check_mounth(std::string  line);
bool    check_day(std::string  line);
double  get_value(std::string line);
std::string get_date(std::string line);
bool	read_infile(char *str, std::map<std::string, double> &data);
std::string ErrorYear(std::string str);
std::string ErrorMounth(std::string str);
std::string ErrorDay(std::string str);
std::string ErrorDateFormat(std::string str);
std::string ErrorAmountFormat(std::string str);
std::string ErrorAmountValue(std::string str);
std::string ErrorMissingInfo(std::string str);

class Date
{
private:
    int year;
    int mounth;
    int day;
public:
    Date(){};
    ~Date(){};
    void    set_year(int year);
    void    set_mounth(int mounth);
    void    set_day(int day);
    int     get_year();
    int     get_month();
    int     get_day();
    bool    check_day();
};

class   Error : public std::exception
{
    public:
        const char *what() const throw ();
};

#endif