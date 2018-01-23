#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H
#include <math.h>

/*****************************************
 * UW User ID:  uesenthi
 * Submitted for ECE 250
 * Semester of Submission:  (Fall) 20518647
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "Exception.h"
#include "ece250.h"
#include <iostream>

using namespace std;

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
	private:
		int count;
		int power;
		int array_size;
		T *array;
		state *array_state;

		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function

	public:
		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;		
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;

		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ),
array( new T [array_size] ),
array_state( new state[array_size] ) {

	for ( int i = 0; i < array_size; ++i ) {
	array_state[i] = EMPTY;				//Make every slot in the array empty
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
	delete[] array;						//Delete the hashtable;
	delete[] array_state; 
}

template<typename T >
int DoubleHashTable<T >::size() const {
    return count;						//Returns the current number of filled slots of the array
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    return pow(2, power);				//Returns the total size of the array
}



template<typename T >
bool DoubleHashTable<T >::empty() const {
    if (count == 0)
	{
		return true;
	}
	else 
	{ 
		return false;
	}
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
	int i = static_cast<int>(obj);
	if(i<0)
	{
		while(i<0)
		{
			i = i+array_size;						//If the object is negative, make it the closest positive value
		}
	}
	
	int key = i%array_size;							//Performs the operation key = obj mod(size of array)
	return key;	
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const { 
	double i = static_cast<double>(obj);
	double j = 0;
	if (i<0)
	{
		j = ceil(i/array_size);						//If the value is negative, use the ceiling function of obj/array size
	}
	else
	{
		j = floor(i/array_size);					//If the value is positive, use the floor function of obj/array size
	}
	int key2 = static_cast<int>(j);
	key2 = key2%array_size;
	
	if(key2%2 == 0)
	{
		key2 = key2+1;								//If the key is a multiple of 2, add 1 to make it an odd number.
	}
	
	
	while(key2<0)
	{
		key2 = key2+array_size;						//If the key is a negative number, continuously add the array size until it is positive
	}
	return key2;	
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	int search = static_cast<int>(obj);
	int probe = h1(obj);
	int offset = h2(obj);
	int i = 1;
	int temp = probe;
	
	while(array_state[temp] == OCCUPIED || array_state[temp] == DELETED)			
	{
		if(array[temp] == obj && array_state[temp] == OCCUPIED)
		{
			return true;
		}
		temp = probe + i*offset;												//find the new key by adding the offset
		temp = temp%array_size;
		if(i > array_size)														//If the number of offsets on the original key is greater than the array size, the obect can't be in the hash table
		{
			return false;
		}
		++i;
	}
	
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {	      
    if(array_state[n]!= EMPTY && array_state[n]!= DELETED)    					            
	return array[n];
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) { 
	 if (count == array_size)
	{
		throw overflow();										//If hashtable is full, throw overflor exception
	}
	else
	{
		int probe = h1(obj);
		int offset = h2(obj);
		int k = 1;
		int temp = probe;
		
		while(array_state[temp] == OCCUPIED)
		{
			temp = probe + abs(k*offset);						//find the new key by adding the offset
			temp = temp%array_size;
			k = k+1;
		}
		
		array[temp] = obj;
		array_state[temp] = OCCUPIED;							//Set position of object as now occupied
		++count;												//Increase the total number of elements in the hash table
	
	}
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	int probe = h1(obj);
	int offset = h2(obj);
	int i = 1;
	int temp = probe;
	
	while(array_state[temp] == OCCUPIED || array_state[temp] == DELETED)
	{
		if(array[temp] == obj && array_state[temp] == OCCUPIED)
		{
			array_state[temp]=DELETED;							//Set the array state to DELETED
			count = count - 1;									//Decrement the count
			return true;
		}
		temp = probe + i*offset;
		temp = temp%array_size;
		if(i > array_size)
		{
			return false;										//The entire array does not contain the element, therefore return false
		}
		++i;
	}
	return false;
}

template<typename T >
void DoubleHashTable<T >::clear() { 
	 for (int i = 0; i<array_size; ++i)
	 {
	 	array[i] = 0;											//Set every value in the array to 0, empty and make the number of elements in the array equal zero
	 	array_state[i] = EMPTY;
	 	count = 0;
	 }	
}

template<typename T >
void DoubleHashTable<T >::print() const { 	
    for (int i = 0; i<array_size; ++i)
    {
    	cout<<array[i]<<endl;									//Displays every value in the array
    }

}

#endif
