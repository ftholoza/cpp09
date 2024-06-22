/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:05:14 by francesco         #+#    #+#             */
/*   Updated: 2024/06/22 15:30:27 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

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

int main(int argc, char **argv)
{
    PmergeMe    pmerge;
    unsigned long   list_start, list_end;
    unsigned long   vector_start, vector_end;
    
    if (argc < 3)
    {
        std::cerr << "Error: Not enought arguments" << std::endl;
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
        std::cout << "Before:  ";
        show_l(pmerge.get_pair_list());
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
        std::cout << "After:  ";
        show_list(pmerge.get_lst());
        
        std::cout << "Time to process a range of " << pmerge.get_lst().size();
        std::cout << " elements with std::vector : " << vector_end - vector_start << " us" << std::endl;
        std::cout << "Time to process a range of " << pmerge.get_lst().size();
        std::cout << " elements with std::list : " << list_end - list_start << " us";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}