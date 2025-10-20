/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:34:27 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/18 16:41:36 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_max;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		template<typename Iterator>
		void	addNumbers(Iterator begin, Iterator end) {
			while (begin != end) {
				addNumber(*begin);
				++begin;
			}
		}

		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
