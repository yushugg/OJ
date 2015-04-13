## Problems

1. Majority Element: Use a counter
2. Remove Duplicates From Sorted Array: Two pointers, assignment on original array directly
3. Merge Sorted Array: Reversed merge, will save time and space
4. Min Stack: Use an extra stack to store min elements, if a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, check if the popped element is the same as the current minimum. If it is, pop it off the min stack too
5. Rotate Array: BA = rotate(rotate(A)rotate(B))
6. Unique Binary Search Trees: DP, F(i, n) = G(i - 1) * G(n - i), F(i, n) means number of unique trees when i is root, G(n) means total number of unique trees when nodes number is n, so G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
7. Maximum Subarray: maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
8. Single Number II: Use bits, ones-each bit of int appears once or not, twos-each bit of int appears twice or not, threes-each bit of int appears three times or not, if some bits of threes is marked 1, then these bits of ones and twos will all change to 0.
9. Sort Colors: Two iterations-Count and reassign; One iteration-two pointers and swap.
10. Container With Most Water: Two pointers, front and back.
11. Search in Rotated Sorted Array: Binary search, but compare A[mid] and A[low] to classify this problem, not A[mid] and target.
12. Set Matrix Zeros: Store count things in place, just use one row or column from matrix to save something, so extra space will be saved.
13. Linked List Cycle II: To determine a cycle use slow and fast pointer, both start from head, to find the cycle start, use an entry pointer starting from head, then both move entry and slow one step by step, then meet position is the entry point.
14. Permutations: for E: {a, b, c}, Perm(E) = aPerm(Enoa) + bPerm(Enob) + cPerm(Enoc), so if size(E) == 1, add result, else for begin to end, swap(begin and i) Permutation swap(begin and i). Last step is called the "backtrack step".
15. Unique Binary Search Trees II: return std::vector<TreeNode*> to iterate and to add in the front.
16. 3Sum Closest: Similar to 3Sum, for each one convert to a 2Sum problem, 2Sum use two pointers from start and end, O(N).
17. Gas Station: Greedy, two pointers starting from the same position and one goes left, another goes right.
18. Anagrams: Use unordered_map to construct a hash table.
19. Two Sum: Use a hashMap or map to store {need number, now index}, can be O(N), but consume O(N) space complexity as well.
20. Word Break: DP, canBreak[i] = canBreak[j<=i] && dict.find(str.substr(j~i))
21. String to Integer (atoi): To deal with overflow, inspect the current number before multiplication. If the current number is greater than 214748364, we know it is going to overflow. On the other hand, if the current number is equal to 214748364, we know that it will overflow only when the current digit is greater than or equal to 8, ie. 2147483648 and 2147483649.
22. Maximum Product Subarray: M1) Use max and min two arrays to store result
		
		f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
		g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )
		
	M2) Two pointers, calculate frontProduct from front and endProduct from end, get the max one, this will cancel the sign problems
23. Median of Two Sorted Arrays: Convert to find kth min, first array to find k/2 - 1, second to find n - k/2 + 1, then find(A + a, m - a, B, n, k - a), or find(A, m, B + b, n - b, k - b), always make m < n, and test m and k == 1
24. Longest Consecutive Sequence: Use a hashmap(unordered_map)


## Algorithms

### Containing a sequence

1. Rabin-Karp(or Karp-Rabin): Uses hashing to search pattern string in a text. For text of length n and p patterns of combined length m, its average and best case running time is O(n+m) in space O(p), but its worst-case time is O(nm). Because of common part of string, so hashing of a string only need to substraction and addition operation, which will be constant time.
2. Knuth-Morris-Pratt(or KMP): Search for occurrences of a word within a main text string by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters. Using Partial Match Table to predict movation.
3. Boyer-Moore: String searching algorithm. Bad characters and good postfixes movation.
4. Backtracking: First, some condition do something; Second, for-loop to other possible things. If first and second are one if-and-else, remember to undo parameters in for-loop.  
**Remember, do not need to generate next char or int, just for loop enough**  
**Same for loop explains same position, next recursive explains next position**
5. List: First, find previous list node, or add head if want to be convinence.
6. Tree level order traversal, including level: Every time read all queue content, then push all children of all content

    	while(!q.empty()) {
        	int size = q.size();
        	for (int i=0; i<size; i++) {
            	TreeNode *node = q.front();
            	q.pop();
            	if (i==(size-1)) vi.push_back(node->val);
            	if (node->left) q.push(node->left);
            	if (node->right) q.push(node->right);
        	}
    	}
