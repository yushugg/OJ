#include <iostream>
#include <vector>

using namespace std;

int binarySearchInArray(vector<vector<int>>& matrix, int idx, int begin, int end, int target, bool isRow) {
    int p1 = begin, p2 = end, mid;
    while (p1 <= p2) {
        mid = p1 + (p2 - p1) / 2;
        int key = isRow ? matrix[idx][mid] : matrix[mid][idx];
        if (key == target) return mid;
        else if (key < target) p1 = mid + 1;
        else p2 = mid - 1;
    }
    cout << "binarySearchInArray: " << (isRow ? "row" : "col") << " " << idx << " " << begin << " " << end << " " << ", result: " << p1 << "\n";
    return p1 == end + 1 ? end : p1;
}

bool binarySearchInMatrix(vector<vector<int>>& matrix, int up, int down, int left, int right, int target) {
    cout << "binarySearchInMatrix: " << up << " " << down << " " << left << " " << right << "\n";
    if (up > down || left > right) return false;
    int r = binarySearchInArray(matrix, up + (down - up) / 2, left, right, target, true);
    int c = binarySearchInArray(matrix, r, up, down, target, false);
    if (matrix[r][c] == target) return true;
    return binarySearchInMatrix(matrix, up, c - 1, r + 1, right, target) || binarySearchInMatrix(matrix, c + 1, down, left, r - 1, target);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    return binarySearchInMatrix(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
}

int main() {
    // vector<vector<int>> matrix{{1,   4,  7, 11, 15}, {2,   5,  8, 12, 19}, {3,   6,  9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    vector<vector<int>> matrix{{1, 1}};
    cout << searchMatrix(matrix, 2) << "\n";

    return 0;
}
