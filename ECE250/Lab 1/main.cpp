#include <iostream>
#include "Deque_as_array.h"
#include "Exception.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void TestHead(Deque_as_array test)					//Tests the head functions (underflow and overflow exceptions)
{
	test.enqueue_head(20);							
	cout<<test.head()<<endl;						//should show 20
	try
	{
		test.dequeue_head();
	}
	catch (underflow e)
	{
		cout<< "An underflow was caught"<<endl;
	}
	test.enqueue_head(20);							
	cout<<test.head()<<endl;						//should show 20
	test.enqueue_head(30);							
	cout<<test.head()<<endl;						//should show 30
	test.enqueue_head(30);
	cout<<test.head()<<endl;						//should show 30
	test.enqueue_head(40);
	test.enqueue_head(50);
	cout<<test.head()<<endl;						//should show 50
	test.dequeue_head();
	cout<<test.head()<<endl;						//should show 40
	cout<<test.size()<<endl;						//should show 4
	cout<<test.capacity()<<endl;					//should show 10
	test.enqueue_head(50);
	test.enqueue_head(50);
	test.enqueue_head(50);
	test.enqueue_head(50);
	test.enqueue_head(50);
	cout<<test.size()<<endl;						//should show 9
	test.enqueue_head(50);
	cout<<test.size()<<endl;						//should show 10
	
	try
	{
		test.enqueue_head(50);							//throws overflow exception
	}
	
	catch (overflow e)
	{
		cout<<"An overflow was caught"<<endl;
	}
}





void TestTail(Deque_as_array test)	
{													//Tests the tail functions (underflow and overflow exceptions)
	test.enqueue_tail(47);
	cout<<test.tail()<<endl;						//should show 47
	test.enqueue_tail(13);	
	cout<<test.tail()<<endl;						//should show 13
	test.enqueue_tail(16);
	test.enqueue_tail(15);
	cout<<test.tail()<<endl;						//should show 15
	test.dequeue_tail();
	cout<<test.tail()<<endl;						//should show 16
	cout<<test.size()<<endl;						//should show 3
	test.dequeue_tail();
	test.dequeue_tail();
	test.dequeue_tail();
	cout<<test.size()<<endl;						//should show 0
	try
	{						
		test.dequeue_tail();							//throws underflow exception
	}

	catch(underflow e)
	{
		cout<<"There was an underflow catch"<<endl;
	}
}

int main(int argc, char** argv) {
	Deque_as_array test;
	cout<<test.empty()<<endl;						//should show 1(true)
	cout<<test.capacity()<<endl;					//should show 10

													//This will test the head functions and overflow exception
	
	return 0;
}


//#include "Deque_as_array_tester.h"
//#include <iostream>
//int main() {
//	Deque_as_array_tester<int> tester;
//    
//	std::cout << "Starting Test Run" << std::endl;
//
//	tester.run();
//
//	std::cout << "Finishing Test Run" << std::endl;
//
//	return 0;
//}

