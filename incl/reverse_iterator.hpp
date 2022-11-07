/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:42:28 by thamon            #+#    #+#             */
/*   Updated: 2022/11/08 00:04:22 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

	protected:
		iterator_type _current;

	public:
		reverse_iterator(void) : _current(NULL)
		{
		}

		explicit reverse_iterator(iterator_type it) : _current(it)
		{
		}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base())
		{
		}

		iterator_type base() const
		{
			return (iterator_type(_current));
		}

		reference operator*() const
		{
			iterator_type tmp = _current;
			return (*(--tmp));
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator<Iterator>(_current - n));
		}

		reverse_iterator &operator++()
		{
			_current--;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return (temp);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			_current -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator<Iterator>(_current + n));
		}

		reverse_iterator &operator--()
		{
			_current++;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			_current += n;
			return (*this);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n) const
		{
			return (_current[-n - 1]);
		}
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator==(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator!=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class IteratorR, class IteratorL>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

}

#endif