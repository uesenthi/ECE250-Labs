#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

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

using namespace std;

template <typename T>
class Quadtree;

template <typename T>
class Quadtree_node {
	private:
		T       x_value;
		T       y_value;

		Quadtree_node *north_west;
		Quadtree_node *north_east;
		Quadtree_node *south_west;
		Quadtree_node *south_east;

	public:
		Quadtree_node( T const & = T(), T const & = T() );

		T retrieve_x() const;
		T retrieve_y() const;

		Quadtree_node *nw() const;
		Quadtree_node *ne() const;
		Quadtree_node *sw() const;
		Quadtree_node *se() const;

		T min_x() const;
		T min_y() const;

		T max_x() const;
		T max_y() const;

		T sum_x() const;
		T sum_y() const;

		bool member( T const &, T const & ) const;

		bool insert( T const &, T const & );
		void clear();

	friend class Quadtree<T>;
};

template <typename T>
Quadtree_node<T>::Quadtree_node( T const &x, T const &y ):
x_value( x ), 
y_value( y ), 
north_west( 0 ),
north_east( 0 ),
south_west( 0 ),
south_east( 0 ) {
	// empty constructor
}

template <typename T>
T Quadtree_node<T>::retrieve_x() const {
	return x_value;
}

template <typename T>
T Quadtree_node<T>::retrieve_y() const {
	return y_value;
}

template <typename T>
Quadtree_node<T> *Quadtree_node<T>::nw() const {
	return north_west;
}

template <typename T>
Quadtree_node<T> *Quadtree_node<T>::ne() const {
	return north_east;
}

template <typename T>
Quadtree_node<T> *Quadtree_node<T>::sw() const {
	return south_west;
}

template <typename T>
Quadtree_node<T> *Quadtree_node<T>::se() const {
	return south_east;
}

template <typename T>
T Quadtree_node<T>::min_x() const {
	
	if (north_west == 0 && south_west == 0)
	{
		return this->retrieve_x();											//if north_west and south_west isn't defined for the current node, return the current y value
	}
	
	if (south_west && north_west != 0)
	{	
		return min(south_west->min_x(), north_west->min_x());				//return the lower value from calling the function recursively on both the north_west and south_west
	}
	
	if (south_west != 0 && north_west == 0)
	{
		return south_west->min_x();											//Call recursively on south_west while it exists and north_west doesn't exist for the current node
	}
	
	if (north_west != 0 && south_west == 0)
	{
		return north_west->min_x();											//Call recursively on north_west while it exists and south_west doesn't exist for the current node
	}
}

template <typename T>
T Quadtree_node<T>::min_y() const {

	if (south_east == 0 && south_west == 0)
	{
		return this->retrieve_y();											//if south_east and south_west isn't defined for the current node, return the current y value
	}
	
	if (south_west && south_east != 0)
	{	
		return min(south_west->min_y(), south_east->min_y());				//return the lower value from calling the function recursively on both the south_east and south_west
	}
	
	if (south_west != 0 && south_east == 0)
	{
		return south_west->min_y();											//Call recursively on south_west while it exists and south_east doesn't exist for the current node
	}
	
	if (south_east != 0 && south_west == 0)
	{
		return south_east->min_y();											//Call recursively on south_east while it exists and south_west doesn't exist for the current node
	}
}

template <typename T>
T Quadtree_node<T>::max_x() const {
	
	if (north_east == 0 && south_east == 0)
	{
		return this->retrieve_x();											//if south_east and north_east isn't defined for the current node, return the current x value
	}
	
	if (south_east && north_east != 0)
	{	
		return max(north_east->max_x(), south_east->max_x());				//return the higher value from calling the function recursively on both the south_east and north_east
	}
	
	if (south_east != 0 && north_east == 0)
	{
		return south_east->max_x();											//Call recursively on south_east while it exists and north_east doesn't exist for the current node
	}
	
	if (north_east != 0 && south_east == 0)
	{
		return north_east->max_x();											//Call recursively on north_east while it exists and south_east doesn't exist for the current node
	}
	
}

template <typename T>
T Quadtree_node<T>::max_y() const {

	if (north_east == 0 && north_west == 0)
	{
		return this->retrieve_y();											//if north_west and north_east isn't defined for the current node, return the current y value
	}
	
	if (north_west && north_east != 0)
	{	
		return max(north_west->max_y(), north_east->max_y());				//return the higher value from calling the function recursively on both the north_west and north_east
	}
	
	if (north_west != 0 && north_east == 0)
	{
		return north_west->max_y();											//Call recursively on north_west while it exists and north_east doesn't exist for the current node
	}
	
	if (north_east != 0 && north_west == 0)
	{
		return north_east->max_y();											//Call recursively on north_east while it exists and north_west doesn't exist for the current node
	}
}

