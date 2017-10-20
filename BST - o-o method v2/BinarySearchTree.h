#pragma once

#include "Node.h"
#include <stack>

//Template declaration

template <typename E, typename T>
class BinarySearchTree
{

public:

	BinarySearchTree();

	~BinarySearchTree();

	
	void insert(E key, T value);
	void print_tree_inorder();
	void print_tree_breadth_first(); //breadth-first traversal
	void delete_tree();

	T get_value(E key);
	inline int get_number_of_nodes() { return _numberOfNodes; }


private:

	Node<E, T>** _tree;
	Node<E, T>* root;

	int _numberOfNodes;

	
};

//Template implementation

template <typename E, typename T>
BinarySearchTree<E, T>::BinarySearchTree()
{
	 root = nullptr;
	_tree = &root;
	_numberOfNodes = 0;
}

template <typename E, typename T>
BinarySearchTree<E, T>::~BinarySearchTree()
{

}

template <typename E, typename T>
void BinarySearchTree<E, T>::insert(E key, T value)
{
	if ((*_tree) == nullptr)
	{
		(*_tree) = new Node<E, T>(key, value);
		_numberOfNodes++;
		return;
	}

	Node<E, T>* node = (*_tree);

	while (node != nullptr)
	{
		if (key > node->key)
		{
			if (node->right == nullptr)
			{
				node->right = new Node<E, T>(key, value);
				_numberOfNodes++;
				return;
			}
			node = node->right;
		}
		else
		{
			if (node->left == nullptr)
			{
				node->left = new Node<E, T>(key, value);
				_numberOfNodes++;
				return;
			}
			node = node->left;
		}
	}
}

template <typename E, typename T>
void BinarySearchTree<E, T>::print_tree_inorder() 
{
	std::stack<Node<E, T>*> s;

	Node<E, T>* node = (*_tree);

	bool done = false;

	while (!done)
	{
		while (node != nullptr)
		{
			s.push(node);
			node = node->left;
		}

		if (node == nullptr && (!s.empty()))
		{
			node = s.top();
			s.pop();

			std::cout << node->value << " ";

			node = node->right;
		}

		if (node == nullptr && s.empty())
		{
			done = true;
		}
	}
	std::cout << std::endl;
}

template <typename E, typename T>
void BinarySearchTree<E, T>::print_tree_breadth_first()
{

}

template <typename E, typename T>
void BinarySearchTree<E, T>::delete_tree()
{
	std::stack<Node<E, T>*> s;

	Node<E, T>* node = (*_tree);

	bool done = false;

	while (!done)
	{
		while (node != nullptr)
		{
			if (node->right)
			{
				s.push(node->right);
			}
			s.push(node);
			node = node->left;
		}

		node = s.top();
		s.pop();

		if (node->right && !s.empty() && node->right == s.top())
		{
			s.pop();
			s.push(node);
			node = node->right;
		}
		else
		{
			delete node;
			node = nullptr;
		}

		if (s.empty())
		{
			done = true;
		}
	}
}

template <typename E, typename T>
T BinarySearchTree<E, T>::get_value(E key)
{
	//base case 
	//if the root is null return void or something?
	//or maybe dont have a base case, so the program crashes if you try to get an element from an empty tree?
	//see what other data structures do like maps etc
	if ((*_tree) == nullptr)
	{

	}
}
