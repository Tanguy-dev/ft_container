/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:24:32 by thamon            #+#    #+#             */
/*   Updated: 2022/10/18 21:29:25 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"
#include <vector>

template<class T, class Alloc = std::allocator<T> >
class vector
{
private:
	/* data */
public:
	typedef T														value_type;
	typedef	Alloc													allocator_type;
	typedef typename allocator_type::reference						reference;
    typedef typename allocator_type::const_reference				const_reference;
    typedef typename allocator_type::pointer						pointer;
    typedef typename allocator_type::const_pointer					const_pointer;
	typedef	ft::VectorIterator<value_type>							iterator;
	typedef	ft::VectorIterator<const value_type>					const_iterator;
    typedef	ft::reverse_iterator<iterator>							reverse_iterator;
    typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename std::size_t									size_type;
    typedef typename iterator_traits<iterator>::difference_type		difference_type;

private:
	allocator_type	_alloc;
	pointer			_start;
	size_type		_size;
    size_type		_capacity;

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

	vector(const vector& x) : _alloc(x._alloc), _start(0), _size(x._size), _capacity(x._size)
	{
		_start = _alloc.allocate(x._size);
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(&_start[i], x._start[i]);
		
	}

	~vector(void)
	{
		_alloc.deallocate(_start, _capacity);
	}
};

#endif