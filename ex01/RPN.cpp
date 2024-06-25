/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:37:50 by francesco         #+#    #+#             */
/*   Updated: 2024/06/25 13:05:50 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *ErrorBadInput::what() const throw()
{
    return ("\033[1;31mError: Bad Input\033[0m\n\033[1;34mvalid: 0 -> 9 && ( + - * / )\033[0m");
}

void RPN::add(char c)
{
    char str[2];
    str[0] = c;
    this->stack.push(std::atoi(str));
}

double  RPN::calculator(std::string notation)
{
    int i = 0;
    double  temp;
    double  temp2;

    //std::cout << notation << std::endl;
    while (notation.c_str()[i])
    {
        if (std::isdigit(notation.c_str()[i]))
            this->add(notation.c_str()[i]);
        else
        {
            if (this->stack.size() < 2)
                throw ErrorBadInput();
            temp = this->stack.top();
            this->stack.pop();
            temp2 = this->stack.top();
            this->stack.pop();
            switch (notation.c_str()[i])
            {
                case ('+'):
                    this->stack.push(temp + temp2);
                    break;
                case ('-'):
                    this->stack.push(temp2 - temp);
                    break;
                case ('*'):
                    this->stack.push(temp * temp2);
                    break;
                case ('/'):
                    this->stack.push(temp2 / temp);
                    break;
                default:
                    break;
            }
        }
        i++;
    }
    if (this->stack.size() > 0 && this->stack.size() < 2)
        return (this->stack.top());
    else
        throw ErrorBadInput();
    return (0);
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
    //std::cout << "+: " << temp << temp2 << std::endl;
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
    //std::cout << "-: " << temp << temp2 << std::endl;
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
    //std::cout << "/: "<< temp << temp2 << std::endl;
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
    //std::cout << "*: " << temp << temp2 << std::endl;
    this->stack.pop();
    this->stack.push(temp * temp2);
    return ;
}

std::stack<double> &RPN::get_stack()
{
    return (this->stack);
}
