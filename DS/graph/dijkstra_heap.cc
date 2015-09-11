#include <queue>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

const int MAX_DIST = 9999999;

struct TableEntry {
  bool visited;
  int dist;
  int path;
};

class DistEntry {
public:
  int id;
  int dist;
  DistEntry(int i, int d) : id(i), dist(d) {}
};

struct comp {
  bool operator() (const DistEntry& de1, const DistEntry& de2) const {
    return de1.dist > de2.dist;
  }
};

void dijkstra(TableEntry table[], const list<DistEntry> graph[], int num_vertex, int src) {
  // Initialize table
  for (int i = 0; i < num_vertex; ++i) {
    table[i].visited = false;
    table[i].dist = MAX_DIST;
    table[i].path = src;
  }
  priority_queue<DistEntry, vector<DistEntry>, comp> queue;
  queue.emplace(src, 0);
  table[src].dist = 0;
  while (true) {
    int x = queue.top().id;
    // !!! Use TableEntry visited to determine whether to break
    while (!queue.empty() && table[x].visited) { queue.pop(); x = queue.top().id; }
    if (queue.empty()) break;
    cout << "min is " << x << ", dist is " << table[x].dist << "\n";
    queue.pop();
    table[x].visited = true;
    for (auto iter = graph[x].begin(); iter != graph[x].end(); ++iter) {
      if (!table[iter->id].visited) {
        if (table[iter->id].dist > table[x].dist + iter->dist) {
          table[iter->id].dist = table[x].dist + iter->dist;
          table[iter->id].path = x;
        }
        queue.emplace(iter->id, table[iter->id].dist);
      }
    }
  }
}

void display_graph(const list<DistEntry> graph[], int num_vertex) {
  for (int i = 0; i < num_vertex; ++i) {
    cout << i << ": ";
    for (auto iter = graph[i].begin(); iter != graph[i].end(); ++iter) {
      cout << "(" << iter->id << ", " << iter->dist << ")";
    }
    cout << "\n";
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  int num_vertex, num_edge, src;
  cin >> num_vertex >> num_edge >> src;

  TableEntry table[num_vertex];
  list<DistEntry> *graph = new list<DistEntry>[num_vertex];
  while (num_edge--) {
    int v1, v2, dist;
    cin >> v1 >> v2 >> dist;
    graph[v1 - 1].emplace_back(v2 - 1, dist);
    graph[v2 - 1].emplace_back(v1 - 1, dist);
  }

  display_graph(graph, num_vertex);

  dijkstra(table, graph, num_vertex, src - 1);

  // Result
  for (int i = 0; i < num_vertex; ++i) {
    cout << i << ": " << table[i].dist << " " << table[i].path << "\n";
  }

  delete[] graph;

  return 0;
}

