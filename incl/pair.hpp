/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:05:09 by thamon            #+#    #+#             */
/*   Updated: 2022/11/10 16:26:24 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(void) : first(), second()
		{
		}

		template <class U, class V>
		pair(const ft::pair<U, V> &pr) : first(pr.first), second(pr.second)
		{
		}

		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{
		}

		ft::pair<T1, T2> &operator=(const ft::pair<T1, T2> &pr)
		{
			if (*this == pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	};

	template <class T1, class T2>
	bool operator== (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs != rhs);
	}

	template <class T1, class T2>
	bool operator< (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first)) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator> (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs < lhs);
	}
	
	template <class T1, class T2>
	bool operator<= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs > lhs);
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs < lhs);
	}
}

#endif