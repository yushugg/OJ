class Solution {
public:
  int reverse(int x) {
    bool flag = true;
    if (x<0)
    {
      flag = false;
      x = -x;
    }
    int y = 0;
    while (x)
    {
      y = y*10 + x%10;
      x /= 10;
    }
    return flag ? y : -y;
  }
};
