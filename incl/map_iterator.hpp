/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:29:38 by thamon            #+#    #+#             */
/*   Updated: 2022/11/10 19:25:19 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template <class T, class Category = std::bidirectional_iterator_tag, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	class map_iterator
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
		map_iterator(void)
		{
		}

		map_iterator(const map_iterator &rhs)
		{
			_ptr = rhs.get_ptr();
		}

		map_iterator(pointer ptr) : _ptr(ptr)
		{
		}

		~map_iterator()
		{
		}

		pointer get_ptr(void) const
		{
			return (_ptr);
		}

		operator	map_iterator<const T>(void) const
		{
			return (map_iterator<const T>(this->_ptr));
		}

		map_iterator &operator=(const map_iterator<const T> &cpy)
		{
			if (this != &cpy)
				_ptr = cpy.get_ptr();
			return (*this);
		}

		map_iterator &operator++(void)
		{
			++_ptr;
			return (*this);
		}

		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		map_iterator &operator--(void)
		{
			--_ptr;
			return (*this);
		}
		
		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		bool operator==(const map_iterator<const T> &rhs) const
		{
			return (_ptr == rhs.get_ptr());
		}

		bool operator!=(const map_iterator<const T> &rhs) const
		{
			return (_ptr != rhs.get_ptr());
		}

		value_type &operator*(void)
		{
			return (*_ptr);
		}

		value_type *operator->(void)
		{
			return (_ptr);
		}
	};
}

#endif