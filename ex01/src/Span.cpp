/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:34:26 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/18 16:41:49 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span &other) : _numbers(other._numbers), _max(other._max) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_numbers = other._numbers;
		_max = other._max;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number) {
	if (_numbers.size() >= _max)
		throw FullSpanException();
	_numbers.push_back(number);
}

int		Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int		Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

const char* Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
	return "No span can be found";
}
