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
    
  std::sort(people.begin(), people.end(), [](PersonInfo pi1, PersonInfo pi2) -> bool {
    if (pi1.worth != pi2.worth)
      return pi1.worth > pi2.worth;
    else if (pi1.age != pi2.age)
      return pi1.age < pi2.age;
    else
      return strcmp(pi1.name, pi2.name) < 0;
  });

  // Erase exceed 100
  int currentAge = people[0].age;
  int count = 0;
  for (std::vector<PersonInfo>::iterator iter = people.begin(); iter != people.end(); ++iter)
  {
    if (iter->age != currentAge)
    {
      currentAge = iter->age;
      count = 0;
    }
    ++count;
    if (count > 100)
      people.erase(iter);
  }

  for (int i = 0; i < numOfQueries; ++i)
  {
    int output, startAge, endAge;
    scanf("%d%d%d", &output, &startAge, &endAge);
    
    // Print results
    printf("Case #%d:\n", i+1);
    int idx = 0;
    for (int j = 0; j < people.size(); ++j)
    {
      if (people[j].age >= startAge && people[j].age <= endAge && idx < output)
      {
        printf("%s %d %d\n", people[j].name, people[j].age, people[j].worth);
        ++idx;
      }
      if (idx == output)
        break;
    }
    if (!idx)
      printf("None\n");
  }

  return 0;
}

