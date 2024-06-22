/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:05:22 by francesco         #+#    #+#             */
/*   Updated: 2024/06/22 15:27:29 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): max(0)
{
}

std::list<std::pair<int, int> > PmergeMe::get_pair_list()
{
    return (this->list);
}

std::vector<std::pair<int, int> > PmergeMe::get_pair_vector()
{
    return (this->vector);
}

std::list<int>      PmergeMe::get_lst()
{
    return (this->lst);
}

std::vector<int>    PmergeMe::get_vec()
{
    return (this->vec);
}

void    PmergeMe::show()
{
    std::list<std::pair<int, int> >::iterator itl = this->list.begin();
    std::cout << "max: " << this->max << std::endl;
    std::cout << std::endl;
    while (itl != this->list.end())
    {
        std::cout <<  "(" << (*itl).first << ", ";
        std::cout << (*itl).second << ")";
        itl++;
    }
    return ;
}

bool     is_digit(std::string data)
{
    const char      *str;
    int             i;

    i = 1;
    str = data.c_str();
    if (!std::isdigit(str[0]) && str[0] != '+')
        return (false);
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool    int_check_overflow(std::string str)
{
    if (str.size() >= 11)
    {
        if (str.c_str()[0] != '-' || str.c_str()[0] != '+')
            return (true);
        if (str.c_str()[0] == '-' && str.compare("-2147483648") > 0)
            return (true);
        if (str.c_str()[0] == '+' && str.compare("+2147483647") > 0) 
            return (true);
        if (str.c_str()[0] == '-' && str.compare("-2147483648") <= 0)
            return (false);
        if (str.c_str()[0] == '+' && str.compare("+2147483647") <= 0) 
            return (false);
    }
    if (str.size() == 10)
    {
        if (str.compare("2147483647") > 0)
            return (true);
    }
    return (false);
}

void PmergeMe::add_to_merge(std::string first, std::string second)
{
    std::pair<int, int> pair;
    
    if (first.size() == 0)
    {
        std::cout << "here 1" << std::endl;
        throw ErrorBadInput();
    }
    else if (is_digit(first) && int_check_overflow(first) == false)
        pair.first = std::atoi(first.c_str());
    else
        throw ErrorBadInput();
    if (second == "NULL")
        pair.second = -1;
    else if (is_digit(second) && int_check_overflow(second) == false)
        pair.second = std::atoi(second.c_str());
    else
    {        
        std::cout << "here 3" << std::endl;
        throw ErrorBadInput();
    }
    this->vector.push_back(pair);
    this->list.push_back(pair);
}

const char *ErrorBadInput::what() const throw()
{
    return ("\033[1;31mError: Bad Input\033[0m\n\033[1;34mvalid: positive numbers under INTMAX\033[0m");
}