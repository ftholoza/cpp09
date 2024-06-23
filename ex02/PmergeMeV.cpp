/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeV.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:30:32 by francesco         #+#    #+#             */
/*   Updated: 2024/06/23 19:23:31 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    get_it_v(std::vector<int>::iterator &it, std::vector<int> &vector, int index)
{
    it = vector.begin();
    if (index >= 0)
        while (index--) ++it;
    else
        while (index++) --it;
}

void    PmergeMe::first_sort_v()
{
    //std::vector<std::pair<int, int> >::iterator itv = this->vector.begin();
    std::vector<std::pair<int, int> > &vector = this->vector;
    int i = 0;
    int temp;
    

    while (i < (int)vector.size())
    {
        if (vector[i].first > vector[i].second && vector[i].second != -1)
        {
            temp = vector[i].first;
            vector[i].first = vector[i].second;
            vector[i].second = temp;
        }
        i++;
    }
}

void    merge_v(std::vector<int> &vector, int left, int mid, int right)
{
    std::vector<int> first;
    std::vector<int> second;
    int first_len = mid - left + 1;
    int second_len = right - mid;
    
    for (int i = 0; i < first_len; i++)
        first.push_back(vector[left + i]);
    for (int j = 0; j < second_len; j++)
        second.push_back(vector[mid + 1 + j]);
    int x = 0, y = 0;
    int k = left;
    while (x < (int)first.size() && y < (int)second.size())
    {
        if (first[x] <= second[y])
        {
            vector[k] = first[x];
            x++;
        }
        else
        {
            vector[k] = second[y];
            y++;
        }
        k++;
    }
    while (x < (int)first.size())
    {
        vector[k] = first[x];
        x++;
        k++;
    }
    while (y < (int)second.size())
    {
        vector[k] = second[y];
        y++;
        k++;
    }
}

void    merge_sort_v(std::vector<int> &vector, int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;
        merge_sort_v(vector, left, m);
        merge_sort_v(vector, m + 1, right);
        merge_v(vector, left, m, right);
    }
}

void    show_vector(std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    std::cout << "vector:" << std::endl;
    while (it != vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    return ;
}

void    PmergeMe::second_sort_v()
{
    std::vector<int> vec;
    std::vector<std::pair<int, int> > &vector = this->vector;
    int i = 0;

    while (i < (int)vector.size())
    {
        if (vector[i].second != -1)
            vec.push_back(vector[i].second);
        i++;
    }
    merge_sort_v(vec, 0, vec.size() - 1);
    this->vec = vec;
}

void    insert_v(int index, int target, std::vector<int> &lst)
{
    std::vector<int>  res;
    std::vector<int>::iterator it = lst.begin();

    for (int i = 0; i < index; i++)
    {
        if (it == lst.end())
            break;
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

void    vec_pop_front(std::vector<std::pair<int, int> >  &vector)
{
    std::vector<std::pair<int, int> > res;
    std::vector<std::pair<int, int> >::iterator it = vector.begin();
    
    if (vector.size() > 1)
        it++;
    while (it != vector.end())
    {
        res.push_back(*it);
        it++;
    }
    vector = res;
}

void    sort_pair_v(std::vector<int> lst, std::vector<std::pair<int, int> > list, std::vector<std::pair<int, int> > &sorted_list)
{
    std::vector<int>::iterator    it = lst.begin();
    std::pair<int, int>         pair;
    std::vector<std::pair<int, int > >    sorted_pair;

    while (it != lst.end())
    {
        std::vector<std::pair<int, int> >::iterator itl = list.begin();
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

void    PmergeMe::set_pend_vec()
{
    static int jacobsthal_list[] = {
	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846,
	43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
	22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766};
    std::vector<std::pair<int, int> >::iterator   itl;
    std::vector<std::pair<int, int> > &vector = this->sorted_vector;
    int                                         i = 0;
    int                                         x = 0;

    sort_pair_v(this->vec, this->vector, this->sorted_vector);
    itl = this->sorted_vector.begin();
    vec.insert(vec.begin(), this->sorted_vector.front().first);
    vec_pop_front(this->sorted_vector);
    while (this->sorted_vector.size() > 0)
    {
        x = 0;
        if (jacobsthal_list[i] > (int)this->sorted_vector.size())
            break;
        for (int y = 1; y < jacobsthal_list[i]; y++)
            x++;
        for (int y = 0; y < jacobsthal_list[i]; y++)
        {
            this->pend_v.push_back(vector[x].first);
            x--;
        }
        for (int y = 0; y < jacobsthal_list[i]; y++)
            vec_pop_front(this->sorted_vector);
        i++;
    }
    if (this->sorted_vector.size() > 0)
    {
        itl = --this->sorted_vector.end();
        while (itl != this->sorted_vector.begin())
        {
            this->pend_v.push_back((*itl).first);
            itl--;
        }
        this->pend_v.push_back((*itl).first);
    }
}

int    binary_research_v(int target, int max, std::vector<int> &list)
{
    int start = 0;
    std::vector<int>::iterator    it;
    int mid;
    
    while (start <= max)
    {
        mid = start + (max - start) / 2;
        if (list[mid] < target)
            start = mid + 1;
        else
            max = mid - 1;
    }
    if (target > list[start])
        list.insert(list.begin() + start - 1, target);
    else
        list.insert(list.begin() + start, target);
    return (0);
}

void    PmergeMe::insertion_v()
{
    int jacobsthal_list[] = {
	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846,
	43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
	22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766};
    std::vector<int>::iterator						it = this->pend_v.begin();
    std::vector<std::pair<int, int> >::iterator		itl = --this->vector.end();
	int												y = 0, x = 0, z = 0;

	while (it != this->pend_v.end())
	{
		if (x + z + 1 + jacobsthal_list[y] > (int)this->vec.size())
			binary_research_v(*it, this->vec.size() - 1, this->vec);
		else
			binary_research_v(*it, x + z + 1 + jacobsthal_list[y], this->vec);
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
        binary_research_v((*itl).first, this->vec.size(), this->vec);
    //show_vector(this->vec);
    //std::cout << std::endl;
}