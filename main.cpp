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
	char c, choice;
	cout<<"Generate random graph(a) or Sample Shape(b): "<<endl;
	cin>>choice;

	while(choice!= 'z'){
		if(choice =='a'){
			cout<<"Input size of graph:"<<endl;
			cin>>size;
			Graph g(size);
			g.createGraph();
			g.displayVertices();
			choice='z';
		}
		else if (choice =='b'){
			cout<<"Choose shape:\na. rectangle\nb. triangle\nc. square"<<endl;
			cin>>c;
			
			if(c=='a'|| c=='c')
				size=4;
			else 
				size=3;

			Graph g(size);
			g.sampleShape(c);
			g.displayVertices();
			choice='z';
		}
		else{
			cout<<"Please type 'a' or 'b' to generate graph. Type 'z' to exit."<<endl;
			cin>>choice;
		}
	}

	return 0;
} 