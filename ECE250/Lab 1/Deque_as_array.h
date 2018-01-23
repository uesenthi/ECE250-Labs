#ifndef DEQUE_AS_ARRAY_H
#define DEQUE_AS_ARRAY_H

/*****************************************
 * UW User ID:  uesenthi
 * Submitted for ECE 250
 * Semester of Submission:  (Fall) 2014
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided  code.
 *****************************************/

#include "Exception.h"
#include <iostream>
using namespace std;


class Deque_as_array {
	private:
		int array_size;
		int*array;
		int ihead;
		int itail;
		int count;

	public:
		Deque_as_array( int = 10 );
		~Deque_as_array();

		int head() const;
		int tail() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void enqueue_head( int const & );
		void enqueue_tail( int const & );
		int dequeue_head();
		int dequeue_tail();
		void clear();
		void printe();

	
};

 
Deque_as_array::Deque_as_array( int n ):
array_size( std::max( 1, n ) ), 
array( new int[array_size] ), 
count( 0 ), ihead(0), itail(0) {
	// empty
}

 
Deque_as_array::~Deque_as_array() {
	delete[] array;						
}


int Deque_as_array::size() const {
	return count;					//Returns the number of elements in the list
}

 
int Deque_as_array::capacity() const {
	return array_size;				//Returns total list size
}

 
bool Deque_as_array::empty() const {
	
	if (count > 0)					
	{
		return false;				//Returns false if there is more than one element in the list
	}
	
	else 
	
	{
		return true;				//Returns true if there isn't any element in the array
	}
}

 
int Deque_as_array::head() const {
	
	
	if(count ==0)
	{
		throw underflow();			//Tail is not assigned
	}
	else
	{
		return array[ihead];    	//Returns the head element
	}
}

 
int Deque_as_array::tail() const {
	
	if(count==0)
	{
		throw underflow(); 			//Tail not assigned
	}
	
	else
	{
		return array[itail];		//Returns the tail element
	}
}


void Deque_as_array::enqueue_head( int const &obj ) {
	if(count >= array_size)
	{
		throw overflow();			//List is full
	}
	
	if(count == 0)
	{
		array[ihead] = obj;			//List is empty
	}
	
	if(count > 0)
	{
	
		if(ihead == 0)
		{
			ihead = array_size-1;	//Move to the back of list
		
		}
	
		else 
		{
			--ihead;
		}
	
		array[ihead] = obj;			//set the element as obj
	}
	++count;

}


void Deque_as_array::enqueue_tail( int const &obj ) {
	if(count >= array_size)
	{
		throw overflow();			//list is full
	}
	
	if(count == 0)
	{
		array[itail] = obj;			//list is empty
	}
	
	if(count > 0)					
	{

		if(itail ==array_size-1)
		{
			itail = 0;				//Move to the front of the list
		
		}
	
		else 
		{
			++itail;
		}
	
		array[itail] = obj;			//Initiate the element as obj
	}
	
	++count;

}

 
int Deque_as_array::dequeue_head() {
	if(count > 0)
	{		
		int temp = array[ihead];
	
		if(ihead == array_size-1)
		{
			ihead = 0;				//Move to the front of the list
		}
	
		else
		{
			++ihead;
		}
		--count;
		
	return temp;					//Return element that used to be head
	}
	
	else
	{
		throw underflow();			//List is already empty
	}

}

 
int Deque_as_array::dequeue_tail() {	
	
	if (count > 0)
	{
		int temp = array[itail];
	
		if(itail == 0)
		{
			itail = array_size-1;	//Move to the back of list
		}	
		else
		{
			--itail;
		}
		--count;
	
		return temp;				//Return element that used to be tail
	}
	
	else
	{
		throw underflow();			//List is already empty
	}
	
}

 
void Deque_as_array::clear() {
	
	ihead = 0;					//Reset head to 0
	itail = 0;					//Reset tail to 0
	count = 0;					//Remove every element in the list

}
void Deque_as_array::printe(){
	for (int i=0;i<array_size;i++)
		cout <<array[i]  <<endl;
}



// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
