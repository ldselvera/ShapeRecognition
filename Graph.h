#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class Graph
{
private:
	struct vertex
	{
		int x;
		int y;
		//bool visited = false;	//vertex not visited
		struct vertex *parent;
		int discovery = -1;
		int finished = -1;
		string color = "white";

		bool operator==(const vertex* a) const {
			return (x == a->x && y == a->y);
		}

	};

	vector<list<vertex*> > adjList;
	int size;
	int times;

public:

	Graph() {
		this->size = 0;
	}

	Graph(int size) {
		this->size = size;
		adjList.resize(size);
	}

	void clearGraph() {
		adjList.resize(0);
	}

	void resetGraph(){
		for(auto list:this->adjList){
			for (auto elem:list){
				elem->discovery=-1;
				elem->finished=-1;
				elem->color="white";
			}
		}
	}

	//Generate sample shapes: rectangle, triangle, square
	 void sampleShape(){
		 char c;

		 cout<<"Choose shape:\na. rectangle\nb. triangle\nc. square"<<endl;
		 cin>>c;
		 if (c == 'a') {
			 createRectangle();
			 return;
		 }
		 else if (c == 'b') {
			 createTriangle();
			 return;
		 }
		 else if (c == 'c') {
			 createSquare();
			 return;
		 }
		 else
			 cout << "Please enter a letter from a, b, c.";
	 }
	
	 //Insert vertex into list of vertices
	void insertVertex(int x, int y) {
		vertex *v = new vertex;
		v->x = x;
		v->y = y;

		list<vertex*> li;

		li.push_back(v);
		adjList.push_back(li);

	}

	//Generate n random vertices
	void randomVertices(int n) {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++) {
			insertVertex(rand() % 20, rand() % 20);
		}
	}

	//Insert node into proper adjacency list
	//Node is added to both list 
	//Undirected Graph
	void insertEdge(int a, int b, int c, int d) {
		
		if (adjList.empty()) {
			insertVertex(a, b);
			insertVertex(c, d);
		}
		else {
			if (!findV(a, b))
				insertVertex(a, b);
			if (!findV(c, d)) 
				insertVertex(c, d);
		}

		int indu = indexV(a, b);
		int indw = indexV(c, d);

		vertex *u = adjList[indu].front();
		vertex *w = adjList[indw].front();

		if ((a == c) && (b == d))
			return;
		else {
			if (!findNeighbors(u, w)) {			//Avoid adding repeated edge
				adjList[indu].push_back(w);
			}
			if (!findNeighbors(w, u)) {				//Avoid adding repeated edge
				adjList[indw].push_back(u);
			}
			}
	}	
	
	//Generate n random edges
	void randomEdges(int n) {
		 srand((unsigned int) time(NULL));
		for (int i = 0; i < n; i++) {
			insertEdge(rand() % 20, rand() % 20, rand() % 20, rand() % 20);
		}
	}

	//Display the adjacency list
	void printGraph() {
		int i = 0;
		ofstream outData;
		outData.open("vertices.txt");

		if (adjList.empty())
			cout << "Empty Graph." << endl;
		else {
			cout << "\n-----------Adjacency List Graph Representation--------------\n";
			for (auto list : adjList) {
				cout << i << ": ";
				outData << i << ": ";
				for (auto elem : list) {
					cout << "(" << elem->x << ", " << elem->y << ") ";
					outData << "(" << elem->x << ", " << elem->y << ")";
				}
				cout << endl;
				outData << endl;
				i++;
			}
		}
		outData.close();
	}

	//Function to perform the depth first traversal of
	//the entire graph.
	void depthFirstTraversal() {
		
		resetGraph();

		if (adjList.empty())
			cout << "Empty Graph." << endl;
		else {
			cout << "---------------Depth-First Traversal--------------\n";
			times = 0;
			for (auto list : adjList) {
				if (list.front()->color=="white")
					dfs(list.front());
			}
			cout << endl;
		}
	}

private:

	 //Generate rectangle
	 void createRectangle(){

		 srand((unsigned int) time(NULL));
		 int x = rand()%50;
		 int y = rand()%50;
		 int a = rand()%50;
		 int b = rand()%50;

		 insertEdge(x, y, x, b);
		 insertEdge(a, y, a, b);
		 insertEdge(x, y,a, y);
		 insertEdge(x, b, a, b);

		 cout<<"Rectangle added to the graph."<<endl;
	 }

	 //Generate Square
	 void createSquare(){

		 srand((unsigned int)time(NULL));
		 int x = rand()%50;
		 int y = rand()%50;
		 int dist = abs(x-y);

		 insertEdge(x, y, x + dist, y);
		 insertEdge(x, y + dist, x + dist, y + dist);
		 insertEdge(x, y, x, y + dist);
		 insertEdge(x + dist, y, x + dist, y + dist);

		 cout<<"Square added to the graph."<<endl;
	 }

	 //Generate Triangle
	 void createTriangle(){

		 srand((unsigned int)time(NULL));

		 int a = rand() % 50;
		 int b = rand() % 50;
		 int x = rand() % 50;
		 int y = rand() % 50;
		 int u = rand() % 50;
		 int w = rand() % 50;

		 insertEdge(x, y, a, b);
		 insertEdge(a, b, u, w);
		 insertEdge(u, w, x, y);

		 cout<<"Triangle added to the graph."<<endl;
	 }

	//Return true if edge has already been created
	bool findNeighbors(vertex *v, vertex *w) {
		int indv = indexV(v->x, v->y);

		for (auto *elem : adjList[indv]) {
			if (*elem == w)
				return true;
		}
		return false;
	}

	//Return true if Vertex is in the Adjacent List
	bool findV(int a, int b) {
		for (auto list : adjList) {
			for (auto *elem : list) {
				if ((elem->x == a)&&(elem->y == b))
					return true;
			}
		}
		return false;
	}

	//Return distance between two nodes
	double getDistance(vertex u, vertex w){
		return sqrt(pow((w.x-u.x),2)+ pow((w.y-u.y),2));
	}

	//Return index of vertex in the Adjacent List
	int indexV(int a, int b){
		for(size_t i=0; i<adjList.size();i++){
			if ((a == adjList[i].front()->x) && (b == adjList[i].front()->y))
				return i;
			}
	
		cout << "Index not found." << endl;
		return -1;
	}
		
	//Function to perform the depth first traversal of
	//the graph at a node specified by the parameter vertex.
	void dfs(vertex *v) {
		
		v->color = "gray";
		times++;
		v->discovery = times;

		int j = indexV(v->x, v->y);

		for (auto elem : adjList[j]) {
			if (elem->color == "white") {
				elem->parent = v;
				dfs(elem);
			}
		}

		v->color = "black";
		times++;
		v->finished = times;
		cout << "(" << v->x << ", " << v->y << ")";
		cout << v->discovery << "/"<< v->finished << " ";
		cout << v->color << endl;
	}
};
