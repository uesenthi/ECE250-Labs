#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"
#include <list>

/*****************************************
 * UW User ID:  uesenthi
 * Submitted for ECE 250
 * Semester of Submission:  (Fall) 2014
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

using namespace std;

class Weighted_graph {
	private:
		static const double INF;
		double **graph_matrix;
		int graph_size;
		int edge_sum;
		int *degree_sum;

	public:
		Weighted_graph( int = 50 );
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double minimum_spanning_tree( int ) const;
		bool is_connected() const;

		void insert( int, int, double );

	// Friends

	friend std::ostream &operator << ( std::ostream &, Weighted_graph const & );
};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

Weighted_graph::Weighted_graph( int n ){

	graph_size = n;																//Reference to total size of the graph
	edge_sum = 0;
	degree_sum = new int[n];													//Create an array to hold the degrees of each vertex
	graph_matrix = new double*[n];												//Create an n by n array
	for (int i = 0; i < n; i++){
		graph_matrix[i] = new double[n];
	}
	for (int a = 0; a < n; a++){
		for (int b = 0; b < n; b++){
			graph_matrix[a][b] = INF;											//Set every edge to INF, nothing is connected
		}
		graph_matrix[a][a] = 0;													//Edge to itself is 0
		degree_sum[a] = 0;														
	}
}

Weighted_graph::~Weighted_graph(){
	for (int i = 0; i <graph_size; i++)
	{
		delete[] graph_matrix[i];												//Delete every secondary array in the array
	}
	delete[] graph_matrix;														//Delete the primary array
	delete[] degree_sum;														//Delete the array holding the degree sum of all the nodes
}

int Weighted_graph::degree( int obj ) const{
	if(obj >= graph_size || obj < 0){
		throw illegal_argument();
	}
	
	return degree_sum[obj];														//Return the degree sum of the node being passed
}

int Weighted_graph::edge_count() const{
	return edge_sum;															//Return the total number of edges
}

double Weighted_graph::adjacent(int m, int n) const{
	if(m < 0 || n < 0 || m >= graph_size || n>= graph_size)
	{
		throw illegal_argument();
	}
	return graph_matrix[m][n];													//Return the edge between the two nodes
					
}

double Weighted_graph::minimum_spanning_tree( int m ) const{
if(m < 0 || m >= graph_size){
	throw illegal_argument();
}
else{
	
	bool *visited = new bool [graph_size];										//Create an array to keep track of the nodes visited
	double *distance = new double [graph_size];									//Create an array to keep track of shorted edge to a node
	double path;
	double sum = 0;
	
	for (int i = 0; i < graph_size; i++){
		visited[i] = false;
		distance[i] = INF;
	}
	
	distance[m] = 0;
	
	int currentnode = m;
	int nextnode = 0;
	
	while (true){
		path = INF;
		visited[currentnode]= true;															//Define the current node as visited
		distance[currentnode] = 0;															//Set the current node as the starting node
		
		for (int j = 0; j < graph_size; j++){
			if (visited[j] == false)														
			{
				if(graph_matrix [currentnode][j] != 0 && graph_matrix[currentnode][j] < distance[j]){		//If the edge to the node is smaller than what is registered in the distance
					distance[j] = graph_matrix[currentnode][j];												//change the edge in the distance array to this smaller edge
					
				}
				
				if (distance[j]< path)
				{
					path = distance[j];																		//Finds the smallest edge to travel from the current node
					nextnode = j;
				}
			}
		}
			
			if(path == INF){																				//If path doesn't change because every node connected is already visited
																											//delete the two arrays and return the sum value
				delete[] distance;
				delete[] visited;
				return sum;
			}
			
			else{
				sum = sum + path;																			//Add the path travelled to the sum
				currentnode = nextnode;																		
			}
			
		}
	}
}

bool Weighted_graph::is_connected() const{
	list <int> visited;
	bool *done = new bool [graph_size];																		//Keeps track of which nodes are visited. Initially set everything to false
	for (int i = 0; i < graph_size; i++){
		done[i]= false;
	}
	
	visited.push_back(0);																					//Add first node to the list
	while(visited.empty() == 0)																				//While the list is not empty
	{
		for (int i = 0; i< graph_size ; i++)
		{
			if (adjacent(visited.back(),i)!= INF && adjacent(visited.back(), i)!= 0 && done[i]== false)
			{
				visited.push_front(i);																		//Add all the unvisited nodes connected to the current node 
																											//to the list, to the front of the list
			}
		}
		done[visited.back()]= true;																			//Set the node observed to true and remove it from the list
		visited.pop_back();
	}
	
	for (int j = 0; j < graph_size; j++)
	{
		if (done[j] == false){
			delete[] done;																					//Delete the array and return false if every node isn't connected
			return false;
		}
	}
	delete[] done;																							//Delete the array and return true if every node is connected
	return true;
}

void Weighted_graph::insert(int m, int n, double w){
	if (w<0 || w == INF|| m == n|| m>= graph_size|| m< 0 || n>= graph_size || n<0)
	{
		throw illegal_argument();
	}
	else if (w == 0){
		if(graph_matrix [m][n] != INF){
		graph_matrix [m][n] = INF;																			//Set the edge between the two nodes to infinity, remove a degree to the two nodes and remove one from the total number of edges
		graph_matrix [n][m] = INF;
		edge_sum--;
		degree_sum[m] = degree_sum[m]-1;
		degree_sum[n] = degree_sum[n]-1;
	}
	}
	
	else{
		if (graph_matrix [m][n] == w){
			throw illegal_argument();
		}
		else{
			if(graph_matrix[m][n] != INF){
				graph_matrix [m][n] = w;																	//Change the edge to the value of w
				graph_matrix [n][m] = w;
			}
			else {
				graph_matrix [m][n] = w;																	//Change the value to w, increase the total amount of edges and add a new degree to the two nodes
				graph_matrix [n][m] = w;
				edge_sum = edge_sum + 1;
				degree_sum[m] = degree_sum[m]+1;
				degree_sum[n] = degree_sum[n]+1;
			}
		}
		
	}
}


std::ostream &operator << ( std::ostream &out, Weighted_graph const &graph ) {
	// Your implementation

	return out;
}
#endif
