/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:18:41 by francesco         #+#    #+#             */
/*   Updated: 2024/06/24 16:43:43 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool    is_valid(char c)
{
    if (isblank(c))
        return (true);
    else if (c == '+' || c == '-' || c == '/' || c == '*')
        return (true);
    else if (isdigit(c))
        return (true);
    else
        return (false);
}

// double  calculator(std::string notation)
// {
//     const char *str = notation.c_str();
//     int i = 0;
//     RPN rpn;

//     //std::cout << notation << std::endl;
//     while (str[i])
//     {
//         if (isdigit(str[i]))
//             rpn.add(str[i]);
//         else
//         {
//             switch (str[i])
//             {
//                 case ('+'):
//                     rpn.addition();
//                     break;
//                 case ('-'):
//                     rpn.soustraction();
//                     break;
//                 case ('*'):
//                     rpn.multiplication();
//                     break;
//                 case ('/'):
//                     rpn.division();
//                     break;
//                 default:
//                     break;
//             }
//         }
//         i++;
//     }
//     //rpn.get_stack().pop();
//     if (rpn.get_stack().size() >= 2)
//         throw ErrorBadInput();
//     return (rpn.get_stack().top());
// }

int error(std::string message)
{
    std::cout << message << std::endl;
    return (0);
}

void    show_stack(std::stack<char> stack)
{
    while (stack.size() > 0)
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}

void    rpn_format(std::string &notation)
{
    const char *str = notation.c_str();
    std::string res;
    int     i = 0;
    bool    rhytme = false;

    while (str[i])
    {
        if (isspace(str[i]))
            rhytme = false;
        if (!isspace(str[i]))
        {
            if (rhytme == true)
                throw ErrorBadInput();
            if (!is_valid(str[i]))
                throw ErrorBadInput();
            rhytme = true;
            res += str[i];
        }
        i++;
    }
    notation = res;
}   


int main(int argc, char **argv)
{
    RPN rpn;
    if (argc < 2)
        return (error("to less arguments"));
    if (argc > 2)
        return (error("to many arguments"));
    try
    {
        std::string str(argv[1]);
        rpn_format(str);
        std::cout << rpn.calculator(str) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
        
}