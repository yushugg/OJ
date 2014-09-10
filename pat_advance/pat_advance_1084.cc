#include <cstdio>
#include <map>
#include <cstring>

int main()
{
  char origin[85];
  char now[85];
  std::map<char, bool> worn;

  // Initialize map
  for (int k = 0; k < 26; ++k)
  {
    char key = 'A' + k;
    worn[key] = false;
  }
  for (int k = 0; k < 10; ++k)
  {
    char key = '0' + k;
    worn[key] = false;
  }
  worn['_'] = false;

  scanf("%s", origin);
  scanf("%s", now);

  int j = 0;
  for (int i = 0; origin[i] != '\0'; ++i)
  {
    if (j >= strlen(now) || origin[i] != now[j])
    {
      // To uppercase
      char cap = origin[i] < 'a' ? origin[i] : origin[i] - ('a' - 'A');
      if (!worn[cap])
      {
        putchar(cap);
        worn[cap] = true;
      }
    }
    else
    {
      ++j;
    }
  }

  putchar('\n');

  return 0;
}

