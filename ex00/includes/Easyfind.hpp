/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:23:27 by aberenge          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:13 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return ("Element not found in container");
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int value);

#include "Easyfind.tpp"

#endif
