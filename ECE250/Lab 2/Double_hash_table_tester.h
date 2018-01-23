/*************************************************
 * Double_hash_table_tester
 * A class for testing double hash tables.
 *
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2007 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *************************************************/

#ifndef DOUBLE_HASH_TABLE_TESTER_H
#define DOUBLE_HASH_TABLE_TESTER_H
#define PARAMETERIZED

#include "Exception.h"
#include "Tester.h"
#include "DoubleHashTable.h"

#include <iostream>


template <typename Type>
class Double_hash_table_tester:public Tester< DoubleHashTable<Type> > {
	using Tester< DoubleHashTable<Type> >::object;
	using Tester< DoubleHashTable<Type> >::command;

	public:
		Double_hash_table_tester( DoubleHashTable<Type> *obj = 0 ):Tester< DoubleHashTable<Type> >( obj ) {
			// empty
		}

		void process();
};


/****************************************************
 * void process()
 *
 * Process the current command.  For singly-linked lists, these include:
 *
 *           Member 
 *   Flag   Function         Tests if ...
 *
 *  Accessors
 *
 *   size n          size            the size equals n
 *   capacity n      capacity        the capacity equals n *  
 *   empty b         empty           the result is the boolean value b (0/1)
 *   member n b      member          checks if n is in the hash table (return value b)
 *   bin n m         bin             checks if m is in bin n
 *
 *  Mutators
 *
 *   insert n        insert          the element can be inserted into the hash table (always succeeds)
 *   remove n b      remove          the element can be inserted into the hash table
 *   clear           clear           empties the hash table
 ****************************************************/

template <typename Type>
void Double_hash_table_tester<Type>::process() {
	if ( command == "size" ) {
		// check if the size equals the next integer read

		int expected_size;

		std::cin >> expected_size;

		int actual_size = object->size();

		if ( actual_size == expected_size ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in size(): expecting the value '" << expected_size << "' but got '" << actual_size << "'" << std::endl;
		}
	} else if ( command == "capacity" ) {
		// check if the capacity equals the next integer read

		int expected_capacity;

		std::cin >> expected_capacity;

		int actual_capacity = object->capacity();

		if ( actual_capacity == expected_capacity ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in capacity(): expecting the value '" << expected_capacity << "' but got '" << actual_capacity << "'" << std::endl;
		}
	
	} else if ( command == "empty" ) {
		// check if the empty status equals the next boolean read

		bool expected_empty;

		std::cin >> expected_empty;

		bool actual_empty = object->empty();

		if ( actual_empty == expected_empty ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in empty(): expecting the value '" << expected_empty << "' but got '" << actual_empty << "'" << std::endl;
		}
	} else if ( command == "member" ) {
		// check if the element is in the object

		Type n;
		bool expected_member;

		std::cin >> n;
		std::cin >> expected_member;

		bool actual_member = object->member( n );

		if ( actual_member == expected_member ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in member(" << n << "): expecting the value '" << expected_member << "' but got '" << actual_member << "'" << std::endl;
		}
	} else if ( command == "bin" ) {
		// check the element in the specified bin

		int n;
		Type expected_value;

		std::cin >> n;
		std::cin >> expected_value;

		Type actual_value = object->bin( n );

		if ( actual_value == expected_value ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in bin(" << n << "): expecting the value '" << expected_value << "' but got '" << actual_value << "'" << std::endl;
		}
	} else if ( command == "insert" ) {
		// insert the next integer read onto the hash table

		Type n;

		std::cin >> n;

		object->insert( n );
		std::cout << "Okay" << std::endl;
		
			
    } else if ( command == "insert!" ) {
		

	    Type n;

		

		try {
			object->insert( n  );
			std::cout << "Failure in insert(): expecting to catch an exception but got " << n << "'" << std::endl;
		} catch( overflow ) {
			std::cout << "Okay" << std::endl;
		} catch (...) {
			std::cout << "Failure in insert(): expecting an overflow exception but caught a different exception" << std::endl;
		}
		
	} else if ( command == "remove" ) {
		// check the element in the specified bin

		Type n;
		bool expected_value;

		std::cin >> n;
		std::cin >> expected_value;

		bool actual_value = object->remove( n );

		if ( actual_value == expected_value ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in remove(" << n << "): expecting the value '" << expected_value << "' but got '" << actual_value << "'" << std::endl;
		}
	} else if ( command == "clear" ) {
		object->clear();

		std::cout << "Okay" << std::endl;
	} else if ( command == "print" ) {
		object->print();

		std::cout << std::endl << "Okay" << std::endl;
	//} else if ( command == "cout" ) {
	//	std::cout << *object << std::endl;
	} else {
		std::cout << command << ": Command not found." << std::endl;
	}
}
#endif