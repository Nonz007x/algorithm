#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <list>

using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph {

private:
  int V;

  vector<iPair>* adj;

public:
  Graph(int V) {
    this->V = V;
    adj = new vector<iPair>[V];
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  void prim(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);
    vector<bool> inTree(V, 0);
    vector<int> parent(V, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      if (inTree[u]) continue;

      inTree[u] = 1;
      for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = i->first;
        int weight = i->second;
        if (!inTree[v] && dist[v] > weight) {
          dist[v] = weight;
          parent[v] = u;
          pq.push(make_pair(dist[v], v));
        }
      }
      
    }
  }

  vector<int> shortest(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = i->first;
        int weight = i->second;

        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          parent[v] = u;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
    for (int i = 0; i < V; i++) {
      cout << dist[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < V; i++) {
      cout << parent[i] << " ";
    }
    
    return dist;
  }

  void gay(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = i->first;
        int weight = i->second;

        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
  }
};

int main() {
  cout << "test\n";
  Graph g(5);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 3, 9);
  g.addEdge(0, 4, 1);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 3, 6);
  g.addEdge(3, 4, 2);

  vector<int> out = g.shortest(0);
  // for (int i = 0; i < 4; i++) {
  //   cout << out[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < 4; i++) {
  //   cout << out[i] << " ";
  // }
  

  return 0;
}