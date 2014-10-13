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

  int len = 0;
  int b[20005];
  int c[205];
  for (int i = 0; i < numOfPeople; ++i)
  {
    if (c[people[i].age] <= 100)
    {
      b[len++] = i;
      ++c[people[i].age];
    }
  }

  for (int i = 0; i < numOfQueries; ++i)
  {
    int output, startAge, endAge;
    scanf("%d%d%d", &output, &startAge, &endAge);
    
    // Print results
    printf("Case #%d:\n", i+1);
    int idx = 0;
    for (int j = 0; j < len && idx < output; ++j)
    {
      if (people[b[j]].age >= startAge && people[b[j]].age <= endAge)
      {
        printf("%s %d %d\n", people[b[j]].name, people[b[j]].age, people[b[j]].worth);
        ++idx;
      }
    }
    if (!idx)
      printf("None\n");
  }

  return 0;
}

