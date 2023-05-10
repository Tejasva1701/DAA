// Bhoomika Singh
// Program to implement Kruskal's algorithm for MST

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
    private:
	  vector<pair<int, edge> > G;
	  vector<pair<int, edge> > T;
	  int *parent;
	  int V;
   
    public:
	  Graph(int V);
	  void addEdge(int u, int v, int w);
	  int find_set(int i);
	  void union_set(int u, int v);
	  void kruskal();
	  void print();
};

Graph::Graph(int V) {
	parent = new int[V];
	for (int i = 0; i < V; i++)
    	parent[i] = i;
}

void Graph::addEdge(int u, int v, int w) {
	G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i) {
  // if i is the parent of itself
	if (i == parent[i])
    	return i;
	else
    // recursively call Find on its parent
    	return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
	parent[u] = parent[v];
}

void Graph::kruskal() {
	int i, u1, v1;
	sort(G.begin(), G.end());  // increasing weight
	for (i = 0; i < G.size(); i++) {
    	u1 = find_set(G[i].second.first);
    	v1 = find_set(G[i].second.second);
    	if (u1 != v1) {
      		T.push_back(G[i]);  // add to tree
      		union_set(u1, v1);
    }
  }
}

void Graph::print() {
	cout << "Edge  :" << " Weight" << endl;
	for (int i = 0; i < T.size(); i++) {
    	cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first;
    	cout << endl;
  }
}

int main() {
  
 	Graph g(6);
  	g.addEdge(0,1,4);
	g.addEdge(0,2,4);   
	g.addEdge(1,2,2);            
	g.addEdge(2,4,2);
	g.addEdge(2,3,3);
	g.addEdge(2,5,4);
	g.addEdge(3,5,3);
	g.addEdge(4,5,3);
  
  	g.kruskal();
  
  	g.print();
  
  	return 0;
}
