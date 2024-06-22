/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:37:50 by francesco         #+#    #+#             */
/*   Updated: 2024/06/12 18:26:34 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *ErrorBadInput::what() const throw()
{
    return ("\033[1;31mError: Bad Input\033[0m\n\033[1;34mvalid: 0 -> 9 && ( + - * / )\033[0m");
}

void RPN::addition()
{
    double  temp;
    double  temp2;

    if (this->stack.size() < 2)
        throw ErrorBadInput();
    temp = this->stack.top();
    this->stack.pop();
    temp2 = this->stack.top();
    this->stack.pop();
    this->stack.push(temp + temp2);
    return ;
}

void RPN::soustraction()
{
    double  temp;
    double  temp2;

    if (this->stack.size() < 2)
        throw ErrorBadInput();
    temp = this->stack.top();
    this->stack.pop();
    temp2 = this->stack.top();
    this->stack.pop();
    this->stack.push(temp - temp2);
    return ;
}

void RPN::division()
{
    double  temp;
    double  temp2;

    if (this->stack.size() < 2)
        throw ErrorBadInput();
    temp = this->stack.top();
    this->stack.pop();
    temp2 = this->stack.top();
    this->stack.pop();
    this->stack.push(temp / temp2);
    return ;
}

void RPN::multiplication()
{
    double  temp;
    double  temp2;

    if (this->stack.size() < 2)
        throw ErrorBadInput();
    temp = this->stack.top();
    this->stack.pop();
    temp2 = this->stack.top();
    this->stack.pop();
    this->stack.push(temp * temp2);
    return ;
}

void RPN::add(char c)
{
    char str[1];
    str[0] = c;
    this->stack.push(std::atof(str));
}

std::stack<double> &RPN::get_stack()
{
    return (this->stack);
}
