/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeL.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:51:54 by francesco         #+#    #+#             */
/*   Updated: 2024/06/22 15:12:14 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::first_sort_l()
{
    std::list<std::pair<int, int> >::iterator itl = this->list.begin();
    int temp;

    while (itl != this->list.end())
    {
        if ((*itl).first > (*itl).second && (*itl).second != -1)
        {
            
            temp = (*itl).first;
            (*itl).first = (*itl).second;
            (*itl).second = temp;
        }
        itl++;
    }
    return ;
}

void get_it(std::list<int>::iterator &it, std::list<int> &list, int index)
{
    it = list.begin();
    if (index >= 0)
        while (index--) ++it;
    else
        while (index++) --it;
}

void    show_list(std::list<int> list)
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void    merge(std::list<int> &list, int left, int mid, int right)
{
    std::list<int> first;
    std::list<int> second;
    std::list<int>::iterator it = list.begin();
    int first_len = mid - left + 1;
    int second_len = right - mid;
    
    for (int i = 0; i < first_len; i++)
    {
        get_it(it, list, left + i);
        first.push_back(*it);
    }
    for (int j = 0; j < second_len; j++)
    {
        get_it(it, list, mid + 1 + j);
        second.push_back(*it);
    }
    std::list<int>::iterator it_first = first.begin();
    std::list<int>::iterator it_second = second.begin();
    int k = left;
    while (it_first != first.end() && it_second != second.end())
    {
        if (*it_first <= *it_second)
        {
            get_it(it, list, k);
            *it = *it_first;
            it_first++;
        }
        else
        {
            get_it(it, list, k);
            *it = *it_second;
            it_second++;
        }
        k++;
    }
    while (it_first != first.end())
    {
        get_it(it, list, k);
        *it = *it_first;
        it_first++;
        k++;
    }
    while (it_second != second.end())
    {
        get_it(it, list, k);
        *it = *it_second;
        it_second++;
        k++;
    }
}

void    merge_sort_l(std::list<int> &list, int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;
        //std::cout << "mid: " << m << std::endl;
        merge_sort_l(list, left, m);
        merge_sort_l(list, m + 1, right);
        merge(list, left, m, right);
    }
}

void    PmergeMe::second_sort_l()
{
    std::list<int>  lst;
    
    std::list<int>::iterator itl = lst.begin();
    std::list<std::pair<int, int> >::iterator it = this->list.begin();
    while (it != this->list.end())
    {
        if ((*it).second != -1)
            lst.push_back((*it).second);
        it++;
    }
    itl = lst.begin();
    merge_sort_l(lst, 0, lst.size() - 1);
    this->lst = lst;
}

void    show_pair_list(std::list<std::pair<int, int> > list)
{
    std::list<std::pair<int, int> >::iterator itl = list.begin();
    while (itl != list.end())
    {
        std::cout <<  "(" << (*itl).first << ", ";
        std::cout << (*itl).second << ")";
        itl++;
    }
    std::cout << std::endl;
    return ;
}

void    sort_pair_l(std::list<int> lst, std::list<std::pair<int, int> > list, std::list<std::pair<int, int> > &sorted_list)
{
    std::list<int>::iterator    it = lst.begin();
    std::pair<int, int>         pair;
    std::list<std::pair<int, int > >    sorted_pair;

    while (it != lst.end())
    {
        std::list<std::pair<int, int> >::iterator itl = list.begin();
        while (itl != list.end())
        {
            if ((*itl).second == *it)
            {
                pair.first = (*itl).first;
                pair.second = (*itl).second;
                sorted_pair.push_back(pair);
            }
            itl++;
        }
        it++;
    }
    sorted_list = sorted_pair;
}

void    PmergeMe::set_pend_list()
{
    static int jacobsthal_list[] = {
	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846,
	43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
	22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766};
    std::list<std::pair<int, int> >::iterator   itl;
    int                                         i = 0;

    sort_pair_l(this->lst, this->list, this->sorted_list);
    itl = this->sorted_list.begin();
    this->lst.push_front(this->sorted_list.front().first);
    this->sorted_list.pop_front();
    while (this->sorted_list.size() > 0)
    {
        itl = this->sorted_list.begin();
        if (jacobsthal_list[i] > (int)this->sorted_list.size())
            break;
        for (int y = 1; y < jacobsthal_list[i]; y++)
            itl++;
        for (int y = 0; y < jacobsthal_list[i]; y++)
        {
            this->pend.push_back((*itl).first);
            itl--;
        }
        for (int y = 0; y < jacobsthal_list[i]; y++)
            this->sorted_list.pop_front();
        i++;
    }
    if (this->sorted_list.size() > 0)
    {
        itl = --this->sorted_list.end();
        while (itl != this->sorted_list.begin())
        {
            this->pend.push_back((*itl).first);
            itl--;
        }
        this->pend.push_back((*itl).first);
    }
}

int get_list_index(std::list<int>::iterator it, std::list<int> &list)
{
    int i = 0;
    while (it != list.end())
    {
        it++;
        i++;
    }
    return (list.size() - i);
}

void    insert_l(int index, int target, std::list<int> &lst)
{
    std::list<int>  res;
    std::list<int>::iterator it = lst.begin();

    for (int i = 0; i < index; i++)
    {
        res.push_back(*it);
        it++;
    }
    res.push_back(target);
    while (it != lst.end())
    {
        res.push_back(*it);
        it++;
    }
    lst = res;
}

int    binary_research(int target, int max, std::list<int> &list)
{
    int start = 0;
    std::list<int>::iterator    it;
    std::list<int>::iterator    iti;
    int mid;
    
    while (start <= max)
    {
        mid = start + (max - start) / 2;
        get_it(it, list, mid);
        if (*it < target)
            start = mid + 1;
        else
            max = mid - 1;
    }
    get_it(it, list, start);
    if (target > *it)
    {        
        get_it(iti, list, start -1);
        list.insert(iti, target);
    }
    else
    {
        get_it(iti, list, start);
        list.insert(iti, target);
    }
    return (0);
}

void    PmergeMe::insertion_l()
{
    int jacobsthal_list[] = {
	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846,
	43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
	22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766};
    std::list<int>::iterator						it = this->pend.begin();
    std::list<std::pair<int, int> >::iterator		itl = --this->list.end();
	int												y = 0, x = 0, z = 0;

	while (it != this->pend.end())
	{
		if (x + z + 1 + jacobsthal_list[y] > (int)this->lst.size())
			binary_research(*it, this->lst.size() - 1, this->lst);
		else
			binary_research(*it, x + z + 1 + jacobsthal_list[y], this->lst);
		jacobsthal_list[y]--;
		it++;
		x += 1;
		if (jacobsthal_list[y] == 0)
		{
			z = x;
			y++;
		}
	}
	if ((*itl).second == -1)
        binary_research((*itl).first, this->lst.size(), this->lst);
}