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
		int weight;
	};
	
	map <int, edge> edges;
	map <int, vertex> vertices;
	vertex v;
	edge ed;
	
  public:

	Graph ( )
	{}

	void insertVertex(int xx, int yy, int i){
		v.x=xx;
		v.y=yy;
		vertices[i]=v; 
	}

	void displayVertices(){
		cout<<"---------------Vertices--------------\n";
		for(auto elem : vertices)
		{
			cout <<"Vertex "<< elem.first+1 << ": (" << elem.second.x << ", " << elem.second.y << ")\n";
		}
	}

	void setEdges(){
		srand(time(NULL));
		int n, a, b;
		
		cout<<"How many edges?"<<endl;
		cin>>n;

		for(int i=0; i<n ; i++){

			a = rand()%vertices.size();
			b = rand()%vertices.size();

			while(a == b)
				b = rand()%vertices.size();

			edges[i].a.x = vertices[a].x;
			edges[i].a.y= vertices[a].y;
			edges[i].b.x = vertices[b].x;
			edges[i].b.y= vertices[b].y;

		}
	}

	void displayEdges(){
		cout<<"---------------Edges--------------\n";
		for(auto elem : edges){
			cout <<"Edge "<< elem.first+1<< ": (" << elem.second.a.x << ", " << elem.second.a.y << ") (";
			cout<<elem.second.b.x << ", " << elem.second.b.y << ")\n";
		}
	}

	void writeGraph(){
		ofstream file;
		 file.open("Graph.txt");
		if(file.is_open()){
			for(auto elem : edges){
				file <<"(" << elem.second.a.x << ", " << elem.second.a.y << ") (";
				file<<elem.second.b.x << ", " << elem.second.b.y << ")\n";
			}
		}
		file.close();
	}
};

int main()
{
	
	Graph g;
	int u, v,x;
	srand(time(NULL));

	cout<<"How many vertices?"<<endl;
	cin>>x;

	for(int i=0; i<=x;i++){
		u=rand()%20;
		v=rand()%20;
		g.insertVertex(u,v, i);
	}

	g.displayVertices();

	g.setEdges();
	g.displayEdges();
	g.writeGraph();

	return 0;
} 