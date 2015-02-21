#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
  std::vector<std::string> getVersionVector(std::string version) {
    std::vector<std::string> vec;
    std::string level = "";
    for (size_t i = 0; i != version.length(); ++i)
    {
      if (version[i] == '.')
      {
        if (level == "")
          level = "0";
        vec.push_back(level);
        level = "";
      }
      else if (level != "" || version[i] != '0')
        level.push_back(version[i]);
    }
    if (level == "")
      level = "0";
    vec.push_back(level);

    // Test output
    //for (auto iter = vec.begin(); iter != vec.end(); ++iter)
      //std::cout << *iter << ":";
    //std::cout << std::endl;

    return vec;
  }

  int compareVersion(std::string version1, std::string version2) {
    std::vector<std::string> version1Vec = getVersionVector(version1);
    std::vector<std::string> version2Vec = getVersionVector(version2);
    size_t minSize = version1Vec.size() < version2Vec.size() ? version1Vec.size() : version2Vec.size();

    for (size_t i = 0; i != minSize; ++i)
    {
      if (version1Vec[i].length() != version2Vec[i].length())
      {
        if (version1Vec[i].length() < version2Vec[i].length())
          return -1;
        else
          return 1;
      }
      else if (version1Vec[i] != version2Vec[i])
      {
        if (version1Vec[i] < version2Vec[i])
          return -1;
        else
          return 1;
      }
    }

    if (version1Vec.size() > version2Vec.size())
    {
      for (size_t i = minSize; i != version1Vec.size(); ++i)
        if (version1Vec[i] != "0")
          return 1;

      return 0;
    }
    else if (version1Vec.size() < version2Vec.size())
    {
      for (size_t i = minSize; i != version2Vec.size(); ++i)
        if (version2Vec[i] != "0")
          return -1;

      return 0;
    }
    else
      return 0;
  }
};

int main(int argc, char* argv[])
{
  std::string version1, version2;
  std::cin >> version1 >> version2;

  Solution s;
  std::cout << s.compareVersion(version1, version2) << std::endl;

  return 0;
}

