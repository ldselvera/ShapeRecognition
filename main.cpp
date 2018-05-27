/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
*/

#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{	
	
	int size;

	cout<<"Input size of graph:"<<endl;
	cin>>size;

	Graph g(size);
	g.createGraph();
	g.displayVertices();

	return 0;
} 