/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:29:38 by thamon            #+#    #+#             */
/*   Updated: 2022/11/02 23:18:04 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template <class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	class vector_iterator
	{
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;

	private:
		pointer _ptr;

	public:
		vector_iterator(void)
		{
		}

		vector_iterator(const vector_iterator &rhs)
		{
			_ptr = rhs.get_ptr();
		}

		vector_iterator(pointer ptr) : _ptr(ptr)
		{
		}

		~vector_iterator()
		{
		}

		pointer get_ptr(void) const
		{
			return (_ptr);
		}

		operator	vector_iterator<const T>(void) const
		{
			return (vector_iterator<const T>(this->_ptr));
		}

		vector_iterator &operator=(const vector_iterator<const T> &cpy)
		{
			if (*this != cpy)
				_ptr = cpy.get_ptr();
			return (*this);
		}

		vector_iterator &operator++(void)
		{
			++_ptr;
			return (*this);
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		vector_iterator &operator--(void)
		{
			--_ptr;
			return (*this);
		}
		
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool operator==(const vector_iterator<const T> &rhs) const
		{
			return (_ptr == rhs.get_ptr());
		}

		bool operator!=(const vector_iterator<const T> &rhs) const
		{
			return (_ptr != rhs.get_ptr());
		}

		bool operator>(const vector_iterator<const T> &rhs) const
		{
			return (_ptr > rhs.get_ptr());
		}

		bool operator<(const vector_iterator<const T> &rhs) const
		{
			return (_ptr < rhs.get_ptr());
		}

		bool operator>=(const vector_iterator<const T> &rhs) const
		{
			return (_ptr >= rhs.get_ptr());
		}

		bool operator<=(const vector_iterator<const T> &rhs) const
		{
			return (_ptr <= rhs.get_ptr());
		}

		value_type &operator*(void)
		{
			return (*_ptr);
		}

		value_type &operator->(void)
		{
			return (_ptr);
		}

		vector_iterator operator+(int nb) const
		{
			vector_iterator tmp(*this);
			tmp += nb;
			return (tmp);
		}

		vector_iterator operator-(int nb) const
		{
			vector_iterator tmp(*this);
			tmp -= nb;
			return (tmp);
		}

		friend vector_iterator	operator+(std::ptrdiff_t n, vector_iterator it)
		{
			vector_iterator	tmp(it.get_ptr());
			tmp += n;
			return (tmp);
		}

		int	operator-(const vector_iterator<const T> &rhs) const
		{
			return (_ptr - rhs.get_ptr());
		}

		vector_iterator	operator+=(int n)
		{
			_ptr += n;
			return (*this);
		}

		vector_iterator	operator-=(int n)
		{
			_ptr -= n;
			return (*this);
		}

		value_type	operator[](int n)
		{
			return (_ptr[n]);
		}
	};
}

#endif