/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:21:20 by thamon            #+#    #+#             */
/*   Updated: 2022/10/31 20:12:35 by thamon           ###   ########.fr       */
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

	ft::vector<int> myfront;

	myfront.push_back(78);
	myfront.push_back(16);

	// now front equals 78, and back 16

	myfront.front() -= myfront.back();

	std::cout << "myfront.front() is now " << myfront.front() << '\n';

	std::cout << '\n';

	ft::vector<int> myback;

	myback.push_back(10);

	while (myback.back() != 0)
	{
		myback.push_back(myback.back() - 1);
	}

	std::cout << "myback contains:";
	for (unsigned i = 0; i < myback.size(); i++)
		std::cout << ' ' << myback[i];
	std::cout << '\n'
			  << std::endl;

	ft::vector<int> myassign;
	ft::vector<int> myassignsec;

	myassign.assign(7, 100); // 7 ints with a value of 100

	std::cout << "Size of myassign: " << int(myassign.size()) << '\n';
	for (unsigned i = 0; i < myassign.size(); i++)
		std::cout << myassign[i] << ' ';
	myassign.assign(2, 186); // 7 ints with a value of 100
	std::cout << "\nSize of myassign: " << int(myassign.size()) << '\n';

	for (unsigned i = 0; i < myassign.size(); i++)
		std::cout << myassign[i] << ' ';

	// ft::vector<int>::iterator ittttt;
	// ittttt = myassign.begin() + 1;

	// myassignsec.assign(ittttt, myassign.end() - 1); // the 5 central values of first
	// std::cout << "Size of myassignsec: " << int(myassignsec.size()) << '\n';
	// for (unsigned i = 0; i < myassignsec.size(); i++)
	// 	std::cout << myassignsec[i] << '\n';

	std::cout << '\n'
			  << std::endl;
	ft::vector<int> myclear;
	myclear.push_back(100);
	myclear.push_back(200);
	myclear.push_back(300);

	std::cout << "myclear contains:";
	for (unsigned i = 0; i < myclear.size(); i++)
		std::cout << ' ' << myclear[i];
	std::cout << '\n';

	myclear.clear();
	myclear.push_back(1101);
	myclear.push_back(2202);

	std::cout << "myclear contains:";
	for (unsigned i = 0; i < myclear.size(); i++)
		std::cout << ' ' << myclear[i];
	std::cout << '\n'
			  << std::endl;

	ft::vector<int> foo(3, 100); // three ints with a value of 100
	ft::vector<int> bar(5, 200); // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n'
			  << std::endl;

	ft::vector<int> myend;
	for (int i = 1; i <= 20; i++)
		myend.push_back(i);

	std::cout << "myend contains:";
	for (ft::vector<int>::iterator it = myend.begin(); it != myend.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n'
			  << std::endl;

	ft::vector<int> myerase;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myerase.push_back(i);

	// erase the 6th element
	myerase.erase(myerase.begin() + 5);

	// erase the first 3 elements:
	myerase.erase(myerase.begin(), myerase.begin() + 3);

	std::cout << "myerase contains:";
	for (unsigned i = 0; i < myerase.size(); ++i)
		std::cout << ' ' << myerase[i];
	std::cout << '\n'
			  << std::endl;

	// ft::vector<int> myinsert(3, 100);
	// ft::vector<int>::iterator it;

	// it = myinsert.begin();
	// it = myinsert.insert(it, 200);

	// myinsert.insert(it, 2, 300);

	// // "it" no longer valid, get a new one:
	// it = myinsert.begin();

	//   ft::vector<int> anothervector (2,400);
	//   myinsert.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray[] = {501, 502, 503};
	// myinsert.insert(myinsert.begin(), myarray, myarray + 3);

	// std::cout << "myinsert contains:";
	// for (it = myinsert.begin(); it < myinsert.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	ft::vector<int> fooo(3, 100); // three ints with a value of 100
	ft::vector<int> barr(2, 200); // two ints with a value of 200

	if (fooo == barr)
		std::cout << "fooo and barr are equal\n";
	if (fooo != barr)
		std::cout << "fooo and barr are not equal\n";
	if (fooo < barr)
		std::cout << "fooo is less than barr\n";
	if (fooo > barr)
		std::cout << "fooo is greater than barr\n";
	if (fooo <= barr)
		std::cout << "fooo is less than or equal to barr\n";
	if (fooo >= barr)
		std::cout << "fooo is greater than or equal to barr\n";

	std::cout << '\n';

	ft::vector<int> lil(3, 100); // three ints with a value of 100
	ft::vector<int> lal(5, 200); // five ints with a value of 200

	lil.swap(lal);

	std::cout << "lil contains:";
	for (ft::vector<int>::iterator it = lil.begin(); it != lil.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "lal contains:";
	for (ft::vector<int>::iterator it = lal.begin(); it != lal.end(); ++it)
		std::cout << ' ' << *it;
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