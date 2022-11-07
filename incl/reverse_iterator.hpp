/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:42:28 by thamon            #+#    #+#             */
/*   Updated: 2022/11/07 21:45:23 by thamon           ###   ########.fr       */
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
		typename iterator_traits<_Iterator>::iterator_category
			typename iterator_traits<_Iterator>::value_type
			typename iterator_traits<_Iterator>::difference_type
			typename iterator_traits<_Iterator>::pointer
			typename iterator_traits<_Iterator>::reference
	};

}

#endif