template <typename T>
T Quadtree_node<T>::sum_x() const {
	
	if (this == 0)																										//If current node is not defined, return nothing
	{
		return 0;
	}
	
	else if (north_east && north_west && south_west && south_east == 0)													//If every direction does not exist, just return node x_value
	{
		return x_value;
	}

	else
	{
		return x_value + north_east->sum_x() + north_west->sum_x()+ south_east->sum_x()+ south_west->sum_x();			//call sum on every region and add them all together with current node x_value
	}
}

template <typename T>
T Quadtree_node<T>::sum_y() const {
	
	if (this == 0)
	{
		return 0;																										//If current node is not defined, return nothing
	}
	
	else if (north_east && north_west && south_west && south_east == 0)
	{
		return y_value;																									//If every direction does not exist, just return node x_value
	}

	else
	{
		return y_value + north_east->sum_y() + north_west->sum_y()+ south_east->sum_y()+ south_west->sum_y();			//call sum on every region and add them all together with current node x_value
	}
}

template <typename T>
bool Quadtree_node<T>::member( T const &x, T const &y ) const {
	
	if (this->x_value == x && this->y_value== y)										//If the current node matches the member node, return true
	{
		return true;
	}
	else
	{
			if (x >= this->x_value && y >= this->y_value)								//Check if member node applies to the north_east position
			{
				if (north_east ==0) 													//If it is required to look at the north_east position but it is not defined, return false
				{
					return false;
				}
				else
				{
					return north_east->member(x,y);										//Call recursively on north_east if it exists
				}
			}
		
			if (x >= this->x_value && y < this->y_value)								//Check if member node applies to the south_east position
			{
				if (south_east ==0) 													//If it is required to look at the south_east position but it is not defined, return false
				{
					return false;
				}
				else
				{
					return south_east->member(x,y);										//Call recursively on south_east if it exists
				}
			}
			if (x < this->x_value && y >= this->y_value)								//Check if member node applies to the north_west position
			{
				if (north_west ==0) 													//If it is required to look at the north_west position but it is not defined, return false
				{
					return false;
				}
				else
				{
					return north_west->member(x,y);										//Call recursively on north_west if it exists
				}
			}
			if (x < this->x_value && y < this->y_value)									//Check if member node applies to the south_west position
			{
				if (south_west ==0) 													//If it is required to look at the south_west position but it is not defined, return false
				{
					return false;
				}
				else
				{
					return south_west->member(x,y);										//Call recursively on south_west if it exists
				}		
			}		
	}
}

template <typename T>
bool Quadtree_node<T>::insert( T const &x, T const &y ) {
	
		
	if (this->x_value == x && this->y_value== y)										//If node to be insserted is already there, return false
	{
		return false;
	}
	else
	{
			if (x >= this->x_value && y >= this->y_value)								//Check if new node applies to the north_east position
			{
				if (north_east ==0) 
				{
					Quadtree_node <T> *northeast = new Quadtree_node <T> (x, y);		//Create a new node and set north_east pointer to this node
					this->north_east = northeast;
					return true;
				}
				else
				{
					return north_east->insert(x,y);										//Call recursively on north_east if it exists
				}
			}
		
			if (x >= this->x_value && y < this->y_value)								//Check if new node applies to the south_east position
			{
				if (south_east ==0) 
				{
					Quadtree_node <T> *southeast = new Quadtree_node <T> (x, y);		//Create a new node and set south_east pointer to this node
					this->south_east = southeast;
					return true;
				}
				else
				{
					return south_east->insert(x,y);										//Call recursively on south_east if it exists
				}
			}
			if (x < this->x_value && y >= this->y_value)								//Check if new node applies to the north_west position
			{
				if (north_west ==0) 
				{
					Quadtree_node <T> *northwest = new Quadtree_node <T> (x, y);		//Create a new node and set north_west pointer to this node
					this->north_west = northwest;
					return true;
				}
				else
				{
					return north_west->insert(x,y);										//Call recursively on north_west if it exists
				}
			}
			if (x < this->x_value && y < this->y_value)									//Check if new node applies to the south_west position
			{
				if (south_west ==0) 
				{
					Quadtree_node <T> *southwest = new Quadtree_node <T> (x, y);		//Create a new node and set south_west pointer to this node
					this->south_west = southwest;
					return true;
				}
				else
				{
					return south_west->insert(x,y);										//Call recursively on south_west if it exists
				}		
			}		
	}
}

template <typename T>
void Quadtree_node<T>::clear() {
	if (north_east != 0)
	{
		north_east->clear();				//Call recursively the clear() on north_east if it exists
	}
	
	if (south_east != 0)
	{
		south_east->clear();				//Call recursively the clear() on south_east if it exists
	}
	
	if (north_west != 0)
	{
		north_west->clear();				//Call recursively the clear() on north_west if it exists
	}
	
	if (south_west != 0)
	{
		south_west->clear();				//Call recursively the clear() on north_west if it exists
	}
	delete this;							//Delete the current node
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
