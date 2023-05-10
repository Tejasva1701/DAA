// Bhoomika Singh
// Program to implement Prim's algorithm for MST

# include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f  // to set the distances at infinity

typedef pair<int, int> iPair;

class Graph
{
	int V;
	list <pair<int, int> > *adj; //stores vertex and weight

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void primMST();
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src = 0;
	vector<int> key(V, INF);
	vector<int> parent(V, -1);
	vector<bool> inMST(V, false);

	pq.push(make_pair(0, src));
	key[src] = 0;

	// till priority queue becomes empty
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		
		if(inMST[u] == true){
			continue;
		}
	
		inMST[u] = true;

		// 'i' is used to get all adjacent vertices of a vertex
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			
			if (inMST[v] == false && key[v] > weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	// Print edges of MST using parent array
	for (int i = 1; i < V; ++i)
		cout << parent[i] << " - " << i << endl;
}

// Driver program to test methods of graph class
int main()
{
	Graph g(6);

	g.addEdge(0,1,4);
	g.addEdge(0,2,4);   
	g.addEdge(1,2,2);            
	g.addEdge(2,4,2);
	g.addEdge(2,3,3);
	g.addEdge(2,5,4);
	g.addEdge(3,5,3);
	g.addEdge(4,5,3);

	g.primMST();

	return 0;
}

