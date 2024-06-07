/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:40:53 by francesco         #+#    #+#             */
/*   Updated: 2024/06/07 01:10:06 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <map>
#include <string>
#include <iostream>

bool    is_str_digit(std::string str)
{
    const char *string;
    for (int i = 0; string[i] != 0; i++)
        if (std::isdigit(string[i]) == 0)
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

std::string get_data(std::string line)
{
    if (line.size() < 12)
        return (NULL);
    line.substr(0, 4);
    
}

void    insert_data(std::map<std::string, double> &map, std::string line)
{
    
}

int main(int argc, char **argv)
{
    try
    {
        std::string     line;
        std::ifstream   data("data.csv");
        std::map<std::string, double>   map;
        while (std::getline(data, line))
        {
            
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}