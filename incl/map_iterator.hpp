/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:29:38 by thamon            #+#    #+#             */
/*   Updated: 2022/11/23 01:24:11 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>
#include "BSTnode.hpp"

namespace ft
{
	template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class map_iterator
	{
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;

	protected:
		T *_ptr;

	public:
		map_iterator(void) : _ptr(NULL)
		{
		}

		map_iterator(const map_iterator &rhs)
		{
			*this = rhs;
		}

		map_iterator(T *ptr) : _ptr(ptr)
		{
		}

		~map_iterator()
		{
		}

		T *get_ptr(void) const
		{
			return (_ptr);
		}

		map_iterator &operator=(const map_iterator &cpy)
		{
			if (this != &cpy)
				_ptr = cpy._ptr;
			return (*this);
		}

		map_iterator &operator++(void)
		{
			_ptr = _ptr->next();
			return (*this);
		}

		map_iterator operator++(int)
		{
			map_iterator tmp = *this;
			_ptr = _ptr->next();
			return (tmp);
		}

		map_iterator &operator--(void)
		{
			_ptr = _ptr->prev();
			return (*this);
		}

		map_iterator operator--(int)
		{
			map_iterator tmp = *this;
			_ptr = _ptr->prev();
			return (tmp);
		}

		bool operator==(const map_iterator &rhs) const
		{
			return (_ptr == rhs._ptr);
		}

		bool operator!=(const map_iterator &rhs) const
		{
			return (_ptr != rhs._ptr);
		}

		reference operator*(void) const
		{
			return (_ptr->value);
		}

		pointer operator->(void) const
		{
			return (&_ptr->value);
		}
	};

	template <class T, class U, class map_iterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class constMap_iterator
	{
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;

	protected:
		T *_ptr;

	public:
		constMap_iterator(void) : _ptr(NULL)
		{
		}

		constMap_iterator(const constMap_iterator &rhs)
		{
			*this = rhs;
		}

		constMap_iterator(T *ptr) : _ptr(ptr)
		{
		}

		constMap_iterator(const map_iterator &cpy)
		{
			_ptr = cpy.get_ptr();
		}

		~constMap_iterator()
		{
		}

		T *get_ptr(void) const
		{
			return (_ptr);
		}

		constMap_iterator &operator=(const constMap_iterator &cpy)
		{
			if (this != &cpy)
				_ptr = cpy._ptr;
			return (*this);
		}

		constMap_iterator &operator++(void)
		{
			_ptr = _ptr->next();
			return (*this);
		}

		constMap_iterator operator++(int)
		{
			constMap_iterator tmp = *this;
			_ptr = _ptr->next();
			return (tmp);
		}

		constMap_iterator &operator--(void)
		{
			_ptr = _ptr->prev();
			return (*this);
		}

		constMap_iterator operator--(int)
		{
			constMap_iterator tmp = *this;
			_ptr = _ptr->prev();
			return (tmp);
		}

		bool operator==(const constMap_iterator &rhs) const
		{
			return (_ptr == rhs._ptr);
		}

		bool operator!=(const constMap_iterator &rhs) const
		{
			return (_ptr != rhs._ptr);
		}

		const reference operator*(void) const
		{
			return (_ptr->value);
		}

		const pointer operator->(void) const
		{
			return (&_ptr->value);
		}
	};
}

#endif