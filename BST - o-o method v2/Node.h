#pragma once

//Template declaration

template <typename E, typename T>
class Node
{

public:

	Node(E key, T value);

	~Node();

	Node<E, T>& operator=(const Node<E, T>& rhs);	//assignment
	//Node<E, T>(const Node<E, T>& src) {}	//copy

public:

	E key;
	T value;
	Node<E, T>* left;
	Node<E, T>* right;


};

//Template implementation

template <typename E, typename T>
Node<E, T>::Node(E key, T value)
{
	this->key = key;
	this->value = value;
	left = nullptr;
	right = nullptr;
}

template <typename E, typename T>
Node<E, T>::~Node()
{

}

template <typename E, typename T>
Node<E, T>& Node<E, T>::operator=(const Node<E, T>& rhs)
{
	//Check self-assignment
	//"this" is a pointer to the object the function is being called on. The pointer holds the 
	//memory location of the object in question. We compare this memory location with the memory location of
	//rhs. This is why we say &rhs even though we pass in the object by reference anyway.
	//If the two mem locations are the same, then the data MUST be the same therefore self-assignment.
	if (this == &rhs)
	{
		return (*this);
	}

	//delete old memory is allocated
	if (right)
	{
		delete right;
	}
	if (left)
	{
		delete left;
	}

	//copy data
	key = rhs.key;
	value = rhs.value;
	left = rhs.left;
	right = rhs.right;

	//return the existing object so we can chain operation
	return *this;
}