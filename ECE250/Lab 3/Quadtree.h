#ifndef QUADTREE_H
#define QUADTREE_H

/*****************************************
 * UW User ID:  uesenthi
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Fall) 2014
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "ece250.h"
#include "Quadtree_node.h"
#include "Exception.h"
#include <iostream>

template <typename T>
class Quadtree {
	private:
		Quadtree_node<T> *tree_root;
		int count;

	public:
		Quadtree();
		~Quadtree();

		// Accessors

		int size() const;
		bool empty() const;

		T min_x() const;
		T min_y() const;

		T max_x() const;
		T max_y() const;

		T sum_x() const;
		T sum_y() const;

		Quadtree_node<T> *root() const;
		bool member( T const &, T const & ) const;

		// Mutators

		void insert( T const &, T const & );
		void clear();

	
};

template <typename T>
Quadtree<T>::Quadtree():
tree_root( 0 ), 
count( 0 ) {
	// empty constructor
}

template <typename T>
Quadtree<T>::~Quadtree() {
	tree_root->clear();																	//Call the quadtree_node clear() function on tree_root
}

template <typename T>
int Quadtree<T>::size() const {
	return count;
}

template <typename T>
bool Quadtree<T>::empty() const {
	if (count == 0)
	{
		return true;																	
	}
	else
	{
		return false;
	}
}

template <typename T>
T Quadtree<T>::min_x() const {
	if (count == 0)
	{
		throw underflow();																//If there isn't any node in the tree, throw underflow exception
	}
	
	else 
	{
		return tree_root->min_x();														//Call the min_x quadtree_node function on tree_root
	}
}

template <typename T>
T Quadtree<T>::min_y() const {
	if (count == 0)
	{
		throw underflow();																//If there isn't any node in the tree, throw underflow exception
	}
	
	else
	{
		return tree_root->min_y();														//Call the min_y quadtree_node function on tree_root
	}
}

template <typename T>
T Quadtree<T>::max_x() const {

	if (count == 0)
	{
		throw underflow();																//If there isn't any node in the tree, throw underflow exception
	}
	
	else
	{
		return tree_root->max_x();														//Call the max_x quadtree_node function on tree_root
	}
}

template <typename T>
T Quadtree<T>::max_y() const {
	
	if (count == 0)
	{
		throw underflow();																//If there isn't any node in the tree, throw underflow exception
	}
	
	else
	{
		return tree_root->max_y();														//Call the max_y quadtree_node function on tree_root
	}
}

template <typename T>
T Quadtree<T>::sum_x() const {
	return tree_root->sum_x();															//Call the sum_x function from the quadtree_node class starting at tree_root
}

template <typename T>
T Quadtree<T>::sum_y() const {
	return tree_root->sum_y();															//Call the sum_y function from the quadtree_node class starting at tree_root
}

template <typename T>
Quadtree_node<T> *Quadtree<T>::root() const {
	return tree_root;
}

template <typename T>
bool Quadtree<T>::member( T const &x, T const &y ) const {
	if (tree_root == 0)
	{
		return false;																	//If tree_root isn't set, there cannot be any other nodes in the tree, so return false
	}
	
	else
	{
		return tree_root->member(x,y);													//use the member function from the Quadtree_node class on tree_root
	}
}

template <typename T>
void Quadtree<T>::insert( T const &x, T const &y ) {
	if (tree_root == 0)
	{
		Quadtree_node <T> *root = new Quadtree_node <T> (x, y);							//If tree root doesn't exist yet, create a new node and set tree_root's pointer to that node
		tree_root = root;
		count=1;
	}
	else
	{
		if (tree_root->insert(x, y) == true)											//If you are able to successfully insert the node, increase the count by 1
		{
			count++;
		}
		
	}
}

template <typename T>
void Quadtree<T>::clear() {
	
	if (count != 0){
		tree_root->clear();																//Call the clear function from the Quadtree_node class
		count = 0;																		//Set count back to 0
		tree_root = 0;																	//Set the tree root to point to zero
	}
}



// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
