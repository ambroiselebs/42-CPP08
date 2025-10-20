/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:22:58 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/18 16:29:26 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::cout << "=== Test from subject ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with exception (span full) ===" << std::endl;
	try {
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw exception
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with no span (empty) ===" << std::endl;
	try {
		Span sp = Span(5);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with no span (one element) ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(42);
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	try {
		Span sp = Span(10000);
		std::vector<int> numbers;

		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++) {
			numbers.push_back(std::rand() % 100000);
		}

		sp.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Successfully added 10,000 numbers!" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with addNumbers (range) ===" << std::endl;
	try {
		Span sp = Span(100);
		std::vector<int> vec;
		for (int i = 0; i < 100; i++) {
			vec.push_back(i * 2);
		}
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
