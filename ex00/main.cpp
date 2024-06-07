/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:40:53 by francesco         #+#    #+#             */
/*   Updated: 2024/06/07 13:52:46 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void    insert_data(std::map<std::string, double> &map, std::string line)
{
    std::string date;
    double      value;

    try
    {
        date = get_date(line);
        value = get_value(line);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    map.insert(std::pair<std::string, double>(date, value));
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    try
    {
        std::string     line;
        std::ifstream   data("data.csv");
        if (data.bad() || data.eof() || data.is_open() == false)
        {
            std::cerr << "data.csv opening failed" << std::endl;
            return (0);
        }
        std::map<std::string, double>   map;
        while (std::getline(data, line))
            insert_data(map, line);
        read_infile(argv[1], map);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}