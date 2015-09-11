#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

struct Table {
  bool visited;
  int dist;
  int path;
};

struct DistEntry {
  int id;
  int dist;
};

struct comp {
  bool operator() (const DistEntry& de1, const DistEntry& de2) const {
    return de1.dist > de2.dist;
  }
};

void dijkstra(Table& table[], unordered_map<int, list<DistEntry>>& graph) {
  priority_queue<DistEntry, vector<DistEntry>, comp> queue;
  while (true) {
    if (queue.empty()) break;
    int x = queue.top().id;
    queue.pop();
    table[x].visited = true;
    for (auto iter = graph[x].begin(); iter != graph[x].end(); ++iter) {
      if (!table[iter->id].visited && table[iter->id].dist > table[x].dist + graph[x].dist) {
        table[iter->id].dist = table[x].dist + graph[x].dist;
        queue.emplace(iter->id, table[iter->id].dist);
      }
    }
  }
}

int main() {
  return 0;
}

