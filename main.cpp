/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
*/

#include "Graph.h"
#include <iostream>

using namespace std;

void mainMenu(){
	cout<<"\n1. Generate random vertices\n";
	cout<<"2. Generate random edges\n";
	cout<<"3. Add Sample Shape\n";
	cout<<"4. Add vertices\n";
	cout<<"5. Add edges\n";
	cout<<"6. Display vertices\n";
	cout<<"7. Display edges\n";
	cout<<"8. Clear graph\n";
	cout<<"9. Exit\n\n";
	return;
}


int main()
{	
	int choice, x, y, a, b, n;
	bool quit = false;

	Graph g;
	
	while(!quit){
		mainMenu();
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter number of random vertices to be created:";
				cin>>n;
				g.randomVertices(n);
				break;
			case 2:
				cout<<"Enter number of random edges to be created:";
				cin>>n;
				g.randomEdges(n);
				break;
			case 3:
				g.sampleShape();
				break;
			case 4:
				cout<<"Enter number of random vertices to be created:";
				cin>>n;
				for(int i=0; i <n; i++){
					cout<<"Type x & y coordinate:";
					cin>>x>>y;
					g.insertVertex(x, y);
					g.setGraph();
				}
				break;
			case 5:
				if(g.isEmpty())
					cout<<"No vertices in the graph"<<endl;
				else{
					cout<<"Enter number of random edges to be created:";
					cin>>n;
					
					g.displayVertices();

					for(int i=0; i <n; i++){
						cout<<"Choose 2 vertices:";
						cin>>a>>b;
						g.insertEdge(a, b);
					}
				}
				break;
			case 6:
				g.displayVertices();
				break;
			case 7:
				g.printGraph();
				break;
			case 8:
				g.clearVertices();
				g.setSize(0);
				cout<<"Graph cleared.\n";
				break;
			case 9:
				quit=true;
				break;
			default:
				cout<<"Please type a number from 1-9"<<endl;
				mainMenu();
				cin>>choice;
		}
	}
	

	return 0;
} 