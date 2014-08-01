#include <cstdio>
#include <cstring>

char str[10050];
char num[10050];
int exp;

int main()
{
  // Read string
  scanf("%s", str);

  sscanf(str, "%[^E]E%d", num, &exp);

  if (num[0] == '-')
    putchar('-');
  
  if (exp > 0)
  {
    putchar(num[1]);
    int i;
    for (i = 3; i < strlen(num); ++i)
    {
      if (exp > 0)
      {
        putchar(num[i]);
        --exp;
      }
      else
        break;
    }
    // Add 0s
    while (exp)
    {
      putchar('0');
      --exp;
    }
    // Add . and remaining demical
    if (i < strlen(num))
      putchar('.');
    while (i < strlen(num))
    {
      putchar(num[i++]);
    }
    putchar('\n');
  }
  else if (exp < 0)
  {
    printf("0.");
    for (int i = 0; i < (-exp)-1; ++i)
      putchar('0');
    for (int i = 1; i < strlen(num); ++i)
      if (num[i] != '.')
        putchar(num[i]);
    putchar('\n');
  }
  else
  {
    for (int i = 1; i < strlen(num); ++i)
      putchar(num[i]);
    putchar('\n');
  }

  return 0;
}

