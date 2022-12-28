/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:32:00 by thamon            #+#    #+#             */
/*   Updated: 2022/12/28 18:34:28 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "incl/stack.hpp"
#include "incl/vector.hpp"
#include <stack>
#include <vector>
#include <iostream>

int	main(void)
{
	ft::stack<int> first;
	std::cout << "=============\t\tft::stack\t=============" << std::endl;
	std::cout << "is it empty ? " << (first.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "size of my stack before adding 3 values : " << first.size() << std::endl;
	first.push(42);
	first.push(666);
	first.push(21);
	std::cout << first.size() << std::endl;
	std::cout << "trying to show all values of present on my stack " << std::endl;
    for (ft::stack<int> dump = first; !dump.empty(); dump.pop())
		std::cout << dump.top() << std::endl;
	std::cout << "is it empty ? " << (first.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "\n=============== testing operators ===============\n" << std::endl;
	
	ft::stack<int> second;
	second.push(84);
	second.push(1337);
	second.push(2727);

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<=" << std::endl;
	if (first <= second)
		std::cout << "stack1 is <= than stack2" << std::endl;
	else
		std::cout << "stack1 is not <= than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<" << std::endl;
	if (first < second)
		std::cout << "stack1 is < than stack2" << std::endl;
	else
		std::cout << "stack1 is not < than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "==" << std::endl;
	if (first == second)
		std::cout << "both stacks are equal" << std::endl;
	else
		std::cout << "both stacks are not equal" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">" << std::endl;
	if (first > second)
		std::cout << "stack1 is > than stack2" << std::endl;
	else
		std::cout << "stack1 is not > than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">=" << std::endl;
	if (first >= second)
		std::cout << "stack1 is >= than stack2" << std::endl;
	else
		std::cout << "stack 1 is not >= than stack2" << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "!=" << std::endl;
	if (first != second)
		std::cout << "both stacks are differents" << std::endl;
	else
		std::cout << "both stacks are equal" << std::endl;
	std::cout << "================================" << std::endl;

	std::cout << "\n\n=============== Now testing with real STD::STACK ===============\n" << std::endl;

	std::stack<int> firstR;
	std::cout << "=============\t\tstd::stack\t=============" << std::endl;
	std::cout << "is it empty ? " << (firstR.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "size of my stack before adding 3 values : " << firstR.size() << std::endl;
	firstR.push(42);
	firstR.push(666);
	firstR.push(21);
	std::cout << firstR.size() << std::endl;
	std::cout << "trying to show all values of present on my stack " << std::endl;
    for (std::stack<int> dump = firstR; !dump.empty(); dump.pop())
		std::cout << dump.top() << std::endl;
	std::cout << "is it empty ? " << (firstR.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "\n=============== testing operators ===============\n" << std::endl;
	
	std::stack<int> secondR;
	secondR.push(84);
	secondR.push(1337);
	secondR.push(2727);

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<=" << std::endl;
	if (firstR <= secondR)
		std::cout << "stack1 is <= than stack2" << std::endl;
	else
		std::cout << "stack1 is not <= than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<" << std::endl;
	if (firstR < secondR)
		std::cout << "stack1 is < than stack2" << std::endl;
	else
		std::cout << "stack1 is not < than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "==" << std::endl;
	if (firstR == secondR)
		std::cout << "both stacks are equal" << std::endl;
	else
		std::cout << "both stacks are not equal" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">" << std::endl;
	if (firstR > secondR)
		std::cout << "stack1 is > than stack2" << std::endl;
	else
		std::cout << "stack1 is not > than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">=" << std::endl;
	if (firstR >= secondR)
		std::cout << "stack1 is >= than stack2" << std::endl;
	else
		std::cout << "stack 1 is not >= than stack2" << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "!=" << std::endl;
	if (firstR != secondR)
		std::cout << "both stacks are differents" << std::endl;
	else
		std::cout << "both stacks are equal" << std::endl;
	std::cout << "================================" << std::endl;
}
