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

	
};

 
Deque_as_array::Deque_as_array( int n ):
array_size( std::max( 1, n ) ), 
array( new int[array_size] ), 
count( 0 ) {
	// empty
}

 
Deque_as_array::~Deque_as_array() {
	
}

 
int Deque_as_array::size() const {
	// enter your implementation here
	return array_size;
	return 0;
}

 
int Deque_as_array::capacity() const {
	int count = 0;
	for (int i = 0; i<= array_size-1; ++i)
	{
		if (array[i]!= 0)
		{
			++count;
		}
	}
	return count;
}

 
bool Deque_as_array::empty() const {
	int count = 0;
	for (int i = 0; i<=array_size-1; ++i)
	{
		if (array[i]!= 0)
		{
			++count;
		}
	}
	
	if (count > 0)
	{
		return false;
	}
	else 
	{
		return true;	
	}
}

 
int Deque_as_array::head() const {
	return array[ihead];
	return 0;     
}

 
int Deque_as_array::tail() const {
	return array[itail];
	return 0;     
}


void Deque_as_array::enqueue_head( int const &obj ) {
	
	int temp = itail;
	for(int i = 0; i <= array_size-1; ++i)
	{
		array[temp]=array[temp-1];
		--temp;
		
		if(temp == ihead)
		{
			array[temp] = &obj;
			break;
		}
	}
}


void Deque_as_array::enqueue_tail( int const &obj ) {
	
	int temp = ihead;
	for(int i = 0; i <= array_size-1; ++i)
	{
		array[temp]=array[temp+1];
		--temp;
		
		if(temp == itail)
		{
			array[temp] = &obj;
			break;
		}
	}
}

 
int Deque_as_array::dequeue_head() {
	// enter your implementation here
	return 0;     // This returns a default object
}

 
int Deque_as_array::dequeue_tail() {
	// enter your implementation here
	return 0;     // This returns a default object
}

 
void Deque_as_array::clear() {
	
	for (int i =0; i<= array_size-1; ++i)
	{
		array[i] = 0;
	}
}



// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
