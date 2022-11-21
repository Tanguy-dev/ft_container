/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:04:29 by thamon            #+#    #+#             */
/*   Updated: 2022/11/21 22:31:31 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

namespace ft
{
	template <class Pair>
	struct BSTnode
	{
		BSTnode *parent;
		BSTnode *left;
		BSTnode *right;
		BSTnode *value;

		explicit BSTnode() : parent(NULL), left(NULL), right(NULL), value()
		{
		}

		explicit BSTnode(const Pair &data) : parent(NULL), left(NULL), right(NULL), value(data)
		{
		}

		~BSTnode()
		{
		}

		BSTnode(const BSTnode &x) : parent(x.parent), left(x.left), right(x.right), value(x.value)
		{
		}

		BSTnode &operator=(const BSTnode &x)
		{
			if (this != &x)
			{
				parent = x.parent;
				left = x.left;
				right = x.right;
				value = x.value;
			}
			return (*this);
		}

		BSTnode *findMin(BSTnode *node)
		{
			if (!node)
				return (NULL);
			while (node->left)
				node = node->left;
			return (node);
		}

		BSTnode *findMax(BSTnode *node)
		{
			if (!node)
				return (NULL);
			while (node->right)
				node = node->right;
			return (node);
		}

		BSTnode *next(void)
		{
			BSTnode *tmp = this;

			if (tmp->right)
				return (findMin(tmp->right));

			BSTnode *tmpParent = tmp->parent;

			while (tmpParent && tmp == tmpParent->right)
			{
				tmp = tmpParent;
				tmpParent = tmpParent->parent;
			}
			return (tmpParent);
		}

		BSTnode *prev(void)
		{
			BSTnode *tmp = this;

			if (tmp->left)
				return (findMax(tmp->left));

			BSTnode *tmpParent = tmp->parent;

			while (tmpParent && tmp == tmpParent->left)
			{
				tmp = tmpParent;
				tmpParent = tmpParent->parent;
			}
			return (tmpParent);
		}
	};
}
#endif