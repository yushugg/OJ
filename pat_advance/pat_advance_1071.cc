#include <cstdio>
#include <vector>
#include <map>

std::map<std::vector<char>, int> patternMap;

int main()
{
  freopen("in.txt", "r", stdin);
  // Read
  char c;
  int wordLength = 0;
  std::vector<char> word;
  while ((c = getchar()) != '\n')
  {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
      ++wordLength;
      if (c >= 'A' && c <= 'Z')
        c += 32;
      word.push_back(c);
    }
    else
    {
      if (wordLength)
      {
        if (patternMap.find(word) == patternMap.end())
          patternMap.insert(std::make_pair(word, 0));
        ++patternMap[word];
        word.clear();
      }
      wordLength = 0;
    }
  }
  // Last one counts!!!
  if (wordLength)
  {
    if (patternMap.find(word) == patternMap.end())
      patternMap.insert(std::make_pair(word, 0));
    ++patternMap[word];
    word.clear();
  }

  std::pair<std::vector<char>, int> max;
  max.second = 0;
  for (std::map<std::vector<char>, int>::iterator iter = patternMap.begin(); iter != patternMap.end(); ++iter)
  {
    if (iter->second > max.second)
      max = *iter;
  }

  for (size_t i = 0; i < max.first.size(); ++i)
    putchar(max.first[i]);
  printf(" %d\n", max.second);

  return 0;
}

