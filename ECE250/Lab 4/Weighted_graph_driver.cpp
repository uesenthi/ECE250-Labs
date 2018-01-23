/****************************************************
 * Executable:   Weighted_graph_driver
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2006-9 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *
 * and call the member functiSon run()
 *
 * The member function run() will interpret the
 * input appropriately and exit when the interpreter
 * receives either the command 'exit' or and
 * end-of-file.
 ****************************************************/

#include <iostream>
#include "Weighted_graph_tester.h"

int main() {
//	Weighted_graph h = Weighted_graph (4);
//	h.insert(0, 1, 3.5);
//	h.insert(0, 2, 4.5);
//	h.minimum_spanning_tree(0);
//	h.insert(2, 3, 5.5);
//	h.minimum_spanning_tree(0);
//	h.insert(1, 3, 2.5);
//	h.insert(2, 3, 1.5);
//	h.minimum_spanning_tree(0);
//	h.insert(2, 3, 0);
//	h.minimum_spanning_tree(0);
//	
//	
	Weighted_graph_tester tester;

	std::cout << "Starting Test Run" << std::endl;
	tester.run();

	std::cout << "Finishing Test Run" << std::endl;

	return 0;
}
