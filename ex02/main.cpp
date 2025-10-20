/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:00:00 by aberenge          #+#    #+#             */
/*   Updated: 2025/10/20 00:00:00 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Test with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same test with std::list ===" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	{
		MutantStack<int> mstack;

		// Test avec des nombres
		for (int i = 0; i < 10; i++)
			mstack.push(i * 2);

		std::cout << "Forward iteration:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Reverse iteration:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Test de copie
		MutantStack<int> copy(mstack);
		std::cout << "Copy size: " << copy.size() << std::endl;
		std::cout << "Copy top: " << copy.top() << std::endl;

		// Test d'assignation
		MutantStack<int> assigned;
		assigned = mstack;
		std::cout << "Assigned size: " << assigned.size() << std::endl;
		std::cout << "Assigned top: " << assigned.top() << std::endl;
	}

	std::cout << "\n=== Test with strings ===" << std::endl;
	{
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("World");
		strStack.push("42");

		for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	return 0;
}
