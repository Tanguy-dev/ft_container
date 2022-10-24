/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:29:38 by thamon            #+#    #+#             */
/*   Updated: 2022/10/25 00:03:13 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template <class Category = std::random_access_iterator_tag, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	class vector_iterator
	{
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;

	protected:
		pointer _ptr;

	public:
		vector_iterator(void)
		{
		}

		vector_iterator(const vector_iterator &other)
		{
			_ptr = other.get_ptr();
		}

		vector_iterator(pointer ptr) : _ptr(ptr)
		{
		}

		~vector_iterator(void);
		{
		}

		pointer get_ptr(void)
		{
			return (_ptr);
		}

		operator	vector_iterator<const T>(void) const
		{
			return (vector_iterator<const T>(this->_ptr));
		}

		vector_iterator &operator=(const vector_iterator<const T> &other)
		{
			if (*this != other)
				_ptr = other.get_prt();
			return (*this);
		}

		vector_iterator &operator++()
		{
			++_ptr;
			return *this;
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			operator++();
			return tmp;
		}

		vector_iterator &operator--()
		{
			--_ptr;
			return *this;
		}
		
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			operator--();
			return tmp;
		}

		// bool operator==(const vector_iterator &rhs) const
		// {
		// 	return p == rhs.p;
		// }

		// bool operator!=(const vector_iterator &rhs) const
		// {
		// 	return p != rhs.p;
		// }

		// int &operator*()
		// {
		// 	return *p;
		// }
	};
}

#endif