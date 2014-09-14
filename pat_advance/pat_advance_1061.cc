#include <cstdio>
#include <cstring>


void printWeek(char c)
{
  const char* list[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

  printf("%s ", list[(c - 'A')]);
}


void printHour(char c)
{
  if (c >= '0' && c <= '9')
    printf("0%c:", c);
  else
    printf("%d:", c - 'A' + 10);
}


void printMinute(size_t i)
{
  if (i < 10)
    printf("0%lu\n", i);
  else
    printf("%lu\n", i);
}


int main()
{
  freopen("in.txt", "r", stdin);

  const size_t strLen = 61;
  char encodings[4][strLen];

  for (size_t i = 0; i != 4; ++i)
    scanf("%s", encodings[i]);

  bool first = true;
  for (size_t i = 0; i != strLen; ++i)
  {
    // First common capital English letter
    if (first)
    {
      if (encodings[0][i] >= 'A' && encodings[0][i] <= 'G' &&
        encodings[0][i] == encodings[1][i])
      {
        printWeek(encodings[0][i]);
        first = false;
      }
    }
    // Second common English letter
    else
    {
      if (((encodings[0][i] >= '0' && encodings[0][i] <= '9') || 
        (encodings[0][i] >= 'A' && encodings[0][i] <= 'N')) &&
        (encodings[0][i] == encodings[1][i]))
      {
        printHour(encodings[0][i]);
        break;
      }
    }
  }

  for (size_t i = 0; i != strLen; ++i)
  {
    if (((encodings[2][i] >= 'a' && encodings[2][i] <= 'z') || 
      (encodings[2][i] >= 'A' && encodings[2][i] <= 'Z')) &&
      encodings[2][i] == encodings[3][i])
    {
      printMinute(i);
      break;
    }
  }

  return 0;
}

