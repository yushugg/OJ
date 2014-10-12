#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

struct PersonInfo
{
  char name[9];
  int age;
  int worth;
};

int main()
{
  freopen("in.txt", "r", stdin);

  int numOfPeople, numOfQueries;
  scanf("%d%d", &numOfPeople, &numOfQueries);

  std::vector<PersonInfo> people;
  for (int i = 0; i < numOfPeople; ++i)
  {
    PersonInfo pi;
    scanf("%s%d%d", pi.name, &pi.age, &pi.worth);
    people.push_back(pi);
  }

  for (int i = 0; i < numOfQueries; ++i)
  {
    int output, startAge, endAge;
    scanf("%d%d%d", &output, &startAge, &endAge);

    std::vector<PersonInfo> considerPeople;
    int idx = 0;
    for (int j = 0; j < numOfPeople; ++j)
    {
      if (people[j].age >= startAge && people[j].age <= endAge)
      {
        PersonInfo pi;
        strcpy(pi.name, people[j].name);
        pi.age = people[j].age;
        pi.worth = people[j].worth;
        considerPeople.push_back(pi);
        ++idx;
      }
    }
    
    if (!idx)
    {
      printf("Case #%d:\n", i+1);
      printf("None\n");
      continue;
    }
    
    std::sort(considerPeople.begin(), considerPeople.end(), [](PersonInfo pi1, PersonInfo pi2) -> bool {
      if (pi1.worth != pi2.worth)
        return pi1.worth > pi2.worth;
      else if (pi1.age != pi2.age)
        return pi1.age < pi2.age;
      else
        return strcmp(pi1.name, pi2.name) < 0;
    });

    // Print results
    printf("Case #%d:\n", i+1);
    for (int j = 0; j < idx && j < output; ++j)
      printf("%s %d %d\n", considerPeople[j].name, considerPeople[j].age, considerPeople[j].worth);
  }

  return 0;
}

