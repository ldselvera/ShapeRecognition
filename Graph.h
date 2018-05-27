#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <set>
#include <iterator>

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
	
	map <int, vertex> vertices;
	vertex v;

	int size;
	list<vertex> *graph;
	
  public:

	Graph (int size){
		this->size=size;
		graph = new list<vertex>[size];
	}

	bool isEmpty() const{
		return (size==0);
	}

	void createGraph(){
		char choice;
		/*cout<<"Choose sample shape(a, b, or c):\na. Rectangle\nb. Triangle\nc. Square"<<endl;
		cin>>choice;
		sampleShape(choice);
		*/
		int x, y,c,a,b;
		srand(time(NULL));	

		//Generate random Vertices and Edges
		for(int i=0; i<size;i++){
			x=rand()%20;
			y=rand()%20;

			if(x==y)
				y=rand()%20;

			insertVertex(x, y, i);
		}

		cout<<"How many edges?"<<endl;
		cin>>c;

		for(int i=0; i<c;i++){
			a=rand()%size;
			b=rand()%size;
			insertEdge(getVertex(a), getVertex(b));
		}
	}

	void printGraph();


	void insertVertex(int x, int y, int i){
			v.x=x;
			v.y=y;
			vertices[i]=v;
	}

    //Generate sample shapes: rectangle, triangle, square
	
	void sampleShape(char c)
	{
		
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

			insertEdge(vertices[0], vertices[1]);
			insertEdge(vertices[2], vertices[3]);
			insertEdge(vertices[0], vertices[2]);
			insertEdge(vertices[1], vertices[3]);

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

			insertEdge(vertices[0], vertices[1]);
			insertEdge(vertices[2], vertices[1]);
			insertEdge(vertices[0], vertices[2]);
			
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

			insertEdge(vertices[0], vertices[1]);
			insertEdge(vertices[2], vertices[3]);
			insertEdge(vertices[0], vertices[2]);
			insertEdge(vertices[1], vertices[3]);
		}

	}

	void insertEdge(vertex a, vertex b){

		int inda;
		int indb;

		for (auto elem : vertices){
			if(elem.second.x==a.x && elem.second.y== a.y)
				inda=elem.first;
			else if(elem.second.x==b.x && elem.second.y== b.y)
				indb = elem.first;
		}
		cout<<endl;
		cout<<inda<<" "<<vertices[inda].x<<" "<<vertices[inda].y<<endl;
		cout<<indb<<" "<<vertices[indb].x<<" "<<vertices[indb].y<<endl;

		graph[inda].push_back(b);	
		graph[indb].push_back(a);
	}

	void displayVertices(){
		cout<<"---------------Vertices--------------\n";
		for(auto elem : vertices)
		{
			cout <<"Vertex "<< elem.first+1 << ": (" << elem.second.x << ", " << elem.second.y << ")\n";
		}
	}

	vertex getVertex(int i){
		return vertices[i];
	}

	int getDistance(vertex a, vertex b){
		return sqrt(pow((b.x-a.x),2)+ pow((b.y-a.y),2));
	}

	int getGraphSize(){
		return this->size;
	}
};
