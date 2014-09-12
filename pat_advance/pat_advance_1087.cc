#include <cstdio>
#include <map>
#include <cstring>
#include <list>
#include <vector>
#include <stack>


const int MaxDist = 10000000;

struct Table
{
  int happiness;
  bool visited;
  int dist;
  std::vector<char*> path;
};

struct cmp_str
{
  bool operator()(char const *str1, char const *str2) const
  {
    return strcmp(str1, str2) < 0;
  }
};
std::map<char*, Table, cmp_str> tableMap;

// Adjacent list
struct Dist
{
  char* name;
  int dist;
};
std::map<char*, std::list<Dist>, cmp_str> adjacent;


void Dijkstra(
  std::map<char*, std::list<Dist>, cmp_str>& adjacent, 
  std::map<char*, Table, cmp_str>& tableMap)
{
  while (true)
  {
    bool allVisited = true;

    char* min = new char[4];
    // Find min dist
    int minDist = MaxDist;
    for (std::map<char*, Table, cmp_str>::iterator iter = tableMap.begin(); iter != tableMap.end(); ++iter)
    {
      if (!(iter->second).visited)
      {
        allVisited = false;
        if ((iter->second).dist < minDist)
        {
          strcpy(min, iter->first);
          break;
        }
      }
    }
    if (allVisited)
      break;

    for (std::map<char*, Table, cmp_str>::iterator iter = tableMap.begin(); iter != tableMap.end(); ++iter)
    {
      if (!(iter->second).visited)
      {
        if ((iter->second).dist < tableMap[min].dist)
          strcpy(min, iter->first);
      }
    }

    // Update distance and path
    tableMap[min].visited = true;
    for (std::list<Dist>::iterator iter = adjacent[min].begin(); iter != adjacent[min].end(); ++iter)
    {
      if (!tableMap[iter->name].visited)
      {
        if (tableMap[iter->name].dist > tableMap[min].dist + iter->dist)
        {
          tableMap[iter->name].dist = tableMap[min].dist + iter->dist;
          tableMap[iter->name].path.clear();
          tableMap[iter->name].path.push_back(min);
        }
        // If multiple path
        else if (tableMap[iter->name].dist == tableMap[min].dist + iter->dist)
        {
          tableMap[iter->name].path.push_back(min);
        }
      }
    }
  }
}


void iterRoads(
  char* src, 
  char* dest, 
  std::map<char*, Table, cmp_str>& tableMap,
  std::stack<char*>& pi,
  int& loadNum,
  int& happiness,
  int& avgHappiness,
  std::vector<char*>& output)
{
  if (strcmp(src, dest) == 0)
  {
    ++loadNum;
    int hap = 0;
    int avgHap;
    int size = pi.size() - 1;
    std::vector<char*> out;
    while (!pi.empty())
    {
      char* top = pi.top();
      hap += tableMap[top].happiness;
      out.push_back(top);
      pi.pop();
    }
    avgHap = hap / size;
    if (hap > happiness || (hap == happiness && avgHap > avgHappiness))
    {
      happiness = hap;
      avgHappiness = avgHap;
      output.clear();
      output.assign(out.begin(), out.end());
    }
  }
  else
  {
    for (std::vector<char*>::iterator iter = tableMap[dest].path.begin(); iter != tableMap[dest].path.end(); ++iter)
    {
      std::stack<char*> s(pi);
      s.push(*iter);
      iterRoads(src, *iter, tableMap, s, loadNum, happiness, avgHappiness, output);
    }
  }
}


int main()
{
  freopen("in.txt", "r", stdin);

  int N, K;
  scanf("%d%d", &N, &K);
  char src[4];
  scanf("%s", src);
  Table t;
  t.happiness = 0;
  t.visited = false;
  t.dist = 0;
  tableMap.insert(std::make_pair(src, t));
  std::list<Dist> l;
  adjacent.insert(std::make_pair(src, l));

  // Construct table map
  for (int i = 0; i < N-1; ++i)
  {
    char* city = new char[4];
    int hap;
    scanf("%s%d", city, &hap);
    Table temp;
    temp.happiness = hap;
    temp.visited = false;
    temp.dist = MaxDist;

    tableMap.insert(std::make_pair(city, temp));

    std::list<Dist> li;
    adjacent.insert(std::make_pair(city, li));
  }

  // Construct adjacent list
  for (int i = 0; i < K; ++i)
  {
    char* from = new char[4];
    char* dest = new char[4];
    int dist;
    scanf("%s%s%d", from, dest, &dist);
    
    Dist temp;
    temp.name = new char[4];
    strcpy(temp.name, dest);
    temp.dist = dist;

    Dist t;
    t.name = new char[4];
    strcpy(t.name, from);
    t.dist = dist;

    adjacent[from].push_back(temp);
    adjacent[dest].push_back(t);
  }

  Dijkstra(adjacent, tableMap);

  // Calculate number of path
  int loadNum = 0;
  char dest[4];
  strcpy(dest, "ROM");
  std::stack<char*> s;
  s.push(dest);
  int happs = 0;
  int avgHappiness = 0;
  std::vector<char*> output;
  iterRoads(src, dest, tableMap, s, loadNum, happs, avgHappiness, output);

  printf("%d %d %d %d\n", loadNum, tableMap[dest].dist, happs, avgHappiness);

  for (int i = 0; i < output.size() - 1; ++i)
    printf("%s->", output[i]);
  printf("%s\n", output[output.size()-1]);

  return 0;
}

