#include <cstdio>
#include <cstring>

const char* calls[] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
const char* numStr[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
  //freopen("out.txt", "w", stdout);
  char number[15];
  scanf("%s", number);
  int start = 0;

  int length = strlen(number);
  if (number[0] == '-')
  {
    printf("Fu ");
    start = 1;
  }

  if (strcmp(number, "0") == 0)
  {
    printf("ling\n");
    return 0;
  }

  for (int i = start; i < length; )
  {
    if (number[i] == '0')
    {
      // Whether ends are all zeros
      int zeroNum = 0;
      if (length - i > 4)
      {
        for (int j = i; j < length - 4; ++j)
        {
          if (number[j] == '0')
            ++zeroNum;
          else
            break;
        }
        if (zeroNum == 4)
        {
          bool zeros = true;
          i += zeroNum;
          for (int k = i; k < length; ++k)
            if (number[k] != '0')
              zeros = false;
          if (!zeros)
            printf("ling ");
        }
        else if (zeroNum == length - 4 - i)
        {
          printf("Wan");
          bool zeros = true;
          i += zeroNum;
          for (int k = i; k < length; ++k)
            if (number[k] != '0')
              zeros = false;
          if (!zeros)
            putchar(' ');
        }
        else
        {
          printf("ling ");
          i += zeroNum;
        }
      }
      else
      {
        for (int j = i; j < length; ++j)
        {
          if (number[j] == '0')
            ++zeroNum;
          else
            break;
        }
        if (zeroNum == length - i)
        {
          i += zeroNum;
        }
        else
        {
          printf("ling ");
          i += zeroNum;
        }
      }
    }
    else
    {
      printf("%s", numStr[number[i]-'0']);
      if (i != length - 1)
        putchar(' ');
      printf("%s", calls[length-i-1]);
      bool zeros = true;
      for (int k = i+1; k < length; ++k)
        if (number[k] != '0')
          zeros = false;
      if (zeros)
        i = length;
      else if (i != length - 1)
        putchar(' ');
      ++i;
    }
  }

  putchar('\n');

  return 0;
}

