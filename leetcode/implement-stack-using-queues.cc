class Stack {
private:
  queue<int> q;

public:
  // Push element x onto stack.
  void push(int x) {
    q.push(x);
  }

  // Removes the element on top of the stack.
  void pop(void) {
    int size = q.size();
    while (size > 1) {
      int val = q.front();
      q.pop();
      q.push(val);
      --size;
    }
    q.pop();
  }

  // Get the top element.
  int top(void) {
    int size = q.size();
    while (size > 1) {
      int val = q.front();
      q.pop();
      q.push(val);
      --size;
    }
    int topVal = q.front();
    q.pop();
    q.push(topVal);
    return topVal;
  }

  // Return whether the stack is empty.
  bool empty(void) {
    return q.empty();
  }
};
