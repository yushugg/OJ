//
//  main.cpp
//  OJ
//
//  Created by yushu on 14-8-20.
//  Copyright (c) 2014年 yushu. All rights reserved.
//

#include <cstdio>
#include <cstring>

bool normalAdd(long a, long b, long c)
{
  bool flag;
  if (a > 0 && b > 0 && a+b <= 0)
    flag = true;
  else if (a < 0 && b < 0 && a+b >= 0)
    flag = false;
  else if (a + b > c)
    flag = true;
  else
    flag = false;

  return flag;
}

int main(int argc, const char * argv[])
{
  freopen("in.txt", "r", stdin);
  int T;
  scanf("%d", &T);

  const char* limit = "9223372036854775808";
  const long max = 9223372036854775807;

  for (int i = 0; i < T; ++i)
  {
    char aStr[25], bStr[25], cStr[25];
    long a, b, c;
    bool flag = true;

    scanf("%s%s%s", aStr, bStr, cStr);

    if (strcmp(aStr, limit))
    {
      sscanf(aStr, "%ld", &a);
      if (strcmp(bStr, limit))
      {
        sscanf(bStr, "%ld", &b);
        if (strcmp(cStr, limit))
        {
          sscanf(cStr, "%ld", &c);
          flag = normalAdd(a, b, c);
        }
        // c == 2E63
        else
        {
          if (a >= -max)
            flag = normalAdd(a-1, b, max);
          else if (b >= -max)
            flag = normalAdd(a, b-1, max);
          else
            flag = false;
        }
      }
      // b == 2E63
      else
      {
        if (strcmp(cStr, limit))
        {
          sscanf(cStr, "%ld", &c);
          if (c >= -max)
            flag = normalAdd(a, max, c-1);
          else
            flag = true;
        }
        // c == 2E63
        else
        {
          flag = a > 0;
        }
      }
    }
    // a == 2E63
    else
    {
      if (strcmp(bStr, limit))
      {
        sscanf(bStr, "%ld", &b);
        if (strcmp(cStr, limit))
        {
          sscanf(cStr, "%ld", &c);
          if (c >= -max)
            flag = normalAdd(max, b, c-1);
          else
            flag = true;
        }
        // c == 2E63
        else
        {
          flag = b > 0;
        }
      }
      // b == 2E63
      else
      {
        flag = true;
      }
    }

    // Print true or false
    if (flag)
      printf("Case #%d: true\n", i+1);
    else
      printf("Case #%d: false\n", i+1);
  }

  return 0;
}

