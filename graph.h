#include <set>
#include <map>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
  private:
	set<int> Vertices;
	set<pair<int , int> > Edges;

	map<pair<int, int>, int> Weight_of_Edges;
	map<int, set<int> > AdjList_of_Vertices;


  public:
	int Nvertices, Nedges;
	bool isDirected;

	set<int> vertices()
	{
		return Vertices;
	}

	struct attribute
	{
		bool visited = false;
		int distance = INT_MAX;
		int parent = 0;
	};
	vector<attribute> Attributes;

	Graph ( int Nvertices, int Nedges, bool isDirected = false )
	{
		this->Nvertices = Nvertices;
		this->Nedges = Nedges;
		this->isDirected = isDirected;

		set<int> s = {};
		attribute atb;

		for ( int i = 1; i <= Nvertices; i++ )
		{
			AdjList_of_Vertices.insert ( make_pair ( i, s ) );
			Attributes.push_back ( atb );
		}
	}

	std::set<int> adjList ( int vertex )
	// returns the adjacency list (a set) of a vertex.
	{
		return AdjList_of_Vertices[vertex];
	}

	int get_weight ( int u, int v )
	// returns the weight of th edge {u, v}
	{
		return Weight_of_Edges[make_pair ( u, v )];
	}

	int get_weight ( pair<int, int> edge )
	{
		return Weight_of_Edges[edge];
	}

	void insert_edge ( int u, int v, int weight = 1 )
	{
		new_edge ( u, v, make_pair ( u, v ), weight );

		if ( !isDirected )
		{
			new_edge ( v, u, make_pair ( v, u ), weight );
		}

	}

	void insert_edge ( pair<int, int> edge, int weight = 1 )
	{
		insert_edge ( edge.first, edge.second, weight );
	}

	void new_edge ( int u, int v, pair<int, int> edge, int weight )
	{
		AdjList_of_Vertices[u].insert ( v );
		Edges.insert ( edge );
		Weight_of_Edges.insert ( make_pair ( edge, weight ) );
	}

	bool is_visited ( int u )
	{
		return Attributes[u].visited;
	}

	bool get_distance ( int u )
	{
		return Attributes[u]. distance;
	}

	bool is_edge ( int u, int v )
	{
		if ( Edges.count ( make_pair ( u, v ) ) == 0 ) return false;

		return true;
	}

	int get_parent ( int u )
	{
		return Attributes[u].parent;
	}

	void visit ( int u )
	{
		Attributes[u].visited = true;
	}

	void set_distance ( int node, int new_distance )
	{
		Attributes[node].distance = new_distance;
	}

	void set_parent ( int child, int parent )
	{
		Attributes[child].parent = parent;
	}
};
