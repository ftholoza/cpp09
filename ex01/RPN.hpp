/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:14:08 by francesco         #+#    #+#             */
/*   Updated: 2024/06/16 07:36:39 by francesco        ###   ########.fr       */
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
    int max;
    std::stack<double> stack;
public:
    RPN(){};
    ~RPN(){};
    void    add(char c);
    void addition();
    void soustraction();
    void division();
    void multiplication();
    std::stack<double> &get_stack();
};

class   ErrorBadInput : public std::exception
{
    public:
        const char *what() const throw ();
};

#endif