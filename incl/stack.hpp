/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:06:05 by thamon            #+#    #+#             */
/*   Updated: 2022/10/24 20:27:44 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

// #include "vector.hpp"
#include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef std::size_t	size_type;
	
	protected:
		Container c;

	public:
		explicit				stack(const container_type &ctnr = container_type()) : c(ctnr)
		{
		}

		bool					empty(void) const
		{
			return (c.empty());
		}

		size_type				size(void) const
		{
			return (c.size());
		}

		value_type				&top(void)
		{
			return (c.back());
		}

		const value_type		&top(void) const
		{
			return (c.back());
		}

		void					push(const value_type &val)
		{
			c.push_back(val);
		}

		void					pop(void)
		{
			c.pop_back();
		}

		friend bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs.c == rhs.c);
		}

		friend bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs.c != rhs.c);
		}

		friend bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs.c < rhs.c);
		}

		friend bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs.c > rhs.c);
		}

		friend bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs <= rhs);
		}

		friend bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
		{
			return (lhs >= rhs);
		}
	};
}

#endif