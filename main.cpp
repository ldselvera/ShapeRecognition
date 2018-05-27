/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
*/

#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void mainMenu(){
	cout<<"1. Generate random graph\n";
	cout<<"2. Sample Shape\n";
	cout<<"3. Create Graph\n";
	cout<<"4. Exit\n";
	return;
}

void randomGraph(){
		int size;
		cout<<"Input size of graph:"<<endl;
		cin>>size;
		Graph g(size);
		g.createRandomGraph();
		g.displayVertices();
		cout<<"\nGenerating random edges..."<<endl;
		g.printGraph();

		return;
}

void shapeGraph(){
	int size;
	char c;

	cout<<"Choose shape:\na. rectangle\nb. triangle\nc. square"<<endl;
	cin>>c;
	
	if(c=='a'|| c=='c')
		size=4;
	else 
		size=3;

	Graph g(size);
	g.sampleShape(c);
	g.displayVertices();
	g.printGraph();
	return;
}

void inputGraph(){
	int size=0, x, y,a, b, choice;
	bool quit=false;

	Graph g(size);


	while(!quit){
		cout<<"\n1. Insert vertex x & y\n2. Insert edge\n3. Display vertices\n4. Display graph\n5. Exit"<<endl;
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Type x & y coordinate:";
				cin>>x>>y;
				g.insertVertex(x, y);
				g.setGraph();
				break;
			case 2:
				g.displayVertices();
				cout<<"Choose 2 vertices:";
				cin>>a>>b;
				g.insertEdge(a, b);
				break;
			case 3:
				g.displayVertices();
				break;
			case 4:
				g.printGraph();
				break;
			case 5:
				quit=true;
				break;
			default:
				cout<<"Please type a number from 1-5"<<endl;
				cout<<"1. Insert vertex x & y\n2. Insert edge\n3. Display vertices\n4. Display graph\n5. Exit"<<endl;
				cin>>choice;
		}

	}
	return;
}

int main()
{	
	int choice;
	bool quit = false;

	mainMenu();
	cin>>choice;

		switch(choice){
			case 1:
				randomGraph();
				break;
			case 2:
				shapeGraph();
				break;
			case 3:
				inputGraph();
				break;
			case 4:
				quit=true;
				break;
			default:
				cout<<"Please type a number from 1-4"<<endl;
				mainMenu();
				cin>>choice;
		}
	

	return 0;
} 