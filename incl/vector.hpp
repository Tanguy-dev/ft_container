/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:24:32 by thamon            #+#    #+#             */
/*   Updated: 2022/10/24 23:59:49 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"
#include "vector_iterator.hpp"
#include <vector>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	private:
		/* data */
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		/* Faire les vectors iterator et les reverses */
		typedef	ft::vector_iterator<value_type>							iterator;
		typedef	ft::vector_iterator<const value_type>					const_iterator;
		// typedef	ft::reverse_iterator<iterator>							reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef typename std::size_t size_type;
		// typedef typename std::iterator_traits<iterator>::difference_type		difference_type;

	private:
		allocator_type _alloc;
		pointer _start;
		size_type _size;
		size_type _capacity;

	public:
		explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(0), _size(0), _capacity(0)
		{
		}

		explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(0), _size(n), _capacity(n)
		{
			_start = alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				_alloc.construct(&_start[i], value);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
		}

		vector(const vector &x) : _alloc(x._alloc), _start(0), _size(x._size), _capacity(x._size)
		{
			_start = _alloc.allocate(x._size);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_start[i], x._start[i]);
		}

		~vector(void)
		{
			_alloc.deallocate(_start, _capacity);
		}

		/*		Operator		*/
		vector &operator=(const vector &x)
		{
			if (*this == x)
				return (*this);
			_alloc.deallocate(_start, _capacity);
			_size = x._size;
			_capacity = x._capacity;
			_start = x._alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_start[i], x._start);
			return (*this);
		}

		/*		Iterators		*/
		iterator begin()
		{
			return (iterator(_start));
		}

		const_iterator begin() const
		{
			return (const_iterator(_start));
		}

		iterator end()
		{
			return (iterator(_start + 1));
		}

		const_iterator end() const
		{
			return (const_iterator(_start + 1));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_start));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_start));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_start + 1));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_start + 1));
		}

		// const_iterator cbegin() const noexcept;
		// const_iterator cend() const noexcept;
		// const_reverse_iterator crbegin() const noexcept;
		// const_reverse_iterator crend() const noexcept;
	};
}

#endif