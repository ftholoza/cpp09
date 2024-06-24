/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:14:08 by francesco         #+#    #+#             */
/*   Updated: 2024/06/24 16:32:48 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

class RPN
{
private:
    std::stack<double> stack;
public:
    RPN(){};
    ~RPN(){};
    void    add(char c);
    void addition();
    void soustraction();
    void division();
    void multiplication();
    double  calculator(std::string notation);
    std::stack<double> &get_stack();
};

void    show_stack(std::stack<char> stack);

class   ErrorBadInput : public std::exception
{
    public:
        const char *what() const throw ();
};

#endif