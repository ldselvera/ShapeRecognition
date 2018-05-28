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

		bool operator==(const vertex& a) const{
        	return (x == a.x && y == a.y);
    	}

	};
	
	vector<vertex> vertices;
	vertex v;
	vector<list<vertex> > adjList;

	int size;

  public:

	Graph(){
		this->size=0;
		adjList.resize(size);
	}

	Graph (int size){
		this->size=size;
		adjList.resize(size);
	}

	bool isEmpty() const{
		return vertices.empty();
	}

    //Generate sample shapes: rectangle, triangle, square
	void sampleShape(){
		char c;

		cout<<"Choose shape:\na. rectangle\nb. triangle\nc. square"<<endl;
		cin>>c;
		if(c=='a'){						//Generate rectangle
			createRectangle();
			return;
		}
		else if (c=='b'){			//Generate Triangle
			createTriangle();
			return;
		}
		else{							//Generate Square
			createSquare();
			return;
		}
	}

	void createRectangle(){
				
		srand(time(NULL));
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

		int n = vertices.size()-1;

		insertEdge(n-3, n-2);
		insertEdge(n-1, n);
		insertEdge(n-3, n-1);
		insertEdge(n-2, n);

		cout<<"Rectangle added to the graph."<<endl;
	}

	void createSquare(){
		
		srand(time(NULL));
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

		int n = vertices.size()-1;

		insertEdge(n-3, n-2);
		insertEdge(n-1, n);
		insertEdge(n-3, n-1);
		insertEdge(n-2, n);
		
		cout<<"Square added to the graph."<<endl;
	}

	void createTriangle(){

		srand(time(NULL));

		int x = rand()%50;

		insertVertex(x, rand()%50);
		setGraph();

		insertVertex(x, rand()%50);
		setGraph();

		insertVertex(rand()%50, rand()%50);
		setGraph();

		int n = vertices.size()-1;

		insertEdge(n-2, n-1);
		insertEdge(n, n-1);
		insertEdge(n-2, n);

		cout<<"Triangle added to the graph."<<endl;
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

		if(vertices.empty())
			vertices.push_back(v);
		else{
			for(int i=0;i<vertices.size();i++){
				if(vertices[i]==v)
					return;
				}
				
			vertices.push_back(v);
			}	
		
	}

	//Generate n random vertices
	void randomVertices(int n){
		srand(time(NULL));	
		int x, y;
		for(int i=0; i<n;i++){
			x=rand()%20;
			y=rand()%20;
			if(x==y)
				y=rand()%20;
			
			insertVertex(x, y);
			setGraph();
		}
	}

	//Insert node into proper adjacency list
	//Node is added to both list 
	//Undirected Grpah
	void insertEdge(int a, int b){

		if(vertices[a]==vertices[b])
			return;
		

		if(vertices.empty())
			cout<<"No vertices in the graph."<<endl;
		else{
			adjList[a].push_back(vertices[b]);	
			adjList[b].push_back(vertices[a]);
		}
	}

	//Generate n random edges
	void randomEdges(int n){
		srand(time(NULL));	
		int a, b;
		for(int i=0; i<n;i++){
			a=rand()%vertices.size();
			b=rand()%vertices.size();
			insertEdge(a, b);
		}
	}


	//Display the adjacency list
	void printGraph(){
		if(adjList.empty())
			cout<<"No edges in the graph"<<endl;
		else{
			cout<<"\n-----------Adjacency List Graph Representation--------------\n";
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
	}

	//Display all nodes/vertices
	void displayVertices(){
		if(vertices.empty())
			cout<<"No vertices in the graph."<<endl;
		else{
			cout<<"---------------Vertices--------------\n";
			int i=0;
			for(auto elem : vertices)
			{
				cout <<"Vertex "<<i << ": (" << elem.x << ", " << elem.y << ")\n";
				i++;
			}
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

	void clearVertices(){
		vertices.resize(0);
	}

	void setSize(int size){
		adjList.resize(size);
	}

	int getGraphSize(){
		return this->adjList.size();
	}

};
