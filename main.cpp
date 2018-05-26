/*
A simple C++ class - "Graph". 
The Graph class can be used to generate vertices and edges for a graph.
*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>
#include <cmath>

using namespace std;

class Graph
{
  private:
	struct vertex
	{
		int x;
		int y;
	};

	struct edge
	{
		vertex a;
		vertex b;
		double distance=0.0;
	};
	
	map <int, edge> edges;
	map <int, vertex> vertices;
	vertex v;
	edge ed;
	
  public:

	Graph ( )
	{}

	void insertVertex(int x, int y, int i){
			v.x=x;
			v.y=y;
			vertices[i]=v;
	}

	void sampleShape(char c){
		srand(time(NULL));
		if(c=='a'){
			int x = rand()%50;
			int y = rand()%50;
			int u = rand()%50;
			int w = rand()%50;

			v.x=x;
			v.y=y;
			vertices[0]=v;

			v.x=x;
			v.y=w;
			vertices[1]=v;

			v.x=u;
			v.y=y;
			vertices[2]=v;

			v.x=u;
			v.y=w;
			vertices[3]=v;

			insertEdge(vertices[0], vertices[1], 0);
			insertEdge(vertices[0], vertices[2], 1);
			insertEdge(vertices[1], vertices[3], 2);
			insertEdge(vertices[2], vertices[3], 3);

			edges[0].distance= sqrt(pow((edges[0].b.x-edges[0].a.x),2)+ pow((edges[0].b.y-edges[0].a.y),2));
			edges[1].distance= sqrt(pow((edges[1].b.x-edges[1].a.x),2)+ pow((edges[1].b.y-edges[1].a.y),2));
			edges[2].distance= sqrt(pow((edges[2].b.x-edges[2].a.x),2)+ pow((edges[2].b.y-edges[2].a.y),2));
			edges[3].distance= sqrt(pow((edges[3].b.x-edges[3].a.x),2)+ pow((edges[3].b.y-edges[3].a.y),2));

		}
		else if (c=='b'){
			int x = rand()%50;

			v.x=x;
			v.y=rand()%50;
			vertices[0]=v;

			v.x=x;
			v.y=rand()%50;
			vertices[1]=v;

			v.x=rand()%50;
			v.y=rand()%50;
			vertices[2]=v;

			insertEdge(vertices[0], vertices[1], 0);
			insertEdge(vertices[0], vertices[2], 1);
			insertEdge(vertices[1], vertices[2], 2);

			edges[0].distance= sqrt(pow((edges[0].b.x-edges[0].a.x),2)+ pow((edges[0].b.y-edges[0].a.y),2));
			edges[1].distance= sqrt(pow((edges[1].b.x-edges[1].a.x),2)+ pow((edges[1].b.y-edges[1].a.y),2));
			edges[2].distance= sqrt(pow((edges[2].b.x-edges[2].a.x),2)+ pow((edges[2].b.y-edges[2].a.y),2));
		}
		else{
			int x = rand()%50;
			int y = rand()%50;
			int dist = abs(x-y);
			
			v.x=x;
			v.y=y;
			vertices[0]=v;

			v.x=x+dist;
			v.y=y;
			vertices[1]=v;

			v.x=x;
			v.y=y+dist;
			vertices[2]=v;

			v.x=x+dist;
			v.y=y+dist;
			vertices[3]=v;

			insertEdge(vertices[0], vertices[1], 0);
			insertEdge(vertices[0], vertices[2], 1);
			insertEdge(vertices[1], vertices[3], 2);
			insertEdge(vertices[2], vertices[3], 3);

			edges[0].distance= sqrt(pow((edges[0].b.x-edges[0].a.x),2)+ pow((edges[0].b.y-edges[0].a.y),2));
			edges[1].distance= sqrt(pow((edges[1].b.x-edges[1].a.x),2)+ pow((edges[1].b.y-edges[1].a.y),2));
			edges[2].distance= sqrt(pow((edges[2].b.x-edges[2].a.x),2)+ pow((edges[2].b.y-edges[2].a.y),2));
			edges[3].distance= sqrt(pow((edges[3].b.x-edges[3].a.x),2)+ pow((edges[3].b.y-edges[3].a.y),2));
		}

	}

	void insertEdge(vertex a, vertex b, int i){

			edges[i].a = a;
			edges[i].b= b;

			edges[i].distance= sqrt(pow((edges[i].b.x-edges[i].a.x),2)+ pow((edges[i].b.y-edges[i].a.y),2));
	}

	void displayVertices(){
		cout<<"---------------Vertices--------------\n";
		for(auto elem : vertices)
		{
			cout <<"Vertex "<< elem.first+1 << ": (" << elem.second.x << ", " << elem.second.y << ")\n";
		}
	}

	void displayEdges(){
		cout<<"---------------Edges--------------\n";
		for(auto elem : edges){
			cout <<"Edge "<< elem.first+1<< ": (" << elem.second.a.x << ", " << elem.second.a.y << "), (";
			cout<<elem.second.b.x << ", " << elem.second.b.y << ") Distance: "<<elem.second.distance<<"\n";
		}
	}

	void writeGraph(){
		ofstream file;
		 file.open("Graph.txt");
		if(file.is_open()){
			for(auto elem : edges){
				file <<"(" << elem.second.a.x << ", " << elem.second.a.y << "), (";
				file<<elem.second.b.x << ", " << elem.second.b.y << ")\n";
			}
		}
		file.close();
	}

	edge getEdge(int i){
		return edges[i];
	}

	vertex getVertex(int i){
		return vertices[i];
	}
};

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