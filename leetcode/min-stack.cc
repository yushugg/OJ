#include <stack>

class MinStack {
private:
  std::stack<int> data;
  std::stack<int> min;

public:
  void push(int x) {
    data.push(x);
    if (min.empty() || x <= min.top())
      min.push(x);
  }

  void pop() {
    if (!data.empty())
    {
      if (data.top() == min.top())
        min.pop();
      data.pop();
    }
  }

  int top() {
    return data.top();
  }

  int getMin() {
    return min.top();
  }
};
