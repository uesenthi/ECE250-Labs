/****************************************************
 * Executable:  Quadtree_int_driver
 * Copyright (c) 2006-9 bdy Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *
 * Create an instance of the Quadtree_tester<int> class
 * and call the member function run().
 *
 * The member function run() will interpret the
 * input appropriately and exit when the interpreter
 * receives either the command 'exit' or and
 * end-of-file.
 ****************************************************/

#include <iostream>
#include "Quadtree_tester.h"
#include "ece250.h"
#include "Quadtree_node.h"
#include "Exception.h"
#include <iostream>
#include "Quadtree.h"

int main() {
	
	Quadtree_tester<int> tester;

	std::cout << "Starting Test Run" << std::endl;

	tester.run();

	std::cout << "Finishing Test Run" << std::endl;

	return 0;   
}
