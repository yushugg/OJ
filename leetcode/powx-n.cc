#include <cstdio>
#include <vector>

class Solution {
public:
  double pow(double x, int n) {
    int num = n;
    if (n < 0)
      num = -n;
    double product = 1;
    std::vector<double> results;
    int idx;
    for (idx = 1; idx <= num && idx > 0; idx *= 2)
    {
      if (results.empty())
        results.push_back(x);
      else
      {
        double back = results.back();
        results.push_back(back * back);
      }
    }
    idx /= 2;
    if (idx < 0)
      idx = 1073741824;
    while (idx)
    {
      if (idx <= num)
      {
        num -= idx;
        product *= results.back();
      }
      idx /= 2;
      results.pop_back();
    }

    if (n >= 0)
      return product;
    else
      return 1 / product;
  }
};

int main(int argc, char* argv[])
{
  double x;
  scanf("%lf", &x);
  int n;
  scanf("%d", &n);

  Solution s;
  printf("%lf\n", s.pow(x, n));

  return 0;
}

