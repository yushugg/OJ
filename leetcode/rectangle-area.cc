#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (A > C) swap(A, C); if (E > G) swap(E, G);
    if (B > D) swap(B, D); if (F > H) swap(F, H);
    if (C <= E || A >= G || D <= F || B >= H) return (C - A) * (D - B) + (G - E) * (H - F);
    int x1 = max(A, E), x2 = min(C, G), y1 = max(B, F), y2 = min(D, H);
    return (C - A) * (D - B) + (G - E) * (H - F) - (x2 - x1) * (y2 - y1);
  }
};

int main () {
  int A, B, C, D, E, F, G, H;
  scanf("%d%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &G, &H);

  Solution solution;
  printf("%d\n", solution.computeArea(A, B, C, D, E, F, G, H));

  return 0;
}

