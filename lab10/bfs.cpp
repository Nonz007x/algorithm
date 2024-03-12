#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
class Graph {
private:
  int V;
  vector<list<int>> adj;
public:
  Graph(int v): V(v) {
    adj.resize(v);
  }

  void addEdge(int v, int w) {
    adj[v].push_back(w);  
    // undirected
    // adj[w].push_back(v);
  }

  void BFS(int i) const {
    int visited[V] = {0};
    queue<int> q;
    cout << i + 1 << " ";
    BFS_helper(i, &q, visited);
  }

  void BFS_helper(int i, queue<int>* q, int* visited) const {
    if (i < V) {
      visited[i] = 1;
      for (auto v : adj[i]) {
        if(!visited[v]) {
          cout << v + 1 << " ";
          visited[v] = 1;
          q->push(v);
        }
      }
      for (int i = 0; i < q->size(); i++) {
        int temp = q->front();
        q->pop();
        BFS_helper(temp, q, visited);
      }
    }
  }

  void printAdj() const {
    for (int i = 0; i < V; i++) {
      cout << i << ": ";
      for (auto v : adj[i]) {
        cout << v << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
};


int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(2, 5);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(4, 5);

  g.printAdj();
  g.BFS(0);
  return 0;
}
