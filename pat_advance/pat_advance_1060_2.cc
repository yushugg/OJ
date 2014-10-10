#include <cstdio>
#include <cstring>

int getExp(const char* num)
{
  int exp = 0;
  bool startCount = false;
  bool hasDot = false;
  int i;
  for (i = 0; i < strlen(num); ++i)
  {
    if (num[i] != '.')
    {
      if (startCount)
        ++exp;
      else if (num[i] != '0')
      {
        startCount = true;
        ++exp;
      }
    }
    else
    {
      hasDot = true;
      break;
    }
  }
  if (!exp && hasDot)
  {
    for (++i; i < strlen(num); ++i)
    {
      if (num[i] == '0')
        --exp;
      else
        break;
    }
    if (i == strlen(num))
      exp = 0;
  }

  return exp;
}

char* getValid(const char* num, int valid)
{
  char* validNum = new char[valid+1];
  for (int i = 0; i < valid; ++i)
    validNum[i] = '0';
  validNum[valid] = '\0';

  bool startCount = false;
  int idx = 0;
  for (int i = 0; i < strlen(num) && idx < valid; ++i)
  {
    if (num[i] != '.')
    {
      if (startCount)
        validNum[idx++] = num[i];
      else if (num[i] != '0')
      {
        startCount = true;
        validNum[idx++] = num[i];
      }
    }
  }

  return validNum;
}

int main()
{
  int N;
  char A[105], B[105];
  scanf("%d%s%s", &N, A, B);

  if (strcmp(getValid(A, N), getValid(B, N)) == 0 && getExp(A) == getExp(B))
    printf("YES 0.%s*10^%d\n", getValid(A, N), getExp(A));
  else
    printf("NO 0.%s*10^%d 0.%s*10^%d\n", getValid(A, N), getExp(A), getValid(B, N), getExp(B));

  return 0;
}

