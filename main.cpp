/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
*/

#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;


int main()
{	
	Graph g;

	char choice;

	cout<<"Choose sample shape(a, b, or c):\na. Rectangle\nb. Triangle\nc. Square"<<endl;
	cin>>choice;
	
	int x, y,c,a,b,size;
	srand(time(NULL));	

/*	Generate random Vertices and Edges
	cout<<"How many vertices?"<<endl;
	cin>>size;
	
	for(int i=0; i<size;i++){
		x=rand()%20;
		y=rand()%20;

		if(x==y)
			y=rand()%20;

		g.insertVertex(x, y, i);
	}

	cout<<"How many edges?"<<endl;
	cin>>c;

	for(int i=0; i<c;i++){
		a=rand()%size;
		b=rand()%size;
		g.insertEdge(g.getVertex(a), g.getVertex(b), i);
	}
*/

	g.sampleShape(choice);
	g.displayVertices();
	g.displayEdges();
	g.writeGraph();

	return 0;
} 