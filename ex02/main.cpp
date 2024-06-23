/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:05:14 by francesco         #+#    #+#             */
/*   Updated: 2024/06/23 20:37:36 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Colors.hpp"
# include "PmergeMe.hpp"
# include <set>

double  time()
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return (time.tv_usec + time.tv_sec * 1000000);
}

void    show_v(std::vector<std::pair<int, int> > vector)
{
    std::vector<std::pair<int, int> >::iterator it = vector.begin();

    while (it != vector.end())
    {
        std::cout << (*it).first << " ";
        if ((*it).second != -1)
            std::cout << (*it).second;
        it++;
    }
    return;
}

void    show_l(std::list<std::pair<int, int> > list)
{
    std::list<std::pair<int, int> >::iterator it = list.begin();

    while (it != list.end())
    {
        std::cout << (*it).first << " ";
        if ((*it).second != -1)
            std::cout << (*it).second << " ";
        it++;
    }
    std::cout << std::endl;
    return;
}

bool    check_dup(char **argv)
{
    std::list<int>  list;
    for (int i = 1; argv[i]; i++)
        list.push_back(std::atoi(argv[i]));
    std::set<int> sorted(list.begin(), list.end());
    if (list.size() == sorted.size())
        return (false);
    else
        return (true);
}

bool    check_if_sort(std::list<int> mlist, std::vector<int> mvec, char **argv)
{
    std::list<int>::iterator    it;
    std::set<int>::iterator     it2;
    std::vector<int>::iterator  itv;
    std::list<int>  list;
    for (int i = 1; argv[i]; i++)
        list.push_back(std::atoi(argv[i]));
    std::set<int> sorted(list.begin(), list.end());
    it = mlist.begin();
    it2 = sorted.begin();
    while (it != mlist.end() && it2 != sorted.end())
    {
        if (*it == *it2)
        {
            it++;
            it2++;
        }
        else
            return (false);
    }
    it2 = sorted.begin();
    itv = mvec.begin();
    while (itv != mvec.end() && it2 != sorted.end())
    {
        if (*itv == *it2)
        {
            itv++;
            it2++;
        }
        else
            return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    PmergeMe    pmerge;
    unsigned long   list_start, list_end;
    unsigned long   vector_start, vector_end;
    
    if (argc < 3)
    {
        std::cerr << RED <<"Error: Not enought arguments" << END_STYLE <<std::endl;
        return (1);
    }
    try
    {
        if ((argc -1) % 2 == 0)
        {
            for (int i = 1; argc != i; i += 2)
                pmerge.add_to_merge(argv[i], argv[i + 1]);
        }
        else
        {
            int i = 1;
            while (i + 1 != argc)
            {
                pmerge.add_to_merge(argv[i], argv[i + 1]);
                i += 2;
            }
            pmerge.add_to_merge(argv[i], "NULL");
        }
        if (check_dup(argv) == true)
            throw (ErrorBadInput());
        std::cout << RED << "Before:  " << END_STYLE << CYAN;
        show_l(pmerge.get_pair_list());
        std::cout << END_STYLE;
        list_start = time();
        pmerge.first_sort_l();
        pmerge.second_sort_l();
        pmerge.set_pend_list();
        pmerge.insertion_l();
        list_end = time();
        vector_start = time();
        pmerge.first_sort_v();
        pmerge.second_sort_v();
        pmerge.set_pend_vec();
        pmerge.insertion_v();
        vector_end = time();
        std::cout << std::endl << RED << "After:  " << END_STYLE << CYAN;
        show_list(pmerge.get_lst());
        std::cout << std::endl;
        if (check_if_sort(pmerge.get_lst(), pmerge.get_vec(), argv) == true)
            std::cout << END_STYLE << RED << "CHECK: " << GREEN << "[SORTED]" << std::endl;
        std::cout << std::endl << END_STYLE;
        std::cout << PURPLE << "Time to process a range of " << pmerge.get_lst().size();
        std::cout << " elements with std::vector : " << vector_end - vector_start << " us" << std::endl;
        std::cout << "Time to process a range of " << pmerge.get_lst().size();
        std::cout << " elements with std::list : " << list_end - list_start << " us" << END_STYLE;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}