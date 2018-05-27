#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

using namespace std;

class Graph
{
  private:
	struct vertex
	{
		int x;
		int y;
	};
	
	vector<vertex> vertices;
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

	//Generate random graph with inputted number of vertices and edges
	void createRandomGraph(){
		
		int x, y,c,a,b;
		srand(time(NULL));	

		//Generate random Vertices and Edges
		for(int i=0; i<size;i++){
			x=rand()%20;
			y=rand()%20;
		if(x==y)
			y=rand()%20;
			insertVertex(x, y);
			setGraph();
		}
	
		cout<<"How many edges?"<<endl;
		cin>>c;

		for(int i=0; i<c;i++){
			a=rand()%size;
			b=rand()%size;
			insertEdge(a, b);
		}
	}

	//Initialize adjacency list with inputted vertices
	void setGraph(){

		adjList.resize(vertices.size());

		vertex a = vertices[vertices.size()-1];
		adjList[adjList.size()-1].push_back(a);
	}

	//Insert vertex into list of vertices
	void insertVertex(int x, int y){
			v.x=x;
			v.y=y;
			vertices.push_back(v);
	}

    //Generate sample shapes: rectangle, triangle, square
	void sampleShape(char c)
	{
		
		srand(time(NULL));
		
		if(c=='a'){						//Generate rectangle
			int x = rand()%50;
			int y = rand()%50;
			int u = rand()%50;
			int w = rand()%50;

			insertVertex(x, y);
			setGraph();

			insertVertex(x, w);
			setGraph();

			insertVertex(u, y);
			setGraph();

			insertVertex(u, w);
			setGraph();			

			insertEdge(0, 1);
			insertEdge(2, 3);
			insertEdge(0, 2);
			insertEdge(1, 3);

		}
		else if (c=='b'){				//Generate Triangle
			int x = rand()%50;

			insertVertex(x, rand()%50);
			setGraph();

			insertVertex(x, rand()%50);
			setGraph();

			insertVertex(rand()%50, rand()%50);
			setGraph();

			insertEdge(0, 1);
			insertEdge(2, 1);
			insertEdge(0, 2);
			
		}
		else{							//Generate Square
			int x = rand()%50;
			int y = rand()%50;
			int dist = abs(x-y);

			insertVertex(x, y);
			setGraph();

			insertVertex(x+dist, y);
			setGraph();

			insertVertex(x, y+dist);
			setGraph();

			insertVertex(x+dist, y+dist);
			setGraph();			

			insertEdge(0, 1);
			insertEdge(2, 3);
			insertEdge(0, 2);
			insertEdge(1, 3);
		}

	}

	//Insert node into proper adjacency list
	//Node is added to both list 
	//Undirected Grpah
	void insertEdge(int a, int b){
		adjList[a].push_back(vertices[b]);	
		adjList[b].push_back(vertices[a]);
	}

	//Display the adjacency list
	void printGraph(){

		cout<<endl;
		cout<<"-----------Adjacency List Graph Representation--------------\n";
		for(int i=0; i<vertices.size();i++){
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

	//Display all nodes/vertices
	void displayVertices(){
		cout<<"---------------Vertices--------------\n";
		int i=0;
		for(auto elem : vertices)
		{
			cout <<"Vertex "<<i << ": (" << elem.x << ", " << elem.y << ")\n";
			i++;
		}
	}

	vertex getVertex(int i){
		return vertices[i];
	}

	//Display individual vertex
	void displayVertex(vertex a){
		cout<<"("<<a.x<<", "<<a.y<<"), ";
	}

	//Return distance between two nodes
	int getDistance(vertex a, vertex b){
		return sqrt(pow((b.x-a.x),2)+ pow((b.y-a.y),2));
	}

	void setSize(int size){
		adjList.resize(size);
	}

	int getGraphSize(){
		return this->adjList.size();
	}


};
