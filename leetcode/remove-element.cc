class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int start = 0;
    int end = n - 1;

    // Find last element that is not same
    while (end >= 0 && A[end] == elem)
      --end;

    while (start < end)
    {
      if (A[start] == elem)
      {
        A[start] = A[end];
        A[end] = elem;
        while (end >= 0 && A[end] == elem)
          --end;
      }
      ++start;
    }

    return end + 1;
  }
};
