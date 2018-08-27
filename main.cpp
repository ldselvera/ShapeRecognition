/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
Perform Depth-Firs Search.
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
	cout<<"6. Display Graph\n";
	cout<<"7. Clear graph\n";
	cout<<"8. Depth-First Traversal\n";
	cout<<"9. Detect Shape\n";
	cout << "10. Exit\n\n";
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
				cout<<"Enter number of random vertices to be inputted:";
				cin>>n;
				for(int i=0; i <n; i++){
					cout<<"Type x & y coordinate:";
					cin>>x>>y;
					g.insertVertex(x, y);
				}
				break;
			case 5:
				cout<<"Enter number of random edges to be inputted:";
				cin>>n;
					for(int i=0; i <n; i++){
						cout<<"\nType first x & y coordinate:";
						cin>>a>>b;
						cout << "\nType second x & y coordinate:";
						cin >> x >> y;
						g.insertEdge(a, b, x, y);
					}
				break;
			case 6:
				g.printGraph();
				break;
			case 7:
				g.clearGraph();
				cout<<"Graph cleared.\n";
				break;
			case 8:
				g.depthFirstTraversal();
				break;
			case 9:
				g.detectShape();
				break;
			case 10:
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
