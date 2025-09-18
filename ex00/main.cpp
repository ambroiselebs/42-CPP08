/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:22:58 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:27 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int>	vec;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator	it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator	it = easyfind(vec, 7);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
