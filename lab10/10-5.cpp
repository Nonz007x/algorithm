#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
	int V;

	list<pair<int, int> >* adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);

  int src2dest(int src, int dest);
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

int main() {
  int V;
  cin >> V;

  Graph g(V);
  for (int i = 0; i < V; i++) {
    int v;
    cin >> v;
    
    while (v != -1) {
      g.addEdge(i, v, 1);
      cin >> v;
    }
  }

  int s, d;
  cin >> s >> d;
  cout << g.src2dest(s, d);

  return 0;
}
