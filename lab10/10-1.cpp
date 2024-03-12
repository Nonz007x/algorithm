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

	vector<int> shortestPath(int src);

  void src2dest(int src, int dest);

	int buildHospital(int h, vector<int> hospitals);
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

vector<int> Graph::shortestPath(int src) {
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// printf("Vertex Distance from Source\n");
	// for (int i = 0; i < V; ++i)
	// 	printf("%d \t\t %d\n", i + 1, dist[i]);
	
	return dist;
}

void Graph::src2dest(int src, int dest) {
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

  printf("Shortest distance from %d to %d: %d\n", src, dest + 1, dist[dest]);
}

int Graph::buildHospital(int h, vector<int> hospitals) {
	vector<vector<int>> distHospital(h, vector<int>(V));
	//find all distance from hospitals
	for (int i = 0; i < h; i++) {
		distHospital[i] = shortestPath(hospitals[i]);
	}
	//find min distance from all hospitals
	vector<int> minDistance(V, INF);
	for (int j = 0; j < h; j++) {
		for (int k = 0; k < V; k++) {
			minDistance[k] = min(minDistance[k], distHospital[j][k]);
		}
	}
	
	int minDist = INF;
	int buildArea;
	for (int i = 0; i < V; i++) {
		int sum = 0;
		vector<int> newHospital = shortestPath(i);

		for (int j = 0; j < V; j++) {
			sum += min(minDistance[j], newHospital[j]);
		}

		if (minDist > sum) {
			minDist = sum;
			buildArea = i;
		}
	}
	return buildArea + 1;
}

int main() {
	int V, h;
	cin >> h >> V;

  vector<int> hospitals(h);
	for (int i = 0; i < h; i++) {
		int v;
		cin >> v;
		hospitals[i] = v - 1;
	}

	Graph g(V);
	for (int i = 0; i < V; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u - 1, v - 1, w);
	}

	cout << g.buildHospital(h , hospitals);

	return 0;
}
