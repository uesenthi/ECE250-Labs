#include <iostream>
#include <string>

using namespace std;

int array[];
int array_size;
int ihead = 0;
int itail = 0;
int count = 0;

void Deque_as_array(int n)
{
	if(n < 1)
	{
		array[1];
		array_size=1;
	}
	array_size = n; 
	array [array_size];
	itail = n-1;
}

int head() 
{
	return array[ihead];
}

int tail()
{
	return array[itail];
}

int size() {
	return array_size;
}

void enqueue_head(int j)
{
	int temp = itail;
	for(int i = 0; i <= array_size-1; ++i)
	{
		array[temp]=array[temp-1];
		--temp;
		
		if(temp == ihead)
		{
			array[temp] = j;
			break;
		}
	}
}

void enqueue_tail(int j)
{
	int temp = ihead;
	for(int i = 0; i <= array_size-1; ++i)
	{
		array[temp]=array[temp+1];
		--temp;
		
		if(temp == itail)
		{
			array[temp] = j;
			break;
		}
	}
}

void clear()
{
	for (int i =0; i<= array_size-1; ++i)
	{
		array[i] = 0;
	}
}
