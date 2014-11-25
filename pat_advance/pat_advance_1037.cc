#include <cstdio>
#include <algorithm>

int main()
{
  int NC, NP;
  scanf("%d", &NC);
  int* coupons = new int[NC];
  for (int i = 0; i < NC; ++i)
    scanf("%d", &coupons[i]);

  scanf("%d", &NP);
  int* products = new int[NP];
  for (int i = 0; i < NP; ++i)
    scanf("%d", &products[i]);

  std::sort(coupons, coupons + NC);
  std::sort(products, products + NP);

  int sum = 0;

  int c = NC - 1;
  int p = NP - 1;
  while (c >= 0 && p >= 0 && coupons[c] > 0 && products[p] > 0)
  {
    sum += coupons[c] * products[p];
    --c;
    --p;
  }

  while (c >= 0 && coupons[c] >= 0)
    --c;
  while (p >= 0 && products[p] >= 0)
    --p;
  int ctag = c;
  int ptag = p;

  c = p = 0;
  while (c <= ctag && p <= ptag)
  {
    sum += coupons[c] * products[p];
    ++c;
    ++p;
  }

  printf("%d\n", sum);

  delete[] coupons;
  delete[] products;

  return 0;
}

