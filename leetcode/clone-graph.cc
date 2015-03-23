/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include <unordered_map>

class Solution {
public:
  UndirectedGraphNode *clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& labelMap)
  {
    UndirectedGraphNode* newNode;
    if (labelMap.find(node->label) == labelMap.end())
    {
      newNode = new UndirectedGraphNode(node->label);
      labelMap[node->label] = newNode;
    }
    else
    {
      newNode = labelMap[node->label];
      return newNode;
    }

    for (auto iter = node->neighbors.begin(); iter != node->neighbors.end(); ++iter)
      newNode->neighbors.push_back(clone(*iter, labelMap));

    return newNode;
  }

  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node)
      return node;

    std::unordered_map<int, UndirectedGraphNode*> labelMap;

    return clone(node, labelMap);
  }
};
