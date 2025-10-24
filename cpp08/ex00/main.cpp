/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:46:02 by agorski           #+#    #+#             */
/*   Updated: 2025/10/20 14:57:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void test_vector()
{
	std::cout << "<<< Test std::vector >>>" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	try
	{
		std::cout << "Searching for 30... ";
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << " at index " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 99... ";
		easyfind(vec, 99);
		std::cout << "Found 99 (this should not happen)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
}

void test_list()
{
	std::cout << "\n<<< Test std::list >>>" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try
	{
		std::cout << "Searching for 1... ";
		std::list<int>::iterator it = easyfind(lst, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 5... ";
		easyfind(lst, 5);
		std::cout << "Found 5 (this should not happen)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
}

int main()
{
	test_vector();
	test_list();
	// You can add tests for other containers here, e.g. std::deque
	return 0;
}
