/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:21:20 by thamon            #+#    #+#             */
/*   Updated: 2022/10/26 23:32:59 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	namespace ft = std;
// #else
#include <vector>
#include <stack>
#include <map.hpp>
#include <stack.hpp>
#include <vector.hpp>
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T> &src) { *this = src; }
	MutantStack<T> &operator=(const MutantStack<T> &rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main()
{
	ft::stack<int> stack_int;
	std::stack<int> stack_intt;
	size_t size;

	stack_int.push(34);
	stack_int.push(28);
	stack_int.push(18);
	stack_int.push(19);
	stack_int.push(1);
	stack_int.push(89);

	stack_intt.push(34);
	stack_intt.push(28);
	stack_intt.push(18);
	stack_intt.push(19);
	stack_intt.push(1);
	stack_intt.push(89);

	size = stack_int.size();
	std::cout << "La size de ft::stack = " << stack_int.size() << " et voici ce qu'elle contient : " << std::endl;
	for (size_t i = size; i != 0; i--)
	{
		std::cout << stack_int.top() << std::endl;
		stack_int.pop();
	}

	size = stack_intt.size();
	std::cout << std::endl
			  << "La size de std::stack = " << stack_intt.size() << " et voici ce qu'elle contient : " << std::endl;
	for (size_t i = size; i != 0; i--)
	{
		std::cout << stack_intt.top() << std::endl;
		stack_intt.pop();
	}

	std::cout << std::endl
			  << "<---------------------------------Vector test--------------------------------->" << std::endl;

	std::vector<int> real_vec;
	ft::vector<int> my_vec;

	real_vec.push_back(10);
	real_vec.push_back(42);
	real_vec.push_back(32);
	real_vec.push_back(895);

	for (std::vector<int>::iterator it = real_vec.begin(); it != real_vec.end(); ++it)
		std::cout << ' ' << *it;
	// for (std::vector<int>::iterator it = my_vec.begin() ; it != my_vec.end(); ++it)
	// 	std::cout << ' ' << *it;
	// for (size_t i = 0; real_vec[i]; i++)
	// {
	// 	std::cout << real_vec[i] << std::endl;
	// }
	std::cout << '\n'
			  << std::endl;

	ft::vector<int> myvector;

	//   set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	std::cout << "myvector contains after 5 :";
	for (size_t i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	myvector.resize(8, 100);
	std::cout << "myvector contains after 8,100 :";
	for (size_t i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	myvector.resize(12);
	std::cout << "myvector contains after 12 :";
	for (size_t i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	myvector.resize(10);

	std::cout << '\n'
			  << std::endl;

	// assign some values:
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);

	std::cout << '\n'
			  << std::endl;

	std::vector<int> myfront;

	myfront.push_back(78);
	myfront.push_back(16);

	// now front equals 78, and back 16

	myfront.front() -= myfront.back();

	std::cout << "myfront.front() is now " << myfront.front() << '\n';


	std::cout << '\n';

	std::vector<int> myback;

	myback.push_back(10);

	while (myback.back() != 0)
	{
		myback.push_back(myback.back() - 1);
	}

	std::cout << "myback contains:";
	for (unsigned i = 0; i < myback.size(); i++)
		std::cout << ' ' << myback[i];
	std::cout << '\n';
}

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}

// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }