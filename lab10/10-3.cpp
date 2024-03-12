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
  int C;
  cin >> C;
  vector<Graph*> graphs(C);
  vector<int> answer(C);
  for (int i = 0; i < C; i++) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    graphs[i] = new Graph(n);

    for (int j = 0; j < m; j++) {
      int a, b, w;
      cin >> a >> b >> w;
      graphs[i]->addEdge(a, b, w);
    }

    answer[i] = graphs[i]->src2dest(s, t);
  }

  for (int i = 0; i < C; i++) {
    cout << answer[i] << "\n";
  }

  for (int i = 0; i < C; ++i) {
    delete graphs[i];
  }

  return 0;
}
