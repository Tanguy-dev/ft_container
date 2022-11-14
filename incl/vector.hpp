/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:24:32 by thamon            #+#    #+#             */
/*   Updated: 2022/11/14 16:01:17 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"
#include <iostream>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::vector_iterator<value_type> iterator;
		typedef ft::vector_iterator<const value_type> const_iterator;
		typedef	ft::reverse_iterator<iterator>							reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		typedef typename std::size_t size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

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
			_start = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				_alloc.construct(&_start[i], value);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type* = 0) : _alloc(alloc), _start(0), _size(0), _capacity(0)
		{
			this->assign(first, last);
		}

		vector(const vector &x) : _alloc(x._alloc), _start(0), _size(x._size), _capacity(x._size)
		{
			_start = _alloc.allocate(x._size);
			for (size_t i = 0; i < x._size; i++)
				_alloc.construct(&_start[i], x._start[i]);
		}

		~vector()
		{
			this->clear();
			_alloc.deallocate(_start, _capacity);
		}

		/*		Operator		*/
		vector &operator=(const vector &x)
		{
			if (*this == x)
				return (*this);
			this->clear();
			_alloc.deallocate(_start, _capacity);
			_capacity = x._capacity;
			_size = x._size;
			_start = _alloc.allocate(_size);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_start[i], x._start[i]);
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
			return (iterator(_start + _size));
		}

		const_iterator end() const
		{
			return (const_iterator(_start + _size));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		/*		Capacity		*/
		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		void resize(size_type n, value_type val = value_type())
		{
			size_type new_size;

			if (n < _size)
			{
				while (_size != n)
					this->pop_back();
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					if (_capacity == 0)
						new_size = 1;
					else
						new_size = _capacity * 2;
					if (new_size < n)
						new_size = n;
					this->reserve(new_size);
				}
				while (_size < n)
				{
					_alloc.construct(&_start[_size], val);
					_size++;
				}
			}
		}

		size_type capacity() const
		{
			return (_capacity);
		}

		bool empty() const
		{
			if (_size)
				return (false);
			return (true);
		}

		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (n != 0 && n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _start[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_start[i]);
				_alloc.deallocate(_start, _capacity);
				_capacity = n;
				_start = tmp;
			}
		}

		/*		Element access		*/
		reference operator[](size_type n)
		{
			return (_start[n]);
		}

		const_reference operator[](size_type n) const
		{
			return (_start[n]);
		}

		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return (_start[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return (_start[n]);
		}

		reference front()
		{
			return (_start[0]);
		}

		const_reference front() const
		{
			return (_start[0]);
		}

		reference back()
		{
			return (_start[_size - 1]);
		}

		const_reference back() const
		{
			return (_start[_size - 1]);
		}

		/*		Modifiers		*/
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		assign(InputIterator first, InputIterator last)
		{
			int range;
			InputIterator tmp;

			tmp = first;
			range = 0;
			while (tmp != last)
			{
				tmp++;
				range++;
			}
			if (range < 0)
				std::length_error("vector");
			this->clear();
			this->reserve(range);
			for (; first != last; ++first)
				this->push_back(*first);
		}

		void assign(size_type n, const value_type &val)
		{
			while (_size > 0)
				this->pop_back();
			while (_size < n)
				this->push_back(val);
		}

		void push_back(const value_type &val)
		{
			if (_capacity < _size + 1)
			{
				if (_size == 0)
					this->reserve(1);
				else
					this->reserve(_size * 2);
			}
			_alloc.construct(&_start[_size], val);
			_size++;
		}

		void pop_back()
		{
			_alloc.destroy(&_start[_size - 1]);
			_size--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_type index;

			index = position - this->begin();
			this->insert(position, 1, val);
			return (iterator(this->begin() + index));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			iterator src;
			iterator dest;
			size_type index;
			size_type new_capacity;

			if (n <= 0)
				return;
			index = position - this->begin();
			if (_size + n >= _capacity)
			{
				if (_size == 0)
					new_capacity = 1;
				else
					new_capacity = _size * 2;
				if (new_capacity < _size + n)
					new_capacity = _size + n;
				this->reserve(new_capacity);
			}
			src = this->end() - 1;
			dest = src + n;
			while (src >= (this->begin() + index))
			{
				_alloc.construct(&(*dest), *src);
				_alloc.destroy(&(*src));
				src--;
				dest--;
			}
			src++;
			for (size_t i = 0; i < n; i++)
			{
				_alloc.construct(&(*src), val);
				src++;
			}
			_size += n;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
		{
			iterator tmp;
			iterator src;
			iterator dest;
			InputIterator tmp_input;
			size_type index;
			size_type nb;

			tmp_input = first;
			nb = 0;
			while (tmp_input != last)
			{
				tmp_input++;
				nb++;
			}
			tmp = iterator(&(*first));
			index = &(*position) - _start;
			if (_size + nb > _capacity)
				this->reserve(_size + nb);
			src = this->end() - 1;
			dest = src + nb;
			while (src >= iterator(_start + index))
			{
				_alloc.construct(&(*dest), *src);
				_alloc.destroy(&(*src));
				src--;
				dest--;
			}
			src++;
			while (first != last)
			{
				_alloc.construct(&(*src), *first);
				src++;
				first++;
			}
			_size += nb;
		}

		iterator erase(iterator position)
		{
			return (this->erase(position, position + 1));
		}

		iterator erase(iterator first, iterator last)
		{
			iterator tmp;
			size_type i;

			if (first == last)
				return (first);
			tmp = first;
			while (tmp != last)
			{
				_alloc.destroy(&(*tmp));
				tmp++;
				_size--;
			}
			tmp = first;
			i = 0;
			while (tmp != this->end())
			{
				_alloc.construct(&(*tmp), *(last + i));
				_alloc.destroy(&(*(last + i)));
				tmp++;
				i++;
			}
			return (first);
		}

		void swap(vector &x)
		{
			value_type *tmp_start = this->_start;
			size_type tmp_size = this->_size;
			size_type tmp_capacity = this->_capacity;
			allocator_type tmp_alloc = this->_alloc;

			this->_start = x._start;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;

			x._start = tmp_start;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
			x._alloc = tmp_alloc;
		}

		void clear()
		{
			while (_size > 0)
				this->pop_back();
		}

		/*		Allocator		*/
		allocator_type get_allocator() const
		{
			return (_alloc);
		}
	};
	/*		Operateur		*/
	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		typename ft::vector<T>::const_iterator lit;
		typename ft::vector<T>::const_iterator rit;

		lit = lhs.begin();
		rit = rhs.begin();
		if (lhs.size() != rhs.size())
			return (false);
		while (lit != lhs.end())
		{
			if (*lit != *rit)
				return (false);
			lit++;
			rit++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		typename ft::vector<T>::const_iterator lit;
		typename ft::vector<T>::const_iterator rit;

		lit = lhs.begin();
		rit = rhs.begin();
		while (lit != lhs.end())
		{
			if (rit == rhs.end() || (*lit) > (*rit))
				return (false);
			else if ((*lit) < (*rit))
				return (true);
			lit++;
			rit++;
		}
		return (rit != rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y)
	{
		return (x.swap(y));
	}
}

#endif