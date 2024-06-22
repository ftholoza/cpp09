/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:05:25 by francesco         #+#    #+#             */
/*   Updated: 2024/06/22 12:14:37 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_hpp
# define PmergeMe_hpp

# include "iostream"
# include "list"
# include "vector"
# include "utility"
# include "cstdlib"
# include "sys/time.h"

class PmergeMe
{
    private:
        std::list<int>  temp;
        int max;
        std::vector<std::pair<int, int> > vector;
        std::list<std::pair<int, int> > list;
        std::list<std::pair<int, int> > sorted_list;
        std::vector<std::pair<int, int> > sorted_vector;
        std::vector<int>    vec;
        std::list<int>  lst;
        std::list<int>  pend;
        std::vector<int> pend_v;
    public:
        PmergeMe();
        ~PmergeMe(){};
        void    add_to_merge(std::string first, std::string second);
        void    first_sort_l();
        void    first_sort_v();
        void    second_sort_l();
        void    second_sort_v();
        void    insertion_l();
        void    insertion_v();
        void    set_pend_vec();
        void    set_pend_list();
        std::list<std::pair<int, int> > get_pair_list();
        std::vector<std::pair<int, int> >get_pair_vector();
        std::list<int>      get_lst();
        std::vector<int>    get_vec();
        void    show();
};

void    show_list(std::list<int> list);
void    show_vector(std::vector<int> vector);

class   ErrorBadInput : public std::exception
{
    public:
        const char *what() const throw ();
};

# endif