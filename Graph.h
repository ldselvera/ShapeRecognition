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

	vector<list<vertex> > adjList;

	int size;
	
  public:

	Graph (int size){
		this->size=size;
		adjList.resize(size);
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

		for(int i=0; i<adjList.size();i++){
			vertex a = vertices[i];
			adjList[i].push_back(a);
		}

	
		cout<<"How many edges?"<<endl;
		cin>>c;

		for(int i=0; i<c;i++){
			a=rand()%size;
			b=rand()%size;
			insertEdge(a, b);
		}
	}


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

			for(int i=0; i<adjList.size();i++){
			vertex a = vertices[i];
			adjList[i].push_back(a);
		}

			insertEdge(0, 1);
			insertEdge(2, 3);
			insertEdge(0, 2);
			insertEdge(1, 3);

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

			for(int i=0; i<adjList.size();i++){
				vertex a = vertices[i];
				adjList[i].push_back(a);
			}

			insertEdge(0, 1);
			insertEdge(2, 1);
			insertEdge(0, 2);
			
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

			for(int i=0; i<adjList.size();i++){
				vertex a = vertices[i];
				adjList[i].push_back(a);
			}	

			insertEdge(0, 1);
			insertEdge(2, 3);
			insertEdge(0, 2);
			insertEdge(1, 3);
		}

	}

	void insertEdge(int a, int b){
		adjList[a].push_back(vertices[b]);	
		adjList[b].push_back(vertices[a]);
	}

	void printGraph(){

		cout<<endl;
		cout<<"-----------Adjacency List Graph Representation--------------"
		for(int i=0; i<adjList.size();i++){
			cout<<i<<": ";
			if(adjList[i].empty())
				cout<<"Empty";
			else{
				list<vertex> li = adjList[i];
				for(auto elem: li){
					cout<<"("<<elem.x<<", "<<elem.y<<"), ";
				}
			}
			cout<<endl;
		}
	}

	void displayVertices(){
		cout<<"---------------Vertices--------------\n";
		for(auto elem : vertices)
		{
			cout <<"Vertex "<< elem.first << ": (" << elem.second.x << ", " << elem.second.y << ")\n";
		}
	}

	vertex getVertex(int i){
		return vertices[i];
	}

	void displayVertex(vertex a){
		cout<<"("<<a.x<<", "<<a.y<<"), ";
	}

	int getDistance(vertex a, vertex b){
		return sqrt(pow((b.x-a.x),2)+ pow((b.y-a.y),2));
	}

	int getGraphSize(){
		return this->size;
	}
};
