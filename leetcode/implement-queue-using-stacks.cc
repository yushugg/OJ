class Queue {
private:
  stack<int> in;
  stack<int> out;

public:
  // Push element x to the back of queue.
  void push(int x) {
    in.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    while (!in.empty()) {
      int val = in.top();
      in.pop();
      out.push(val);
    }
    out.pop();
    while (!out.empty()) {
      int val = out.top();
      out.pop();
      in.push(val);
    }
  }

  // Get the front element.
  int peek(void) {
    while (!in.empty()) {
      int val = in.top();
      in.pop();
      out.push(val);
    }
    int ret = out.top();
    while (!out.empty()) {
      int val = out.top();
      out.pop();
      in.push(val);
    }
    return ret;
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return in.empty();
  }
};
