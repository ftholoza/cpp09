/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:34:42 by ftholoza          #+#    #+#             */
/*   Updated: 2024/06/07 15:59:57 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

class   ErrorInvalidYear : public std::runtime_error
{
    private:
        std::string message;
    public:
        ErrorInvalidYear(std::string str) throw()
        {
            this->message = "\033[1;31mError: Invalid Year => ";
            message += str;
            message += "\33[0m";
        };
        const char * what() const throw();
};
        

class   ErrorInvalidMounth : public std::exception
{
    private:
        std::string message;
    public:
        ErrorInvalidMounth(std::string str) throw(){
            this->message = "\033[1;31mError: Invalid Mounth => ";
            this->message += str;
            this->message += "\33[0m";
        };
        virtual const char * what() const throw();
};
        

class   ErrorInvalidDay : public std::exception
{
    private:
        std::string message;
    public:
        ErrorInvalidDay(std::string str) throw(){
            this->message = "\033[1;31mError: Invalid Day => ";
            message += str;
            message += "\33[0m";
        }
        virtual const char * what() const throw();
};

class   ErrorInvalidDateFormat : public std::exception
{
    private:
        std::string message;
    public:
        ErrorInvalidDateFormat(std::string str) throw(){
            this->message = "\033[1;31mError: Invalid Date Format => ";
            message += str;
            message += "\33[0m";
        }
        virtual const char * what() const throw();
};

class   ErrorInvalidAmountFormat : public std::exception
{
    private:
        std::string message;
    public:
        ErrorInvalidAmountFormat(std::string str) throw(){
            this->message = "\033[1;31mError: Invalid Amount Format => ";
            this->message += str;
            this->message += "\33[0m";
        }
        virtual const char * what() const throw();
};

class   ErrorNegative1000 : public std::exception
{
    private:
        std::string message;
    public:
        ErrorNegative1000(std::string str) throw(){
            this->message = "\033[1;31mError: Amount need to be between 0 and 1000 => ";
            message += str;
            message += "\33[0m";
        }
        virtual const char * what() const throw();
};

class   ErrorIncomplet : public std::exception
{
    private:
        std::string message;
    public:
        ErrorIncomplet(std::string str){
            this->message = "\033[1;31mError: Date or Amount is missing => ";
            message += str;
            message += "\33[0m";
        }
        virtual const char * what() const throw();
};


