/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:24:30 by thamon            #+#    #+#             */
/*   Updated: 2022/11/21 23:34:54 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <stdexcept>
#include "pair.hpp"
#include "BSTnode.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef BSTnode<value_type>	map_node;
		typedef ft::map_iterator<map_node, value_type> iterator;
		typedef ft::constMap_iterator<map_node, const value_type, iterator> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;
		typedef typename Alloc::template rebind<map_node>::other node_alloc_type;

	private:
		key_compare		_compare;
		allocator_type	_alloc;
		node_alloc_type		_node_alloc;
		map_node		*_root;
		map_node		*_end;
		map_node		*_rend;
		size_type		_size;

	public:
		class value_compare
		{
			friend class map;

		protected:
			Compare _comp;
			
			value_compare(Compare c) : _comp(c)
			{

			}

		public:
			typedef bool restult_type;
			typedef value_type first_arg_type;
			typedef value_type second_arg_type;

			bool operator() (const value_type &x, const value_type &y) const
			{
				return (_comp(x.first, y.first));
			}
		};
		
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
				_compare(comp),
				_alloc(alloc),
				_node_alloc(std::allocator<map_node>()),
				_root(NULL),
				_end(NULL),
				_rend(NULL),
				_size(0)
		{
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, map_node());
			
			_rend = _node_alloc.allocate(1);
			_node_alloc.construct(_rend, map_node());
			_rend->parent = _end;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			_compare = comp;
			_size = 0;
			_alloc = alloc;
			_node_alloc = std::allocator<map_node>();
			_root = NULL;
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, map_node());
			
			_rend = _node_alloc.allocate(1);
			_node_alloc.construct(_rend, map_node());
			_rend->parent = _end;
			this->insert(first, last);
		}

		map(const map &x)
		{
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, map_node());
			
			_rend = _node_alloc.allocate(1);
			_node_alloc.construct(_rend, map_node());
			_rend->parent = _end;
			_root = NULL;
			*this = x;
		}

		~map()
		{
			this->clear();
			_node_alloc.destroy(_end);
			_node_alloc.dealocate(_end, 1);
			_node_alloc.destroy(_rend);
			_node_alloc.dealocate(_rend, 1);
		}

		map& operator= (const map& x)
		{
			this->clear();
			_compare = x._compare;
			_size = 0;
			_alloc = x.alloc;
			_node_alloc = x.node_alloc;
			this->insert(x.begin(), x.end());
			return (*this);
		}

		/*		Iterators		*/
		iterator begin()
		{
			return (iterator(_rend->parent));
		}

		const_iterator begin() const
		{
			return (const_iterator(_rend->parent));
		}

		iterator end()
		{
			return (iterator(_end));
		}

		const_iterator end() const
		{
			return (const_iterator(_end));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_end));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_rend->parent));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_rend->parent));
		}

		/*		Capacity		*/
		bool empty() const
		{
			if (_size)
				return (false);
			return (true);
		}
		
		size_type size() const
		{
			return (_size);
		}
		
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		
		/*		Element access		*/
		mapped_type& operator[] (const key_type& k)
		{
			return ((*(this->insert(value_type(k,mapped_type())).first)).second);
		}
		
		mapped_type& at (const key_type& k)
		{
			iterator it = this->find(k);
			if (it  == this->end())
				throw std::out_of_range("out_of_range");
			return ((*it).second);
		}
		
		const mapped_type& at (const key_type& k) const
		{
			const_iterator it = this->find(k);
			if (it  == this->end())
				throw std::out_of_range("out_of_range");
			return ((*it).second);
		}

		/*		Modifiers		*/
		pair<iterator,bool> insert (const value_type& val)
		{
			iterator it;
			map_node	*node;
			map_node	*new_node;

			if (!_root)
			{
				_root = _node_alloc.allocate(1);
				_node_alloc.construct(_root, map_node(val));

				_root->left = _rend;
				_root->right = _end;
				_end->parent = _root;
				_rend->left = _root;
				_size = 0;
			}
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return ((this->insert(val)).first);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->insert(*first);
				first++;
			}
		}
	};
}

#endif