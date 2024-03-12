#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

using namespace std;

class Graph {
	int V;

	list<pair<int, int> >* adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);

  int src2dest(int src, int dest);

  void primMST(vector<iPair> adj, int v, int src);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	//undirected
	adj[v].push_back(make_pair(u, w));
}

int Graph::src2dest(int src, int dest) {
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

    if (u == dest) break;
    
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	return dist[dest];
}
void Graph::primMST(vector<iPair> adj, int V, int src) { 
  priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // Priority Queue
  vector<int> key(V, INF); // keep distance of vertex
  vector<int> parent(V, -1); // keep path of MST
  vector<bool> inMST(V, false); // keep status of vertex

  pq.push(make_pair(0, src));
  key[src] = 0;

  while (!pq.empty()) { 
    int u = pq.top().second; // get u from pq.
    pq.pop();

    if(inMST[u] == true) continue;

    inMST[u] = true; // add u into MST

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { 
      int v = (*i).first; //get v and weight from adj list of u
      int weight = (*i).second;
      if (inMST[v] == false && key[v] > weight) {
        key[v] = weight;
        pq.push(make_pair(key[v], v)); // push v into pq.
        parent[v] = u;
      }
    }
  }
}

int main() {

  return 0;
}